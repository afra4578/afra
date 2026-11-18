#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

int create(struct node **head, int val)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (!new_node)
    {
        printf("insufficient\n");
        return -1;
    }
    new_node->data = val;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
    printf("%d added to the list\n", val);
    return 0;
}

int search(struct node *head, int val)
{
    struct node *current = head;
    while (current != NULL)
    {
        if (current->data == val)
        {
            printf("%d found\n", val);
            return 1;
        }
        current = current->next;
    }
    printf("%d not found\n", val);
    return 0;
}

int count_nodes(struct node *head)
{
    int count = 0;
    struct node *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

int traversal(struct node *head)
{
    if (head == NULL)
    {
        printf("empty list!\n");
        return -1;
    }
    printf("List elements: ");
    struct node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    return 0;
}

int main()
{
    struct node *head = NULL;
    int ch, val;
    while (1)
    {
        printf("\n1. Create\n2. Count \n3. Search\n4. Traversal\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value to add: ");
            scanf("%d", &val);
            create(&head, val);
            break;
        case 2:
            printf("Number of nodes: %d\n", count_nodes(head));
            break;
        case 3:
            printf("Enter value to search: ");
            scanf("%d", &val);
            search(head, val);
            break;
        case 4:
            traversal(head);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

}

