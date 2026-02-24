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

void reverseData(){
    struct node *i = head, *j;
    while(i != NULL){
        j = i->next;
        while(j != NULL){
            int temp = i->data;
            i->data = j->data;
            j->data = temp;
            j = j->next;
        }
        i = i->next;
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
    int n,x,i;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    printf("Enter values:\n");
    for(i=0;i<n;i++){
        scanf("%d",&x);
        insert(x);
    }

    reverseData();

    printf("Reversed data list: ");
    display();
}