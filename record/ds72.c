#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL;
    struct node *tail = NULL;
    struct node *newNode, *temp;

    for (int i = 1; i <= 5; i++) {
        newNode = (struct node *)malloc(sizeof(struct node));

        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter value for node %d: ", i);
        if (scanf("%d", &newNode->data) != 1) {
            printf("Invalid input\n");
            free(newNode);
            return 1;
        }

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("\nLinked List elements: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    temp = head;
    while (temp != NULL) {
        struct node *next = temp->next;
        free(temp);
        temp = next;
    }

    head = NULL;
    tail = NULL;

    return 0;
}
