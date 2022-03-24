//SINGLE LINKED LIST 

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *delete(node *l);
void display(node *l);
node *insert(node *r);
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
                left=delete(left);
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
    int data;
    printf("ENTER THE VALUE YOU WANT TO INSERT AT THE NODE\n");
    scanf("%d",&data);
    node *t=NULL;
    t=(node *)malloc(sizeof(node));
    t->data=data;
    if(r==NULL)
    {
        r=t;
        r->next=NULL;
    }
    else
    {
        r->next=t;
        r=t;
        r->next=NULL;
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
node *delete(node *l)
{
    int key;
    printf("ENTER THE KEY YOU WANT TO DELETE:\n");
    scanf("%d",&key);
    node *p=l;
    node *q=l->next;
    if(p->data==key)
    {
        node *t=p;
        p=p->next;
        free(t);
        return p;
    }
    while(q!=NULL)
    {
        if(q->data==key)
        {
            node *t=q;
            p->next=q->next;
            free(t);
            break;
        }
        p=p->next;
        q=q->next;
    }
    return l;
}
