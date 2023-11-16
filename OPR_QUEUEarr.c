//program to demonstrate outpur restricted queue using array.
#include<stdio.h>
#include<stdlib.h>
void insert_front();
void insert_rear();
void delete_front();
void display();
int front=-1,rear=-1;
int MAX=30;
int queue[30];
int main()
{
    int choice;
    while(1)
    {
    printf("\n1.Insert in rear\n2.Insert in front\n3.delete from front\n4.Display\n5.Quit\n");
    printf("\nenter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: insert_rear();
                display();
                break;
        case 2: insert_front();
                display();
                break;
        case 3: delete_front();
                display();
                break;
        case 4: display();
                break;
        case 5: exit(1);
    }
    }
}
void insert_rear()
{
    int d;
    printf("enter the element to be added:");
    scanf("%d",&d);
    if((rear+1)%MAX==front) 
    {
        printf("Queue overflow\n");  
        return;
    }
    if(front==-1 && rear==-1)
    {
        front+=1;
        rear+=1;
        queue[rear]=d;
        return;
    }
    rear+=1;
    queue[rear]=d;
}
void insert_front()
{
    int d;
    printf("enter the element to be added:");
    scanf("%d",&d);
    if((rear+1)%MAX==front) 
    {
        printf("Queue overflow\n");  
        return;
    }
    if(front==-1 && rear==-1)
    {
        front+=1;
        rear+=1;
        queue[front]=d;
        return;
    }
    if(front==0)
    {
        front=MAX-1;
        queue[front]=d;
        return;
    }
    front=front-1;
    queue[front]=d;
}
void delete_front()
{
    if(front==-1)
    {
        printf("queue underflow\n");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else 
    front=(front+1)%MAX;
}
void display()
{
    if(front==-1)
    {
        printf("queue empty\n");
        return;
    }
    printf("\nthe queue elements are:\n");
    int i=front;
    while(i!=rear+1)
    {
        printf("%d\t",queue[i]);
        i=(i+1)%MAX;
    }
}