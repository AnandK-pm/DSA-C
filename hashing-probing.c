//program to implement a hash table using open addressing-linear probing
#include<stdio.h>
#include<stdlib.h>
#include<string.h> //string.h is included as the value passed with the key is a string and strcpy must be used to copy the content
#define Tsize 10

struct node
{
    int key;
    char value[30];
};
struct node hash_table[Tsize];

void initialize()
{
    for(int i=0;i<Tsize;i++)
    {
        hash_table[i].key=-1;
       strcpy(hash_table[i].value,"NULL");
    }
}

int hash_func(int key)
{
    return (key)%Tsize;
}

int linear_probe(int index)
{
    return (index+1)%Tsize;
}

void insertHash(int item_key,char value[])
{
    int attempt=1;
    int index=hash_func(item_key);
    while(hash_table[index].key!=-1 && attempt <= Tsize)
    {
        index=linear_probe(index);
        attempt++;
    }
    if (attempt > Tsize) 
    {
        printf("\nHash table overflow! Unable to insert (%d, %s)\n", item_key, value);
        return;
    }

    hash_table[index].key=item_key;
    strcpy(hash_table[index].value, value);
}

void displayHash()
{
    printf("\nHash Table:\n");
    for (int i = 0; i < Tsize; i++) 
    {
        printf("[%d]: (%d, %s)\n", i, hash_table[i].key, hash_table[i].value);
    }
    printf("\n");
}

int main()
{
    initialize(hash_table);
    while(1)
    {
        int c,key;
        printf("\n\n1.Insert a record\n2.Display hash table\n3.Quit\n");
        printf("\nenter your choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1: char val[30];
                    printf("enter the key and value:");
                    scanf("%d %s",&key,val);
                    insertHash(key,val);
                    break;
            case 2: printf("\nThe hash table:\n\n");
                    displayHash();
                    break;
            case 3: exit(1);
        }

    }
  /*insertHash(101, "John");
    insertHash(205, "Alice");
    insertHash(309, "Bob");
    insertHash(418, "Eva");
    insertHash(523, "Mike");
    insertHash(634, "Sara");
    insertHash(737, "Tom");
    insertHash(842, "Emma");
    insertHash(954, "Alex");
    insertHash(1065, "Sophia");
    insertHash(1177, "David");
    insertHash(1288, "Grace");
    displayHash();         */  //input sample to check

}