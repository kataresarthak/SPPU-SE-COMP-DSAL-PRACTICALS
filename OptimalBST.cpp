#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left,*right;
};

node *construct(int r[5][5],int i,int j) {
    node *p;
    if(r[i][j]==0)
        return NULL;
    else
        p=new node;
    p->data=r[i][j];
    p->left=construct(r,i,r[i][j]-1);
    p->right=construct(r,r[i][j]+1,j);
    return p;
}

int find(int c[5][5],int i,int j)
{
    int min=999;
    int l,k,cost;
    for(k=i;k<=j;k++) {
        cost=c[i][k-1]+c[k+1][j];
        if(cost<min)
        {
            min=cost;
            l=k;
        }
    }
    return l;
}

void optimal(int p[10],int q[10],int n)
{
    int w[5][5],c[5][5],r[5][5],i,j,k;
    node *root;
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            c[i][j]=w[i][j]=r[i][j]=0;
    for(i=1;i<=n;i++)
    {
        w[i][i]=q[i-1]+q[i]+p[i];
        c[i][i]= w[i][i];
        r[i][i]=i;
    }
    for(int step=2;step<=n;step++)
        for(i=1;i<=n-step+1;i++)
        {
            j=i+step-1;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            k=find(c,i,j);
            c[i][j]=w[i][j]+c[i][k-1]+c[k+1][j];
            r[i][j]=k;
        }
    for(i=1;i<=n;i++)
    {
        j=i;
        cout<<w[i][j]<<c[i][j]<<r[i][j];
    }
    for(int step=2;step<=n;step++)
    {
        for(i=1;i<=n-step+1;i++)
        {
            j=i+step-1;
            cout<<w[i][j]<<" "<<c[i][j]<<" "<<r[i][j]<<" ";
        }
    }
    cout<<"\nMinimum Cost of BST :"<<c[1][n];
}

int main()
{
    int p[10],q[10],i,n;
    string wrd[5];
    cout<<"Enter number of Words :";
    cin>>n;
    cout<<"Enter words :";
    for(i=0;i<n;i++)
        cin>>wrd[i];
    cout<<"Enter number (probability) p: ";
    for(i=1;i<=n;i++)
        cin>>p[i];
    cout<<"Enter number (Frequency) q: ";
    for(i=0;i<=n;i++)
        cin>>q[i];
    optimal(p,q,n);
    return 0;
}