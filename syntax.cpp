#include "My.h" 
#include <iomanip>
#include <list>   
#include <forward_list>
#include <chrono>
#include <thread>
#include <fstream>
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
template<class T> T f1(T&a){cout<<"T&a ";           return a;}
template<class T> T f1(const T&a){cout<<"const T&a ";return a;}
template<class T> T f1(T&&a){cout<<"T&&a ";          return a;}
void test_literal_ref(){
    int i=9;
    const int ci=7;
    debug(f1(i));debug(f1(i+1));debug(f1(8));debug(f1(ci));
    debug(f1(static_cast<const int&>(i)));
    debug(f1(static_cast<const int&>(3)));
}
int test_ivvalid_iterator() {
    std::string str1 = "Hello";
    std::string str2 = "World";

    const char* ptr = str1.c_str(); // Points to str1's buffer
    //const char* ptr = str1.data();//.c_str(); // Points to str1's buffer
    std::cout << "Before swap: ptr points to " << ptr << "\n";

    //std::swap(str1, str2);
    str1.swap(str2);

    std::cout << "After swap: ptr still points to " << ptr << "\n";
    std::cout << "str1 is now: " << str1 << ", str2 is: " << str2 << "\n";

    // Modify str2 (which now owns the old buffer of str1)
    str2 += "!!!aaaaaaaaaaaaaaaaaaaaaaaaaa"; // This may trigger reallocation

    std::cout << "After modifying str2: ptr points to " << ptr << "\n";
    std::cout << "str2 is now: " << str2 << "\n sizeof str2: " << str2.size() << "\n    ";

    return 0;
}
void test_container() {
    vector<int> v = {1, 2, 3, 4, 5,6,7,8,9,10};
    auto iter = v.begin();
    while (iter != v.end()) {
        if (*iter % 2 == 0) {
            iter = v.erase(iter); // erase returns the next iterator
        } else {
            //iter=v.insert(iter, *iter++ * 10);
            iter=v.insert(iter, *iter * 10); // insert before the next position
            //iter += 2; // move past the newly inserted element and the original one
            iter++;iter++;
        }
    }
    for(const auto& x:v) cout<<x<<" "; 
    cout<<endl;
}
void test_container1() {
    forward_list<int> v = {1, 2, 3, 4, 5,6,7,8,9,10};
    auto prev = v.before_begin();
    auto iter = v.begin();
    while (iter != v.end()) {
        if (*iter % 2 == 0) {
            iter = v.erase_after(prev); // erase returns the next iterator
        } else {
            prev=v.insert_after(prev, *iter * 10); // insert before the next position
            //iter += 2; // move past the newly inserted element and the original one
            iter++;prev++;
        }
    }
    for(const auto& x:v) cout<<x<<" "; 
    cout<<endl;
}
void test_container_capacity() {
        vector<int> v2;
    for(int i=0;i<20;i++) {
        v2.push_back(i);
        cout<<i<<" "<<" "<<v2.size()<<", "<<v2.capacity()<<", "<<&v2[0]<<endl;
    }   
}
enum class cap { title, middle, end };
void print(const char* text, double num, cap c)
{
    if (c == cap::title)
        std::cout <<
            "┌──────────┬────────────┬──────────────────────────┐\n"
            "│  number  │   iomanip  │      representation      │\n"
            "├──────────┼────────────┼──────────────────────────┤\n";
    std::cout << std::left
         << "│ " << std::setw(8) << text <<      " │ fixed      │ "
         << std::setw(24) << std::fixed  << num <<            " │\n"
         << "│ " << std::setw(8) << text <<      " │ scientific │ "
         << std::setw(24) << std::scientific << num <<        " │\n"
         << "│ " << std::setw(8) << text <<      " │ hexfloat   │ "
         << std::setw(24) << std::hexfloat << num <<          " │\n"
         << "│ " << std::setw(8) << text <<      " │ default    │ "
         << std::setw(24) << std::defaultfloat << num <<      " │\n";
    std::cout << (c != cap::end ?
            "├──────────┼────────────┼──────────────────────────┤\n" :
            "└──────────┴────────────┴──────────────────────────┘\n");
}
void test_setf() {
    cout.precision(2);
    print("0.0", 0.0, cap::title);
    print("0.01", 0.01, cap::middle);
    print("0.00001", 1, cap::end);

    debug(cout.setf(ios::showpoint));
    print("0.0", 0.0, cap::title);
    print("0.01", 0.01, cap::middle);
    print("0.00001", 1, cap::end);
    debug(cout.setf(ios::fmtflags(0), ios::floatfield));
    print("0.0", 0.0, cap::title);
    print("0.01", 0.01, cap::middle);
    print("0.00001", 1, cap::end);

    double d=1.00/5;
    cout.precision(2);
    cout.setf(ios::fixed);
    cout<<1<<","<<1.1<<","<<1.0/5<<",d:"<<d<<endl;
    cout.setf(ios::fixed, ios::floatfield);
    cout << 3.1415926 << endl;
    cout.setf(ios::scientific, ios::floatfield);
    cout << 3.1415926 << endl;
    //cout.setf(1L<<4, ios::floatfield);
    cout.setf(ios::fmtflags(0), ios::floatfield);
    cout << 3.1415926 << endl;

}
enum Color { RED, GREEN, BLUE };
bool test_enumerate_para(Color c){return c == RED;}
void test_enumerate(){
    Color color = RED; // =RED+1 fail
    //debug(test_enumerate_para(color+1)); fail
    debug(test_enumerate_para(color));
    switch (color+1) {  //color+1: promoted to int
        case RED:       // RED: promoted to int 0
            std::cout << "Color is RED\n";
            break;
        case GREEN:
            std::cout << "Color is GREEN\n";
            break;
        case BLUE:
            std::cout << "Color is BLUE\n";
            break;
        default:
            std::cout << "Unknown Color\n";
            break;
    }
}
void test_stream(){
    //std::cin.tie(nullptr);
    cout << "Sleeping for 2 seconds..." ;
    std::this_thread::sleep_for(std::chrono::seconds(10));
    cout << "Resumed." << endl;
    /////////////
    //std::cin.tie(nullptr);
    // Also consider disabling synchronization with C standard streams
    //std::ios_base::sync_with_stdio(false); 

    std::cout << "This prompt might not appear before input if streams are untied and buffering is enabled.\n";
    int x;
    std::cin >> x;
    std::cout << "Entered Number: " << x;
    std::this_thread::sleep_for(std::chrono::seconds(2));

}
void test_io_manip() {
/*int i = -16;
double d = 3.14159;

// pad the first column to use a minimum of 12 positions in the output 
cout << "i: " << setw(12) << i << "next col" << '\n'
<< "d: " << setw(12) << d << "next col" << '\n'; // pad the first column and left-justify all columns 
cout << left
<< "i: " << setw(12) << i << "next col" << '\n'
<< "d: " << setw(12) << d << "next col" << '\n'
<< right; // restore normal justification

// pad the first column and right-justify all columns 
cout << right
<< "i: " << setw(12) << i << "next col" << '\n'
<< "d: " << setw(12) << d << "next col" << '\n'; // pad the first column but put the padding internal to the field 
cout << internal
<< "i: " << setw(12) << i << "next col" << '\n'
<< "d: " << setw(12) << d << "next col" << '\n'; // pad the first column, using # as the pad character 
cout << setfill('#')
<< "i: " << setw(12) << i << "next col" << '\n' << "d: " << setw(12) << d << "next col" << '\n' << setfill(' ');
*/
    char ch;
    cin>>unitbuf;cout<<unitbuf;
    while (cin.get(ch)) cout.put(ch);
    //cin >> noskipws; 
    //while (cin >> ch) cout<<ch;
    //cin >> skipws;
}
void test_fstreams() {
    fstream inOut("copyOut", fstream::ate | fstream::in| fstream::out);
    if (!inOut) {cerr << "Error opening file!" << endl;return;}

    auto end_mark = inOut.tellg();// remember original end-of-file position 
    inOut.seekg(0, fstream::beg); // reposition to the start of the file 
    size_t cnt = 0; // accumulator for the byte count 
    string line; // hold each line of input // while we haven't hit an error and are still reading the original data 
    while (inOut && inOut.tellg() != end_mark && getline(inOut, line)) { // and can get another line of input 
        cnt += line.size() + 1; // add 1 to account for the newline 
        auto mark = inOut.tellg(); // remember the read position 
        //inOut << cnt;   // test overwrite
        inOut.seekp(0, fstream::end); // set the write marker to the end 
        inOut << cnt; // write the accumulated length // print a separator if this is not the last line 
        if (mark != end_mark) inOut << " "; 
        inOut.seekg(mark); // restore the read position
    } 
    inOut.seekp(0, fstream::end); 
    inOut << "\n";
}
void test_fstreams_app() {  // app mode is simpler than ate mode
    system("cp copyOut.1 copyOut");
    system("cat copyOut");
    fstream inOut("copyOut", fstream::app | fstream::in| fstream::out);
    if (!inOut) {cerr << "Error opening file!" << endl;return;}
    inOut.seekg(0, fstream::end);  //app not at end when opened
    auto end_mark = inOut.tellg();// remember original end-of-file position 
    inOut.seekg(0, fstream::beg); // reposition to the start of the file 
    size_t cnt = 0; // accumulator for the byte count 
    string line; // hold each line of input // while we haven't hit an error and are still reading the original data 
    while (inOut && getline(inOut, line)) { // and can get another line of input 
        cnt += line.size() + 1; // add 1 to account for the newline 
        auto mark = inOut.tellg(); // remember the read position 
        //inOut.seekp(0, fstream::end); // set the write marker to the end 
        inOut << cnt; // write the accumulated length // print a separator if this is not the last line 
        if (mark == end_mark) break;
        inOut << " "; inOut.seekg(mark); // restore the read position
    } 
    //inOut.seekp(0, fstream::end); 
    inOut << "\n";
    inOut.close();
    system("cat copyOut");
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
    //test_literal_ref();
    //test_ivvalid_iterator();
    //test_container();
    //test_container1();
    //test_container_capacity();
    //test_setf();
    //test_enumerate();
    //test_stream();
    //test_io_manip();
    test_fstreams_app();
    return 0;
}