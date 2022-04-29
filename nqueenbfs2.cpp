#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdlib>

using namespace std;
int N,C=0;
typedef pair<int,int> position;

struct bs
{
    int *board;
    int c=-1;
};
vector <bs*> boardqueue;
bool checkpos(int j, bs *init)
{
    int i,k;
    if(init->c==-1)
    return true;
    for(i=init->c,k=1;i>=0;i--,k++)
    {
        if(init->board[i]==j || init->board[i]==(j-(k)) || init->board[i]==(j+(k)))
        return false;
    }
    return true;

}
void boardcopy(bs *init,bs*newb)
{
    int i;
    for(i=0;i<=init->c;i++)
    {
        newb->board[i]=init->board[i];
    }
    newb->c=init->c+1;
}
void getsuccessor(bs *init)
{
    int i,j;
    i=init->c+1;
    j=0;
    for(j=0;j<N;j++)
    {
        if(checkpos(j,init))
        {
            bs* newb=(bs*)malloc(sizeof(bs));
            newb->board=(int*)malloc(N*sizeof(int));
            boardcopy(init,newb);
            newb->board[newb->c]=j;
            //newb->c=newb->c+1;
            cout<<j<<endl;
            boardqueue.push_back(newb);
        }
    }
    cout<<endl;
}
int main()
{
    bs *init=(bs*)malloc(sizeof(bs));
    cout<<"Enter Queen number: ";
    cin>>N;
    init->board=(int*)malloc(N*sizeof(int));
    init->c=-1;
    boardqueue.push_back(init);
    int i=0;
    while(!boardqueue.empty())
    {
        init=boardqueue[0];
        boardqueue.erase(boardqueue.begin());
        if(init->c==(N-1))
        C++;
        else
        {
            cout<<i<<"("<<boardqueue.size()<<")"<<endl<<"--------"<<endl;
            getsuccessor(init);
            i++;
        }
        free(init);
    }
    cout<<"No. of allowed configs: "<<C<<endl;
    return 0;
}