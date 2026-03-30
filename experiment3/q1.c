#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;

void push(int x){
    if(top == MAX-1)
        printf("Overflow\n");
    else
        stack[++top] = x;
}

void pop(){
    if(top == -1)
        printf("Underflow\n");
    else
        printf("Popped: %d\n", stack[top--]);
}

void display(){
    if(top == -1)
        printf("Empty\n");
    else{
        for(int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
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