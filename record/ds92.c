#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
void enqueue(); void dequeue(); void display();
int main() { int choice;
while(1)
{
   
    printf("\n1. ENQUEUE");
    printf("\n2. DEQUEUE");
    printf("\n3. TRAVERSAL");
    printf("\n4. EXIT");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;

        default:
            printf("\nInvalid choice!");
    }
}

return 0;

}

void enqueue() { struct node *new;

new = (struct node*)malloc(sizeof(struct node));

if(new == NULL)
{
    printf("\nMemory allocation failed!");
    return;
}

printf("\nEnter the element: ");
scanf("%d", &new->data);

new->next = NULL;

if(front == NULL)
{
    front = rear = new;
}
else
{
    rear->next = new;
    rear = new;
}

printf("\ninserted successfully.");

}

void dequeue() { struct node *temp;

if(front == NULL)
{
    printf("\nQueue Underflow!");
    return;
}

temp = front;

printf("\nDeleted element is: %d", temp->data);

front = front->next;

if(front == NULL)
{
    rear = NULL;
}

free(temp);
}
void display() { struct node *temp;
if(front == NULL)
{
    printf("\nQueue is empty!");
    return;
}
temp = front;
printf("\nQueue elements are:\n");
while(temp != NULL)
{
    printf("%d -> ", temp->data);
    temp = temp->next;
}
printf("NULL");
}




