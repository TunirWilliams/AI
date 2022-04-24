#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#define N 3
using namespace std;
struct board
{
    int board[N][N];
    int i,j,h=0,c=0;
};
int goal[N][N];
vector <board*> boardlist;
void inputarray(board *a)
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for (j = 0; j < N; j++)
        {
            cout<<"("<<i<<","<<j<<"): ";
            cin>>a->board[i][j];
            cout<<endl;
            if(a->board[i][j]==0)
            {
                a->i=i;
                a->j=j;
            }
        }
        
    }
}
void sort()
{
    int i,j,min;
    board *tmp;
    for(i=0;i<boardlist.size();i++)
    {
        min=i;
        for(j=i+1;j<boardlist.size();j++)
        {
            if((boardlist[i]->c+boardlist[i]->h)>boardlist[j]->c+boardlist[j]->h)
            {
                min=j;
            }
        }
        if(min!=i)
        {
            tmp=boardlist[i];
            boardlist[i]=boardlist[min];
            boardlist[min]=tmp;
        }
    }
}
void displayarray(board *a)
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for (j = 0; j < N; j++)
        {
            cout<<a->board[i][j];
        }
        cout<<endl;
    }
}
int calculateh(board *a)
{
    int i,j,k=1,h=0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(a->board[i][j]!=goal[i][j])
            {
                h++;
            }
            k++;
        }
    }
    return h;
}
void arraycpy(board *a,board *b)
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            a->board[i][j]=b->board[i][j];
        }
    }
}
bool compa(board *a,board *b)
{
    return (a->h+a->c)<(b->h+b->c);
}
void check(board *a)
{
    //down
    if(a->i!=0)
    {
        board *b=(board*)malloc(sizeof(board));
        arraycpy(b,a);
        b->j=a->j;
        b->i=a->i;
        b->c=a->c+1;
        b->board[b->i][b->j]=b->board[b->i-1][b->j];
        b->board[b->i-1][b->j]=0;
        b->i=b->i+1;
        b->h=calculateh(b);
        boardlist.push_back(b);
    }
    //up
    if(a->i!=N-1)
    {
        board *c=(board*)malloc(sizeof(board));
        arraycpy(c,a);
        c->j=a->j;
        c->i=a->i;
        c->c=a->c+1;
        c->board[c->i][c->j]=c->board[c->i+1][c->j];
        c->board[c->i+1][c->j]=0;
        c->i=c->i+1;
        c->h=calculateh(c);
        boardlist.push_back(c);
    }
    //left
    if(a->j!=N-1)
    {    
        board *d=(board*)malloc(sizeof(board));
        arraycpy(d,a);
        d->j=a->j;
        d->i=a->i;
        d->c=a->c+1;
        d->board[d->i][d->j]=d->board[d->i][d->j+1];
        d->board[d->i][d->j+1]=0;
        d->j=d->j+1;
        d->h=calculateh(d);
        boardlist.push_back(d);
    }
    //right
    if(a->j!=0)
    {
        board *e=(board*)malloc(sizeof(board));
        arraycpy(e,a);
        e->j=a->j;
        e->i=a->i;
        e->c=a->c+1;
        e->board[e->i][e->j]=e->board[e->i][e->j-1];
        e->board[e->i][e->j-1]=0;
        e->j=e->j-1;
        e->h=calculateh(e);
        boardlist.push_back(e);
    }
    sort(boardlist.begin(),boardlist.end(),compa);
}
int main()
{
    board *init=(board*)malloc(sizeof(board));
    inputarray(init);
    int i,j,k=1;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            goal[i][j]=k%9;
            k++;
        }
    }
    init->c=0;
    init->h=calculateh(init);
    boardlist.push_back(init);
    while(!boardlist.empty())
    {
        init=boardlist[0];
        boardlist.erase(boardlist.begin());
        displayarray(init);
        cout<<endl;
        cout<<endl;
        if(init->h==0)
        {
            break;
        }
        check(init);
        free(init);
    }
    return 0;
}