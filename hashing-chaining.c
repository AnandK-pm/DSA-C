//program to implement a hash table using sepeerate chaining
#include<stdio.h>
#include<stdlib.h>
#include<string.h> //string.h is included as the value passed with the key is a string and strcpy must be used to copy the content
# define Tsize 10

struct node 
{
    int key;
    char value[30];
    struct node *link;
};

struct hash_table              //structure of hash table of size 10
{
    struct node *table[Tsize]; //array of pointers of type struct node
};

void initialize(struct hash_table *hashtable)  //it will be pass by value if you define the parameter as (struct hash_table hashtable and only a copy of hashtable can be modified.no modifications will be done to the hashtable in main function)
{//pointer to the structure hashtable to pass by reference and hence modifying the hashtable itself 
    for(int i=0;i<Tsize;i++)
    {
        hashtable->table[i]=NULL;
    }
}

int hash_func(int key)
{
    return key % 10;
}

void insertHash(struct hash_table *hashtable,int key,char value[])
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->key=key;
    strcpy(newnode->value, value);
    newnode->link=NULL;
    int index=hash_func(key);
    if(hashtable->table[index]==NULL)
    {
        hashtable->table[index]=newnode;
    }
    else
    {
        struct node *q;
        q=hashtable->table[index];
        while(q->link!=NULL)
        {
            q=q->link;
        }
        q->link=newnode;
    }
}

int searchHash(struct hash_table *hashtable,int item_key)
{
    int index=hash_func(item_key);
    struct node *q;
    q=hashtable->table[index];
    while(q!=NULL)
    {
        if(q->key==item_key)
        return index;
        q=q->link;
    }
    return -1;
}

void deleteHash(struct hash_table*hashtable,int item_key)
{
    struct node *temp,*q;
    int index=hash_func(item_key);
    if(hashtable->table[index]==NULL)
    {
        printf("Key not found\n");
        return;
    }
    if(hashtable->table[index]->key==item_key)
    {
        temp=hashtable->table[index];
        hashtable->table[index]=hashtable->table[index]->link;
        free(temp);
        return;
    }
    q=hashtable->table[index];
    while(q!=NULL)
    {
        if(q->link->key==item_key)
        {
            q->link=q->link->link;
        }
        q=q->link;
    }
    printf("key not found\n");
}

void displayHash(struct hash_table *hashtable)
{
    for(int i=0;i<Tsize;i++)
    {
        printf("[%d] ",i);
        struct node *q;
        q=hashtable->table[i];
        while(q!=NULL)
        {
            printf("(%d, %s) -> ",q->key,q->value);
            q=q->link;
        }
        printf("\n");
    }
}

int main()
{
    struct hash_table myHashTable;
    initialize(&myHashTable);
    while(1)
    {
        int c,key;
        printf("\n\n1.Insert a record\n2.Search a record\n3.Delete a record\n4.Display hash table\n5.Quit\n");
        printf("\nenter your choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1: char val[30];
                    printf("enter the key and value:");
                    scanf("%d %s",&key,val);
                    insertHash(&myHashTable,key,val);
                    break;
            case 2: printf("enter the key to be searched:");
                    scanf("%d",&key);
                    int p=searchHash(&myHashTable,key);
                    printf("\nthe key %d is at index %d\n",key,p);
                    break;
            case 3: printf("enter the key to be deleted:");
                    scanf("%d",&key);
                    deleteHash(&myHashTable,key);
                    break;
            case 4: printf("\nThe hash table:\n\n");
                    displayHash(&myHashTable);
                    break;
            case 5: exit(1);
        }

    }
}