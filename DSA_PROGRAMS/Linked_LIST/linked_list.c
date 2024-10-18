#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void traversalanddisplay(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d\n",*ptr);
        ptr=ptr->next;
    }
}
int main()
{
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * fourth;


    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    fourth=(struct node*)malloc(sizeof(struct node));
    head->data=7;
    head->next=second;
    second->data=11;
    second->next=third;
    third->data=66;
    third->next=fourth;
    fourth->data=41;
    fourth->next=NULL;

    traversalanddisplay(head);
    return 0;

}

