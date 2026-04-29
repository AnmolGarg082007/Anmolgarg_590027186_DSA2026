#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up
void heapifyUp(int index) {
    int parent = (index - 1) / 2;

    if (index > 0 && heap[parent] > heap[index]) {
        swap(&heap[parent], &heap[index]);
        heapifyUp(parent);
    }
}

// Heapify Down
void heapifyDown(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert
void insert(int value) {
    if (size == MAX) {
        printf("Heap Overflow\n");
        return;
    }
    heap[size] = value;
    heapifyUp(size);
    size++;
}

// Delete Root
void deleteRoot() {
    if (size == 0) {
        printf("Heap Empty\n");
        return;
    }
    printf("Deleted: %d\n", heap[0]);
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

// Display
void display() {
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n1.Insert 2.Delete 3.Display 4.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                deleteRoot();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
        }
    }
}