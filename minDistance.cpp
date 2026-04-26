#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;   
class city{
public:
    string name;
    map<city*, int> distance;
    /*bool operator< (const city& other) const {
        return name < other.name;
    }*/
}; 
ostream& operator<<(ostream& os,const vector<city>& v){
    for(auto & c: v){os<<c.name<<" ";}
    return os;
}
int minDistance(const city& c1, const city& c2, int d=0, vector<city> visited={}, int minD=INT_MAX){ 
    cout<<visited<<minD<<endl;
    visited.push_back(c1);
    if(c1.name==c2.name){
        minD=min(minD,d);    
        cout<<visited<<minD<<" "<<d<<endl;
        return minD;
    }
    for(auto & p: c1.distance){
        int x=0;
        for(auto const& v: visited){
            if(p.first->name==v.name){
                x++;
            }
        }
        if(x>0) continue;
        minD=minDistance(*(p.first),c2,d+p.second,visited,minD);
    }
    visited.pop_back();
    return minD;
}
int main(){
    city c1,c2,c3,c4;
    c1.name="A";
    c2.name="B";
    c3.name="C";
    c4.name="D";
    c1.distance={{&c2,5},{&c3,10}};
    c2.distance={{&c3,3},{&c4,1},{&c1,0}};
    c3.distance={{&c2,4},{&c4,1}};
    c4.distance={{&c3,1},{&c2,1}};
    cout<<minDistance(c1,c3)<<endl; 
    cout<<"OK"<<endl;
    return 0;
}