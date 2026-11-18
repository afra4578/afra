struct node {
    int data;
    struct node *prev;
    struct node *next;
};
struct DoubleNode {
    int data;
    struct DoubleNode* prev;
    struct DoubleNode* next;
};

    struct DoubleNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (pos == 0) {
        newNode->next = head;
        if (head != NULL) head->prev = newNode;
        return newNode;
    }

    struct DoubleNode* curr = head;
    for (int i = 0; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
    }
    if (curr == NULL) return head;

    newNode->next = curr->next;
    newNode->prev = curr;
    if (curr->next != NULL) {
        curr->next->prev = newNode;
    }
    curr->next = newNode;
    return head;


