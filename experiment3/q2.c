#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int x){
    struct node* temp = malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

void pop(){
    if(top == NULL)
        printf("Underflow\n");
    else{
        struct node* temp = top;
        printf("Popped: %d\n", temp->data);
        top = top->next;
        free(temp);
    }
}

void display(){
    struct node* temp = top;
    if(temp == NULL)
        printf("Empty\n");
    else{
        while(temp){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    int ch, x;
    while(1){
        printf("\n1.Push 2.Pop 3.Display 4.Exit\n");
        scanf("%d",&ch);

        switch(ch){
            case 1: scanf("%d",&x); push(x); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: return 0;
        }
    }
}