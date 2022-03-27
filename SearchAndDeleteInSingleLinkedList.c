#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
void insert(node **r);
void display(node *l);
void searchanddelete(node **l);
int main()
{
    int x=1,d;
    node *left=NULL,*right=NULL;;
    while(x)
    {
        printf("1:Insert\n2:Display\n3:SEARCH and DELETE\n");
        scanf("%d",&d);
        switch(d)
        {
            case 1:
                insert(&right);
                if(left==NULL)
                {
                    left=right;
                }
                break;
            case 2:
               display(left);
               break;
            case 3:
               searchanddelete(&left);
               break;
        }
    }
}
void insert(node **r)
{
    node *p=NULL;
    p=(node *)malloc(sizeof(node));
    int d;
    scanf("%d",&d);
    p->data=d;
    if(*r==NULL)
    {
        *r=p;
    }
    else
    {
        (*r)->next=p;
        (*r)=p;
    }
    (*r)->next=NULL;
}
void display(node *l)
{
    while(l!=NULL)
    {
        printf("%d ",l->data);
        l=l->next;
    }
    printf("\n");
}
void searchanddelete(node **l)
{
    node *p=(*l);
    node *q=(*l)->next;
    int k;
    printf("ENTER THE KEY YOU WANT TO SEARCH AND DELETE:\n");
    scanf("%d",&k);
    int x=0;
    while(p!=NULL)
    {
        if(p->data==k)
        {
            node *k=p;
            p=q;
            free(k);
            x=1;
            break;
        }
        else
        {
            if(q->data==k)
            {
                node *m=q;
                p->next=q->next;
                free(m);
                x=1;
                break;
            }
        }
    }
    if(x==1)
    {
        printf("THE KEY WAS FOUND AND DELETED.\n");
    }
}
