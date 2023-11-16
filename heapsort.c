//heapsort and binary search an element in the sorted array
//array indexing is from 1 to hsize
#include<stdio.h>
void max_heapify(int arr[],int i,int hsize)
{
    int left=2*i;                    
    int right=2*i+1;
    int largest=i;
    if(left<=hsize && arr[left]>arr[i])
    {
        largest=left;
    }
    if(right<=hsize && arr[right]>arr[largest])
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
    for(int i=hsize/2;i>=1;i--)
    {
        max_heapify(arr,i,hsize);
    }
}
void heapsort(int arr[],int hsize)
{

    build_maxheap(arr,hsize);
    for(int i=hsize;i>1;i--)
    {
        int temp=arr[1];
        arr[1]=arr[i];
        arr[i]=temp;
        hsize=hsize-1;
        max_heapify(arr,1,hsize);
    }
}
int binary_search(int arr[],int a,int b,int target)
{
    if(a>b)   //element not found
    return -1;
    int c=a+(b-a)/2;  //midpoint
    if(arr[c]==target)
    return c;
    else if(arr[c]>target)
    return binary_search(arr,a,c-1,target);
    else 
    return binary_search(arr,c+1,b,target);
}
int main()
{
    int n,arr[30];
    printf("enter the number of elements:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("enter the element %d: ",i);
        scanf("%d",&arr[i]);
    }
    heapsort(arr,n);
    printf("\nThe sorted list is\n");
    for(int i=1;i<=n;i++)
    {
        printf("%d ",arr[i]);
    }
    int target;
    printf("\nEnter the target: ");
    scanf("%d",&target);

    int pos = binary_search(arr,1,n,target);

    if (pos!=-1) 
    {
        printf("Target %d found at position %d.\n",target,pos);
    } 
    else 
    {
        printf("Target %d not found in the array.\n",target);
    }
}
