#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i;
    struct node
    {
        int data;
        struct node *link;
    }*ptr,*q;
    printf("enter the number of nodes:");
    scanf("%d",&n);
    ptr=(struct node*)malloc(n*sizeof(struct node));
    for(i=0;i<n;i++)
    {
        printf("enter the node element %d:",i+1);
        scanf("%d",&(ptr+i)->data);
        if(i==n-1)
        (ptr+i)->link=NULL;
        else
        (ptr+i)->link=(ptr+i+1);    //this approach of incrementing pointer is not welcomed in all envs.so look at linkedlist1.c for proper implementation and traversal of linkedlist
    }

while(ptr!=NULL)
{
    printf("%d\n",ptr->data);
    ptr=ptr->link;
}

}