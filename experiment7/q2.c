#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void init() {
    for(int i=0;i<SIZE;i++)
        hashTable[i] = -1;
}

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hash(key);
    while(hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }
    hashTable[index] = key;
    printf("Inserted %d\n", key);
}

void search(int key) {
    int index = hash(key);
    int start = index;

    while(hashTable[index] != -1) {
        if(hashTable[index] == key) {
            printf("Found %d at index %d\n", key, index);
            return;
        }
        index = (index + 1) % SIZE;
        if(index == start) break;
    }
    printf("Not Found\n");
}

void delete(int key) {
    int index = hash(key);
    int start = index;

    while(hashTable[index] != -1) {
        if(hashTable[index] == key) {
            hashTable[index] = -1;
            printf("Deleted %d\n", key);
            return;
        }
        index = (index + 1) % SIZE;
        if(index == start) break;
    }
    printf("Not Found\n");
}

void display() {
    for(int i=0;i<SIZE;i++)
        printf("%d ", hashTable[i]);
    printf("\n");
}

int main() {
    init();
    insert(10);
    insert(20);
    insert(30);
    display();

    search(20);
    delete(20);
    display();

    return 0;
}