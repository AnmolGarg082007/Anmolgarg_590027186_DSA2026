#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertEnd(int x){
    struct node *p = malloc(sizeof(struct node));
    p->data = x;

    if(head == NULL){
        head = p;
        p->next = head;
        return;
    }

    struct node *t = head;
    while(t->next != head)
        t = t->next;

    t->next = p;
    p->next = head;
}

void delBeg(){
    if(head == NULL) return;

    if(head->next == head){
        free(head);
        head = NULL;
        return;
    }

    struct node *t = head;
    while(t->next != head)
        t = t->next;

    struct node *temp = head;
    head = head->next;
    t->next = head;
    free(temp);
}

void display(){
    if(head == NULL) return;

    struct node *t = head;
    do{
        printf("%d ", t->data);
        t = t->next;
    }while(t != head);
}

int main(){
    int n,x,i;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    printf("Enter values:\n");
    for(i=0;i<n;i++){
        scanf("%d",&x);
        insertEnd(x);
    }

    delBeg();

    printf("Circular list after deletion: ");
    display();
}