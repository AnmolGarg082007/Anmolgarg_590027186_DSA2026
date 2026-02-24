#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct s{
    int roll,marks;
    char name[50];
    struct s*next;
}*h=NULL;

void add(int r,char n[],int m){
    struct s*p=malloc(sizeof(*p)),*t=h;
    p->roll=r; p->marks=m;
    strcpy(p->name,n);
    p->next=NULL;
    if(!h){ h=p; return; }
    while(t->next) t=t->next;
    t->next=p;
}

void show(){
    struct s*t=h;
    while(t){
        printf("%d %s %d\n",t->roll,t->name,t->marks);
        t=t->next;
    }
}

int main(){
    int n,r,m,i;
    char name[50];

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%s%d",&r,name,&m);
        add(r,name,m);
    }

    show();
}