#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <variant>
#include <memory>
#include <cctype>
#include <stdexcept>
using namespace std;
// === JSON Value Definition ===
struct JsonValue;

using JsonArray = std::vector<JsonValue>;
using JsonObject = std::map<std::string, JsonValue>;

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
/*
class Tokenizer {
public:
    Tokenizer(const std::string& input) : str(input), pos(0) {}

    Token nextToken() {
        skipWhitespace();
        if (pos >= str.size()) return Token{TokenType::End, ""};

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
            if (str[pos] == '\') {
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
*/

class Tokenizer {
  public:
  Tokenizer(const std::string& input) : str(input), pos(0) {}
  Token nextToken() {
        //skipWhitespace();
        if (pos >= str.size()) return Token{TokenType::End, ""};

        char ch = str[pos];
        switch (ch) {
            case '{': ++pos; return {TokenType::LeftBrace, "{"};
            case '}': ++pos; return {TokenType::RightBrace, "}"};
            case '[': ++pos; return {TokenType::LeftBracket, "["};
            case ']': ++pos; return {TokenType::RightBracket, "]"};
            case ':': ++pos; return {TokenType::Colon, ":"};
            case ',': ++pos; return {TokenType::Comma, ","};
            //case '"': return parseString();
            default:
                if (std::isdigit(ch) || ch == '-') return parseNumber();
                if (str.compare(pos, 4, "true") == 0) { pos += 4; return {TokenType::True, "true"}; }
                if (str.compare(pos, 5, "false") == 0) { pos += 5; return {TokenType::False, "false"}; }
                if (str.compare(pos, 4, "null") == 0) { pos += 4; return {TokenType::Null, "null"}; }
                throw std::runtime_error("Unexpected character: " + std::string(1, ch));
        }
    }

    std::string str;
    size_t pos;
    Token parseNumber() {
        size_t start = pos;
        while (pos < str.size() && (std::isdigit(str[pos]) || str[pos] == '.' || str[pos] == '-')) ++pos;
        return {TokenType::Number, str.substr(start, pos - start)};
    }
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

};
int main(){
  Token t1{TokenType::LeftBrace, ":9"};
  Tokenizer t("abc");
  cout<<t.str<<endl <<t.pos<<endl ;
}