#include<iostream>
#include <utility>
#include <vector>
#include <queue>
#include <unistd.h>
#define N 8
using namespace std;
typedef pair<int,int> position;
position queen;
struct bd
{
    int board[N];
};
queue <struct bd> posque;
bool checkpos(position q,int brd[N])
{
    int i,j,k;
    j=q.second;
    k=q.first;
    if(k==0)
    return true;
    for(i=q.first-1,k=1;i>=0;i--,k++)
    {
        if(brd[i]==j || brd[i]==(j-(k)) || brd[i]==(j+(k)))
        return false;
    }
    return true;

}
int addon(int i)
{
    int j,c=0;
    struct bd a;
    struct bd *b;
    if(!posque.empty())
    {
        a=(posque.front());
        posque.pop();
    }
    /*else
    {
        a=(struct bd*)malloc(sizeof(struct bd*));

    }*/
    position q;
    q.first=i;
    for(j=0;j<N;j++)
    {
        q.second=j;
        if(checkpos(q,a.board))
        {
            b=(struct bd*)malloc(sizeof(struct bd));
            copy(begin(a.board),end(a.board),b->board);
            b->board[i]=j;
            posque.push(*b);
            if(i==(N-1)) c++;
        }
    }
    return c;
}

int main()
{
    int c=0,i;
    struct bd a;
    for(i=0;i<N;i++)
    {
        a.board[0]=i;
        posque.push(a);
    }
    for(i=1;i<N;i++)
    {
        c=addon(i);
    }
    cout<<"Total config: "<<c<<endl;
    return 0;
}