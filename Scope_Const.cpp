#include <iostream> 
using namespace std;
#define debug(x) cout<<#x<<"="<<x<<endl;    
int x=11;
struct Scope{
    int x;
    Scope(int x):x(x){}
    void f(int x){
        debug(x);
        debug(this->x);
        debug(::x);
        debug(Scope::x)
    }
};
int testScope() {
    Scope s{22};
    s.f(33);
    cout << s.Scope::x<< endl;
    return 0;
}
class Const{
    public:
    const Const& f()const{
        cout << "Inside const member function f()" << endl;  return *this;
    }
    Const& f(){
        cout << "Inside nonconst member function f()" << endl; return *this;
    }
    void f1() const {
        //x = 10; // error: cannot modify member in const function
        cout << "Inside const member function f1()" << endl;
    }
    void f1() {
        x = 20; // allowed: non-const member function can modify member
        cout << "Inside non-const member function f2()" << endl;
    }
    private:
    int x = 0;
};
void testConst() {
    Const c;
    const Const cc;
    //c.f().f2();   // Calls non-const version
    c.f().f1();   // Calls non-const version
    cc.f().f1(); // Calls const version
    //cc.f().f2(); // Calls const version
}
int main() {
    testScope();
    testConst();
    return 0;
};