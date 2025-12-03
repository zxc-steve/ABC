#include <string>
#include <iostream> 
#include <vector>
using namespace std; 
class Base{ //Class with Pure Virtuals Are Abstract Base Class
    public:
    virtual void print()=0;
};   
class X{
    public:
    int x;
    string s;
    virtual void print()  {cout << "X: " << x << ", " << s << endl;}
    X()=default;
    //X(): x(0), s("") {}
    X(int x, string s): x(x), s(s) {}   
};
class Y: public X{
    public:
    int y;
    string s;
    void print() override {cout << "Y: " << y << ", " << s << endl;}
    Y(int y, string s): y(y), s(s) {} 
    Y():X(0,""), y(0), s("") {} ; 
};
class Z: public Y{
    public:
    int z;
    string s;
    void print() override { cout << "Z: " << z << ", " << s << endl;}   
    Z(int z, string s): Y(z, s), z(z), s(s) {}  
    Z():Z(1,"default") {} ;
};
class Container{
    public:
    vector<Base*> contents; 
    void add(Base* b) {contents.push_back(b);}
};
void f(char s[]){
    while(*s!=0){
    cout << "f(char*): " << *s++ << endl;
    }
}
int main() {
    
    //f((char*)"Hello World");
    X x{10, string("Hello from X")};
    Y y{20, "Hello from Y"};
    Z z(30, "Hello from Z");
    Z a;    
    X* ptr = &x;    ptr->print();
    ptr = &y;       ptr->print();
    ptr = &z;       ptr->print();

    vector<X*> contents={&x, &y, &z}; 
    for(auto b: contents){
        b->print();
    }
    return 0;
}
/*
1.Add no virtual function with the same name
2.Add virtual function with the same name but different signature
3.Add virtual function with the same name and same signature
4.Add operator+() overload, return lvalue reference
5.Add operator+() overload, return by value
6. Add virtual destructor to each class

*/