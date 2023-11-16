//program to demonstrate doubly linked list.
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link1;
    struct node *link2;
}*head=NULL;
void createlist();
void insert(int);
void delete();
void display();
int main()
{
    int n,i,choice;
    struct node *temp; //notice that these are pointers to nodes ,not the node itself.
    while(1)
    {
    printf("\n1.create list\n2.display\n3.Add to empty list\n4.Add at the beginning\n5.Add at the end"
    "\n6.Add after node\n7.Add before node\n8.Add at position\n9.Delete\n10.Quit\n\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: createlist();  
                display();
                break;
        case 2: display();
                break;
        case 3: insert(-1);
                display();
                break;
        case 4: insert(1);
                display();
                break;
        case 5: insert(0);
                display();
                break;
        case 6: insert(2);
                display();
                break;
        case 7: insert(3);
                display();
                break;
        case 8: insert(4);
                display();
                break;
        case 9: delete();
                display();
                break;
        case 10: exit(1);
    }
    }
}
void createlist()
{
    int i,n,d;
    printf("enter the number of nodes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        struct node *temp,*q;
        temp=(struct node*)malloc(sizeof(struct node));
        printf("enter the element %d:",i+1);
        scanf("%d",&d);
        if(head==NULL)
        {
            temp->link1=NULL;
            temp->data=d;
            temp->link2=NULL;
            head=temp;
        }
        else
        {
            temp->data=d;
            temp->link2=NULL;
            q=head;
            while(q->link2!=NULL)
            {
                q=q->link2;
            }
            q->link2=temp;
            q->link2->link1=q;
        }
    }
}
void display()
{
    struct node *q;
    q=head;
    while(q!=NULL)
    {
        printf("%d\n",q->data);
        q=q->link2;
    }
}
void insert(int index) 
{
    int d;
    struct node *temp;
    printf("enter the data to be inserted:");
    scanf("%d",&d);
    if(index==-1)
    {
        if(head==NULL)        //adding element to an empty list
        {
            temp=(struct node*)malloc(sizeof(struct node));
            scanf("%d",&temp->data);
            temp->link1=NULL;
            temp->data=d;
            temp->link2=NULL;
            head=temp;
            return;
        }
    }
    if(index==1)  //insertion at the beginning
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=d;
        temp->link1=NULL;
        temp->link2=head;
        head->link1=temp;
        head=temp;
        return;
    }
    if(index==0) //insertion at the end //if we want the tail in main function to be updated as it pointing to the last node,a new function shoudl be created with tail passing as an argument
    {
        struct node *q;
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=d;
        temp->link2=NULL;
        q=head;
        while(q->link2!=NULL)   //here we want to stop the iteration at the last node.i.e,once the q pointer reaches the node which have its link as NULL
        {
            q=q->link2;
        }                       //q now points to the node which have its link as NULL
        q->link2=temp;   
        q->link2->link1=q;
        return; 
    }
    if(index==2) //insertion after a node
    {
        int item;
        struct node *q;
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=d;
        printf("enter the element after which the new element is to be added: ");
        scanf("%d",&item);
        q=head;
        while(q->data!=item)
        {
            q=q->link2;
        }
        temp->link2=q->link2;
        temp->link1=q;
        q->link2=temp;
        return;
    }
    if(index==3)   //insertion before a node
    {
        int item;
        struct node *q;
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=d;
        printf("enter the element before which the new element is to be added: ");
        scanf("%d",&item);
        q=head;
        while((q->link2)->data!=item)
        {
            q=q->link2;
        }
        temp->link2=q->link2;
        temp->link1=q;
        q->link2=temp;
        return;
    }
    if(index==4) //insertion using position
    {
        int pos,trav=1;
        struct node *q;
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=d;
        printf("enter the position at which element should be added:");
        scanf("%d",&pos);
        q=head;
        while(trav!=pos-1)
        {
            q=q->link2;
            trav++;
        }
        temp->link2=q->link2;
        temp->link1=q;
        q->link2=temp;
        return;
    }
    
}
//deletion function
void delete()
{
    int d;
    struct node *q,*temp;
    printf("enter the data to be deleted:");
    scanf("%d",&d);
    if((head)->data==d)
    {
        head=(head)->link2;
        return;
    }
    else
    {
    q=head;
    while(q->link2!=NULL)
    {
        if((q->link2)->data==d)
        {
            temp=q->link2;
            q->link2=temp->link2;
            return;
        }
        q=q->link2;
    }
    }
    printf("element not found\n");
}
