#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    node *lchild;
    int data;
    node *rchild;
};

class BST
{
public:
    node *root;
    BST()
    {
        root=NULL;
    }

    node* insertBST(node*,int);
    node* insertBSTrecursion(node* ,int );
    void preorder(node*);
    int Height(node*);
    node* Delete(node* , int );
    node* InSucc(node *);
    node* InPre(node *);
};



node* BST::insertBST(node *p,int val)
{
    node *r=NULL;
    node *q;
    while(p!=NULL)
    {
        r=p;
        if(p->data==val)
        {
            cout<<"\ncannot be added as this no is already present";
            return NULL;

        }
        else if((p->data)>val)
            p=p->lchild;
        else
                p=p->rchild;
    }

    q= new node;
    q->data=val;
    q->lchild=q->rchild=NULL;
    if(r==NULL)
        return q;
    else
    {
        if(r->data > val)
        {
            r->lchild=q;
        }
        else
        {
            r->rchild=q;

        }
         return q;
    }
}

void BST::preorder(node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

node* BST::insertBSTrecursion(node* p,int val)
{
    node *q;
    if(p==NULL)
    {
        q=new node;
        q->data=val;
        q->lchild=NULL;
        q->rchild=NULL;
        return q;
    }
    else if(p->data > val)
        p->lchild = insertBSTrecursion(p->lchild,val);
    else
        p->rchild = insertBSTrecursion(p->rchild,val);
}


int BST::Height(node *p)
{
    int x=0,y=0;
    if(p)
    {
        x=Height(p->lchild);
        y=Height(p->rchild);
        if(x>y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}


node* BST::InPre(node *p)
{
 while(p && p->rchild!=NULL)
 p=p->rchild;

 return p;
}

node* BST::InSucc(node *p)
{
 while(p && p->lchild!=NULL)
 p=p->lchild;

 return p;
}




node* BST::Delete(node *p,int key)
{
 node *q;

 if(p==NULL)
 return NULL;
 if(p->lchild==NULL && p->rchild==NULL)
 {
 if(p==root)
 root=NULL;
 free(p);
 return NULL;

 }

 if(key < p->data)
 p->lchild=Delete(p->lchild,key);
 else if(key > p->data)
 p->rchild=Delete(p->rchild,key);
 else
 {
 if(Height(p->lchild)>Height(p->rchild))
 {
 q=InPre(p->lchild);
 p->data=q->data;
 p->lchild=Delete(p->lchild,q->data);
 }
 else
 {
 q=InSucc(p->rchild);
 p->data=q->data;
 p->rchild=Delete(p->rchild,q->data);
 }


 }
 return p;
}



int main()
{
    BST obj;
    obj.root=obj.insertBSTrecursion(obj.root,10);
    obj.insertBSTrecursion(obj.root,20);
    obj.insertBSTrecursion(obj.root,33);
    obj.insertBSTrecursion(obj.root,22);
    obj.insertBSTrecursion(obj.root,14);
    obj.preorder(obj.root);
    obj.Delete(obj.root,10);
    cout<<"\n after deletion ";
    obj.preorder(obj.root);
    cout<<"\nnew root after deletion ";
    cout<<obj.root->data;
}
