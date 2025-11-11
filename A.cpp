#include <iostream>
#include <string>
using namespace std;
using Ret=void;
using Tp= int;
Ret f(Tp& a){cout<<"Tp& "<<a<<endl;}
Ret f(const Tp& a){cout<<"const Tp& "<<a<<endl;}
Ret f(Tp&& a){cout<<"Tp&& "<<++a<<endl;}
Ret f(const Tp&& a){cout<<"const Tp&& "<<a<<endl;}
template <typename T> Ret f1(const T& a){f(a);cout<<" ----const T&"<<endl;}
template <typename T> Ret f1(T& a){f(a);cout<<" ----T&"<<endl;}
template <typename T> Ret f1( T&& a){f(a); cout<<" ----T&&"<<endl;}
const int g(){return 99;}
int main() {
    int i=2,&r1=i;
    const int  j=i++,&r2=j;
    const int &&r=g();
    //f("zxcab");cout<<"---------------"<<endl;
    //f(&i);f(&j);f(std::move(&i));cout<<&i<<endl;
    f(i);f(j);f(r);f(std::move(i));
    //f1(i);f1(j);f1(2+r2);f1(std::move(i));
    return 9;
}

