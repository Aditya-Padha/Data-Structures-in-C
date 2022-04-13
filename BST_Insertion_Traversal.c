#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
    int data;
    struct node *left;
    struct node *right;
}node;
void insert(node **bt,int n);
void inorder(node *l);
void preorder(node *l);
void postorder(node *l);
int main()
{
    node *l=NULL;
    int x=1,d;
    while(x)
    {
        int n;
        printf("\n");
        printf("1: INSERT A ELEMENT\n2: INORDER PRINT\n3: PREORDER PRINT\n4: POSTORDER PRINT\n");
        scanf("%d",&d);
        switch(d)
        {
            case 1:
               scanf("%d",&n);
               insert(&l,n);
               break;
            case 2:
                inorder(l);
                break;
            case 3:
                preorder(l);
                break;
            case 4:
                postorder(l);
                break;
        }
    }
    return 0;
}
void insert(node **bt,int n)
{
    node *temp=NULL;
    if(*bt==NULL)
    {
        temp=(node *)malloc(sizeof(node));
        temp->left=temp->right=NULL;
        temp->data=n;
        *bt=temp;
        return;
    }
    if(n<(*bt)->data)
    {
        insert(&(*bt)->left,n);
    }
    else if(n>(*bt)->data)
    {
        insert(&(*bt)->right,n);
    }
}
void inorder(struct node* r)
{
	if(r!= NULL)
	{
		inorder(r->left);
	    printf("%d ",r->data);
		inorder(r->right);
	}	
}
void preorder(struct node* r)
{
	if(r!= NULL)
	{
		printf("%d ",r->data);
		preorder(r->left);
		preorder(r->right);
	}
}
void postorder(struct node* r)
{
	if(r!= NULL)
	{
		postorder(r->left);
		postorder(r->right);
		printf("%d ",r->data);
	}
}



