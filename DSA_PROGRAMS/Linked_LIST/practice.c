#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct  node* next;
};
void printLL(struct node * ptr)
{
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }

}
struct node * insertatbeginning(struct node* head,int data)
{
    struct node* ptr=malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}
struct node * insertatend(struct node *head,int data)
{
    struct node *ptr= (struct node *)malloc(sizeof(struct node));
    struct node *p =head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    ptr->data=data;
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

struct node * insertinindex(struct node *head,int data,int index)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p=head;
    for(int i=0;i<index-1;i++)
    {
        p=p->next;
    }
    ptr->next=p->next;
    ptr->data=data;
    p->next=ptr;

    
    return head;

}

    




int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    fourth=(struct node*)malloc(sizeof(struct node));
    head->data=7;
    head->next=second;
    second->data=11;
    second->next=third;
    third->data=33;
    third->next=fourth;
    fourth->data=55;
    fourth->next=NULL;
    printLL(head);
    head=insertatbeginning(head,4);
    printLL(head);
    head=insertatend(head,22);
    printLL(head);
    head=insertinindex(head,17,2);
    printLL(head);
    return 0;




}