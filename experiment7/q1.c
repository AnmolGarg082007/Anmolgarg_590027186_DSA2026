#include <stdio.h>

int main() {
    int sap;
    printf("Enter SAP ID: ");
    scanf("%d", &sap);

    int last3 = sap % 1000;
    int family = last3 % 10;

    printf("Last 3 digits: %d\n", last3);
    printf("Family: %d\n", family);

    return 0;
}