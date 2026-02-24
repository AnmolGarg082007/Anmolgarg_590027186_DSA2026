#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct n{
    int c,e;
    struct n*next;
}*h=NULL;

void add(int c,int e){
    struct n*p=malloc(sizeof(*p)),*t=h;
    p->c=c; p->e=e; p->next=NULL;
    if(!h){ h=p; return; }
    while(t->next) t=t->next;
    t->next=p;
}

int eval(int x){
    int sum=0;
    struct n*t=h;
    while(t){
        sum+=t->c*pow(x,t->e);
        t=t->next;
    }
    return sum;
}

int main(){
    int n,c,e,x,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&c,&e);
        add(c,e);
    }
    scanf("%d",&x);
    printf("%d",eval(x));
}