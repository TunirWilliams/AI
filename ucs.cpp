#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
struct node
{
    int label;
    int cost;
};
int start=0,goal=6;
vector <node> que;
vector<node> adjlist[7];
int visited[7];
bool compareNodes(node a,node b)
{
    return (a.cost<b.cost);
}
void getSuccessor(node a, int price_now)
{
    vector <node>::iterator itr;
    for(itr=adjlist[a.label].begin();itr!=adjlist[a.label].end();itr++)
    {
        itr->cost=itr->cost+price_now;
        que.push_back(*itr);
        sort(que.begin(),que.end(),compareNodes);
    }
}
bool goalTest(node a)
{
    if(a.label==goal)
    {
        cout<<"The cost is: "<<visited[a.label]<<endl;
        return true;
    }
    else return false;
}
int main()
{
    int i,price_now=0;
    ifstream in;
    char line[256];
    struct node a;
    int start=0, goal=6;
    in.open("./dataset.csv");
    vector <node>::iterator itr;
    for(i=0;i<7;i++)
    {
        visited[i]=20000;
    }
    while(in.getline(line,256))
    {
        a.label=line[2]-48;
        a.cost=line[4]-48;
        adjlist[line[0]-48].push_back(a);
    }
    a.label=0;
    a.cost=0;
    que.push_back(a);
    while(!que.empty())
    {
        a=*que.begin();
        que.erase(que.begin());
        if(a.cost<visited[a.label])
        visited[a.label]=a.cost;
        if(goalTest(a))
        return 0;
        getSuccessor(a,a.cost);
        price_now=a.cost;
    }
    return 1;
}