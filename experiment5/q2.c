#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* create(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int totalNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + totalNodes(root->left) + totalNodes(root->right);
}

int leafNodes(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return leafNodes(root->left) + leafNodes(root->right);
}

int height(struct Node* root) {
    if (root == NULL) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
}

int main() {
    struct Node* root = create(10);
    root->left = create(20);
    root->right = create(30);
    root->left->left = create(40);

    printf("Total Nodes: %d\n", totalNodes(root));
    printf("Leaf Nodes: %d\n", leafNodes(root));
    printf("Height: %d\n", height(root));

    return 0;
}