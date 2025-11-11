#include <iostream>
#include <sstream>
#include <string>
#include<vector>
using namespace std;
string debug_rep(const string &s);
template <typename T> string debug_rep(const T &t);
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        //os << vec[i];
        os<<debug_rep(vec[i]);
        if (i != vec.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

template <typename T> string debug_rep(const T &t) {
ostringstream ret; ret << t;return ret.str();}
template <typename T> string debug_rep(T *p){
   ostringstream ret;ret << "pointer: " << p;
    if (p) ret << " " << debug_rep(*p);
    else ret << " null pointer";
    return ret.str();
}
string debug_rep(const string &s) { return '"' + s + '"'; }


int main(){
    int i=0;
    cout<<debug_rep(&i)<<endl;
    cout<<debug_rep(vector{9,8,7,6,5,});
    cout<<debug_rep(vector<string>{"1","@","#5"})<<endl;
    cout<<debug_rep(string("zxcvb"))<<endl;
cout << debug_rep("99999")<<endl;
}
