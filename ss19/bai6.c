#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    if (newNode == NULL) {
        printf("Khong cap phat duoc bo nho\n");
        return NULL;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
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

bool isEmpty(Queue *q) {
    return q->front == NULL;
}

bool searchBFS(Node *root, int target) {
    if (root == NULL) return false;
    Queue *q = createQueue();
    enqueue(q, root);
    while (!isEmpty(q)) {
        Node *current = dequeue(q);
        if (current->data == target) return true;
        if (current->left != NULL) enqueue(q, current->left);
        if (current->right != NULL) enqueue(q, current->right);
    }
    return false;
}

int main() {
    Node *root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int x;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    if (searchBFS(root, x)) {
        printf("Tim thay %d trong cay\n", x);
    } else {
        printf("Khong tim thay %d trong cay\n", x);
    }

    return 0;
}
