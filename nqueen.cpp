#include<iostream>
#include <utility>
#include <vector>
#include <stack>
#define N 4
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
    for(i=q.first-1;i>=0;i--)
    {
        if(board[i]==j || board[i]==(j-(k-i)) || board[i]==(j+(k-i)))
        return false;
    }
    return true;

}
int main()
{
    int i=0,j=0,c=0;
    board[0]=0;
    while(board[0]<N)
    {
        queen.first=i;
        queen.second=j;
        if(checkpos(queen))
        {
            postack.push(queen);
            board[i]=j;
            i++;
            j=0;
            if(postack.size()==N)
            {
                c++;
                j=(postack.top().second)+1;
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
                    postack.pop();
                    i--;
                }
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