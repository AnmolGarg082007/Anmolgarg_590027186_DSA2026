#include <stdio.h>

#define MAX 100

struct Node {
    int value;
    int priority;
};

struct Node heap[MAX];
int size = 0;

// Swap
void swap(struct Node *a, struct Node *b) {
    struct Node temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up
void heapifyUp(int index) {
    int parent = (index - 1) / 2;

    if (index > 0 && heap[parent].priority > heap[index].priority) {
        swap(&heap[parent], &heap[index]);
        heapifyUp(parent);
    }
}

// Heapify Down
void heapifyDown(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < size && heap[left].priority < heap[smallest].priority)
        smallest = left;

    if (right < size && heap[right].priority < heap[smallest].priority)
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert
void insert(int value, int priority) {
    if (size == MAX) {
        printf("Queue Full\n");
        return;
    }

    heap[size].value = value;
    heap[size].priority = priority;
    heapifyUp(size);
    size++;
}

// Delete
void deleteHighestPriority() {
    if (size == 0) {
        printf("Queue Empty\n");
        return;
    }

    printf("Removed: %d\n", heap[0].value);

    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

// Peek
void peek() {
    if (size == 0) {
        printf("Empty\n");
        return;
    }
    printf("Top Element: %d (Priority: %d)\n", heap[0].value, heap[0].priority);
}

// Display
void display() {
    for (int i = 0; i < size; i++)
        printf("%d(p=%d) ", heap[i].value, heap[i].priority);
    printf("\n");
}

int main() {
    int choice, val, pri;

    while (1) {
        printf("\n1.Insert 2.Delete 3.Peek 4.Display 5.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value and priority: ");
                scanf("%d %d", &val, &pri);
                insert(val, pri);
                break;
            case 2:
                deleteHighestPriority();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
        }
    }
}