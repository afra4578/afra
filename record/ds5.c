#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push() {
	int value;
	if (top == MAX - 1) {
    	printf("Stack Overflow");
	} else {
    	printf("Enter value to push: ");
    	scanf("%d", &value);
    	top++;
    	stack[top] = value;
    	printf("Element pushed successfully\n");
	}
}

void pop() {
	if (top == -1) {
    	printf("Stack Underflow\n");
	} else {
    	printf("Popped element: %d\n", stack[top]);
    	top--;
	}
}

void display() {
	int i;
	if (top == -1) {
    	printf("Stack is empty\n");
	} else {
    	printf("Stack elements: ");
    	i = top;
    	while (i >= 0) {
        	printf("%d ", stack[i]);
        	i--;
    	}
    	printf("\n");
	}
}

int main() {
	int choice = 0;

	while (choice != 4) {
    	printf("1. Push\n");
    	printf("2. Pop\n");
    	printf("3. Display\n");
    	printf("4. Exit\n");
    	printf("Enter your choice: ");

    	if (scanf("%d", &choice) != 1) {
        	while (getchar() != '\n');
        	printf("Invalid choice!\n");
        	continue;
    	}

    	if (choice == 1) {
        	push();
    	} else if (choice == 2) {
        	pop();
    	} else if (choice == 3) {
        	display();
    	} else if (choice == 4) {
        	printf("Exiting program...\n");
    	} else {
        	printf("Invalid choice!\n");
    	}
	}

	return 0;
}

