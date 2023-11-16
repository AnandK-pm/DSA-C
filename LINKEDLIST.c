//program to implement linked list
#include<stdio.h>
#include<stdlib.h>
struct node     //structure node is defined globally to create function traversal 
{
    int data;
    struct node *link;
}*head=NULL,*tail=NULL;
void createlist();
void traversal();
void search();
void insert(int);
void delete();
void reverse();
int main()
{
    int n,i,choice;
    struct node *temp; //notice that these are pointers to nodes ,not the node itself.
    while(1)
    {
    printf("\n1.create list\n2.traverse\n3.Search\n4.Add to empty list\n5.Add at the beginning\n6.Add at the end"
    "\n7.Add after node\n8.Add before node\n9.Add at position\n10.Delete\n11.Reverse\n12.Quit\n\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: createlist();  
                traversal();
                break;
        case 2: traversal();
                break;
        case 3: search();
                break;
        case 4: insert(-1);
                traversal();
                break;
        case 5: insert(1);
                traversal();
                break;
        case 6: insert(0);
                traversal();
                break;
        case 7: insert(2);
                traversal();
                break;
        case 8: insert(3);
                traversal();
                break;
        case 9: insert(4);
                traversal();
                break;
        case 10:delete();
                traversal();
                break;
        case 11:reverse();
                traversal();
                break;
        case 12: exit(1);
    }
    }
//printf("%d",tail->data); //observer that the tail points to the same data as before even after adding a new node at the end 
//printf("%d\n",head->data);//note that the content of head is not changed even after the function call .because the fucntion call is by value.
}
//traversal function
void createlist()
{
      printf("enter the number of nodes:");
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {
        temp=(struct node*)malloc(sizeof(struct node));
        if (temp == NULL) 
        {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        printf("enter the node element %d:",i+1);
        scanf("%d",&temp->data);
        temp->link=NULL;
        if(head==NULL)
        {
            head=temp;      //this statement actually makes the pointer head to point to the same node as temp points.it doesnt duplicate the node nor copies the content.notice head and temp are pointers to nodes ,not the node itself
        }                   
        else
        {
            tail->link=temp;
        }
        tail=temp;
      }     
}
void traversal()
{
    struct node *q;
    //struct node *ptr=head; //if not using function ,new pointer ptr must be used instead of head for traversing as updating head would lose the label of head pointer pointing to first node.
    printf("\nlinked list elements are:\n\n");
    q=head;
    while(q!=NULL)      //here it actually checks whether the head is a NULL pointer .we cant use the condition (head->link!=NULL) because the laast element in the linked list will not be printed (as head ->link =NULL for last element)
    {
    printf("%d\t",q->data);
    q=q->link;  //head pointer is incremented 
    }
    printf("\n\n");
}
//search function
void search()
{
    struct node *q;
    int el;
    printf("enter the element to be searched:");
    scanf("%d",&el);
 int pos=1;
 q=head;
 while(q!=NULL)
 {
    if(q->data==el)
    {
        printf("\nitem %d is found in the position:%d\n",el,pos);
        return;
    }
    q=q->link;
    pos+=1;
 }
 printf("item %d not found in the list\n",el);
}
//insert function
void insert(int index) //used doublee pointer to call the function by reference,since using single pointer will only manipulate the copy of head inside the function definition.
{
    struct node *temp;
    printf("enter the data to be inserted:");
    if(index==-1)
    {
        if(head==NULL)        //adding element to an empty list
        {
            temp=(struct node*)malloc(sizeof(struct node));
            scanf("%d",&temp->data);
            temp->link=NULL;
            head=temp;
            return;
        }
    }
    if(index==1)  //insertion at the beginning
    {
        temp=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&temp->data);
        temp->link=head;
        head=temp;
        return;
    }
    if(index==0) //insertion at the end //if we want the tail in main function to be updated as it pointing to the last node,a new function shoudl be created with tail passing as an argument
    {
        struct node *q;
        temp=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&temp->data);
        temp->link=NULL;
        q=head;
        while(q->link!=NULL)   //here we want to stop the iteration at the last node.i.e,once the q pointer reaches the node which have its link as NULL
        {
            q=q->link;
        }                       //q now points to the node which have its link as NULL
        q->link=temp;   
        q=temp;
        return; 
    }
    if(index==2) //insertion after a node
    {
        int item;
        struct node *q;
        temp=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&temp->data);
        printf("enter the element after which the new element is to be added: ");
        scanf("%d",&item);
        q=head;
        while(q->data!=item)
        {
            q=q->link;
        }
        temp->link=q->link;
        q->link=temp;
        return;
    }
    if(index==3)   //insertion before a node
    {
        int item;
        struct node *q;
        temp=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&temp->data);
        printf("enter the element before which the new element is to be added: ");
        scanf("%d",&item);
        q=head;
        while((q->link)->data!=item)
        {
            q=q->link;
        }
        temp->link=q->link;
        q->link=temp;
        return;
    }
    if(index==4) //insertion using position
    {
        int pos,trav=1;
        struct node *q;
        temp=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&temp->data);
        printf("enter the position at which element should be added:");
        scanf("%d",&pos);
        q=head;
        while(trav!=pos-1)
        {
            q=q->link;
            trav++;
        }
        temp->link=q->link;
        q->link=temp;
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
        head=(head)->link;
        return;
    }
    else
    {
    q=head;
    while(q->link!=NULL)
    {
        if((q->link)->data==d)
        {
            temp=q->link;
            q->link=temp->link;
            return;
        }
        q=q->link;
    }
    }
    printf("element not found\n");
}
void reverse()
{
    struct node *temp,*prev,*next;
    prev=NULL;
    temp=head;
    while(temp!=NULL)
    {
        next=temp->link;
        temp->link=prev;
        prev=temp;
        temp=next;
    }
    head=prev;
    return;
}




