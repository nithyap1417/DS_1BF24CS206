#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
int stack[MAX];
int top=-1;
void push(char x)
{
    if(top==(MAX-1))
        printf("Stack overflow");
    else
    {
        top++;
        stack[top]=x;
    }
}
char pop()
{
    if(top==-1){
    printf("Stack underflow");
    return -1;}
    else
    {
        char ch= stack[top];
        top--;
        return ch;
    }
}
char peek()
{
    if(top==-1){
        printf("Stack underflow");
        return -1;}
    else
        return stack[top];
}
int precedence(char op)
{
    switch(op)
    {
        case '+':
        case '-':
          return 1;
        case '*':
        case '/':
          return 2;
        case '^':
          return 3;
        case '(':
          return 0;
    }
    return -1;
}
int associativity(char op)
{
    if(op=='^')
        return 1;
    
    else
        return 0;
    
}
void infixTOpostfix(char infix[],char postfix[])
{
    int i=0,k=0;
    char c;
    for(i=0;infix[i]!='\0';i++)
    {
        c=infix[i];
        if(isalnum(c))
            postfix[k++]=c;
        else if(c=='(')
            push(c);
        else if(c==')')
        {
            while(peek()!='(')
            {
                postfix[k++]=pop();
            }
            pop();
        }
        else
        {
            while(top!=-1 && (precedence(peek())>precedence(c) || precedence(peek())==precedence(c) && associativity==0))
            {
                postfix[k++]=pop();
            }
            push(c);
        }
    }
    while(top!=-1)
    {
        postfix[k++]=pop();
    }
    postfix[k]='\0';
}
    
int main()
{
    char infix[MAX];
    char postfix[MAX];
    printf("Enter Infix Expression: ");
    scanf("%s",infix);
    infixTOpostfix(infix,postfix);
    printf("Postfix expression is %s",postfix);
    return 0;
}