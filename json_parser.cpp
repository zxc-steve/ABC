
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <variant>
#include <memory>
#include <cctype>
#include <stdexcept>
//using namespace std;
// === JSON Value Definition ===

struct JsonValue;
using JsonArray = std::vector<JsonValue>;
using JsonObject = std::map<std::string, JsonValue>;
using JsonVariant = std::variant<
        std::nullptr_t,
        bool,
        double,
        std::string,
        JsonArray,
        JsonObject
    >;

struct JsonValue: JsonVariant{
    using JsonVariant::JsonVariant; // Inherit constructors
                                    // i.e. make  JsonVariant construtors available in JsonValue scope
};
/*
struct JsonValue {
    using ValueType = std::variant<
        std::nullptr_t,
        bool,
        double,
        std::string,
        JsonArray,
        JsonObject
    >;

    ValueType value;

    JsonValue() : value(nullptr) {}
    JsonValue(bool b) : value(b) {}
    JsonValue(double d) : value(d) {}
    JsonValue(const std::string& s) : value(s) {}
    JsonValue(const JsonArray& arr) : value(arr) {}
    JsonValue(const JsonObject& obj) : value(obj) {}
};
*/
// === Tokenizer ===
enum class TokenType {
    LeftBrace, RightBrace,
    LeftBracket, RightBracket,
    Colon, Comma,
    String, Number,
    True, False, Null,
    End
};

struct Token {
    TokenType type;
    std::string value;
};

class Tokenizer {
public:
    Tokenizer(const std::string& input) : str(input), pos(0) {}

    Token nextToken() {
        skipWhitespace();
        if (pos >= str.size()) return {TokenType::End, std::string("")};

        char ch = str[pos];
        switch (ch) {
            case '{': ++pos; return {TokenType::LeftBrace, "{"};
            case '}': ++pos; return {TokenType::RightBrace, "}"};
            case '[': ++pos; return {TokenType::LeftBracket, "["};
            case ']': ++pos; return {TokenType::RightBracket, "]"};
            case ':': ++pos; return {TokenType::Colon, ":"};
            case ',': ++pos; return {TokenType::Comma, ","};
            case '"': return parseString();
            default:
                if (std::isdigit(ch) || ch == '-') return parseNumber();
                if (str.compare(pos, 4, "true") == 0) { pos += 4; return {TokenType::True, "true"}; }
                if (str.compare(pos, 5, "false") == 0) { pos += 5; return {TokenType::False, "false"}; }
                if (str.compare(pos, 4, "null") == 0) { pos += 4; return {TokenType::Null, "null"}; }
                throw std::runtime_error("Unexpected character: " + std::string(1, ch));
        }
    }

    Token peekToken() {
        size_t savedPos = pos;
        Token token = nextToken();
        pos = savedPos;
        return token;
    }

private:
    std::string str;
    size_t pos;

    void skipWhitespace() {
        while (pos < str.size() && std::isspace(str[pos])) ++pos;
    }

    Token parseString() {
        ++pos; // skip opening quote
        std::string result;
        while (pos < str.size() && str[pos] != '"') {
            if (str[pos] == '\\') {
                ++pos;
                if (pos < str.size()) {
                    result += str[pos]; // naive escape handling
                }
            } else {
                result += str[pos];
            }
            ++pos;
        }
        ++pos; // skip closing quote
        return {TokenType::String, result};
    }

    Token parseNumber() {
        size_t start = pos;
        while (pos < str.size() && (std::isdigit(str[pos]) || str[pos] == '.' || str[pos] == '-')) ++pos;
        return {TokenType::Number, str.substr(start, pos - start)};
    }
};

// === Parser ===
class JsonParser {
public:
    JsonParser(const std::string& input) : tokenizer(input) {}

    JsonValue parse() {
        return parseValue();
    }

private:
    Tokenizer tokenizer;

    JsonValue parseValue() {
        Token token = tokenizer.peekToken();
        switch (token.type) {
            case TokenType::LeftBrace: return parseObject();
            case TokenType::LeftBracket: return parseArray();
            case TokenType::String: return parseString();
            case TokenType::Number: return parseNumber();
            case TokenType::True: tokenizer.nextToken(); return JsonValue(true);
            case TokenType::False: tokenizer.nextToken(); return JsonValue(false);
            case TokenType::Null: tokenizer.nextToken(); return JsonValue();
            default: throw std::runtime_error("Unexpected token in value");
        }
    }

    JsonValue parseObject() {
        tokenizer.nextToken(); // consume '{'
        JsonObject obj;

        while (tokenizer.peekToken().type != TokenType::RightBrace) {
            Token key = tokenizer.nextToken();
            if (key.type != TokenType::String) throw std::runtime_error("Expected string key");

            Token colon = tokenizer.nextToken();
            if (colon.type != TokenType::Colon) throw std::runtime_error("Expected ':'");

            JsonValue val = parseValue();
            obj[key.value] = val;

            Token next = tokenizer.peekToken();
            if (next.type == TokenType::Comma) tokenizer.nextToken();
            else if (next.type != TokenType::RightBrace) throw std::runtime_error("Expected ',' or '}'");
        }

        tokenizer.nextToken(); // consume '}'
        return JsonValue(obj);
    }

    JsonValue parseArray() {
        tokenizer.nextToken(); // consume '['
        JsonArray arr;

        while (tokenizer.peekToken().type != TokenType::RightBracket) {
            arr.push_back(parseValue());

            Token next = tokenizer.peekToken();
            if (next.type == TokenType::Comma) tokenizer.nextToken();
            else if (next.type != TokenType::RightBracket) throw std::runtime_error("Expected ',' or ']'");
        }

        tokenizer.nextToken(); // consume ']'
        return JsonValue(arr);
    }

    JsonValue parseString() {
        Token token = tokenizer.nextToken();
        return JsonValue(token.value);
    }

    JsonValue parseNumber() {
        Token token = tokenizer.nextToken();
        return JsonValue(std::stod(token.value));
    }
};

// === Main ===
int main() {
    std::string json = R"({
        "name": "Steve",
        "age": 30,
        "is_student": false,
        "skills": ["C++", "Python", "JSON"],
        "details": null
    })";

    try {
        JsonParser parser(json);
        JsonValue root = parser.parse();
        std::cout << "Parsed successfully!\n";
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
    }

    return 0;
}
