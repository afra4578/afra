#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node *next;
};

struct Node* insertEnd(struct Node *head, int val);
struct Node* createList(struct Node *head);
struct Node* deleteBeginning(struct Node *head);
struct Node* deleteEnd(struct Node *head);
struct Node* deleteLocation(struct Node *head, int pos);
void traverseList(struct Node *head);

int main() {
struct Node *head = NULL;
int choice, pos;

do {
printf("\n1.Creation 2.Delete from Beginning 3.Delete from End 4.Delete from Location 5.Traversal 6.Exit\n");
printf("Enter choice: ");
scanf("%d", &choice);

switch (choice) {
case 1:
head = createList(head);
break;
case 2:
head = deleteBeginning(head);
break;
case 3:
head = deleteEnd(head);
break;
case 4:
printf("Enter position: ");
scanf("%d", &pos);
head = deleteLocation(head, pos);
break;
case 5:
traverseList(head);
break;
case 6:
printf("Exiting\n");
break;
default:
printf("Invalid choice\n");
}
} while (choice != 6);

return 0;
}

struct Node* insertEnd(struct Node *head, int val) {
struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = val;
newNode->next = NULL;

if (head == NULL) {
head = newNode;
} else {
struct Node *temp = head;
while (temp->next != NULL) {
temp = temp->next;
}
temp->next = newNode;
}
return head;
}

struct Node* createList(struct Node *head) {
int n, val, i;
printf("Enter number of nodes: ");
scanf("%d", &n);

for (i = 1; i <= n; i++) {
printf("Enter value for node %d: ", i);
scanf("%d", &val);
head = insertEnd(head, val);
}
return head;
}

struct Node* deleteBeginning(struct Node *head) {
struct Node *temp;

if (head == NULL) {
printf("List is empty, underflow\n");
} else {
temp = head;
head = head->next;
printf("Deleted element is %d\n", temp->data);
free(temp);
}
return head;
}

struct Node* deleteEnd(struct Node *head) {
struct Node *temp, *prev;

if (head == NULL) {
printf("List is empty, underflow\n");
} else if (head->next == NULL) {
printf("Deleted element is %d\n", head->data);
free(head);
head = NULL;
} else {
temp = head;
while (temp->next != NULL) {
prev = temp;
temp = temp->next;
}
prev->next = NULL;
printf("Deleted element is %d\n", temp->data);
free(temp);
}
return head;
}

struct Node* deleteLocation(struct Node *head, int pos) {
struct Node *temp, *prev;
int i;

if (head == NULL) {
printf("List is empty, underflow\n");
return head;
}

if (pos == 1) {
temp = head;
head = head->next;
printf("Deleted element is %d\n", temp->data);
free(temp);
return head;
}

temp = head;
for (i = 1; i < pos; i++) {
prev = temp;
temp = temp->next;
if (temp == NULL) {
printf("Invalid position\n");
return head;
}
}

prev->next = temp->next;
printf("Deleted element is %d\n", temp->data);
free(temp);
return head;
}

void traverseList(struct Node *head) {
if (head == NULL) {
printf("List is empty\n");
} else {
struct Node *temp = head;
printf("Linked list elements are: ");
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}
}
