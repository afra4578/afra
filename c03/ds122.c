#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* Find_Min(struct Node* ptr) {
    while (ptr != NULL && ptr->left != NULL) {
        ptr = ptr->left;
    }
    return ptr;
}


struct Node* Insert_node(int item, struct Node* ptr) {
    if (ptr == NULL) {
        ptr = (struct Node*)malloc(sizeof(struct Node));
        ptr->data = item;
        ptr->left = NULL;
        ptr->right = NULL;
        return ptr;
    }
    else if (item < ptr->data) {
        ptr->left = Insert_node(item, ptr->left);
    }
    else {
        ptr->right = Insert_node(item, ptr->right);
    }
    return ptr;
}


struct Node* Delete_node(int item, struct Node* ptr) {
    if (ptr == NULL) {
        printf("Element %d not found in the BST.\n", item);
        return ptr;
    }

    if (item < ptr->data) {
        ptr->left = Delete_node(item, ptr->left);
    }
    else if (item > ptr->data) {
        ptr->right = Delete_node(item, ptr->right);
    }
    else {
        
        if (ptr->left == NULL) {
            struct Node* temp = ptr->right;
            free(ptr);
            return temp;
        }
        // Case 2: Node with only left child
        else if (ptr->right == NULL) {
            struct Node* temp = ptr->left;
            free(ptr);
            return temp;
        }
        // Case 3: Node with two children
        struct Node* temp = Find_Min(ptr->right);
        ptr->data = temp->data;
        ptr->right = Delete_node(temp->data, ptr->right);
    }
    return ptr;
}

// Function matching Algorithm 4: Search(item, ptr)
struct Node* Search(int item, struct Node* ptr) {
    if (ptr == NULL || ptr->data == item) {
        return ptr;
    }
    if (item < ptr->data) {
        return Search(item, ptr->left);
    }
    return Search(item, ptr->right);
}

// Function matching Algorithm 5: Inorder(ptr)
void Inorder(struct Node* ptr) {
    if (ptr != NULL) {
        Inorder(ptr->left);
        printf("%d ", ptr->data);
        Inorder(ptr->right);
    }
}

// Main Menu Driver Program
int main() {
    struct Node* root = NULL;
    struct Node* temp = NULL;
    int choice, item, n, i;

    while (1) {
       
        printf("\n1. Create BST (Insert multiple elements)");
        printf("\n2. Delete a Node");
        printf("\n3. Search an Element");
        printf("\n4. In-order Traversal");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes to insert: ");
                scanf("%d", &n);
                printf("Enter %d values:\n", n);
                for (i = 0; i < n; i++) {
                    scanf("%d", &item);
                    root = Insert_node(item, root);
                }
                printf("BST created successfully.\n");
                break;

            case 2:
                if (root == NULL) {
                    printf("BST is empty!\n");
                } else {
                    printf("Enter element to delete: ");
                    scanf("%d", &item);
                    root = Delete_node(item, root);
                }
                break;

            case 3:
                if (root == NULL) {
                    printf("BST is empty!\n");
                } else {
                    printf("Enter element to search: ");
                    scanf("%d", &item);
                    temp = Search(item, root);
                    if (temp != NULL) {
                        printf("Element %d found in the BST.\n", item);
                    } else {
                        printf("Element %d not found in the BST.\n", item);
                    }
                }
                break;

            case 4:
                if (root == NULL) {
                    printf("BST is empty!\n");
                } else {
                    printf("In-order Traversal: ");
                    Inorder(root);
                    printf("\n");
                }
                break;

            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
