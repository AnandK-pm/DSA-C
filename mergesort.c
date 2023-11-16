#include<stdio.h>
void merge(int arr[],int p,int q,int r)
{
    int nl=q-p+1;
    int nr=r-q;
    int L[nl];
    int R[nr];
    for(int i=0;i<nl;i++)
    {
        L[i]=arr[p+i];

    }
    for(int j=0;j<nr;j++)
    {   
        R[j]=arr[q+j+1];
    }
int i=0;
int j=0;
int k=p;
while(i<nl && j<nr)
{
    if(L[i]>R[j])
    {
        arr[k++]=R[j++];
    }
    else
    {
        arr[k++]=L[i++];
    }
}
while(i<nl)
{
    arr[k++]=L[i++];
}
while(j<nr)
{
    arr[k++]=R[j++];
}
}
void merge_sort(int arr[],int p,int r)
{
    if(p>=r)
    return;
    int q=(p+r)/2;
    merge_sort(arr,p,q);
    merge_sort(arr,q+1,r);
    merge(arr,p,q,r);
}
int main()
{
    int arr[30],n;
    printf("enter the size of the array:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter the element %d",i+1);
        scanf("%d",&arr[i]);
    }
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
