#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void create();
void insert_first();
void insert_last();
void delete_first();
void delete_last();
void display();

int main()
{
    int choice;

    while(1)
    {
 
        printf("\n1. Creation");
        printf("\n2. Insert at First");
        printf("\n3. Insert at Last");
        printf("\n4. Delete from First");
        printf("\n5. Delete from Last");
        printf("\n6. Traversal");
        printf("\n7. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create();
                break;

            case 2:
                insert_first();
                break;

            case 3:
                insert_last();
                break;

            case 4:
                delete_first();
                break;

            case 5:
                delete_last();
                break;

            case 6:
                display();
                break;

            case 7:
                return 0;

            default:
                printf("\nInvalid choice!");
        }
    }

    return 0;
}

void create()
{
    struct node *new, *temp;
    int n, i;

    printf("\nEnter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        new = (struct node*)malloc(sizeof(struct node));

        if(new == NULL)
        {
            printf("\nMemory allocation failed!");
            return;
        }

        printf("Enter data: ");
        scanf("%d", &new->data);

        new->prev = NULL;
        new->next = NULL;

        if(head == NULL)
        {
            head = new;
        }
        else
        {
            temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = new;
            new->prev = temp;
        }
    }
}

void insert_first()
{
    struct node *new;

    new = (struct node*)malloc(sizeof(struct node));

    if(new == NULL)
    {
        printf("\nMemory allocation failed!");
        return;
    }

    printf("\nEnter data: ");
    scanf("%d", &new->data);

    new->prev = NULL;
    new->next = head;

    if(head != NULL)
    {
        head->prev = new;
    }

    head = new;

    printf("\nNode inserted at first position.");
}

void insert_last()
{
    struct node *new, *temp;

    new = (struct node*)malloc(sizeof(struct node));

    if(new == NULL)
    {
        printf("\nMemory allocation failed!");
        return;
    }

    printf("\nEnter data: ");
    scanf("%d", &new->data);

    new->next = NULL;
    new->prev = NULL;

    if(head == NULL)
    {
        head = new;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = new;
        new->prev = temp;
    }

    printf("\nNode inserted at last position.");
}

void delete_first()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("\nList is empty!");
        return;
    }

    temp = head;
    head = head->next;

    if(head != NULL)
    {
        head->prev = NULL;
    }

    free(temp);

    printf("\nFirst node deleted.");
}

void delete_last()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("\nList is empty!");
        return;
    }

    temp = head;

    if(head->next == NULL)
    {
        head = NULL;
        free(temp);
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->prev->next = NULL;
        free(temp);
    }

    printf("\nLast node deleted.");
}

void display()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("\nList is empty!");
        return;
    }

    temp = head;

    printf("\nDoubly Linked List:\n");

    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");
}


