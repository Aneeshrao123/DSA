#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* insert_head(struct node *head,int data)
{
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}

struct node*insert_end(struct node*head,int data)
{
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    struct node*p;
    ptr->data=data;
    
    if(head==NULL)
    {
       return ptr;
    }
    while(ptr->next!=NULL)
    {
        p=p-> next;
    }
    ptr->next=NULL;
    p->next=ptr;
    return head;
}
struct node*insert_pos(struct node*head,int data,int index)
{
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    struct node*p;
    ptr->data=data;
    if(index<0)
    {
        printf("Invalid index\n");
    }
    while(p!=NULL)
    {
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
    }
    ptr->next=p->next;
    p->next=ptr;
    return ptr;
}
    
struct node* delete_end(struct node*head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    struct node *p=head;
    struct node *q=head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;

    }
    p->next=NULL;
    free(q);
    return head;
}
struct node*delete_beg(struct node*head)
{
   if(head==NULL)
    {
        printf("List is empty\n");
    }
    struct node*ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
struct node*delete_index(struct node *head,int index)
{

}
int main()
{
    struct node *head=NULL;
    int ch,ele,pos;
    printf("1...insert at head\n");
    printf("2...insert at end\n");
    printf("3...insert at index\n");
    printf("4...delete from end\n");
    printf("5...delete at beginning\n");
    printf("6...delete at index\n");
    printf("7...delete at value\n");
    printf("8...display\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: 
        printf("Enter the element to be inserted at beginning\n");
        scanf("%d",&ele);
        head=insert_head(head,ele);
        break;
        case 2:
        printf("Enter element to be inserted at end\n");
        scanf("%d", ele);
        head=insert_end(head,ele);
        break;
        case 3:
        printf("Enter element to be inserted and index\n");
        scanf("%d %d",ele,pos);
        head=insert_pos(head,ele,pos);
        break;
        case 4:
        head=delete_end(head);
        break;
        case 5:
        head=delete_beg(head);
        case 6:
        
        









    }



}