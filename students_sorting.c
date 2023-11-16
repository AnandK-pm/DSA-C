#include <stdio.h>
#include <string.h>
struct student
{
    char name[30];
    float height;
    int weight;
};
void createfile(char filename[], struct student arr[], int size) 
{
    FILE* file = fopen(filename, "a+");
    for (int i = 0; i < size; i++) 
    {
        arr[i].name[strcspn(arr[i].name, "\n")] = '\0';
        fprintf(file, "%s %.2f %d\n", arr[i].name, arr[i].height, arr[i].weight);
    }
    fclose(file);
}
void merge(struct student arr[], int p, int q, int r) 
{
    int nl = q - p + 1;
    int nr = r - q;
    struct student L[nl];
    struct student R[nr];
    for(int i=0;i<nl;i++)
    {
        L[i]=arr[p+i];
    }
    for(int j=0;j<nl;j++)
    {
        R[j]=arr[q+j+1];
    }
    int i=0;
    int j=0;
    int k=p;
    while(i<nl && j<nr )
    {
        if(strcmp(L[i].name, R[j].name) < 0)
        {
            arr[k++]=L[i++];
        }
        else
        {
            arr[k++]=R[j++];
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
void merge_sort(struct student arr[],int p,int r)
{
    if(p>=r)
    return;
    int q=(p+r)/2;
    merge_sort(arr,p,q);
    merge_sort(arr,q+1,r);
    merge(arr,p,q,r);
}
int partition(struct student arr[],int p,int r)
{
    int i=p-1;
    struct student k=arr[r];  //temporary pivot
    for(int j=p;j<r;j++)
    {
        if(strcmp(arr[j].name, k.name) < 0)
        {
            i=i+1;
            struct student temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    struct student s=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=s;
    return i+1;
}
void quicksort(struct student arr[],int p,int r)
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
    int n;
    printf("enter the number of students:");
    scanf("%d", &n);
    getchar(); // Consume the newline character left in the buffer

    struct student s[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter the name of student %d: ", i + 1);
        fgets(s[i].name, sizeof(s[i].name), stdin);
        s[i].name[strcspn(s[i].name, "\n")] = '\0'; // Remove newline character
        printf("enter the height of student %d: ", i + 1);
        scanf("%f", &s[i].height);
        printf("enter the weight of student %d: ", i + 1);
        scanf("%d", &s[i].weight);
        getchar(); // Consume the newline character left in the buffer
    }

    char unsorted[] = "unsorted.txt";
    createfile(unsorted, s, n);

    char mergesorted[] = "mergesorted.txt";
    merge_sort(s, 0, n - 1);
    createfile(mergesorted, s, n);

    char quicksorted[] = "quicksorted.txt";
    quicksort(s, 0, n - 1);
    createfile(quicksorted, s, n);

    return 0;
}
