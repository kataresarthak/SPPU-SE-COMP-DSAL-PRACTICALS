#include<iostream>
using namespace std;

#define true 1
#define false 0
#define max 100
class node
{
    public:

    int data,top,visit;
    node *left,*right;
    node *root;
    node()
    {
        root=NULL;
    
    }
    node * create(node *root);
    void insert(node *root,node *temp);
    void dispmenu(node *root);

    void recdispvlr(node *root);
    void recdisplvr(node *root);
    void recdisplrv(node *root);

    void nonrecvlr(node *root);
    void nonreclvr(node *root);
    void nonreclrv(node *root);
};

node *node::create(node *root)
{
    node *temp;
    char c;
    do
    {
        temp=new node;
        temp->left=NULL;
        temp->right=NULL;
        temp->visit=false;
        cout<<"\nENTER THE DATA :";
        cin>>temp->data;
        if(root==NULL)
            root=temp;
        else
            insert(root,temp);
        cout<<"\nWANT TO ENTER MORE NODES (Y/N) :";
        cin>>c;
    }while(c=='Y' || c=='y');
    return root;
}

void node::insert(node *root,node *temp)
{
    char ch;
    cout<<"INSERT DATA TO LEFT(L) OR RIGHT(R) OF "<<root->data<<" :";
    cin>>ch;
    if(ch=='l'||ch=='L')
    {
        if(root->left==NULL)
            root->left=temp;
        else
            insert(root->left,temp);
    }
    if(ch=='r'||ch=='R')
    {
        if(root->right==NULL)
            root->right=temp;
        else
            insert(root->right,temp);
}
}

void node::dispmenu(node *root)
{
    int ch;
    char ans;
    node *stack[100];
    do
    {
        cout<<"\nDISPLAY BINARY TREE:-\n1.RECURSIVE PREORDER\n2.RECURSIVE INORDER\n3.RECURSIVE POSTORDER\n";
        cout<<"4.NON-RECURSIVE PREORDER\n5.NON-RECURSIVE INORDER\n6.NON-RECURSIVE POSTORDER";
        cout<<"\nENTER YOUR CHOICE :";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"RECURCIVE PREORDER (VLR) TRAVERSEL\n";
                recdispvlr(root);
                break;
            case 2:
                cout<<"RECURCIVE INORDER (LVR) TRAVERSEL\n";
                recdisplvr(root);
                break;
            case 3:
                cout<<"RECURCIVE POSTORDER (LRV) TRAVERSEL\n";
                recdisplrv(root);
                break;
            case 4:
                cout<<"NON-RECURCIVE PREORDER (VLR) TRAVERSEL\n";
                nonrecvlr(root);
                break;
            case 5:
                cout<<"NON-RECURCIVE INORDER (LVR) TRAVERSEL\n";
                nonreclvr(root);
                break;
            case 6:
                cout<<"NON-RECURCIVE POSTORDER (LRV) TRAVERSEL\n";
                nonreclrv(root);
                break;
            default:
                cout<<"invalid choice\n";
        }
        cout<<"\n\nDO U WANT TO CONTINUE DISPLAYING TREE (Y/N) :";
        cin>>ans;
    }while(ans=='y'||ans=='Y');
}

void node::recdispvlr(node *root)
{
    if(root)
    {
        cout<<"\t"<<root->data;
        recdispvlr(root->left);
        recdispvlr(root->right);
    }
}

void node::recdisplvr(node *root)
{
    if(root)
    {
        recdisplvr(root->left);
        cout<<"\t"<<root->data;
        recdisplvr(root->right);
    }
}

void node::recdisplrv(node *root)
{
    if(root)
    {
        recdisplrv(root->left);
        recdisplrv(root->right);
        cout<<"\t"<<root->data;
    }
}

void node::nonrecvlr(node *root)
{
    node *stack[100],*temp;
    int top=-1;
    temp=root;
    while(1)
    {
        while(temp)
        {
            top++;
            stack[top]=temp;
            cout<<temp->data<<"\t";
            temp=temp->left;
        }
        if(top!=-1)
        {
            temp=stack[top];
            top--;
            temp=temp->right;
        }
        else
            break;
    }
}

void node::nonreclvr(node *root)
{
    node *stack[100],*temp;
    int top=-1;
    temp=root;

    while(1)
    {
        while(temp)
        {
            top++;
            stack[top]=temp;
            temp=temp->left;
        }
        if(top!=-1)
        {
            temp=stack[top];
            top--;
            cout<<temp->data<<"\t";
            temp=temp->right;
        }
        else
            break;
    }
}

void node::nonreclrv(node* root)
{
    node *stack[100];
    int top=-1;
    node *temp=root;
    node *prev=NULL;

    while (temp!=NULL || top!=-1)
    {
        while (temp!=NULL)
        {
            stack[++top]=temp;
            temp=temp->left;
        }

        temp=stack[top];

        if (temp->right==NULL || temp->right==prev)
        {
            cout<<temp->data<<"\t";
            top--;
            prev=temp;
            temp=NULL;
        }
        else
        {
            temp=temp->right;
        }
    }
}

int main()
{
    int i,ch;
    char c,ans;

    node p1;
    do
    {
        cout<<"\n================MENU================\n";
        cout<<"1:CREATE BINARY TREE\n2:DISPLAY\n3:EXIT";
        cout<<"\nENTER YOUR CHOICE :";
        cin>>ch;
        switch(ch)
        {
            case 1:
                p1.root=p1.create(p1.root);
                break;
            case 2:
                p1.dispmenu(p1.root);
                break;
            case 3:
                exit(0);
                break;
        }
        cout<<"\nWANT TO CONTINUE OPERATIONS (Y/N) :";
        cin>>ans;
    }while(ans=='y'||ans=='Y'); //do
    return 0;
}
