#include <iostream>
#include <sstream>
#include <string>
#include<vector>
using namespace std;

template <typename T> string debug_rep(const T &t) {
ostringstream ret; ret << t;return ret.str();}
template <typename T> string debug_rep(T *p){
   ostringstream ret;ret << "pointer: " << p;
    if (p) ret << " " << debug_rep(*p);
    else ret << " null pointer";
    return ret.str();
}
string debug_rep(const string &s) { return '"' + s + '"'; }
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}


int main(){
    int i=0;
    cout<<debug_rep(&i)<<endl;
    cout<<debug_rep(vector{1,2,3,4,5})<<endl;
    cout<<debug_rep(string("zxcvb"))<<endl;
cout << debug_rep("99999")<<endl;
}