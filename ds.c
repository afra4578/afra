#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *insertEnd(struct Node *head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp;

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

void display(struct Node *head)
{
    if (head == NULL) {
        printf("Empty");
        return;
    }

    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
}

void freeList(struct Node *head)
{
    struct Node *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void)
{
    struct Node *head = NULL;
    struct Node *evenHead = NULL;
    struct Node *oddHead = NULL;
    struct Node *temp;
    int n, value, i;

    printf("Enter number of values: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid number of values\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        if (scanf("%d", &value) != 1) {
            printf("Invalid value\n");
            freeList(head);
            return 1;
        }
        head = insertEnd(head, value);
    }

    temp = head;
    while (temp != NULL) {
        if (temp->data % 2 == 0)
            evenHead = insertEnd(evenHead, temp->data);
        else
            oddHead = insertEnd(oddHead, temp->data);
        temp = temp->next;
    }

    printf("\nOriginal list: ");
    display(head);
    printf("\nEven list: ");
    display(evenHead);
    printf("\nOdd list: ");
    display(oddHead);
    printf("\n");

    freeList(head);
    freeList(evenHead);
    freeList(oddHead);
    return 0;
}