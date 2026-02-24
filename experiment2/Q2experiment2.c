#include<stdio.h>
#include<stdlib.h>

struct n{
    int v;
    struct n *nxt;
};

int main(){
    struct n *h=NULL,*t;
    int n,x,key,i,pos=1;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        struct n *p=malloc(sizeof(struct n));
        scanf("%d",&x);
        p->v=x;
        p->nxt=h;
        h=p;
    }

    scanf("%d",&key);

    t=h;
    while(t){
        if(t->v==key){
            printf("Found at %d",pos);
            return 0;
        }
        t=t->nxt;
        pos++;
    }

    printf("Not Found");
}