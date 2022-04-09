/******************************************************************************

stack using single pointer in SLL

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
typedef struct node 
{
    int data;
    struct node* next;
}node;
void display(node* t);
node* pop(node* t);
node* push(node* t,int d);
int main()
{
    node* top=NULL;
    int x=1;
    while(x)
    {
        printf("\n ENTER YOUR CHOICE:\n");
        printf("press 1 for push(enter) in the stack\n");
        printf("press 2 for pop(delete top element) in the stack\n");
        printf("press 3 for displaying stack\n");
        printf("press 4 for seeing peak(top element)\n");
        int k,d;
        scanf("%d",&k);
        switch(k)
        {
            case 1:
            printf("Enter Variable: ");
              scanf("%d",&d);
              top=push(top,d);
              printf("YUP WORKED");
              break;
            case 2:
              top=pop(top);
              break;
            case 3:
              display(top);
              break;
            //case 4:
             // peak(top);
        }
    }
    return 0;
}
node *push(node *t,int d)
{
    node* p=(node *)malloc(sizeof(node));
    if(p!=NULL)
    {
        p->data=d;
        p->next=t;
        t=p;
    }
    return t;
}
node *pop(node *t)
{
    node *temp=t;
    t=t->next;
    free(temp);
    return t;
}
void display(node* t)
{
    node* tmp=t;
    printf("abc");
    while(tmp!=NULL)
    {
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
}
