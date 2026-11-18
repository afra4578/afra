#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node* Insert_node(int item, struct node *ptr)
{
    if (ptr == NULL)
    {
        ptr = (struct node*)malloc(sizeof(struct node));
        ptr->data = item;
        ptr->left = NULL;
        ptr->right = NULL;
        return ptr;
    }
    else if (item < ptr->data)
    {
        ptr->left = Insert_node(item, ptr->left);
    }
    else
    {
        ptr->right = Insert_node(item, ptr->right);
    }

    return ptr;
}
void Create_BST()
{
    int n, item, i;

    root = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Enter item: ");
        scanf("%d", &item);
        root = Insert_node(item, root);
    }
}

void Inorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        Inorder(ptr->left);
        printf("%d\t", ptr->data);
        Inorder(ptr->right);
    }
}

void Preorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        Preorder(ptr->left);
        Preorder(ptr->right);
    }
}

void Postorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        Postorder(ptr->left);
        Postorder(ptr->right);
        printf("%d\t", ptr->data);
    }
}

int main()
{
    int choice, item;

    do
    {
    	printf("\n");
        printf("1. Create BST\n");
        printf("2. Insert a new node\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                Create_BST();
                break;

            case 2:
                printf("Enter item to insert: ");
                scanf("%d", &item);
                root = Insert_node(item, root);
                break;

            case 3:
                printf("Inorder Traversal: ");
                Inorder(root);
                break;

            case 4:
                printf("Preorder Traversal: ");
                Preorder(root);
                break;

            case 5:
                printf("Postorder Traversal: ");
                Postorder(root);
                break;

            case 6:
                printf("Exiting program...");
                break;

            default:
                printf("Invalid Choice!");
        }

    } while (choice != 6);

    return 0;
}
