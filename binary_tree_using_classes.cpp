#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    node *lchild;
    int data;
    node *rchild;
};


class Tree
{
public:
    node *root;
    Tree()
    {
      root=NULL;
    }
    void createTree();
    void preorder(node*);
    void levelOrder();
    int Count(node*);
    int leafnode(node*);
    int height(node*);

};


void Tree::createTree()
{
  node *p,*c;
  int  x;
  queue<node*> que;
  root = new node;
  cout<<"\nenter value for root";
  cin>>x;
  root->data=x;
  root->lchild=NULL;
  root->rchild=NULL;
   que.push(root);
   while(!que.empty())
   {
       p=que.front();
       que.pop();
       cout<<"\nenter the left child ";
       cin>>x;
       if(x!=-1)
       {
           c=new node;
           c->data=x;
           c->lchild=NULL;
           c->rchild=NULL;
           p->lchild=c;
           que.push(c);
       }

       cout<<"\nenter the right child ";
       cin>>x;
       if(x!=-1)
       {
           c=new node;
           c->data=x;
           c->lchild=NULL;
           c->rchild=NULL;
           p->rchild=c;
           que.push(c);
       }

   }
}


void Tree::preorder(node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);

    }
}

void Tree::levelOrder()
{
    node *p;
    queue<node *> q_lOrder;
    q_lOrder.push(root);
    while(!q_lOrder.empty())
    {
        p=q_lOrder.front();
        q_lOrder.pop();
        if(p)
        cout<<p->data<<" ";
        if(p->lchild)
        q_lOrder.push(p->lchild);
        if(p->rchild)
        q_lOrder.push(p->rchild);

    }
}

int Tree::Count(node *p)
{
    int x,y;
    if(p)
    {
        x=Count(p->lchild);
        y=Count(p->rchild);
        return x+y+1;
    }
    return 0;
}

int Tree::leafnode(node *p)
{
    int x,y;
    if(p)
    {
        x=leafnode(p->lchild);
        y=leafnode(p->rchild);
        if(p->lchild==NULL && p->rchild==NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}


int Tree::height(node *p)
{
    int x=0,y=0;
    if(p)
    {
        x=height(p->lchild);
        y=height(p->rchild);

        if(x>y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}


int main()
    {
        Tree obj;
        obj.createTree();
        cout<<"preorder ";
        obj.preorder(obj.root);
        cout<<"\n";
        cout<<"levelorder ";
        obj.levelOrder();
        cout<<"\n";
        cout<<"no of node ";
        cout<<obj.Count(obj.root);
        cout<<"\nno of leaf-node ";
        cout<<obj.leafnode(obj.root);
        cout<<"\n"<<"height of tree "<<obj.height(obj.root);
        return 0;
    }
