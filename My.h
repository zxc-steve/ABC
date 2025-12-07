#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define debug(x) cout<<#x<<"="<<(x)<<endl;
template<typename T>
ostream& operator<<(ostream& os, vector<T>& obj) { 
    for ( const auto& x : obj) os << x << " "; return os; }
template<typename T, typename U>
ostream& operator<<(ostream& os, map<T,U>& obj) { 
    for ( const auto& [k, v] : obj) os << k << ":" << v << " "; return os; }

