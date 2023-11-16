//menu driven program for the demonstration of stack using linked list
#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
struct node
{
    int data;
    struct node *link;
}*top=NULL;
int main()
{
    int choice;
    while(1) 
    {
    printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.Quit\n");
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
        case 4: exit(1);
    }
    }
}
void push()
{
    int item;
    printf("enter the item to be added:");
    scanf("%d",&item);
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=item;
    temp->link=top;
    top=temp;
    return;
}
void pop()
{
    int item;
    if(top==NULL)
    {
    printf("\nstack underflow\n");
    return;
    }
    //struct node*temp;
    //temp=(struct node*)malloc(sizeof(struct node));
    item=top->data;
    top=top->link;
    printf("item popped:%d\n",item);
    //top=temp;
}
void display()
{
    struct node*temp,*q;
    q=top;
    if(top==NULL)
    {
    printf("empty stack\n");
    return;
    }
    printf("\nThe stack elements are:\n");
    while(q!=NULL)
    {
        printf("%d\t",q->data);
        q=q->link;
    }  
}