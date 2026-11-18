#include <stdio.h>
#include <stdlib.h>
struct node { int data; struct node *next; };
struct node *top = NULL;
void push(); void pop(); void display();
int main() { int choice;
while(1)
{
   
    printf("\n1. PUSH");
    printf("\n2. POP");
    printf("\n3. TRAVERSAL");
    printf("\n4. EXIT");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("\nInvalid choice!");
    }
}
return 0;
}
void push() { struct node *new;
new = (struct node*)malloc(sizeof(struct node));
if(new == NULL)
{
    printf("\nMemory allocation failed!");
    return;
}
printf("\nEnter the element: ");
scanf("%d", &new->data);
new->next = top;
top = new;
printf("\nElement pushed successfully.");
}
void pop() { struct node *temp;
if(top == NULL)
{
    printf("\nStack Underflow!");
    return;
}
temp = top;
printf("\nDeleted element is: %d", temp->data);
top = top->next;
free(temp);
}
void display() { struct node *temp;
if(top == NULL)
{
    printf("\nStack is empty!");
    return;
}
temp = top;
printf("\nStack elements are:\n");
while(temp != NULL)
{
    printf("%d\n", temp->data);
    temp = temp->next;
}}

