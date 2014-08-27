/*Binary Search tree
try inputs :
(1) 50 25 75 40 60 35 10 5 15 45 55 65 90 85 95 -1          //complete binary tree
(2) 50 25 75 40 60 35 45 55 65 90 85 95 -1                  // tricky case for outer traversal
(3) 50 25 75 40 60 35 10 5 15 45 55 65 -1                   // tricky case for outer traversal

*/


#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *l,*r;
};

typedef struct node n;
n *head=NULL,*temp,*temp2;
int max;

n* pos(n*,int*);        //finds node to which next node is to attached during creation
void pre(n*);           //preorder traversal
void post(n*);          //postorder traversal
void in(n*);            //inorder traversal
void fill(n*,int[],int);//for filling array according to formula for ith node left-child=2*i+1 right-child=2*i+2
void trav_outer(n*,int);//for outer traversal of nodes(just the leaves, leftmost nodes and rightmost nodes)

int main()
{
    int var,arr[1024],i,j,k,l;
    do
    {
        printf("Enter the element to be inserted(-1 to exit) : ");
        scanf("%d",&var);
        if(var!=-1)
        {
            temp=(n*)malloc(sizeof(n));
            temp->data=var;
            temp->l=NULL;
            temp->r=NULL;

            if(head==NULL)
                head=temp;
            else
            {
                temp2=pos(head,&var);
                if(var>temp2->data)
                    temp2->r=temp;
                else
                    temp2->l=temp;
            }
        }
    }while(var!=-1);

    printf("You have successfully created a Binary Search Tree\n");
//----------------------------------------------------------------------------------------------
    printf("Pre-Order Traversal : ");
    pre(head);
    printf("\n");
//----------------------------------------------------------------------------------------------
    printf("Post-Order Traversal : ");
    post(head);
    printf("\n");
//----------------------------------------------------------------------------------------------
    printf("In-Order Traversal : ");
    in(head);
    printf("\n");
//----------------------------------------------------------------------------------------------
    printf("Filling in the array we get :\n");
    max=0;
    fill(head,arr,0);
    for(j=0;j<=max;j++)
    {
        if(arr[j]!=-1)
            printf("%d ",arr[j]);
        else
            printf(" - ");
    }
    printf("\n");
//----------------------------------------------------------------------------------------------
    printf("Outer traversal :\n");
    trav_outer(head,0);

    return 0;
}

void trav_outer(n* x,int flag)
{
    if(x==NULL)
        return;
    else if(x->l==NULL && x->r==NULL)
        printf("%d ",x->data);
    else if(x==head)
    {
        printf("%d ",x->data);
        trav_outer(x->l,0);
        trav_outer(x->r,1);
    }
    else
    {
        if(flag!=2)
            printf("%d ",x->data);
        if(flag==2)
        {
            trav_outer(x->l,2);
            trav_outer(x->r,2);
        }
        else if(flag==0)
        {
            if(x->l==NULL)
            {
                trav_outer(x->r,0);
                trav_outer(x->l,2);
            }
            else
            {
                trav_outer(x->l,0);
                trav_outer(x->r,2);
            }
        }
        else if(flag==1)
        {
            if(x->r==NULL)
            {
                trav_outer(x->l,1);
                trav_outer(x->r,2);
            }
            else
            {
                trav_outer(x->r,1);
                trav_outer(x->l,2);
            }
        }
    }
}

void fill(n* x,int a[],int i)
{
    if(x==NULL)
    {
        a[i]=-1;
        a[2*i+1]=-1;
        a[2*i+2]=-1;
        return;
    }
    else
    {
        if(max<i)
            max=i;
        a[i]=x->data;
        fill(x->l,a,2*i+1);
        fill(x->r,a,2*i+2);
    }
}

void in(n *x)
{
    if(x==NULL)
        return;
    else
    {
        in(x->l);
        printf("%d ",x->data);
        in(x->r);
    }
}

void post(n* x)
{
    if(x==NULL)
        return;
    else
    {
        post(x->l);
        post(x->r);
        printf("%d ",x->data);
    }
}

void pre(n* x)
{
    if(x==NULL)
        return;
    else
    {
        printf("%d ",x->data);
        pre(x->l);
        pre(x->r);
    }
}

n* pos(n* x,int* key)
{
    if(*key>x->data)
    {
        if(x->r==NULL)
            return x;
        else
            return pos(x->r,key);
    }
    else
    {
        if(x->l==NULL)
            return x;
        else
            return pos(x->l,key);
    }
}
