#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int x){
    struct node *p = malloc(sizeof(struct node));
    p->data = x;
    p->next = NULL;

    if(head == NULL){
        head = p;
        return;
    }

    struct node *t = head;
    while(t->next != NULL)
        t = t->next;

    t->next = p;
}

void delBeg(){
    if(head == NULL) return;
    struct node *t = head;
    head = head->next;
    free(t);
}

void delEnd(){
    if(head == NULL) return;

    if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }

    struct node *t = head;
    while(t->next->next != NULL)
        t = t->next;

    free(t->next);
    t->next = NULL;
}

void delAfter(int val){
    struct node *t = head;

    while(t != NULL && t->data != val)
        t = t->next;

    if(t != NULL && t->next != NULL){
        struct node *temp = t->next;
        t->next = temp->next;
        free(temp);
    }
}

void display(){
    struct node *t = head;
    while(t != NULL){
        printf("%d ", t->data);
        t = t->next;
    }
}

int main(){
    int n,x,i,k;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    printf("Enter values:\n");
    for(i=0;i<n;i++){
        scanf("%d",&x);
        insert(x);
    }

    printf("Enter value after which delete: ");
    scanf("%d",&k);

    delBeg();
    delEnd();
    delAfter(k);

    printf("Final list: ");
    display();
}