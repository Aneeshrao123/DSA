#include<stdio.h>
#include<stdlib.h>

struct node
{
	int key;
	struct node *next;
};
struct node*top=NULL;

void push(struct node *ptr, int  x)
{
	node_t *temp;
	//create a node
	temp=(node_t*)malloc(sizeof(node_t));
	temp->key=x;
	
	temp->link=ptr_stk->top;
	ptr_stk->top=temp;
}
int pop(stack_t* ptr_stk)
{
	int key;
	node_t *pres;
   if(ptr_stk->top==NULL)
	   return 0;
   else
   {
	   pres=ptr_stk->top; //get the first node
	   
	   key=pres->key;
	   ptr_stk->top=pres->link;
	   free(pres);
       return key;
   }
}

void display(stack_t *ptr_stk)
{
  node_t *pres;

  pres=ptr_stk->top;

  if(pres==NULL)
     printf("\nEmpty stack..");
 else
 {
	 //traverse the list
	 while(pres!=NULL)
	 {
		 printf("%d->",pres->key);
		 pres=pres->link;
	 }
 }
}
int main()
{
	struct node*ptr;
	int ch,key,k;
	
	
	while(1)
	{
		
		printf("\n1..push");
		printf("\n2.pop");
		printf("\n3. display");
		printf("\n4.exit");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: printf("enter the element..");
						  scanf("%d",&key);
						  push(ptr,key);
						  break;
			case 2: k=pop(ptr);
						  if(k>0)
							    printf("The element popped = %d\n",k);
						  break;			  
			case 3: display(ptr);
						break;
			case 4 : exit(0);
		}
	}
}






	   
