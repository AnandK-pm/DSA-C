//program to implement graph using adjacent matrix and perform BFS  on it
//for BFS a status array and a queue is maintained and updated everytime and continues until the queue becomes empty
#include<stdio.h>
#include<stdlib.h>
int adjmat[100][100],n;
int front=-1,rear=-1;
int queue[30];
int MAX=30;
void create_graph()
{
    int i,j,choice,max_edges;
    printf("Press 1 for undirected graph and 2 for directed graph:");
    scanf("%d",&choice);
    printf("enter the number of vertices:");
    scanf("%d",&n);
    if(choice==1)
    max_edges=n*(n-1)/2;   //maximum edges for undireccted graphs
    else
    max_edges=n*(n-1);    //maximum edges for directed graphs
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)     //every element in matrix is made 0
        {
            adjmat[i][j]=0;   
        }
    }
    for(i=0;i<max_edges;i++)
    {
        int org,dest;        //origin and destination of the arrow.
        printf("enter the edge %d(press -1,-1 to stop):",i+1);
        scanf("%d %d",&org,&dest);
        if(org==-1 && dest==-1)
        break;
        adjmat[org][dest]=1;
        if(choice==1)
        adjmat[dest][org]=1;       //if undirected graph,the edge is two way

    }
}
void display()
{
    printf("The adjacency matrix is:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",adjmat[i][j]);
        }
        printf("\n");
    }
}
void insert_queue(int d)     //queue
{
     if(rear==MAX-1)
    {
        printf("queue overflow");
        return;
    }
    if(front==-1)
    {
        front++;
        rear++;
        queue[rear]=d;
    }
    else
    {
        rear++;
        queue[rear]=d;
        return;
    }
} 
int delete_queue()              //queue
{
    if(front>rear)
    {
        printf("queue underflow");
        exit(1);
    }
    int del_item=queue[front];
    front++;
    return del_item;
}
int isempty_queue()         //queue
{
    if(front==-1 || front>rear)
    return 1;
    else return 0;
}
void BFS()       //BREADTH FIRST SEARCH
{
    int status[n],v;
    for(int i=0;i<n;i++)
    {
        status[i]=0;        //status of every vertex is made 0
    }
    printf("enter the starting vertex:");
    scanf("%d",&v);
    insert_queue(v);           
    while(!isempty_queue())    //continues until the queue becomes empty
    {
        v=delete_queue();     //v is updated with the new deleted element every time
        if(status[v]==0)
        {
        status[v]=1;
        printf("%d ",v);
        for(int i=0;i<n;i++)
        {
            if(adjmat[v][i]==1 && status[i]==0)   //checked whether i is an adjacent vertex of v and i is unvisited
            {
                insert_queue(i);
            }
        }
        }
    }
}
int main()
{
    int c;
    while(1)
    {
        printf("\n1.Create Graph\n2.Display Adj matrix\n3.BFS\n4.Quit\n");
        printf("\nenter a choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:create_graph();
                   break;
            case 2:display();
                   break;
            case 3:BFS();
                   break;
            case 4:exit(1);
        }
    }
} 