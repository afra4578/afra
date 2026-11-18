#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node* createNode(int x) {
    struct node *n = malloc(sizeof(struct node));
    n->data = x;
    n->left = NULL;
    n->right = NULL;
    return n;
}
struct node* insert(struct node *root, int x) {
    if (root == NULL)
        return createNode(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    return root;
}
int countLeafNodes(struct node *root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}
int countNonLeafNodes(struct node *root) {
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
}
int main() {
    struct node *root = NULL;
    int x, i, n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }
    printf("Number of leaf nodes = %d\n", countLeafNodes(root));
    printf("Number of non-leaf nodes = %d\n", countNonLeafNodes(root));

    return 0;
}
