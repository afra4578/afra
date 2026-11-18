#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node* next;
};

struct Node* head = NULL;

void create();
void insertFront(int item);
void insertAfter(int key, int item);
void insertEnd(int item);
void search(int key);
void traversal();

int main() {
int choice, item, key;

do {
printf("\n1. Creation 2. Insert at Front 3. Insert After Particular Node 4. Insert at End 5. Search 6. Traversal 7. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice) {
case 1:
create();
break;
case 2:
printf("Enter item to insert at front: ");
scanf("%d", &item);
insertFront(item);
break;
case 3:
printf("Enter key node value: ");
scanf("%d", &key);
printf("Enter item to insert: ");
scanf("%d", &item);
insertAfter(key, item);
break;
case 4:
printf("Enter item to insert at end: ");
scanf("%d", &item);
insertEnd(item);
break;
case 5:
printf("Enter key to search: ");
scanf("%d", &key);
search(key);
break;
case 6:
traversal();
break;
case 7:
printf("Exiting...\n");
break;
default:
printf("Invalid choice\n");
}
} while (choice != 7);

return 0;
}

void create() {
struct Node *newnode, *temp;
int n, item, i;

printf("Enter the number of nodes: ");
scanf("%d", &n);

for (i = 1; i <= n; i++) {
newnode = (struct Node*)malloc(sizeof(struct Node));
printf("Enter item for node %d: ", i);
scanf("%d", &item);

newnode->data = item;
newnode->next = NULL;

if (head == NULL) {
head = newnode;
} else {
temp = head;
while (temp->next != NULL) {
temp = temp->next;
}
temp->next = newnode;
}
}
printf("List created successfully\n");
}

void insertFront(int item) {
struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
newnode->data = item;
newnode->next = head;
head = newnode;
printf("Node inserted at front\n");
}

void insertAfter(int key, int item) {
struct Node *newnode, *temp;
temp = head;

while (temp != NULL && temp->data != key) {
temp = temp->next;
}

if (temp == NULL) {
printf("Node not found\n");
} else {
newnode = (struct Node*)malloc(sizeof(struct Node));
newnode->data = item;
newnode->next = temp->next;
temp->next = newnode;
printf("Node inserted successfully\n");
}
}

void insertEnd(int item) {
struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
struct Node* temp;

newnode->data = item;
newnode->next = NULL;

if (head == NULL) {
head = newnode;
} else {
temp = head;
while (temp->next != NULL) {
temp = temp->next;
}
temp->next = newnode;
}
printf("Node inserted at end\n");
}

void search(int key) {
struct Node* temp = head;
int position = 1;

while (temp != NULL) {
if (temp->data == key) {
printf("Element found at position: %d\n", position);
return;
}
temp = temp->next;
position++;
}

printf("Element not found\n");
}

void traversal() {
struct Node* temp;

if (head == NULL) {
printf("List is empty\n");
} else {
temp = head;
while (temp != NULL) {
printf("%d -> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
}
}
