#include <stdio.h>

// define a structure
struct InfoStruct
{
    int id;
    double value;
    char grade;
};

// define a union
union InfoUnion
{
    int id;
    double value;
    char grade;
};

int main()
{
    printf("Memory occupied by structure : %lu bytes\n",
           sizeof(struct InfoStruct));

    printf("Memory occupied by union     : %lu bytes\n",
           sizeof(union InfoUnion));

    return 0;
}
