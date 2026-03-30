#include <stdio.h>

int main(){
    char exp[100], stack[100];
    int top = -1, flag = 1;

    printf("Enter expression: ");
    scanf("%s", exp);

    for(int i=0; exp[i]; i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            stack[++top] = exp[i];
        else{
            if(top == -1){ flag = 0; break; }

            if((exp[i]==')' && stack[top]=='(') ||
               (exp[i]=='}' && stack[top]=='{') ||
               (exp[i]==']' && stack[top]=='['))
                top--;
            else{
                flag = 0;
                break;
            }
        }
    }

    if(top != -1) flag = 0;

    if(flag) printf("Balanced");
    else printf("Not Balanced");
}