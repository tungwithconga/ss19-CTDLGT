#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct QueueNode {
    Node *data;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;

Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) return NULL;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue *q, Node *node) {
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    temp->data = node;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

Node *dequeue(Queue *q) {
    if (q->front == NULL) return NULL;
    QueueNode *temp = q->front;
    Node *result = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return result;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

void insert(Node *root, int value) {
    if (root == NULL) return;
    Queue *q = createQueue();
    enqueue(q, root);
    while (!isEmpty(q)) {
        Node *current = dequeue(q);
        if (current->left == NULL) {
            current->left = createNode(value);
            break;
        } else {
            enqueue(q, current->left);
        }
        if (current->right == NULL) {
            current->right = createNode(value);
            break;
        } else {
            enqueue(q, current->right);
        }
    }
}

void inorder(Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    Node *root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int x;
    printf("Nhap gia tri can them: ");
    scanf("%d", &x);
    insert(root, x);

    printf("Cay sau khi them (duyet trung thu tu): ");
    inorder(root);
    printf("\n");

    return 0;
}
