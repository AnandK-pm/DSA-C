//menu driven program for the demonstration of queue using array
#include<stdio.h>
void insert();
void delete();
void display();
int front=-1,rear=-1;
int queue[30];
int MAX=30;
int main()
{
   int choice;
    char k;
    do 
    {
    printf("\n1.Insert\n2.Delete\n3.Display\n");
    printf("\nenter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: insert();
                display();
                break;
        case 2: delete();
                display();
                break;
        case 3: display();
                break;

    }
    printf("\nDo you want to continue?(Y/N):");
    scanf("%s",&k);
    }while(k=='Y'||k=='y');
}
void insert()
{
    int d;
    printf("enter the data:");
    scanf("%d",&d);
     if(rear==MAX-1)
    {
        printf("queue overflow");
        return;
    }
    if(front==-1)
    {
        front++;
        rear++;
        queue[rear]=d;
    }
    else
    {
        rear++;
        queue[rear]=d;
        return;
    }
}
   
void display()
{
    if(rear==-1)
    {
    printf("empty queue");
    return;
    }
    int i;
    for(i=front;i<=rear;i++)
    {
        printf("%d\t",queue[i]);
    }
}
void delete()
{
    if(front>rear)
    {
        printf("queue underflow");
        return;
    }
    printf("deleted element:%d\n",queue[front]);
    front++;
    return;
}