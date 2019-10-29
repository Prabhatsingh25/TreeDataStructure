#include<bits/stdc++.h>
using namespace std;

class node
{
public:
     node *lchild;
     int data;
     node *rchild;
};

class BinaryTree
{
public:
    node *root;
     BinaryTree()
    {
        root=NULL;
    }


    void createBinaryTree();
    void preorder(node*);
    int BinaryTreeHight(node*);
    int BinaryTreeTotalNode(node*);
    int BinaryTreeLeafNode(node*);
    int BinaryTreeInternalNode(node*);


};


void BinaryTree::createBinaryTree()
{
    node *p,*c;
    queue<node*>que;
    int val;
    if(root==NULL)
    {
        root = new node;
        cout<<"\nenter the value for root ";
        cin>>val;
        root->data = val;
        root->lchild = NULL;
        root->rchild = NULL;
        que.push(root);
    }
    while(!que.empty())
    {
        p=que.front();
        que.pop();
        cout<<"\nenter the value for left child if you want left child otherwise input '-1' ";
        cin>>val;
        if(val!=-1)
        {
          c = new node;
          c->data = val;
          c->lchild=NULL;
          c->rchild = NULL;
          p->lchild = c;
          que.push(c);
        }

        cout<<"\nenter the value for right child if you want right child otherwise input '-1' ";
        cin>>val;
        if(val!=-1)
        {
          c = new node;
          c->data = val;
          c->lchild=NULL;
          c->rchild = NULL;
          p->rchild = c;
          que.push(c);
        }

    }

}

void BinaryTree::preorder(node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

int BinaryTree::BinaryTreeHight(node *p)
{
    int x=0,y=0;
    if(p)
    {
        x= BinaryTreeHight(p->lchild);
        y= BinaryTreeHight(p->rchild);
        if(x>y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}


int BinaryTree::BinaryTreeTotalNode(node *p)
{
    int x=0,y=0;
    if(p)
    {
        x= BinaryTreeTotalNode(p->lchild);
        y= BinaryTreeTotalNode(p->rchild);
        return x+y+1;
    }
    return 0;
}

 int BinaryTree::BinaryTreeLeafNode(node *p)
{
    int x=0,y=0;
    if(p)
    {
        x= BinaryTreeLeafNode(p->lchild);
        y= BinaryTreeLeafNode(p->rchild);
        if(p->lchild==NULL && p->rchild==NULL)
        return x+y+1;
        else
            return x+y;
    }
    return 0;
}


int BinaryTree::BinaryTreeInternalNode(node *p)
{
    int x=0,y=0;
    if(p)
    {
        x= BinaryTreeInternalNode(p->lchild);
        y= BinaryTreeInternalNode(p->rchild);
        if(p->lchild!=NULL && p->rchild!=NULL)
        return x+y+1;
        else
            return x+y;
    }
    return 0;
}



int main()
{
    BinaryTree obj;
    obj.createBinaryTree();
    cout<<"\n hight of Binary Tree "<<obj.BinaryTreeHight(obj.root);
    cout<<"\n Total no of node in Binary Tree "<<obj. BinaryTreeTotalNode(obj.root);
    cout<<"\n Total no of Leaf node in Binary Tree "<<obj. BinaryTreeLeafNode(obj.root);
    cout<<"\n Total no of Internal node in Binary Tree "<<obj. BinaryTreeInternalNode(obj.root);
    cout<<"\n value in preorder ";
    obj.preorder(obj.root);
}
