#include <stdio.h>
#include <string.h>

int main(){
    char str[100], queue[100];
    int front = 0, rear = -1;

    printf("Enter string: ");
    scanf("%s", str);

    for(int i=0; str[i]; i++)
        queue[++rear] = str[i];

    int flag = 1;

    for(int i=0; i<=rear; i++){
        if(str[i] != queue[rear-i]){
            flag = 0;
            break;
        }
    }

    if(flag) printf("Palindrome\n");
    else printf("Not Palindrome\n");
}