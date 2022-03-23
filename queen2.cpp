#include<iostream>
#include <utility>
#include <vector>
#include <queue>
#include <unistd.h>
#define N 4
using namespace std;
typedef pair<int,int> position;
int init=0;
position queen;
struct bd
{
    int board[N];
    int sel=0;
};
queue <struct bd> posque;
bool checkpos(position q)
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
    int i=0,j=0,k=0,c=0;
    while(true)
    {
        queen.first=i;
        queen.second=j;
        if(checkpos(queen) && j<N && i<N)
        {
            if(queen.first==N-1)
            c++;
            else
            posque.push(queen);
            j++;
        }
        else if(j>=N)
        {
            queen=posque.front();
            posque.pop();
            board[queen.first]=queen.second;
            i=queen.first+1;
            j=0;
        }
        if(posque.empty())
        break;

    }
    cout<<"Total config: "<<c<<endl;
    return 0;
}