//program to implement graph traversal using adjacent matrix and perform DFS on it
//for DFS a status array and a stack is maintained and updated everytime and continues until the stack becomes empty
#include<stdio.h>
#include<stdlib.h>
int adjmat[100][100],n;
int top=-1;
int stack[30];
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
void push(int data)  //STACK
{
    if(top==MAX-1)
    {
        printf("stack overflow");
        return;
    }
    top+=1;
    stack[top]=data;
}
int pop()   //stack
{
  if(top==-1)
  {
    printf("stack underflow");
    exit(1);
  }
  int popped_item=stack[top];
  top--;
  return popped_item;
}
int isempty_stack()   //stack
{
    if(top==-1)
    return 1;
    else return 0;
}
void DFS()   //DEPTH FIRST SEARCH
{
    int v,status[n],i;
    for(int i=0;i<n;i++)
    {
        status[i]=0;
    }
    printf("enter the starting vertex:");
    scanf("%d",&v);
    push(v);
    while(!isempty_stack())     //continues until the stack becomes empty
    {
        v=pop();               //v is updated with the new popped element every time
        if(status[v]==0)
        {
        status[v]=1;
        printf("%d ",v);
        for(i=n-1;i>=0;i--)           //the successors of vertex are visited in descending order so that the final output will be in an ascending order.(because stack follows LIFO principle)
        {
            if(adjmat[v][i]==1 && status[i]==0)
            {
                push(i);
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
        printf("\n1.Create Graph\n2.Display Adj matrix\n3.DFS\n4.Quit\n");
        printf("\nenter a choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:create_graph();
                   break;
            case 2:display();
                   break;
            case 3:DFS();
                   break;
            case 4:exit(1);
        }
    }
} 