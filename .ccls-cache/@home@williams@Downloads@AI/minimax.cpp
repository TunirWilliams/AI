#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
int b,m;
int counter=0;
int counter2=0;
struct tree
{
    int n;
    int choice;
    int pl;
    int alpha;
    int beta;
    struct tree **branches;
};

struct tree* buildtree(int b,int m)
{
    struct tree *root;
    int i;
    root=(struct tree*)malloc(sizeof(struct tree));
    counter++;
    if(m!=1) {
    root->branches=(struct tree**)malloc(b*sizeof(struct tree*));
    root->n=-99;
    for(i=0;i<b;i++)
    {
        root->branches[i]=(struct tree*)malloc(sizeof(struct tree));
        root->branches[i]=buildtree(b,m-1);
    }
    }
    else
    {
        root->n=(rand()%100);
        root->branches=NULL;
        cout<<root->n<<" ";
    }
    return root;
}
int minimax(struct tree *gametree)
{
    int i;
    if(gametree->branches==NULL)
    {
        return gametree->n;
    }
    else
    {
        for(i=0;i<b;i++)
        {
        
            if(gametree->n==-99) gametree->n=minimax(gametree->branches[i]);
            if(gametree->branches[i]->n==-99)
            {
                gametree->branches[i]->n=minimax(gametree->branches[i]);
            }
            if(gametree->pl==1)
            {
                if(gametree->n <= gametree->branches[i]->n)
                {
                    gametree->n=gametree->branches[i]->n;
                    gametree->choice=i;
                }
            }
            else
            {
                if(gametree->n >= gametree->branches[i]->n)
                {
                    gametree->n=gametree->branches[i]->n;
                    gametree->choice=i;
                }
            }
            
        }
        return gametree->n;
    }
}
int alphabeta(struct tree *gametree)
{
    int i;
    counter2++;
    if(gametree->branches==NULL)
    {
        return gametree->n;
    }
    else
    {
        for(i=0;i<b && gametree->beta>=gametree->alpha;i++)
        {
        
            if(gametree->n==-99)
            {
            	gametree->branches[i]->alpha=gametree->alpha;
                gametree->branches[i]->beta=gametree->beta;
                gametree->n=alphabeta(gametree->branches[i]);
            }
            if(gametree->branches[i]->n==-99)
            {
                gametree->branches[i]->alpha=gametree->alpha;
                gametree->branches[i]->beta=gametree->beta;
                gametree->branches[i]->n=alphabeta(gametree->branches[i]);
            }
            if(gametree->pl==1)
            {
                if(gametree->n <= gametree->branches[i]->n)
                {
                    gametree->n=gametree->branches[i]->n;
                    gametree->choice=i;
                    gametree->alpha=gametree->n;
                }
            }
            else
            {
                if(gametree->n >= gametree->branches[i]->n)
                {
                    gametree->n=gametree->branches[i]->n;
                    gametree->choice=i;
                    gametree->beta=gametree->n;
                }
            }
            
        }
        return gametree->n;
    }
}

void level(struct tree* gametree)
{
    int i;
    if(gametree->branches!=NULL)
    for(i=0;i<b;i++)
    {
        gametree->branches[i]->pl=1-gametree->pl;
        level(gametree->branches[i]);
    }
}
void sequence(struct tree *gametree)
{
    if(gametree->pl==1)
    {
        cout<<"Max: "<<gametree->n<<" ";
    }
    else
    {
        cout<<"Min: "<<gametree->choice<<" ";
    }
    if(gametree->branches!=NULL)
        sequence(gametree->branches[gametree->choice]);
}
int main()
{
    srand(time(0));
    struct tree *root;
    cin>>b;
    cin>>m;
    root=buildtree(b,m);
    root->pl=1;
    root->alpha=-100;
    root->beta=200;
    level(root);
    cout<<endl;
    cout<<alphabeta(root)<<endl;
    cout<<minimax(root)<<endl;
    sequence(root);
    cout<<endl;
    cout<<"Count pruned: "<<(counter-counter2)<<endl;
    return 0;
}

