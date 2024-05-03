/*A Book consist of chapters, chapters consist of sections and sections consist
of subsections construct a tree and print the nodes find the time and space
requirements of your method.*/

#include<iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    int count;
    Node *child[10];
};

class Tree
{
    public:
        Node *root;
        Tree()
        {
            root=NULL;
        }
        void createnode();
        void displaytree();
};

void Tree::createnode()
{
    root=new Node;
    
    cout<<"ENTER THE NAME OF THE BOOK:- ";
    cin.ignore();
    getline(cin,root->name);
    
    cout<<"ENTER THE NUMBER OF CHAPTERS IN THE BOOK:- ";
    cin>>root->count;
    
    for(int i=0;i<root->count;i++)
    {
        root->child[i]=new Node;
        cout<<"\tENTER THE NAME OF THE CHAPTER "<<i+1<<":- ";
        cin.ignore();
        getline(cin,root->child[i]->name);
        
        cout<<"\tENTER NUMBER OF SECTIONS IN CHAPTER "<<root->child[i]->name<<":- ";
        cin>>root->child[i]->count;
        
        for(int j=0;j<root->child[i]->count;j++)
        {
            root->child[i]->child[j]=new Node;
            cout<<"\t\tENTER THE NAME OF THE SECTION "<<j+1<<":- ";
            cin.ignore();
            getline(cin,root->child[i]->child[j]->name);
            
        }
    }
}


void Tree::displaytree()
{
    cout<<"\n================INDEX================\n";
    cout<<"BOOK\t\tCHAPTER\t\tSECTION"<<endl;
    cout<<root->name<<endl;
    for(int i=0;i<root->count;i++)
    {
        cout<<"\t\t"<<root->child[i]->name<<endl;
        for(int j=0;j<root->child[i]->count;j++)
        {
            cout<<"\t\t\t\t"<<root->child[i]->child[j]->name<<endl;
        }
        cout<<"\t\t--------------------------------"<<endl;
    }
}

int main()
{
    int ch;
    Tree t;
    while(true)
    {
        cout<<"\n================MENU================\n";
        cout<<"\n1.CREATE TREE"<<endl;
        cout<<"2.DISPLAY TREE"<<endl;
        cout<<"0.EXIST"<<endl;
        cout<<"ENTER YOUR CHOICE :";
        cin>>ch;
        switch (ch)
        {
            case 1:
                t.createnode();
                break;
            case 2:
                t.displaytree();
                break;
            case 0:
                exit(0);
                break;
            default:
                cout<<"WRONG CHOICE !!";
        }
    }
    return 0;
}

/*createnode function : The time complexity for creating a tree of depth D with N nodes per level is O(D * N).
                        The space complexity for creating a tree with D depth and N nodes per level is O(D * N).
displaytree function : The time complexity for displaying N nodes in a tree is O(N).
                        The space complexity for storing the tree structure in memory is also O(D * N).*/
