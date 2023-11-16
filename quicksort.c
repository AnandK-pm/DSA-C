#include<stdio.h>
int partition(int arr[],int p,int r)
{
    int i=p-1;
    int k=arr[r];  //temporary pivot
    for(int j=p;j<r;j++)
    {
        if(arr[j]<k)
        {
            i=i+1;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int s=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=s;
    return i+1;
}
void quicksort(int arr[],int p,int r)
{
    if(p<r)
    {
        int q=partition(arr,p,r);
        quicksort(arr,p,q-1);
        quicksort(arr,q+1,r);
    }
}
int main()
{
    int arr[30],n;
    printf("enter the number of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter the element %d:",i+1);
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}