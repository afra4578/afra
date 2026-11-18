
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *ptr, *newnode;

    int n, i, max, min, val;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter value: ");
        scanf("%d", &val);

        newnode->data = val;
        newnode->next = NULL;

        if (head == NULL) {
            newnode->prev = NULL;
            head = newnode;
        }
        else {
            ptr = head;

            while (ptr->next != NULL) {
                ptr = ptr->next;
            }

            ptr->next = newnode;
            newnode->prev = ptr;
        }
    }

    ptr = head;

    max = ptr->data;
    min = ptr->data;

    while (ptr != NULL) {

        if (ptr->data > max) {
            max = ptr->data;
        }

        if (ptr->data < min) {
            min = ptr->data;
        }

        ptr = ptr->next;
    }

    printf("\nMaximum value = %d", max);
    printf("\nMinimum value = %d", min);

    return 0;
}

