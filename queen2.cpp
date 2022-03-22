#include<iostream>
#include <utility>
using namespace std;
int board[4];
bool checkpos(pair<int,int> q)
{
    int i,j,k;
    j=q.second;
    k=q.first;
    if(k==0)
    return true;
    for(i=q.first-1,k=1;i>=0;i--,k++)
    {
        if(board[i]==j || board[i]==(j-(k)) || board[i]==(j+(k)))
        return false;
    }
    return true;

}
int main()
{
    pair<int,int> queen;
    board[0]=1;
    board[1]=3;
    board[2]=0;
    queen.first=3;
    queen.second=2;
    cout<<checkpos(queen)<<endl;

    return 0;
}