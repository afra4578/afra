#include <stdio.h>
#include <stdlib.h>

#define MIN_DEGREE 3
#define MAX_KEYS (2 * MIN_DEGREE - 1)
#define MAX_CHILDREN (2 * MIN_DEGREE)

struct node {
	int keys[MAX_KEYS];
	struct node *children[MAX_CHILDREN];
	int key_count;
	int leaf;
};

struct node *create_node(int leaf) {
	struct node *new_node = malloc(sizeof(*new_node));
	if (new_node == NULL) {
		printf("Memory allocation failed!\n");
		return NULL;
	}
	new_node->key_count = 0;
	new_node->leaf = leaf;
	for (int index = 0; index < MAX_CHILDREN; index++) {
		new_node->children[index] = NULL;
	}
	return new_node;
}

struct node *search(struct node *root, int value) {
	if (root == NULL) {
		return NULL;
	}
	int index = 0;
	while (index < root->key_count && value > root->keys[index]) {
		index++;
	}
	if (index < root->key_count && value == root->keys[index]) {
		return root;
	}
	return root->leaf ? NULL : search(root->children[index], value);
}

int split_child(struct node *parent, int index) {
	struct node *full_child = parent->children[index];
	struct node *right_child = create_node(full_child->leaf);
	if (right_child == NULL) {
		return 0;
	}
	right_child->key_count = MIN_DEGREE - 1;
	for (int offset = 0; offset < MIN_DEGREE - 1; offset++) {
		right_child->keys[offset] = full_child->keys[offset + MIN_DEGREE];
	}
	if (!full_child->leaf) {
		for (int offset = 0; offset < MIN_DEGREE; offset++) {
			right_child->children[offset] = full_child->children[offset + MIN_DEGREE];
			full_child->children[offset + MIN_DEGREE] = NULL;
		}
	}
	full_child->key_count = MIN_DEGREE - 1;
	for (int offset = parent->key_count; offset >= index + 1; offset--) {
		parent->children[offset + 1] = parent->children[offset];
	}
	parent->children[index + 1] = right_child;
	for (int offset = parent->key_count - 1; offset >= index; offset--) {
		parent->keys[offset + 1] = parent->keys[offset];
	}
	parent->keys[index] = full_child->keys[MIN_DEGREE - 1];
	parent->key_count++;
	return 1;
}

int insert_non_full(struct node *current, int value) {
	int index = current->key_count - 1;
	if (current->leaf) {
		while (index >= 0 && value < current->keys[index]) {
			current->keys[index + 1] = current->keys[index];
			index--;
		}
		current->keys[index + 1] = value;
		current->key_count++;
		return 1;
	}
	while (index >= 0 && value < current->keys[index]) {
		index--;
	}
	index++;
	if (current->children[index]->key_count == MAX_KEYS) {
		if (!split_child(current, index)) {
			return 0;
		}
		if (value > current->keys[index]) {
			index++;
		}
	}
	return insert_non_full(current->children[index], value);
}

int insert(struct node **root, int value) {
	if (search(*root, value) != NULL) {
		printf("Duplicate values are not allowed.\n");
		return 0;
	}
	if (*root == NULL) {
		*root = create_node(1);
		if (*root == NULL) {
			return 0;
		}
		(*root)->keys[0] = value;
		(*root)->key_count = 1;
		return 1;
	}
	if ((*root)->key_count == MAX_KEYS) {
		struct node *new_root = create_node(0);
		if (new_root == NULL) {
			return 0;
		}
		new_root->children[0] = *root;
		if (!split_child(new_root, 0)) {
			free(new_root);
			return 0;
		}
		*root = new_root;
	}
	return insert_non_full(*root, value);
}

void inorder(struct node *current) {
	if (current == NULL) {
		return;
	}
	for (int index = 0; index < current->key_count; index++) {
		if (!current->leaf) {
			inorder(current->children[index]);
		}
		printf("%d ", current->keys[index]);
	}
	if (!current->leaf) {
		inorder(current->children[current->key_count]);
	}
}

void free_tree(struct node *current) {
	if (current == NULL) {
		return;
	}
	if (!current->leaf) {
		for (int index = 0; index <= current->key_count; index++) {
			free_tree(current->children[index]);
		}
	}
	free(current);
}

int main(void) {
	struct node *root = NULL;
	int choice, value, count;
	while (1) {
		printf("\n1. Create B-Tree\n2. Insert\n3. Search\n4. In-order traversal\n5. Exit\n");
		printf("Enter your choice: ");
		if (scanf("%d", &choice) != 1) {
			break;
		}
		switch (choice) {
			case 1:
				printf("Enter number of values: ");
				if (scanf("%d", &count) != 1 || count < 0) {
					printf("Invalid number of values.\n");
					break;
				}
				free_tree(root);
				root = NULL;
				for (int index = 0; index < count; index++) {
					printf("Enter value: ");
					if (scanf("%d", &value) != 1 || !insert(&root, value)) {
						printf("Could not add the value.\n");
						break;
					}
				}
				break;
			case 2:
				printf("Enter value to insert: ");
				if (scanf("%d", &value) == 1 && insert(&root, value)) {
					printf("%d inserted into the B-Tree.\n", value);
				}
				break;
			case 3:
				printf("Enter value to search: ");
				if (scanf("%d", &value) == 1) {
					printf(search(root, value) != NULL ? "%d found in the B-Tree.\n" : "%d not found in the B-Tree.\n", value);
				}
				break;
			case 4:
				printf("In-order traversal: ");
				inorder(root);
				printf("\n");
				break;
			case 5:
				free_tree(root);
				return 0;
			default:
				printf("Invalid choice! Please try again.\n");
		}
	}
	free_tree(root);
	return 0;
}


