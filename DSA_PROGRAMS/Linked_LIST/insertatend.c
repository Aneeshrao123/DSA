#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
void display_linkedlist(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
struct node* insertatend(struct node*head,int data)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node*p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    ptr->data=data;
    return ptr;

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
    third->data=44;
    third->next=fourth;
    fourth->data=15;
    fourth->next=NULL;
    display_linkedlist(head);
    //head=insertatend(head,77);
    //display_linkedlist(head);
    return 0;
    



}