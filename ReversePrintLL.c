#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
void insert(node **r);
void display(node *);
void rev(node *);
int main()
{
    int x=1,d;
    node *top=NULL;
    while(x)
    {
        printf("1:Insert\n2:Display\n3:reverse display\n");
        scanf("%d",&d);
        switch(d)
        {
            case 1:
                insert(&top);
                break;
            case 2:
               display(top);
               break;
            case 3:
               rev(top);
               printf("\n");
               break;
        }
    }
    return 0;
}
void insert(node **r)
{
    int d;
    scanf("%d",&d);
    node *p=NULL;
    p=(node *)malloc(sizeof(node));
    p->data=d;
    if(*r==NULL)
    {
        *r=p;
        (*r)->next=NULL;
    }
    else
    {
        p->next=*r;
        *r=p;
    }
}
void display(node *t)
{
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->next;
    }
    printf("\n");
}
void rev(node *t)
{
    if(t==NULL)
    {
        return;
    }
    rev(t->next);
    printf("%d ",t->data);
}
