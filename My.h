#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define debug(x) cout<<#x<<"="<<(x)<<endl;
template<typename T>
ostream& operator<<(ostream& os, vector<T>& obj) { 
    for (auto& x : obj) os << x << " "; return os; }

