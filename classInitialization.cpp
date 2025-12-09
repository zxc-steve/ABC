#include "My.h"
class A{
    public: int i; string s; vector<int> v;
};
class B{
    public: int i; string s; vector<int> v;
    B(int i):i(i),s{"abc"},v{7,8,9}{}
};
class C{
    public: int i; string s; vector<int> v;
    C(int i,string s,vector<int>v):i(i),s{s},v{v}{}
};
ostream& operator<<(ostream& os,A& a){
    cout<<a.i<<','<<a.s<<','<<a.v<<endl;return os;}
ostream& operator<<(ostream& os,B& a){
    cout<<a.i<<','<<a.s<<','<<a.v<<endl;return os;}
ostream& operator<<(ostream& os,C& a){
    cout<<a.i<<','<<a.s<<','<<a.v<<endl;return os;}
int main() {
A a ={1,"xy",{2,3}};
  a={2,"qq",{}};    //default converting constructor and default assignment operator
//auto a1={2,"qq",{}}; //fail
  //B b ={1,"qq",{2,3}};  //fail to compile
B b1 ={2};
b1.s="--";b1={99};
C c ={1,"qq",{2,3}};
//auto d={1,"qq",{2,3}}; // fail to call constructor of C
debug(a);debug(b1);debug(c);
    return 0;
}