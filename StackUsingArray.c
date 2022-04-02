#include <stdio.h>
#define max 10
int push(int a[], int t);
int pop(int a[],int t);
void display(int a[],int t);
int main()
{
    int a[max];
    int top = -1;
    int ch;
    int x=1;
    while(x)
    {
        printf("\n1:PUSH\n2:POP\n3:DISPLAY\n4:EXIT");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                top = push(a,top);
                break;
            case 2:
                top = pop(a,top);
                break;
            case 3:
                display(a,top);
                break;
            case 4:
                x=0;
                break;
        }
    }
    return 0;
}
int push(int a[], int top)
{
    int n;
    scanf("%d",&n);
    top++;
    a[top] = n;
    return top;
}
int pop(int a[], int top)
{
    a[top] = 0;
    top--;
    return top;
}
void display(int a[],int top)
{
    while(top>=0)
    {
        printf("%d ",a[top]);
        top--;
    }
}
