//Implementation of binary search tree-insertion,deletion,searching,number of leaf nodes.
#include<stdio.h>
#include<stdlib.h>
struct node 
{
    struct node *lchild;
    int data;
    struct node *rchild;
}*root=NULL;
void insert();
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);
int get_leafcount(struct node *);
void search();
void delete();
int main()
{
    int choice;
    while(1)
    {
    printf("\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Search\n6.Delete\n7.Count leaf nodes\n8.Quit\n");
    printf("\nenter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:insert();
               break;
        case 2:preorder(root);
               break;
        case 3:inorder(root);
               break;
        case 4:postorder(root);
               break;
        case 5:search();
               break;
        case 6:delete();
               break;
        case 7:int l=get_leafcount(root);
               printf("number of leaf nodes:%d\n",l);
               break;
        case 8:exit(1);
    }
    }

}
void insert()
{
    int item;
    printf("\nenter the key to be inserted:");
    scanf("%d",&item);
    struct node *newnode,*q,*p=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->lchild=NULL;
    newnode->rchild=NULL;
    if(root==NULL)
    { 
        root=newnode;
        return;
    }
    q=root;
    while(q!=NULL)
    {
        p=q; //p is preserved as last node as q might become NULL in the updation.
        if(q->data>item )
        q=q->lchild;
        else if(q->data<item)
        q=q->rchild;
        else
        {
        printf("duplicates are not allowed\n");
        insert();
        return;
        }
    }
    if(p->data>item)
    p->lchild=newnode;
    else
    p->rchild=newnode;
}
void preorder(struct node *ptr)
{
    if(ptr==NULL)
    return;
    printf("%d\t",ptr->data);
    printf("\t");
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
void search()
{
    int item;
    printf("enter the key to be searched:");
    scanf("%d",&item);
    struct node *q;
    q=root;
    while(q!=NULL)     
    {
        if(q->data>item )
        q=q->lchild;
        else if(q->data<item)
        q=q->rchild;
        else
        {
        printf("\n%d is found\n",q->data);
        return;
        }
    }
    printf("\nkey not found");
}
void delete()
{
    struct node *q,*parent=NULL;
    int item;
    printf("enter the key to be deleted:");
    scanf("%d",&item);
    q=root;
    while(q!=NULL)     //this while loop finds the node to be deleted and makes a pointer q points to it
    {   
        if(q->data==item)
        break;              //parent node in p is preserved
        parent=q;                //parent node of the node to be deleted.remains NULL if root node is the node to be deleted.
        if(q->data>item)
        q=q->lchild;
        else if(q->data<item)
        q=q->rchild;
    }
    if (q->lchild == NULL) //the condition for leaf node is also satisfied 
    {
        if (parent == NULL)    //if root node is to be deleted
        {
            root = q->rchild;
        } 
        else if (parent->lchild == q) //checks whether the node to be deleted is the left child of its parent //when given condition (if(p->lchild->data==item) the program execution stops since in the given example the parent node has no lchild .when it tries to access the data of lchild,it becomes invalid and stops execution.so an extra comdition p->lchild!=NULL is given first so that it wont check the data of lchild if lchild is null in the first place
        {
            parent->lchild = q->rchild;
        } 
        else                            //checks whether the node to be deleted is the right child of the parent.
        {
            parent->rchild = q->rchild;
        }
        free(q);
    } 
    else if (q->rchild == NULL) 
    {
        if (parent == NULL)  //since root node will not have any parent.
        {
            root = q->lchild;
        } 
        else if (parent->lchild == q) 
        {
            parent->lchild = q->lchild;
        }
        else 
        {
            parent->rchild = q->lchild;
        }
        free(q);
    }
    else  //if the node to be deleted have both the children,then the node to be deleted is replaced with its inorder successor and inorder successor is deleted from the tree.
    {                        //inorder successor will not have lchild.
       struct node *succ,*parsucc=NULL,*child; //successor and parent of the successor.
       succ=q->rchild;              //to find the inorder successor of a node ,move to the right child of the node to be deleted and move left until there is no left child.
       while(succ->lchild!=NULL)
       {
        parsucc=succ;
        succ=succ->lchild;
       }
       q->data=succ->data;    //node data to be deleted is replaced with successor data
       child=succ->rchild;    //preserving the rchild ,if any,of the successor node that is to be deleted,so that it can be linked with the parent node.succ->rchild will be NULL if it has no right child.
       if(parsucc!=NULL)    //checks whether the successor node is the direct right child of the node q to be deleted  
       parsucc->lchild=child;     
       else                      //if parsucc is NULL it means succ=q->rchild,so q->rchild is updated with succ->rchild
       q->rchild=child;
    }
}
int get_leafcount(struct node *ptr)
{
    if(ptr==NULL)
    return 0;
    if(ptr->lchild==NULL && ptr->rchild==NULL)
    return 1;
    int leftcount=get_leafcount(ptr->lchild);
    int rightcount=get_leafcount(ptr->rchild);
    return leftcount+rightcount;
}
