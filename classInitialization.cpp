#include <iostream>
#include <vector>
using namespace std;
#define debug(x) cout<<#x<<"="<<x<<endl;
class A{
    public: int i; string s; vector<int> v;
};
class B{
    public: int i; string s; vector<int> v;
    B(int i):i(i),s{"abc"},v{7,8,9}{}
};
ostream& operator<<(ostream& os,A& a){
    cout<<a.i<<','<<a.s<<','<<a.v[0]<<endl;return os;}
ostream& operator<<(ostream& os,B& a){
    cout<<a.i<<','<<a.s<<','<<a.v[0]<<endl;return os;}
int main() {
A a ={1,"qq",{2,3}};
//B b ={1,"qq",{2,3}}; fail to compile
B b1 ={2};
debug(a);debug(b1);
    return 0;
}