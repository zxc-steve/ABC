#include <iostream>
#include <vector>
using namespace std;
#define debug(x) cout<<#x<<"="<<x<<endl;
template<typename T>
ostream& operator<<(ostream& os, vector<T>& obj) { 
    for (auto& x : obj) os << x << " "; return os; }
    
////////// back_insert_iterator input //////////
template<typename T>
std::istream& operator>>(std::istream& is, std::back_insert_iterator<std::vector<T>> &obj) {
    T tmp; is >> tmp;  *obj = tmp;   return is;  }

int main() {
    vector<int> v;
    auto it = back_inserter(v);
    while(cin>>it);
    cout << v << endl;
    return 0;
}