#include <string>
#include <iostream> 
#include <vector>
using namespace std; 
class Base{
    public:
    virtual void print()=0;
};   
class X: public Base{
    public:
    int x;
    string s;
    void print() override {cout << "X: " << x << ", " << s << endl;}
    X()=default;
    X(int x, string s): x(x), s(s) {}   
};
class Y: public X{
    public:
    int y;
    string s;
    void print() override {cout << "Y: " << y << ", " << s << endl;}
    Y(int y, string s): y(y), s(s) {}  
};
class Z: public Y{
    public:
    int z;
    string s;
    void print() override { cout << "Z: " << z << ", " << s << endl;}   
    Z(int z, string s): Y(z, s), z(z), s(s) {}  
};
class Container{
    public:
    vector<Base*> contents; 
    void add(Base* b) {contents.push_back(b);
    }
};
int main() {
    X x{10, string("Hello from X")};
    Y y{20, "Hello from Y"};
    Z z(30, "Hello from Z");    
    Base* ptr = &x;ptr->print();
    ptr = &y;ptr->print();
    ptr = &z;ptr->print();

    vector<Base*> contents={&x, &y, &z}; 
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
*/