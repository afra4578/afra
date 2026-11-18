#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *newNode = NULL;
    struct Node *temp = NULL;
    int i, val;

    for (i = 1; i <= 5; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter value for node %d: ", i);
        if (scanf("%d", &val) != 1) {
            printf("Invalid input\n");
            free(newNode);
            return 1;
        }

        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Elements in the linked list are: ");
    temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    temp = head;
    while (temp != NULL) {
        struct Node *next = temp->next;
        free(temp);
        temp = next;
    }

    head = NULL;

    return 0;
}
