//menu driven program for the demonstration of queue using linked list
#include<stdio.h>
#include<stdlib.h>
void insert();
void delete();
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
    printf("\n1.Insert\n2.Delete\n3.Display\n4.Quit\n");
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
        case 4: exit(1);
    }
    }
   
}
void insert()
{
    int item;
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data to be inserted:");
    scanf("%d",&item);
    temp->data=item;
    temp->link=NULL;
    if(front==NULL)
    {
        front=temp; //makes sure that the front is referenced to temp node only once,i.e in the first iteration only where both front and rear is NULL
        rear=temp;
        return;
    }
    rear->link=temp; //link connecting
    rear=temp; //rear is updated in every iteration unlike front.
}
void delete()
{
    int item;
    if(front==NULL)
    {
        printf("queue underflow\n");
        return;
    }
    item=front->data;
    printf("\nitem deleted:%d\n",item);
    front=front->link;
}
void display()
{
    struct node *q;
    if (front==NULL)
    {
        printf("\nempty queue\n");
        return;
    }
    printf("queue elements are:\n");
    q=front;
    while(q!=NULL)
    {
        printf("%d\n",q->data);
        q=q->link;
    }

}
