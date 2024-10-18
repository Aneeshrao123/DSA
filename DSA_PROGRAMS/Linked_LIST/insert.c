#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node * insertatbeginning(struct node * head,int data)
{
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}
struct node * insertatindex(struct node * head,int data,int index)
{
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
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
struct node * insertatend(struct node * head,int data)
{
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->data=data;
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
void printinglinked_list(struct node * ptr)
{
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }

}
int main()
{
    int ch;
    int n;
    struct node*head=(struct node*)malloc(sizeof(struct node));
    head->next=NULL;
    printf("Enter 1 to insert element into linked list\n");
    printf("Enter 2 to display linked list\n");
    scanf("%d",&ch);
    switch(ch)
        case 1:
        {
           printf("Enter element to be inserted\n");
           scanf("%d",&n);
           head=insertatend(head,n);
           while(1){
            printf("Enter element to be inserted\n");
            scanf("%d",&n);
            head=insertatend(head,n);
           }

           
        
        }
        case 2:
        {
            printf("The linked list is:\n");
            printinglinked_list(head);
        }
    }
    return 0;
        
            
        
    

    
}



    