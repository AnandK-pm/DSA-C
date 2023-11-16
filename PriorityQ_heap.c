//program to implement priority queue using max heap
//node with highest priority value will be deleted first
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int priority;
};
int hsize=0;
void MAX_HEAPIFY(struct node arr[],int i)
{
    int largest=i;
    int l=2*i;
    int r=2*i+1;
    if(l<=hsize&& arr[l].priority>arr[i].priority)
    {
        largest =l;
    }
    if(r<=hsize && arr[r].priority>arr[largest].priority)
    {
        largest=r;
    }
    if(largest!=i)
    {
        int temp=arr[largest].data;
        arr[largest].data=arr[i].data;
        arr[i].data=temp;
        int temp1=arr[largest].priority;
        arr[largest].priority=arr[i].priority;
        arr[i].priority=temp1;
        MAX_HEAPIFY(arr,largest);
    }
}
void BUILD_HEAP(struct node arr[])
{
    for(int i=hsize/2;i>=1;i--)    //heapifying process only have to be started from hsize/2 since leaf nodes are already heapified and the last non leaf node will be located at hsize/2
    {
        MAX_HEAPIFY(arr,i);
    }
}
void display(struct node arr[])
{
    int i;
    if(hsize==0)
    {
      printf("heap is empty");
      return;
    }
    printf("The heap is: \n");
    for(i=1;i<=hsize;i++)
    {
        printf("%d : %d\n",arr[i].data,arr[i].priority);
    }
}
void insert(struct node arr[])
{
    int item,i,pr;
    printf("enter the key to be inserted:");
    scanf("%d",&item);
    printf("enter its priority:");
    scanf("%d",&pr);
    hsize+=1;
    arr[hsize].data=item;
    arr[hsize].priority=pr;
    for(i=hsize/2;i>=1;i--)
    {
        MAX_HEAPIFY(arr,i);
    }
}
void delete(struct node arr[])
{
    int temp=arr[1].data;
    arr[1].data=arr[hsize].data;
    arr[hsize].data=temp;
    int temp1=arr[1].priority;
    arr[1].priority=arr[hsize].priority;
    arr[hsize].priority=temp1;
    hsize--;
    for(int i=hsize/2;i>=1;i--)
    {
        MAX_HEAPIFY(arr,i);
    }
}
void highest_priority(struct node arr[])
{
    printf("highest proirity key is:%d with priority %d\n ",arr[1].data,arr[1].priority);
}
int main()
{
    int c;
    while(1)
    {
        printf("\n1.Create Queue\n2.Display\n3.Insert\n4.Delete\n5.Highest priority key\n6.Quit\n");
        printf("\nenter a choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:struct node arr[30];
                   int i;
                   printf("enter the size of array:");
                   scanf("%d",&hsize);
                   for(i=1;i<=hsize;i++)
                   {
                      printf("enter the element %d and its priority:",i);
                      scanf("%d %d",&arr[i].data,&arr[i].priority);
                   }
                   BUILD_HEAP(arr);
                   break;
            case 2:display(arr);
                   break;
            case 3:insert(arr);
                   break;
            case 4:delete(arr);
                   break;
            case 5:highest_priority(arr);
                   break;
            case 6:exit(1);
        }
    }
}