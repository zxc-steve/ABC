#include "My.h"
#include <numeric> // For std::accumulate
template<const char* tagName>
class htmlTag{
public:
    htmlTag(initializer_list<string> li):
    contents{accumulate(li.begin(), li.end(), string{})} 
        {}
    operator string() const {
        return "<" + string(tagName) + map2string() + ">" + contents + "</" + string(tagName) + ">\n";
    }
    htmlTag& setAttribute(const std::string& key, const std::string& value) {
        attributes[key] = value;
        return *this; // for chaining
    }
    private:
    string contents;
    map<string, string> attributes;
    string map2string() const{
        string result;
        for(const auto& [key, value] : attributes) {
            result += " " + key + "='" + value + "'";
        }
        return result;
    }   
};
constexpr char htmlH1[] = "h1" ;
constexpr char htmlDiv[] = "div" ;
constexpr char htmlSpan[] = "span" ;
constexpr char htmlBody[] = "body" ;
constexpr char htmlHtml[] = "html" ;
constexpr char htmlHead[] = "head" ;
constexpr char htmlA[] = "a" ;
constexpr char htmlLi[] = "li" ;
constexpr char htmlP[] = "p" ;

using h1 = htmlTag<htmlH1>;
using Div = htmlTag<htmlDiv>;
using span = htmlTag<htmlSpan>; 
using body = htmlTag<htmlBody>;
using html = htmlTag<htmlHtml>;
using head = htmlTag<htmlHead>;
using a = htmlTag<htmlA>;
using li = htmlTag<htmlLi>;
using p = htmlTag<htmlP>;

int main() {
    h1 header{"Welcome to My Website", " - Enjoy your stay!"};
    Div container{"<p>This is a sample paragraph inside a div.</p>",};
    a a1{"Click here to visit example.com"};
    a1.setAttribute("href", "https://www.example.com");
    span highlight{"This text is highlighted."};
    body pageBody{header, container, highlight,a1};
    html fullPage{pageBody};
    cout << string(fullPage) << endl;
    return 0;
}   