#include <stdio.h>
#include <stdlib.h>

// Cấu trúc node của cây
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Tạo node mới
Node* createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Hàng đợi dùng cho duyệt BFS
typedef struct QueueNode {
    Node *treeNode;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;

Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue *q, Node *treeNode) {
    QueueNode *temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->treeNode = treeNode;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

Node* dequeue(Queue *q) {
    if (q->front == NULL) return NULL;
    QueueNode *temp = q->front;
    Node *result = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return result;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

// Hàm thêm phần tử vào cây nhị phân
void insertNode(Node *root, int value) {
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

// Duyệt trung thứ (inorder)
void inorder(Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Hàm main để kiểm tra
int main() {
    // Khởi tạo cây như bài 1
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Cay truoc khi them (inorder): ");
    inorder(root);
    printf("\n");

    int x;
    printf("Nhap gia tri can them: ");
    scanf("%d", &x);

    insertNode(root, x);

    printf("Cay sau khi them (inorder): ");
    inorder(root);
    printf("\n");

    return 0;
}
