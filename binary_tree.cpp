#include<bits/stdc++.h>
using namespace std;


typedef struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
}node;

queue<node *>que;
node *root;

void createBinaryTree()
{
    int x;
    node *p,*t;
    cout<<"enter the value of root";
    cin>>x;
    root=new node;
    root->data = x;
    root->lchild=NULL;
    root->rchild=NULL;
    que.push(root);
    while(!que.empty())
    {
        p=que.front();
        que.pop();
        cout<<"enter the value for left child";
        cin>>x;
        if(x!=-1)
        {
            t=new node;
            t->data=x;
            t->lchild=NULL;
            t->rchild=NULL;
            p->lchild=t;
            que.push(t);
        }

        cout<<"enter the value for right child";
        cin>>x;
        if(x!=-1)
        {
            t=new node;
            t->data=x;
            t->lchild=NULL;
            t->rchild=NULL;
            p->rchild=t;
            que.push(t);
        }

    }
}

void preorder(node* p)
{
    if(p)
    {
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

int main()
{
  createBinaryTree();
  preorder(root);

}
