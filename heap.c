//program to implement max heap using array
//parent nodes>child nodes
//root node indexed at 1,left and right child of a node at index i will be 2i and 2i+1.parent of node at i =floor(i/2)
//location 0 of the array is unaccessed
#include<stdio.h>
#include<stdlib.h>
int hsize=0;
void MAX_HEAPIFY(int arr[],int i)
{
    int largest=i;
    int l=2*i;
    int r=2*i+1;
    if(l<=hsize&& arr[l]>arr[i])
    {
        largest =l;
    }
    if(r<=hsize && arr[r]>arr[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        int temp=arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;
        MAX_HEAPIFY(arr,largest);
    }
}
void BUILD_HEAP(int arr[])
{
    for(int i=hsize/2;i>=1;i--)    //heapifying process only have to be started from hsize/2 since leaf nodes are already heapified and the last non leaf node will be located at hsize/2
    {
        MAX_HEAPIFY(arr,i);
    }
}
void display(int arr[])
{
    int i;
    if(hsize==0)
    {
      printf("heap is empty");
      return;
    }
    printf("The heap is: ");
    for(i=1;i<=hsize;i++)
    {
        printf("%d ",arr[i]);
    }
}
void insert(int arr[])
{
    int item,i;
    printf("enter the key to be inserted:");
    scanf("%d",&item);
    hsize+=1;
    arr[hsize]=item;
    for(i=hsize/2;i>=1;i--)
    {
        MAX_HEAPIFY(arr,i);
    }
}
void delete(int arr[])
{
    int temp=arr[1];
    arr[1]=arr[hsize];
    arr[hsize]=temp;
    hsize--;
    for(int i=hsize/2;i>=1;i--)
    {
        MAX_HEAPIFY(arr,i);
    }
}
void largest_value(int arr[])
{
    printf("largest key is:%d\n ",arr[1]);
}
int main()
{
    int c;
    while(1)
    {
        printf("\n1.Build Heap\n2.Display\n3.Insert\n4.Delete\n5.Largest key\n6.Quit\n");
        printf("\nenter a choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:int arr[30],i;
                   printf("enter the size of array:");
                   scanf("%d",&hsize);
                   for(i=1;i<=hsize;i++)
                   {
                      printf("enter the element %d:",i);
                      scanf("%d",&arr[i]);
                   }
                   BUILD_HEAP(arr);
                   break;
            case 2:display(arr);
                   break;
            case 3:insert(arr);
                   break;
            case 4:delete(arr);
                   break;
            case 5:largest_value(arr);
                   break;
            case 6:exit(1);
        }
    }
}