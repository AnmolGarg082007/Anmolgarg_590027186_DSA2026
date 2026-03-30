#include <stdio.h>

int q1[100], q2[100];
int f1=0,r1=-1,f2=0,r2=-1;

void push(int x){
    q2[++r2] = x;

    while(f1 <= r1)
        q2[++r2] = q1[f1++];

    f1 = 0; r1 = -1;

    while(f2 <= r2)
        q1[++r1] = q2[f2++];

    f2 = 0; r2 = -1;
}

void pop(){
    if(f1 > r1){
        printf("Stack Empty\n");
        return;
    }
    printf("Popped: %d\n", q1[f1++]);
}

void peek(){
    if(f1 > r1){
        printf("Stack Empty\n");
        return;
    }
    printf("Top: %d\n", q1[f1]);
}

void display(){
    for(int i=f1;i<=r1;i++)
        printf("%d ", q1[i]);
    printf("\n");
}

int main(){
    int ch,x;
    while(1){
        printf("\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\n");
        scanf("%d",&ch);

        switch(ch){
            case 1: scanf("%d",&x); push(x); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: return 0;
        }
    }
}