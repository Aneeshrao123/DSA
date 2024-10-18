#include<stdio.h>
#include<stdlib.h>
#define MAX 50
struct node{
    char info;
    struct node*left;
    struct node*right;
};
struct node*root=NULL;
struct stack{
    struct node *s[MAX];
    int top=-1;
};
int push(struct stack *ps,int e)
{
    if(ps->top==MAX-1)
    return 0;
    ps->top++;
    ps->s[ps->top]=e;
    return 1;
}
struct node *pop(struct stack *ps)
{
   
    struct node*t=ps->s[ps->top];
    ps->top--;
    return t;
}
int main()
{
    int i;
    char postfix[MAX];
    struct node*temp;
    struct stack obj;
    printf("Enter postfix expression");
    scanf("%s",postfix);
    while(postfix[i]!='\0')
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->info=postfix[i];
        temp->left=NULL;
        temp->right=NULL;
        if(isdigit(postfix[i]))
        push(&obj,temp);
        else{
            temp->right=pop(&obj);
            temp->left=pop(&obj);
            push(&obj,temp);
        }
        i++;

    }
    obj.

}




