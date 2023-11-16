//menu driven program for the demonstration of stack using array
#include<stdio.h>
void push();
void pop();
void display();
int MAX=30;
int stack[30];
int top=-1;
int main()
{
int choice;
    char k;
    do 
    {
    printf("\n1.PUSH\n2.POP\n3.DISPLAY\n");
    printf("enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: push();
                display();
                break;
        case 2: pop();
                display();
                break;
        case 3: display();
                break;

    }
    printf("\nDo you want to continue?(Y/N):");
    scanf("%s",&k);
    }while(k=='Y'||k=='y');
}
void push()
{
    if(top==MAX-1)
    {
        printf("stack overflow");
        return;
    }
    top+=1;
    printf("enter the data:");
    scanf("%d",&stack[top]);
    return;
}
void pop()
{
    if(top==-1)
    {
        printf("stack underflow\n");
        return;
    }
    printf("element deleted:%d\n",stack[top]);
    top--;
    return;
}
void display()
{
    if(top==-1)
    {
        printf("empty stack\n");
        return;
    }
    int n=0;
    while(n<=top)
    {
        printf("%d\t",stack[n]);
        n++;
    }
    printf("\n");
    return;
}