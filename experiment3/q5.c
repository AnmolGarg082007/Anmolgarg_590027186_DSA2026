#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

int prec(char c){
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/') return 2;
    return 0;
}

int main(){
    char exp[100], res[100];
    int k = 0;

    printf("Enter infix: ");
    scanf("%s", exp);

    for(int i=0; exp[i]; i++){
        if(isalnum(exp[i]))
            res[k++] = exp[i];
        else if(exp[i]=='(')
            stack[++top] = exp[i];
        else if(exp[i]==')'){
            while(stack[top] != '(')
                res[k++] = stack[top--];
            top--;
        }
        else{
            while(top!=-1 && prec(stack[top]) >= prec(exp[i]))
                res[k++] = stack[top--];
            stack[++top] = exp[i];
        }
    }

    while(top!=-1)
        res[k++] = stack[top--];

    res[k] = '\0';

    printf("Postfix: %s", res);
}