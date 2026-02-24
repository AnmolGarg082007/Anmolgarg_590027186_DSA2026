#include<stdio.h>
#include<stdlib.h>

struct n{
    int d;
    struct n *prev,*next;
}*h=NULL;

void addEnd(int x){
    struct n*p=malloc(sizeof(*p)),*t=h;
    p->d=x; p->next=NULL;
    if(!h){ p->prev=NULL; h=p; return; }
    while(t->next) t=t->next;
    t->next=p; p->prev=t;
}

void delBeg(){
    if(!h) return;
    struct n*t=h;
    h=h->next;
    if(h) h->prev=NULL;
    free(t);
}

void showF(){
    struct n*t=h;
    while(t){ printf("%d ",t->d); t=t->next; }
}

void showB(){
    struct n*t=h;
    if(!t) return;
    while(t->next) t=t->next;
    while(t){ printf("%d ",t->d); t=t->prev; }
}

int main(){
    int n,x,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){ scanf("%d",&x); addEnd(x); }
    delBeg();
    showF();
    printf("\n");
    showB();
}