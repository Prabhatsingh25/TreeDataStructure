#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *lchild;
    int val;
    struct node *rchild;
}node;

node *root;

typedef struct queue
{
    int size;
    int front;
    int rear;
    node **Q;
}queue;

void create(queue *q,int sz)
{
    q->size = sz;
    q->front=q->rear=-1;
    q->Q=(node**)malloc(q->size*sizeof(node*));
}

void enqueue(queue *q,node *val)
{
    if(q->rear==q->size - 1)
        printf("queue is full\n");
    else
    {
        q->rear++;
        q->Q[q->rear]=val;
        if(q->front==-1)
            q->front=q->rear;
    }
}

node* dequeue(queue *q)
{
    node* val;
    if(q->front==-1)
        printf("queue is empty\n");
    else
    {
        val=q->Q[q->front];
        q->front++;
        return val;
    }
    return 0;
}

int isEmpty(queue *q)
{
    if(q->front > q->rear)
        return 0;
    else
        return 1;
}

void create_binary_tree()
{
    int value;
    node *p,*t;
    queue q;
    create(&q,100);
    root=(node*)malloc(sizeof(node));
    printf("enter the root node");
    scanf("%d",&value);
    root->val=value;
    root->lchild=NULL;
    root->rchild=NULL;
    enqueue(&q,root);
    while(isEmpty(&q))
    {
        p=dequeue(&q);
        printf("enter the left child value");
        scanf("%d",&value);
        if(value!=-1)
        {
            t=(node*)malloc(sizeof(node));
            t->val=value;
            t->lchild=NULL;
            t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }

        printf("enter the right child value");
        scanf("%d",&value);
        if(value!=-1)
        {
            t=(node*)malloc(sizeof(node));
            t->val=value;
            t->lchild=NULL;
            t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }

    }

}

void preorder(node *p)
{
    if(p!=NULL)
    {
        printf("%d",p->val);
        preorder(p->lchild);
        preorder(p->rchild);

    }
}


int main()
{
    create_binary_tree();
    preorder(root);
}
