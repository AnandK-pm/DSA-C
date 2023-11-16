//program to demonstrate priority queue using linked list
//a priority value is attached with the elements.the elements will be deleted in that order.priority value 1 will have the highest priority
#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void display();
struct node
{
    int data,pr;
    struct node *link;
}*front=NULL,*rear=NULL;
int main()
{
    char c;
    while(1)
    {
        int k;
        printf("1.Insert\n2.Delete\n3.Display\n4.Quit");
        printf("\nEnter a choice:");
        scanf("%d",&k);
        switch(k)
        {
            case 1:enqueue();
                   display();
                   break;
            case 2:dequeue();
                   display();
                   break;
            case 3:display();
                   break;
            case 4:exit(1);
                    
        }
    }
}
void enqueue()
{
    struct node *temp,*q;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the element:");
    scanf("%d",&temp->data);
    printf("enter its priority:");
    scanf("%d",&temp->pr);
    if(front==NULL)       //checking if newnode is the first node to be inserted 
    {
        temp->link=NULL;
        front=temp;
        rear=temp;
    }
    else if(temp->pr<front->pr) //checking if the priority of the new node(temp) is higher then the node in the front,if so the new node is made as front,thaat is the first node.
    {
        temp->link=front;
        front=temp;
    }
    else           //new node is added as usually we add a node into queue if the priority of the new node is lower(i.e value of pr will be higher).
    {
        q=front;
        while(q->link!=NULL && (q->link->pr)<=(temp->pr)) //2 conditions is to make sure that ,if we add a node with priority same as an already present node,the first node added will have the highest priority.
        {
            q=q->link;
        }
        temp->link=q->link;
        q->link=temp;
        return;
    }
}
void display()
{
    if(front==NULL)
    {
        printf("empty queue\n");
    }
    struct node *p;
    p=front;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->link;
    }
    printf("\n");
    return;
}
void dequeue()
{
    if(front==NULL)
    {
    printf("queue underflow\n");
    return;
    }
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp=front;
    front=front->link;
    free(temp);
}