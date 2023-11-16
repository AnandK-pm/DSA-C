//program to demonstrate input restricted queue using linked list
#include<stdio.h>
#include<stdlib.h>
void insert_rear();
void delete_front();
void delete_rear();
void display();
struct node
{
    int data;
    struct node *link;
}*front=NULL,*rear=NULL;
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
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data to be inserted:");
    scanf("%d",&d);
    temp->data=d;
    temp->link=NULL;
    if(front==NULL)
    {
        front=temp;
        rear=temp;
        return;
    }
    rear->link=temp;
    rear=temp;
}
void delete_front()
{
    struct node *temp;
    if(front==NULL)
    {
        printf("queue underflow\n");
        return;
    }
    temp=front;
    front=front->link;
    free(temp);
}
void delete_rear()
{
    if(rear==NULL||front==NULL)
    {
    printf("queue underflow\n");
    return;
    }
    if(front==rear)
    {
        front=rear=NULL;
        return;
    }
    struct node *q;
    q=front;
    while(q->link->link!=NULL)
    {
        q=q->link;
    }
    q->link=NULL;  
    rear=q;
}
void display()
{
    if(front==NULL||rear==NULL)
    {
        printf("empty queue\n");
    }
    printf("\nthe queue elements are:\n");
    struct node *q;
    q=front;
    while(q!=NULL)
    {
        printf("%d\t",q->data);
        q=q->link;
    }
}