#include<stdio.h>
#include<stdlib.h>
struct stack{
    int top;
    int size;
    char *arr
};
int isoperator(char ch)
{
    if(ch=='+'||ch=='-'||ch=='/'||ch=='*')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty(struct stack *ptr)
{
    if(ptr->top=-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int precedence(char ch)
{
    if(ch=='+'||ch=='-')
    {
        return 2;
    }
    if(ch=='*'||ch=='/')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}
char stack_top(struct stack *sp)
{
    return sp->arr[sp->top];
}
void push(struct stack *sp,char ch)
{
    if(sp->top==sp->size-1)
    {
        printf("stack is full\n");
    }
    sp->top++;
    sp->arr[sp->top]=ch;

}
char * infixtopostfix(char *infix)
{
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
    sp->top=-1;
    sp->size=strlen(infix);
    sp->arr=(char*)malloc(sizeof(char)*sp->size);
    char *postfix = (char*)malloc(sizeof(char)*strlen(infix)+1);
    int i=0;
    int j=0;
    while(infix[i]!='\0')
    {
        if(!isoperator(infix[i]))
        {
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else
        {
            if(isempty(sp)||precedence(infix[i])>precedence(stack_top(sp)))
            {
                push(sp,infix[i]);

            }
        }
    }
}
int main()
{
    char infix[100];
    printf("Enter infix expression\n");
    scanf("%s",infix);
    printf("postfix expression is: %s",infixtopostfix(infix));

    
}