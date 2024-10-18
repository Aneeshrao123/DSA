#include<stdio.h>
#include<stdlib.h>

int push(int val, int *s, int *t, int sizee) {
    if (*t == sizee - 1) {
        printf("Stack is full\n");
        return -1;
    } else {
        (*t)++;
        s[*t] = val;
        return 1;
    }
}

int pop(int *t, int *s) {
    if (*t == -1) {
        printf("Stack is empty\n");
        return -1; // Error indicator
    } else {
        int poppedValue = s[*t];
        (*t)--;
        return poppedValue;
    }
}

void display(int t, int *s) {
    if (t == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= t; i++) {
            printf("%d ", s[i]);
        }
        printf("\n");
    }
}

int main() {
    int size, top = -1, ch, ele, k;
    printf("Enter size of the stack\n");
    scanf("%d", &size);

    int *s = (int *) malloc(sizeof(int) * size);

    while (1) {
        printf("\n1...Push\n");
        printf("2...Pop\n");
        printf("3...Display\n");
        printf("4...Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to be pushed\n");
                scanf("%d", &ele);
                k = push(ele, s, &top, size);
                if (k > 0) {
                    printf("Element pushed successfully\n");
                }
                break;
            case 2:
                k = pop(&top, s);
                if (k != -1) {
                    printf("Popped value is %d\n", k);
                }
                break;
            case 3:
                display(top, s);
                break;
            case 4:
                free(s);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
