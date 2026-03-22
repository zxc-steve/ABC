#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include <iomanip>

using namespace std;
struct Chess;

struct Chess{
const static int SZ = 5;
    int board[SZ][SZ]{{0}};
    int solutionCnt = 0;    
    int steps[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
    bool move(int x,int y,int cnt=1);
    void moveNew(int x,int y,int cnt=1);
};  
ostream& operator<<(ostream & os,const Chess& c){
    //os<<"cnt="<<c.cnt<<endl;
    for(int i=0;i<c.SZ;i++){
        for(int j=0;j<c.SZ;j++) os<<std::setw(3)<<c.board[i][j]<<' ';
        os<<endl;
    }
    return os;
};
bool Chess::move(int x,int y,int cnt){
        if(x<0||x>=SZ||y<0||y>=SZ||board[x][y]) return false;
        board[x][y] = cnt;
        //cout<<"cnt="<<cnt<<endl<<*this<<endl;
        if(cnt==SZ*SZ) {cout<<"Solution found:"<<++solutionCnt<<endl; cout<<*this;}
        else for(int i=0;i<8;i++) move(x+steps[i][0],y+steps[i][1],cnt+1);
        board[x][y] = 0; // Backtrack
        return true;
    }
void Chess::moveNew(int x,int y,int cnt){   //Simple architecture
        if(x<0||x>=SZ||y<0||y>=SZ||board[x][y]) return;
        if(cnt==SZ*SZ) {cout<<"Solution found:"<<++solutionCnt<<endl; cout<<*this; return;}   
        board[x][y] = cnt;
        //cout<<"cnt="<<cnt<<endl<<*this<<endl;
        for(int i=0;i<8;i++) moveNew(x+steps[i][0],y+steps[i][1],cnt+1);
        board[x][y] = 0; // Backtrack
        return;
    }
int main(){
    Chess c;
    int x,y;
    cout<<"Enter starting position (x y): ";
    cin>>x>>y;
    c.moveNew(x,y);    cout<<c;
    //c.move(1,2);    cout<<c;
}