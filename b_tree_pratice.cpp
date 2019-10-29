#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
}node;

node *root;


void btree()
{
   node *p,*c;
  int  x;
  queue<node*> que;
  root = (node*)malloc(sizeof(node));
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
           c=(node*)malloc(sizeof(node));
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
           c=(node*)malloc(sizeof(node));
           c->data=x;
           c->lchild=NULL;
           c->rchild=NULL;
           p->rchild=c;
           que.push(c);
       }

   }
}

void preorder(node *p)
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
    btree();
    preorder(root);
}
