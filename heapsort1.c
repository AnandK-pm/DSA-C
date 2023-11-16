//program to heapsort an array
//array indexing is from 0 to hsize-1
#include<stdio.h>
void max_heapify(int arr[],int i,int hsize)
{
    int left=2*i+1;        
    int right=2*i+2;
    int largest=i;
    if(left<hsize && arr[left]>arr[i])
    {
        largest=left;
    }
    if(right<hsize && arr[right]>arr[largest])
    {
        largest=right;
    }
    if(i!=largest)
    {
        int temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        max_heapify(arr,largest,hsize);
    }
}
void build_maxheap(int arr[],int hsize)
{
    for(int i=(hsize)/2+1;i>=0;i--)
    {
        max_heapify(arr,i,hsize);
    }
}
void heapsort(int arr[],int hsize)
{

    build_maxheap(arr,hsize);
    for(int i=hsize-1;i>0;i--)
    {
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        hsize=hsize-1;
        max_heapify(arr,0,hsize);
    }
}
int main()
{
    int n,arr[30];
    printf("enter the number of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter the element %d:",i);
        scanf("%d",&arr[i]);
    }
    heapsort(arr,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
