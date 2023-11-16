//menu driven program for the demonstration of circular queue using array
#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void display();
int front=-1,rear=-1;
int queue[5];
int MAX=5;
int main()
{
    int choice;
    while(1) 
    {
    printf("\n1.Insert\n2.Delete\n3.Display\n4.Quit\n");
    printf("\nenter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: enqueue();
                display();
                break;
        case 2: dequeue();
                display();
                break;
        case 3: display();
                break;
        case 4: exit(1);
    }
}
}
void enqueue()
{
    int d;
    printf("enter the data:");
    scanf("%d",&d);
    if(front==-1)  //empty queue checking
    {
        front=rear=0;
        queue[rear]=d;
    }
    else if((rear+1)%MAX==front)   //overflow conditions are when front =0 and rear=MAX-1,and front=rear+1
    {
        printf("Queue overflow\n");  
    }
    else
    {
        rear=(rear+1)%MAX;
        queue[rear]=d;
    }
}
void display()
{
    if(front==-1 && rear==-1)
    {
        printf("empty queue");
    }
    else if(rear<front)                     //printf("the queue elements are:")                             
    {                                       //i=front
        int i=front;                        //while(i!=rear){                
        while(i!=MAX)                       //printf("%d",queue[i])
        {                                   //i=(i+1)%MAX}
           printf("%d\t",queue[i]);
           i++;
        }
        i=0;
        while(i!=rear+1)
        {
            printf("%d\t",queue[i]);
            i++;
        }   
    }  
    else
    {
        for(int i=front;i<=rear;i++)
        printf("%d\t",queue[i]);

    } 
}
void dequeue()
{
    if(front==-1)
    {
        printf("queue underflow\n");
    }
    else if(front==rear)  //checks whether there is only one element in the queue
    {
        front=rear=-1;
    }
    else 
    {
        front=(front+1)%MAX;
    }
}

