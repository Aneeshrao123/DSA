#include <stdio.h>
int main()
{
    int a[5]={2,6,8,9,4};
    int *p[5];
    for (int i=0;i<5;i++)
    {
        p[i]=&a[i]; // storing adress of each array element in array of pointers

    }
    for (int i=0;i<5;i++)

}