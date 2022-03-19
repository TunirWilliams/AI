#include<iostream>
#include <utility>
#include <vector>
#define N 4
using namespace std;

typedef pair<int,int> position;
//position queens[N];
int tos=0;
bool emp=false;
vector<position> postack;

position queen;
int board[N];
bool checkpos(position q);
int main()
{
    int i=1,j=0,c=0;
    board[0]=0;
    while(board[0]<N)
    {
        queen.first=i;
        queen.second=j;
        if(checkpos(queen))
        {
            postack.push_back(queen);
            board[i]=j;
            tos++;
            i++;
            if(i==N) c++;
            j=0;

        }
        else
        {
            j++;
            if(j>=N)
            {
                queen=postack[tos];
                postack.pop_back();
                tos--;
                if(tos==0)
                board[0]++;
                i--;
                j=(queen.second)+1;
                
            }
        }
    }
    cout<<"Total config: "<<c<<endl;
    return 0;
}