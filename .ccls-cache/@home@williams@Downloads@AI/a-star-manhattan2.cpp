#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#define N 3
using namespace std;

typedef vector<vector<int>> board;
struct state
{
    board b;
    int cost,h;
    int i0,j0;
    void init()
    {
        b.resize(N);
        for(int i=0;i<N;i++)
        {
            b[i].resize(N);
        }
    }
};
state benchmarck;
vector<board> closed;
vector<struct state> open;
bool goaltest()
{
    return open[0].b==benchmarck.b;
}
void display(board b,int h)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<"--------"<<endl<<h<<endl<<endl;
}
int calculateh(board b)
{
    int k=1,h=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(b[i][j]!=(k%9))
                h++;
            k++;
        }
    }
    return h-1;
}
bool comparesuccessor(struct state a, struct state b)
{
    return (a.h+a.cost)<(b.h+b.cost);
}
void getsuccessor()
{
   struct state tmp;
   tmp.init();
   tmp.b=open[0].b;
   tmp.i0=open[0].i0;
   tmp.j0=open[0].j0;
   tmp.cost=open[0].cost;
   struct state tmp1;
   tmp1.init();
   tmp1.b=open[0].b;
   tmp1.i0=open[0].i0;
   tmp1.j0=open[0].j0;
   tmp1.cost=open[0].cost;
   struct state tmp2;
   tmp2.init();
   tmp2.b=open[0].b;
   tmp2.i0=open[0].i0;
   tmp2.j0=open[0].j0;
   tmp2.cost=open[0].cost;
   struct state tmp3;
   tmp3.init();
   tmp3.b=open[0].b;
   tmp3.i0=open[0].i0;
   tmp3.j0=open[0].j0;
   tmp3.cost=open[0].cost;
   if(tmp.i0!=0)//up
   {
       tmp.b[tmp.i0][tmp.j0]=tmp.b[tmp.i0-1][tmp.j0];
       tmp.b[tmp.i0-1][tmp.j0]=0;
       tmp.i0--;
       tmp.cost++;
       tmp.h=calculateh(tmp.b);
   }
   if(tmp1.i0!=2)//down
   {
       tmp1.b[tmp1.i0][tmp1.j0]=tmp1.b[tmp1.i0+1][tmp1.j0];
       tmp1.b[tmp1.i0+1][tmp1.j0]=0;
       tmp1.cost++;
       tmp1.i0++;
       tmp1.h=calculateh(tmp1.b);
   }
   if(tmp2.j0!=0)//left
   {
       tmp2.b[tmp2.i0][tmp2.j0]=tmp2.b[tmp2.i0][tmp2.j0-1];
       tmp2.b[tmp2.i0][tmp2.j0-1]=0;
       tmp2.cost++;
       tmp2.j0--;
       tmp2.h=calculateh(tmp2.b);
   }
   if(tmp3.j0!=2)//right
   {
       tmp3.b[tmp3.i0][tmp3.j0]=tmp3.b[tmp3.i0][tmp3.j0+1];
       tmp3.b[tmp3.i0][tmp3.j0+1]=0;
       tmp3.cost++;
       tmp3.j0++;
       tmp3.h=calculateh(tmp3.b);
   }
   open.push_back(tmp);
   open.push_back(tmp1);
   open.push_back(tmp2);
   open.push_back(tmp3);
   closed.push_back(open[0].b);
   open.erase(open.begin());
}
bool search()
{
    display(open[0].b,open[0].h);
    //cout<<open[0].cost+open[0].h<<endl;
    if(goaltest()) return true;
    else if(find(closed.begin(),closed.end(),open[0].b)!=closed.end()) return false;
    else
    {
        getsuccessor();
        sort(open.begin(),open.end(),comparesuccessor);
    }
    return search();
}
int main()
{
    int i,j,k=1;
    struct state stat0;
    stat0.init();
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            cin>>stat0.b[i][j];
            if(stat0.b[i][j]==0)
            {
                stat0.j0=j;
                stat0.i0=i;
            }
        }
    }
    stat0.cost=0;
    stat0.h=calculateh(stat0.b);
    open.push_back(stat0);
    benchmarck.init();
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            benchmarck.b[i][j]=k%9;
            k++;
        }
    }
    benchmarck.i0=2;
    benchmarck.j0=2;
    if(search())cout<<"Match found"<<endl;
    else
         cout<<"Match not found"<<endl;
    return 1;
}
