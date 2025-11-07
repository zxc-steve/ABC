#include <iostream>
using namespace std;
using Ret=void;
using Tp=int;
Ret f(Tp& a){cout<<"Tp& "<<a<<endl;}
Ret f(const Tp& a){cout<<"const Tp& "<<a<<endl;}
Ret f(Tp&& a){cout<<"Tp&& "<<a<<endl;}
Ret f(const Tp&& a){cout<<"const Tp&& "<<a<<endl;}

int main() {
    
    return 9;
}
