#include<stdio.h>
#include<stdlib.h>
struct stack{
    int top;
    int size;
    int * arr;
};
int isempty(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
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
int main()
{
    struct stack *s;
    s->arr=(int*)malloc(s->size*sizeof(struct stack));
    s->top=-1;
    s->size=80;
    s->arr[0]=7;
    s->top++;
    if(isempty(s))
    {
        printf("stack is empty\n");
    }
    else{
        printf("stack is not empty\n");
    }
    if(isfull(s))
    {
        printf("stack is full\n");
    }
    else{
        printf("Stack is not full\n");
    }
    return 0;


}