//conversion of infix expression to postfix
#include<stdio.h>
#include<string.h>
void push(char);
char pop();
char isop(char);
int precedence(char);
char infix[20];
char stack[20];
char postfix[20];
int top=-1;
int main()
{
int i,j;
printf("enter the expression:");
fgets(infix,20,stdin);
int p=0;
for(i=0;i<strlen(infix);i++)
{
    if(infix[i]=='(')
    {
        push(infix[i]);
    }
    else if(infix[i]==')')
    {
        while(stack[top]!='(')
        {
            postfix[p++]=pop();
        }
        pop();
    }
    else if(isop(infix[i]))
    {
        if(top==-1)
        {
            push(infix[i]);
        }
        else if(precedence(stack[top]>=precedence(infix[i])))
        {
            while(precedence(stack[top])>=precedence(infix[i]))
            {
            postfix[p++]=pop();
            }
            push(infix[i]);
        }
        else
        push(infix[i]);
    }
    else
    {
      postfix[p++]=infix[i];
    }
}
for(i=0;i<strlen(stack);i++)
printf("%c\t",stack[i]);
printf("\n");
for(i=0;i<strlen(postfix);i++)
printf("%c\t",postfix[i]);
}
void push(char c)
{
 top+=1;
 stack[top]=c;
}
char pop()
{
if(top==-1)
{
printf("queue underflow");
}
else
return(stack[top--]);
}
char isop(char c)
{
 return(c=='/'||c=='*'||c=='+'||c=='-'||c=='^');
}  
int precedence(char c)
{
 if(c=='(')
 return 0;
 else if(c=='+'||c=='-')
 return 1;
 else if(c=='/'||c=='*')
 return 2;
 else if(c=='^')
 return 3;
 else
 return -1;
}
