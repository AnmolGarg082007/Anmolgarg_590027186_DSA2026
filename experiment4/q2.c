#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int x){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;

    if(rear == NULL){
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue(){
    if(front == NULL){
        printf("Queue Underflow\n");
        return;
    }
    struct node* temp = front;
    printf("Deleted: %d\n", temp->data);
    front = front->next;

    if(front == NULL) rear = NULL;
    free(temp);
}

void display(){
    if(front == NULL){
        printf("Queue is Empty\n");
        return;
    }
    struct node* temp = front;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void peek(){
    if(front == NULL){
        printf("Queue is Empty\n");
        return;
    }
    printf("Front Element: %d\n", front->data);
}

int main(){
    int choice, x;
    while(1){
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Peek 5.Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1: printf("Enter value: "); scanf("%d",&x); enqueue(x); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: peek(); break;
            case 5: return 0;
            default: printf("Invalid Choice\n");
        }
    }
}