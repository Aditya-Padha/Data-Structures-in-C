/******************************************************************************

Doubly Linked List 

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}node;
void display(node *r);
node *insert(node *r);
void delete(node **f,node **r);
int main()
{
    node *right=NULL,*left=NULL;
    int x=1,d;
    while(x)
    {
        printf("\n1: INSERT\n2:DELETE\n3:DISPLAY\n");
        scanf("%d",&d);
        switch(d)
        {
            case 1:
                right=insert(right);
                if(left==NULL)
                {
                    left=right;
                }
                break;
            case 2:
                delete(&left,&right);
                break;
            case 3:
                display(left);
                break;
        }
    }
    return 0;
}
node *insert(node *r)
{
    int d;
    scanf("%d",&d);
    node *p=NULL;
    p=(node *)malloc(sizeof(node));
    p->data=d;
    if(r==NULL)
    {
        r=p;
        r->prev=r->next=NULL;
    }
    else
    {
        r->next=p;
        p->prev=r;
        p->next=NULL;
        r=p;
    }
    return r;
}
void display(node *l)
{
    while(l!=NULL)
    {
        printf("%d ",l->data);
        l=l->next;
    }
}
void delete(node **l,node **r)
{
    node *p=*l,*q=*r;
    int key;
    scanf("%d",&key);
    if(p->data==key)
    {
        node *k=p;
        p=p->next;
        p->prev=NULL;
        free(k);
        *l = p;
    }
    else if(q->data==key)
    {
        node *m=q;
        q=q->prev;
        q->next=NULL;
        free(m);
        *r = q;
    }
    else
    {
        while(p->next!=NULL)
        {
            if(p->data==key)
            {
                node *m=p;
                p->prev->next=p->next;
                p->next->prev=p->prev;
                free(m);
                break;
            }
            p=p->next;
        }
    }
}
