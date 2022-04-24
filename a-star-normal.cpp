#include<iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
#define N 3
using namespace std;
struct board
{
    int arr[N][N];
    int h=0,c=0,i,j;
};
vector <board*> boardlist;
void arraycpy(int a[N][N],int b[N][N])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            a[i][j]=b[i][j];
        }
    }
}
void inputarr(board *b)
{
    cout<<"Enter array: "<<endl;
    for(int i=0;i<N;i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout<<"("<<i<<","<<j<<"): ";
            cin>>b->arr[i][j];
            if(b->arr[i][j]==0)
            {
                b->i=i;
                b->j=j;
            }
        }
    }
}
bool compr(board *a,board *b)
{
    return (a->h+a->c)<(b->h+b->c);
}
void check(board* a)
{
    int i,j;
    //up
    if(a->i!=N-1)
    {
        board *b=(board*)malloc(sizeof(board));
        arraycpy(b->arr,a->arr);
        b->arr[b->i][b->j]=b->arr[b->i+1][b->j];
        b->arr[b->i+1][b->j]=0;
        boardlist.push_back(b);
    }
    //down
    if(a->i!=0)
    {
        board *b=(board*)malloc(sizeof(board));
        arraycpy(b->arr,a->arr);
        b->arr[b->i][b->j]=b->arr[b->i-1][b->j];
        b->arr[b->i-1][b->j]=0;
        boardlist.push_back(b);
    }
    //left
    if(a->j!=N-1)
    {
         board *b=(board*)malloc(sizeof(board));
        arraycpy(b->arr,a->arr);
        b->arr[b->i][b->j]=b->arr[b->i][b->j+1];
        b->arr[b->i][b->j+1]=0;
        boardlist.push_back(b);
    }
    //right
    if(a->j!=0)
    {
         board *b=(board*)malloc(sizeof(board));
        arraycpy(b->arr,a->arr);
        b->arr[b->i][b->j]=b->arr[b->i][b->j-1];
        b->arr[b->i][b->j-1]=0;
        boardlist.push_back(b);
    }
    //sort
    sort(boardlist.begin(),boardlist.end(),compr);
}
int calculateh(int a[N][N])
{
    int i,j,k=1,h=0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(a[i][j]!=k)
            {
                h++;
            }
            k++;
        }
    }
    return h;
}
int main()
{
    int h,i,j;
    board *init;
    init=(board*)malloc(sizeof(board));
    inputarr(init);
    init->h=calculateh(init->arr);
    init->c=0;
    boardlist.push_back(init);
    while(!boardlist.empty())
    {
        init=boardlist.front();
        boardlist.erase(boardlist.begin());
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                cout<<init->arr[i][j]<<" ";
            }
            cout<<endl;
        }
        if(init->h==0) break;//goaltest
        check(init);
        free(init);
    }
    /*for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        cout<<init->arr[i][j]<<" ";
        cout<<endl;
    }*/
    return 0;
}