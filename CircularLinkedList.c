CIRCULAR LINKED LIST

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
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
                display(right);
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
        r->next=r;
    }
    else
    {
        p->next=r->next;
        r->next=p;
        r=p;
    }
    return r;
}
void display(node *r)
{
    node *p=r->next;
    do
    {
        printf("%d",p->data);
        p=p->next;
    }while(p!=r->next);
}
void delete(node **f,node **r)
{
    node *p=*f;
    node *prev;
    node *q=*r;
    int key;
    scanf("%d",&key);
    if(p->data==key)
    {
        node *t=p;
        q->next=p->next;
    }
    else if(q->data==key)
    {
        node *t=q;
        while(p->next!=q)
        {
            p=p->next;
        }
        p->next=q->next;
        q=p;
        free(t);
    }
    else
    {
    do
    {
        if(p->data==key)
        {
            node *temp=p;
            prev->next=p->next;
            free(temp);
            break;
        }
        prev=p;
        p=p->next;
    }while(p!=q);
    }
}
