#include<stdio.h>
#include<stdlib.h>

struct n{ int d; struct n* nx; } *h=NULL;

void add(int x){
    struct n *p=malloc(sizeof(*p)), *t=h;
    p->d=x; p->nx=NULL;
    if(!h){ h=p; return; }
    while(t->nx) t=t->nx;
    t->nx=p;
}

void delBeg(){ if(h){ struct n*t=h; h=h->nx; free(t);} }

void delEnd(){
    if(!h) return;
    if(!h->nx){ free(h); h=NULL; return; }
    struct n*t=h;
    while(t->nx->nx) t=t->nx;
    free(t->nx); t->nx=NULL;
}

void delAfter(int k){
    struct n*t=h;
    while(t && t->d!=k) t=t->nx;
    if(t && t->nx){ struct n*tmp=t->nx; t->nx=tmp->nx; free(tmp); }
}

void show(){ struct n*t=h; while(t){ printf("%d ",t->d); t=t->nx; } }

int main(){
    int n,x,k,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){ scanf("%d",&x); add(x); }
    scanf("%d",&k);
    delBeg(); delEnd(); delAfter(k);
    show();
}