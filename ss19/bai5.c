#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

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

bool searchDFS(Node *root, int target) {
    if (root == NULL) return false;
    if (root->data == target) return true;
    if (searchDFS(root->left, target)) return true;
    if (searchDFS(root->right, target)) return true;
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

    if (searchDFS(root, x)) {
        printf("Tim thay %d trong cay\n", x);
    } else {
        printf("Khong tim thay %d trong cay\n", x);
    }

    return 0;
}
