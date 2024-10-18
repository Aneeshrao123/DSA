#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};
int isfull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr,int val)
{
    if(isfull(ptr))
    {
        printf("stack overfolow\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
        printf("value pushed succesfully\n");

    }
}
int isempty(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int pop(struct stack *ptr)
{
    if(isempty(ptr))
    {
        printf("stack is empty\n");
    }
    else{
        int value=ptr->arr[ptr->top];
        ptr->top--;
        return value;

    }
}

int peek(struct stack *ptr,int pos)
{
    if(pos<0||pos>ptr->top)
    {
        printf("invalid position");
    }
    else
    {
        int val=ptr->arr[pos];
        printf("value at positon %d is %d",pos,val);
    }
}
int main()
{
    struct stack * sp=(struct stack *) malloc(sizeof(struct stack));
    sp->size=5;
    sp->top=-1;
    sp->arr=(int*)malloc(sp->size*sizeof(int));
    push(sp,5);
    push(sp,5);
    push(sp,5);
    push(sp,5);
    peek(sp,2);
    

    
    return 0;





}
