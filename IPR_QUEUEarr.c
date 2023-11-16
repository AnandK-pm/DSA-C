//program to demonstrate input restricted queue by using array.
#include<stdio.h>
#include<stdlib.h>
void insert_rear();
void delete_front();
void delete_rear();
void display();
int front=-1,rear=-1;
int queue[30];
int main()
{
    int choice;
    while(1)
    {
    printf("\n1.Insert\n2.Delete from front\n3.delete from rear\n4.Display\n5.Quit\n");
    printf("\nenter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: insert_rear();
                display();
                break;
        case 2: delete_front();
                display();
                break;
        case 3: delete_rear();
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
    if(front==-1)
    {
        front++;
        rear++;
        queue[front]=d;
        return;
    }
    rear++;
    queue[rear]=d;
}
void delete_front()
{
    if(front==-1)
    {
        printf("queue underflow");
        return;
    }
    front++;
}
void delete_rear()
{
  if (rear==-1)
  {
     printf("queue underflow");
     return;
  }   
  rear--;
}
void display()
{
    int i;
    if(front==-1||rear==-1)
    {
        printf("queue is empty");
        return;
    }
    printf("\nthe queue elements are:\n");
    for(i=front;i<=rear;i++)
    {
        printf("%d",queue[i]);
    }
}
