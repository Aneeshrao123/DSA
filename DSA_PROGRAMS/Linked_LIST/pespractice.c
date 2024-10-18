#include<stdio.h>
#include<stdlib.h>
//void displayarray(int *p,int n)
//{
    //for(int i=0;i<n;i++)
    //{
      //  printf("%d\n",*(p+i));
    //}
//}
//void main()
//{
    //int x=10;
    //int *y;
   // y=&x;
    //printf("adress of y is %p and value of y is %d",y,*y);
    //int x[5]={1,2,3,4,5};
   // int size=sizeof(x)/sizeof(x[0]);
    //displayarray(x,size);
//}
int main()
{
    int array[5]={1,2,3,4,5};
    int *ptr;
    for(ptr=array;ptr<=array+4;ptr++)
    {
        printf("%d\n",*ptr);
    }
}
