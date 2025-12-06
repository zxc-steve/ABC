#include "My.h"    
#include <chrono>
void test_chrono() {    
    using namespace std::chrono;
    //using namespace std::chrono_literals::chrono_literals;
    //cout << "birthday: " << November/28/2021 << '\n';b
    }   
////////// back_insert_iterator input //////////
template<typename T>
std::istream& operator>>(std::istream& is, std::back_insert_iterator<std::vector<T>> &obj) {
    T tmp; is >> tmp;  *obj = tmp;   return is;  }
void test_iterator() {    
    vector<int> v;
    auto it = back_inserter(v);
    while(cin>>it);
    cout << v << endl;
}
int main() {
    string a,b,*ap=&a,*bp=&b,*cp=new string("abc");
    debug(ap);
    debug(bp);
    debug(ap<bp);debug(ap<cp)
    debug(&a-&b);
    test_iterator();
    return 0;
}