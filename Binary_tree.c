//implementation of binary tree using tail recursion,linked list.
#include<stdio.h>
#include<stdlib.h>
struct node 
{
    struct node *lchild;
    int data;
    struct node *rchild;
}*root=NULL;
void preorder(struct node*);
void postorder(struct node*);
void inorder(struct node*);
struct node* create();             //create function returns a pointer to struct node type 
int main()
{
    root=create();               //root pointer now points to that location where temp points,where temp points to the last node after all the recursions
    printf("\n");
    printf("Preorder:\n");
    preorder(root);
    printf("\n");
    printf("Inorder:\n");
    inorder(root);
    printf("\n");
    printf("Postorder:\n");
    postorder(root);
    printf("\n");
}
struct node* create()
{
    int d;
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data:");
    scanf("%d",&d);
    temp->data=d;
    if(d==-1)                      //base case 
    return 0;
    else
    {
        printf("enter the left child of %d\n:",d);
        temp->lchild=create();
        printf("enter the right child of %d\n:",d);
        temp->rchild=create();
        return temp;
    }

}
void preorder(struct node *ptr)
{
    if(ptr==NULL)
    return;
    printf("%d\t",ptr->data);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}
void inorder(struct node *ptr)
{
    if(ptr==NULL)
    return;
    inorder(ptr->lchild);
    printf("%d\t",ptr->data);
    inorder(ptr->rchild);
}
void postorder(struct node *ptr)
{
    if(ptr==NULL)
    return;
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf("%d\t",ptr->data);
}



