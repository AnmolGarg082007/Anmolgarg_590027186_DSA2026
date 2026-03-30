#include <stdio.h>
#include <ctype.h>

int stack[100], top = -1;

int main(){
    char exp[100];

    printf("Enter postfix: ");
    scanf("%s", exp);

    for(int i=0; exp[i]; i++){
        if(isdigit(exp[i]))
            stack[++top] = exp[i] - '0';
        else{
            int b = stack[top--];
            int a = stack[top--];

            if(exp[i]=='+') stack[++top] = a+b;
            if(exp[i]=='-') stack[++top] = a-b;
            if(exp[i]=='*') stack[++top] = a*b;
            if(exp[i]=='/') stack[++top] = a/b;
        }
    }

    printf("Result = %d", stack[top]);
}