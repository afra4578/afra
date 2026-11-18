#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *newNode = NULL, *temp = NULL;
    int i, val;

    for (i = 1; i <= 5; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter value for node %d: ", i);
        scanf("%d", &val);

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

    printf("\nElements in the linked list are:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}



