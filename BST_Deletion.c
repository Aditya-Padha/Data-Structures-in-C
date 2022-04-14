#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
    int data;
    struct node *left;
    struct node *right;
}tree;
void insert(tree **t,int val);
void inorder(tree *r);
tree * inorderpredecessor(tree *r);
tree *deletenode(tree * r,int v);
int main()
{
    tree *t=NULL;
    int x=1,d,num,n;
    while(x)
    {
        printf("1. INSERT IN TREE\n2. DISPLAY USING INORDER\n3. DELETE ANY NODE\n");
        scanf("%d",&d);
        switch(d)
        {
            case 1:
              scanf("%d",&num);
              insert(&t,num);
              printf("\n");
              break;
            case 2:
              inorder(t);
              printf("\n");
              break;
            case 3:
              scanf("%d",&n);
              t=deletenode(t,n);
              printf("\n");
              break;
        }
    }
    return 0;
}
void insert(tree **t,int val)
{
    tree *k=NULL;
    if(*t==NULL)
    {
        k=(tree *)malloc(sizeof(tree));
        k->data=val;
        k->right=k->left=NULL;
        *t=k;
        return;
    }
    else if(val>(*t)->data)
    {
        insert(&(*t)->right,val);
    }
    else if(val<(*t)->data)
    {
        insert(&(*t)->left,val);
    }
}
void inorder(tree *r)
{
    if(r!=NULL)
    {
        inorder(r->left);
        printf("%d ",r->data);
        inorder(r->right);
    }
}
tree *deletenode(tree * r,int v)
{
    tree *ipre;
    if(r==NULL)
    {
        return NULL;
    }
    if(r->left==NULL && r->right==NULL)
    {
        free(r);
        return NULL;
    }
    if(v<r->data)
    {
        r->left=deletenode(r->left,v);
    }
    else if(v>r->data)
    {
        r->right=deletenode(r->right,v);
    }
    else
    {
        ipre=inorderpredecessor(r);
        r->data=ipre->data;
        r->left=deletenode(r->left,ipre->data);
    }
    return r;
}
tree * inorderpredecessor(tree *r)
{
    r=r->left;
    while(r->right!=NULL)
    {
        r=r->right;
    }
    return r;
}


