#include<iostream>
#include <utility>
#include <vector>
#define N 4
using namespace std;

typedef pair<int,int> position;
//position queens[N];
int tos;
bool emp=false;
vector<position> postack;

position queen;
int board[N];
int main()
{
    int i=1,j=0,k;
    board[0]=0;
    while(board[0]<N)
    {
        queen.first=i;
        queen.second=j;
        if(checkpos(queen))
        {
            postack.push_back(queen);
            board[i]=j;
            i++;
            j=0;

        }
        else
        {
            j++;
            if(j>=N)
            {
                queen=postack[tos];
                postack.pop_back();
                i--;
                j=(queen.second)+1;
                
            }
        }
    }
    return 0;
}