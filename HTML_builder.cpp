#include "My.h"
#include <numeric> // For std::accumulate
template <char *tagName>
class htmlTag
{
public:
    htmlTag(initializer_list<string> li) : contents{accumulate(li.begin(), li.end(), string{})}
    {
    }
    operator string() const
    {
        return "<" + string(tagName) + map2string() + ">" + contents + "</" + string(tagName) + ">\n";
    }
    htmlTag &setAttribute(const std::string &key, const std::string &value)
    {
        attributes[key] = value;
        return *this; // for chaining
    }

private:
    string contents;
    map<string, string> attributes;
    string map2string() const
    {
        string result;
        for (const auto &[key, value] : attributes)
        {
            result += " " + key + "='" + value + "'";
        }
        return result;
    }
};
char htmlH1[] = "h1";
char htmlDiv[] = "div";
char htmlSpan[] = "span";
char htmlBody[] = "body";
char htmlHtml[] = "html";
char htmlHead[] = "head";
char htmlA[] = "a";
char htmlLi[] = "li";
char htmlP[] = "p";

using H1 = htmlTag<htmlH1>;
using Div = htmlTag<htmlDiv>;
using Span = htmlTag<htmlSpan>;
using Body = htmlTag<htmlBody>;
using Html = htmlTag<htmlHtml>;
using Head = htmlTag<htmlHead>;
using A = htmlTag<htmlA>;
using Li = htmlTag<htmlLi>;
using P = htmlTag<htmlP>;

int main()
{
    H1 header{"Welcome to My Website", " - Enjoy your stay!"};
    Div container{
        "<p>This is a sample paragraph inside a div.</p>",
    };
    A a1{"Click here to visit example.com"};
    a1.setAttribute("href", "https://www.example.com");
    Span highlight{"This text is highlighted."};
    Body pageBody{header, container, highlight, a1};
    Html fullPage{pageBody}; // Just to show multiple contents
    cout << string(fullPage) << endl;
    // test map output
    map<string, string> testMap = {{"key1", "value1"}, {"key2", "value2"}};
    cout << testMap << endl;
    return 0;
}