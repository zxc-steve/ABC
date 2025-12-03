#include "My.h"    
////////// back_insert_iterator input //////////
template<typename T>
std::istream& operator>>(std::istream& is, std::back_insert_iterator<std::vector<T>> &obj) {
    T tmp; is >> tmp;  *obj = tmp;   return is;  }

int main() {
    string a,b,*ap=&a,*bp=&b;
    debug(ap);
    debug(bp);
    debug(ap<b));
    debug(&a-&b);
    vector<int> v;
    auto it = back_inserter(v);
    while(cin>>it);
    cout << v << endl;
    return 0;
}