#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x){
    if(rear == MAX-1){
        printf("Queue Overflow\n");
        return;
    }
    if(front == -1) front = 0;
    rear++;
    queue[rear] = x;
}

void dequeue(){
    if(front == -1 || front > rear){
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted: %d\n", queue[front]);
    front++;
}

void display(){
    if(front == -1 || front > rear){
        printf("Queue is Empty\n");
        return;
    }
    for(int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

void peek(){
    if(front == -1 || front > rear){
        printf("Queue is Empty\n");
        return;
    }
    printf("Front Element: %d\n", queue[front]);
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