#include<iostream>
#include <utility>
#include <vector>
#include <stack>
#include <unistd.h>
//#define N 15
using namespace std;
typedef pair<int,int> position;
stack <position> postack;
position queen;
int N;
int *board;
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
    cout<<"Enter N: ";
    cin>>N;
    board=(int*)malloc(N*sizeof(int));
    while(true)
    {
        queen.first=i;
        queen.second=j;
        if(checkpos(queen) && j<N)
        {
            
            postack.push(queen);
            board[i]=j;
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
    cout<<"Total config: "<<c<<endl;
    return 0;
}