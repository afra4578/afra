#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void Enqueue();
void Dequeue();
void Display();

int main() {
    int choice, n, i, value;

    printf("Enter number of initial elements to add to queue (max %d): ", MAX);
    scanf("%d", &n);

    if (n > 0 && n <= MAX) {
        front = 0;
        printf("Enter %d element(s):\n", n);
        for (i = 0; i < n; i++) {
            scanf("%d", &value);
            rear++;
            queue[rear] = value;
        }
        printf("Queue initialized successfully.\n");
    } else if (n > MAX) {
        printf("Size exceeds maximum capacity! Initializing empty queue.\n");
    }

    while (1) {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Enqueue();
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Display();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void Enqueue() {
    int value;
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        printf("Enter the value to insert: ");
        scanf("%d", &value);
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("Element inserted successfully\n");
    }
}

void Dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("Dequeued element: %d\n", queue[front]);
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}

void Display() {
    int i;
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
