/*
A Book consist of chapters, chapters consist of sections and sections consist
of subsections construct a tree and print the nodes find the time and space
requirements of your method.
*/

#include<iostream>
#include<string.h>
using namespace std;

struct node
{
    char label[10];
    int count;
    struct node *child[10];
}*root;

class Tree
{
    public:
    Tree()
    {
        root=NULL;
    }
    void create();
    void display(node *r1);
};

void Tree::create()
{
    int i,j;
    root=new node;
    cout<<"ENTER THE NAME OF THE BOOK :";
    cin>>root->label;
    cout<<"ENTER THE NUMBER OF CHAPTERS IN THE BOOK :";
    cin>>root->count;
    for(i=0;i<root->count;i++)
    {
        root->child[i]=new node;
        cout<<"ENTER THE NAME OF CHAPTER "<<i+1<<" :";
        cin>>root->child[i]->label;
        cout<<"ENTER NUMBER OF SECTIONS IN CHAPTER "<<root->child[i]->label<<" :";
        cin>>root->child[i]->count;
        for (j=0;j<root->child[i]->count;j++)
        {
            root->child[i]->child[j]=new node;
            cout<<"ENTER THE NAME OF SECTION "<<j+1<<" :";
            cin>>root->child[i]->child[j]->label;
        }
    }

}

void Tree::display(node *r1)
{
    int i,j,tchapters;
    if(r1!=NULL)
    {
        cout<<"\n--------------INDEX--------------";
        cout<<"\nBOOK : "<<r1->label;
        tchapters=r1->count;
        for(i=0;i<tchapters;i++)
        {
            cout<<"\nCHAPTER "<<i+1<<" : ";
            cout<<r1->child[i]->label;
            cout<<"\nSECTION : ";
            for(j=0;j<r1->child[i]->count;j++)
            {
                cout<<r1->child[i]->child[j]->label<<" ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    Tree t;
    int ch;
    while(true)
    {
        cout<<"\n1.CREATE TREE"<<endl;
        cout<<"2.DISPLAY TREE"<<endl;
        cout<<"0.EXIT"<<endl;
        cout<<"ENTER YOUR CHOICE :";
        cin>>ch;

        switch(ch)
        {
            case 1:
                t.create();
                break;
            case 2:
                t.display(root);
                break;
            case 0:
                break;
            default:
                cout<<"WRONG CHOICE !!";
        }
    }
    return 0;
}

/*
createnode function : The time complexity for creating a tree of depth D with N nodes per level is O(D * N).
                        The space complexity for creating a tree with D depth and N nodes per level is O(D * N).
displaytree function : The time complexity for displaying N nodes in a tree is O(N).
                        The space complexity for storing the tree structure in memory is also O(D * N).
*/
