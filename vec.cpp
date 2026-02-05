#include "My.h"

class vec{
    int *data=nullptr;
    int size;
public:
    using IL=std::initializer_list<int>;
    vec(int size=0):size(size){
        data=new int[size];
        for(int i=0;i<size;i++){data[i]=9;}
    }
    vec(const  IL &il):size(il.size()),data(new int[il.size()]){
        copy(il.begin(),il.end(),data);
    }
    vec(const vec& v){
        size=v.size;
        data=new int[size];
        for(int i=0;i<size;i++){
            data[i]=v.data[i];
        }
        cout<<"copy ";debug(size);

    }
    vec(vec && v)noexcept:data(v.data),size(v.size){
        v.data=nullptr;
        v.size=0;
        cout<<"move\n";
    }

    ~vec(){
        cout<<"size="<<size<<",";
        debug(*this);
        if(!data) delete [] data;
    }
    vec& pushBack(int add){
        int newSize=size+1;
        int *newdata;
        newdata=new int[newSize];
        for(int i=0;i<size;i++){
            newdata[i]=data[i];
        }
        newdata[size]=add;
        delete [] data;
        data=newdata;
        size=newSize;
        return *this;
    }
    int& operator[](const int index){
        return data[index];
    }
    const int& operator[](const int index) const{
        return data[index];
    }
    vec operator+(const vec& other){
        vec v(size+other.size);
        for(int i=0;i<size;i++){
            v.data[i]=data[i];
        }
        for(int i=0;i<other.size;i++){
            v.data[i+size]=other.data[i];
        }
        return v;
    }
    vec& operator=(const vec& other){
        size=other.size;
        delete [] data;
        data=new int[size];
        for(int i=0;i<size;i++){
            data[i]=other.data[i];
        }
        return *this;
    }
    friend ostream& operator<<(ostream& output,const vec& other){
        for(int i=0;i<other.size;i++){
            output<<other.data[i]<<" ";
        }
        return output;
    }
};
void test_vec(){
    vec v(3); //v1{v};
    vec v1(v.pushBack(99));
    v[2]=1;
    vec v2((v+v1));
    //vec v2(v+v1);
    //v2.pushBack(2);
    debug(v+v1);
    v[3]=0;v=v2+v;
    //v4=v+v3;
    //cout<<v<<endl<<v1<<endl<<v.pushBack(77)<<endl;
}
void test_move(vec v){
    debug(v);
}
using IL1=vector<int>::iterator;
int main(){
    int* b=new int[4]{4,3,4,6};
    auto a={1,2,3};
    vec::IL x={4,5,6,7};
    const vec v{a};cout<<v[0];
    //cout<<(vec{4,5,6}[0])<<endl;
    //test_vec();
    //test_move(vec(1)+vec(2));
    vector<vec> vv;
    vv.push_back(vec(1));cout<<"--------\n";
    vv.push_back(vec(2));cout<<"--------\n";
    vv.push_back(vec(3));cout<<"--------\n";
    //debug(vv[0]);
    //debug(vv[1]);
    //debug(vv[2]);
    string s=u8"中文";
    cout<<s<<":";debug(s.size());debug(sizeof(s));
    s=string(u8"中文文字大小");
    cout<<s<<":";debug(s.size());debug(sizeof(s));
    for(auto& c:s){
        cout<<c<<endl;
    }
}