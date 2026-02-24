#include<stdio.h>
#include<stdlib.h>

struct n{ int d; struct n *n; }*h=NULL;

void add(int x,int k){
    struct n *p=malloc(sizeof(struct n)),*t=h;
    p->d=x; p->n=NULL;

    if(!h || k==0){ p->n=h; h=p; return; }

    while(t->n) t=t->n;
    t->n=p;
}

void show(){
    struct n *t=h;
    while(t){ printf("%d ",t->d); t=t->n; }
}

int main(){
    int n,x,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){ scanf("%d",&x); add(x,1); }

    add(100,0);  // beginning
    add(200,1);  // end

    show();
}