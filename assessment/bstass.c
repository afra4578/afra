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
 


struct node* findMin(struct node *root) {
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}


int main() {
    struct node *root = NULL;
    int  x,i,n,a,b;
    printf("no of elememnt");
    scanf("%d",&n);

  	for(i=0;i<n;i++){
                scanf("%d", &x);
                root = insert(root, x);
              
     
} 
a=n/2;
printf("no of leaf node=%d/n",a);
b=a-n;
printf("no of non leaf node=%d",b);
         
}
