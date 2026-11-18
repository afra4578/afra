#include<stdio.h>
#include<stdlib.h>
int main() {
    struct Node* root = NULL;
    struct Node* temp = NULL;
    int choice, item, n, i;
 printf("Enter number of nodes to insert: ");
                scanf("%d", &n);
                printf("Enter %d values:\n", n);
                for (i = 0; i < n; i++) {
                    scanf("%d", &item);
                    root = Insert_node(item, root);
                }
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
