#include<iostream>
#include <utility>
#include <vector>
#include <stack>
#include <unistd.h>
#define N 15
using namespace std;

typedef pair<int,int> position;
//position queens[N];
int init=0;
//vector<position> postack;
stack <position> postack;
position queen;
int board[N];
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
        if(checkpos(queen) && j<N)
        {
            
            postack.push(queen);
            board[i]=j;
            for(k=0;k<=i;k++) cout<<board[k]<<" , ";
            cout<<endl;
            //usleep(1000000);
            i++;
            j=0;
            if(i>=N)
            {
                c++;
                j=(postack.top().second)+1;
                i--;
                queen=(postack.top());
                postack.pop();
            }
        }
        else
        {
            j++;
            if(j>=N)
            {
                if(!postack.empty())
                {
                    j=postack.top().second+1;
                    i=postack.top().first;
                    postack.pop();
                }
                else break;
            }
        }
    }
    /*while(board[0]<N)
    {
        queen.first=i;
        queen.second=j;
        if(checkpos(queen))
        {
            postack.push(queen);
            board[i]=j;
            i++;
            j=0;
            if(postack.size())
            {
                c++;
                queen=postack[tos];
                postack.pop_back();
                tos--;
                i--;
                j=(queen.second)+1;
            }

        }
        else
        {
            j++;
            if(j>=N)
            {
                if(postack.empty())
                board[0]++;
                else {
                queen=postack[tos];
                postack.pop_back();
                tos--;
                i--;
                j=(queen.second)+1;
                }
            }
        }
    }*/
    cout<<"Total config: "<<c<<endl;
    return 0;
}