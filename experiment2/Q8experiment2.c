#include<stdio.h>
#include<stdlib.h>

struct n{
    int d;
    struct n *prev,*next;
}*h=NULL;

void add(int x){
    struct n*p=malloc(sizeof(*p));
    p->d=x;
    if(!h){
        h=p;
        p->next=p;
        p->prev=p;
        return;
    }
    struct n*t=h->prev;
    t->next=p;
    p->prev=t;
    p->next=h;
    h->prev=p;
}

void delBeg(){
    if(!h) return;
    if(h->next==h){ free(h); h=NULL; return; }
    struct n*t=h->prev,*tmp=h;
    h=h->next;
    h->prev=t;
    t->next=h;
    free(tmp);
}

void show(){
    if(!h) return;
    struct n*t=h;
    do{
        printf("%d ",t->d);
        t=t->next;
    }while(t!=h);
}

int main(){
    int n,x,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){ scanf("%d",&x); add(x); }
    delBeg();
    show();
}