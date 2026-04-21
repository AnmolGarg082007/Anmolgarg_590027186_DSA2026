#include <stdio.h>
#define SIZE 100

int tree[SIZE];

void insert(int index, int value) {
    if (index >= SIZE) {
        printf("Out of range\n");
        return;
    }
    tree[index] = value;
}

void display() {
    for (int i = 1; i < 15; i++) {
        if (tree[i] != 0)
            printf("%d ", tree[i]);
    }
}

void relations(int index) {
    printf("Node: %d\n", tree[index]);
    if (index / 2 > 0)
        printf("Parent: %d\n", tree[index / 2]);
    if (2 * index < SIZE)
        printf("Left Child: %d\n", tree[2 * index]);
    if (2 * index + 1 < SIZE)
        printf("Right Child: %d\n", tree[2 * index + 1]);
}

int main() {
    insert(1, 10);
    insert(2, 20);
    insert(3, 30);
    insert(4, 40);

    printf("Tree elements: ");
    display();

    printf("\n\nRelations of node at index 2:\n");
    relations(2);

    return 0;
}