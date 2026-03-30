#include <stdio.h>
#include <string.h>

int main(){
    char str[100], stack[100];
    int top = -1;

    printf("Enter string: ");
    scanf("%s", str);

    for(int i=0; str[i]; i++)
        stack[++top] = str[i];

    for(int i=0; str[i]; i++)
        str[i] = stack[top--];

    printf("Reversed: %s", str);
}