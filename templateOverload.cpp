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
// test conflict #1
    ret<<' '<<(p?debug_rep(*p):"null pointer");
    return ret.str();
}
string debug_rep(const string &s) { return '"' + s + '"'; }
string debug_rep(const char *p) { return debug_rep(string(p)); }

int main(){
    int i=0;
    vector<vector<int>> v={{1,2,3},{4,5,6}};
    cout<<debug_rep(&i)<<endl;
    cout<<debug_rep(&v)<<endl;
    cout<<debug_rep(vector<string>{"1","@","#5"})<<endl;
    cout<<debug_rep(string("zxcvb"))<<endl;
cout << debug_rep("99999")<<endl;
}
