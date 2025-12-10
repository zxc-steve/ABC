#include "My.h"    
#include <chrono>
void test_chrono() {    
    using namespace std::chrono;
    //using namespace std::chrono_literals::chrono_literals;
    //cout << "birthday: " << November/28/2021 << '\n';b
    }   
////////// back_insert_iterator input //////////
template<typename T>
std::istream& operator>>(std::istream& is, std::back_insert_iterator<std::vector<T>> &obj) {
    T tmp; is >> tmp;  *obj = tmp;   return is;  }
void test_iterator() {    
    vector<int> v;
    auto it = back_inserter(v);
    while(cin>>it);
    cout << v << endl;
}
void test_pointer() {
    int a = 7,ary[2],b,c;
    int* p1 = &a,*p2 = ary,*p3 = &b,*p4 = &c;
    debug(p1); debug(p2); debug(p3); debug(p4);
    debug(p1 - p2);debug(p3 - p2);debug(p4 - p3);
    vector<int> v1={1,2,3,4,5},v2={10,20,30,40,50};
    int* pv1 = &v1[0],*pv2 = &v1[1],*pv3 = &v2[0],*pv4 = &v2[1];
    debug(pv1); debug(pv2); debug(pv3); debug(pv4);
    debug(pv2 - pv1); debug(pv4 - pv1);debug(pv4 - p3);
}
void f1(int&a){cout<<"int&a ";debug(a);}
void f1(const int&a){cout<<"const int&a ";debug(a);}
void f1(int&&a){cout<<"int&&a ";debug(a);}
void test_literal_ref(){
    int i=9;
    const int ci=7;
    f1(i);f1(i+1);f1(8);debugFunc(f1(ci));
    f1(static_cast<const int&>(i));
    debugFunc(f1(static_cast<const int&>(3)));
}
int main() {
    /*string a,b,*ap=&a,*bp=&b,*cp=new string("abc");
    auto q=bp+(ap-bp)/2;
    debug(ap);
    debug(bp);
    debug(ap<bp);debug(ap<cp)
    debug(&a-&b);*/
    //test_iterator();
    //test_pointer();
    test_literal_ref();
    return 0;
}