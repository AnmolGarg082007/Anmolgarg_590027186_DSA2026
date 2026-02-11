#include <stdio.h>

// Union declaration
union MixedData
{
    int number;
    float decimal;
    char letter;
};

int main()
{
    union MixedData data;

    data.number = 100;
    printf("After assigning int:\n");
    printf("number = %d\n", data.number);

    data.decimal = 45.67;
    printf("\nAfter assigning float:\n");
    printf("decimal = %.2f\n", data.decimal);

    data.letter = 'A';
    printf("\nAfter assigning char:\n");
    printf("letter = %c\n", data.letter);

    printf("\nSize of union = %lu bytes\n", sizeof(data));

    return 0;
}
