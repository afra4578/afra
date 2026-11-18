#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void Enqueue(int value) {
	if ((rear + 1) % MAX == front) {
    	printf("Queue Overflow! Cannot insert %d\n", value);
    	return;
	}

	if (front == -1) {
    	front = 0;
    	rear = 0;
	} else {
    	rear = (rear + 1) % MAX;
	}

	queue[rear] = value;
	printf("Element %d inserted successfully.\n", value);
}

void Dequeue() {
	if (front == -1) {
    	printf("Queue Underflow! Queue is empty.\n");
    	return;
	}

	printf("Deleted element: %d\n", queue[front]);

	if (front == rear) {
    	front = -1;
    	rear = -1;
	} else {
    	front = (front + 1) % MAX;
	}
}

void Peek() {
	if (front == -1) {
    	printf("Queue is empty.\n");
	} else {
    	printf("Front element is: %d\n", queue[front]);
	}
}

void Display() {
	if (front == -1) {
    	printf("Queue is empty.\n");
    	return;
	}

	printf("Current Queue: ");
	int i = front;
	while (i != rear) {
    	printf("%d ", queue[i]);
    	i = (i + 1) % MAX;
	}
	printf("%d\n", queue[rear]);
}

int main() {
	int choice, value, n;

 
	printf("Enter number of elements to store in the queue (Max %d): ", MAX);
	scanf("%d", &n);

	if (n > MAX) {
    	printf("Cannot exceed max capacity of %d. Setting size to %d.\n", MAX, MAX);
    	n = MAX;
	}

	printf("Enter %d elements:\n", n);
	for (int i = 0; i < n; i++) {
    	printf("Element %d: ", i + 1);
    	scanf("%d", &value);
    	Enqueue(value);
	}

 

	while (1) {
    	printf("\noperations\n");
    	printf("1. Enqueue\n");
    	printf("2. Dequeue\n");
    	printf("3. Peek\n");
    	printf("4. Display Queue\n");
    	printf("5. Exit\n");
    	printf("Enter your choice: ");
    	scanf("%d", &choice);

    	switch (choice) {
        	case 1:
            	printf("Enter value to insert: ");
            	scanf("%d", &value);
            	Enqueue(value);
            	break;
        	case 2:
            	Dequeue();
            	break;
        	case 3:
            	Peek();
            	break;
        	case 4:
            	Display();
            	break;
        	case 5:
            	printf("Exiting program...\n");
            	exit(0);
        	default:
            	printf("Invalid choice! Try again.\n");
    	}
	}

	return 0;
}

