#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;

};

void traversal(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }

 
}
struct node * deleteatfirst(struct node *head)
{
    struct node * ptr=head;
    head=head->next;
    free(ptr);
    return head;

}
struct node * deleteatindex(struct node *head,int index)
{
    struct node *p=head;
    struct node *q=head->next;
    for(int i=0;i<index-1;i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}
struct node * deleteatend(struct node *head)
{
    struct node *p=head;
    struct node *q=head->next;
    while (q->next!=NULL)
    {
       p=p->next;
       q=q->next;
    }
    p->next=NULL;
    free(q);
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
    head->data=2;
    head->next=second;
    second->data=7;
    second->next=third;
    third->data=11;
    third->next=fourth;
    fourth->data=33;
    traversal(head);
    //head=deleteatfirst(head);
    //traversal(head);
    //head=deleteatindex(head,2);
   // traversal(head);
    head=deleteatend(head);
    traversal(head);
    
    return 0;
 

 

}