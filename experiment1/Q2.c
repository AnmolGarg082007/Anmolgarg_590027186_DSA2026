#include <stdio.h>
#include <stdlib.h>

// Function to insert elements
void insertValues(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter value at position %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// Function to display elements
void showArray(int *arr, int size)
{
    printf("\nArray Elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to calculate sum
int calculateSum(int *arr, int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        total += arr[i];
    }
    return total;
}

int main()
{
    int n;
    int *dynamicArray = NULL;

    printf("Enter number of elements (N): ");
    scanf("%d", &n);

    dynamicArray = (int *)malloc(n * sizeof(int));

    if (dynamicArray == NULL)
    {
        printf("Memory allocation unsuccessful!\n");
        return 1;
    }

    insertValues(dynamicArray, n);
    showArray(dynamicArray, n);

    int sum = calculateSum(dynamicArray, n);
    float avg = (float)sum / n;

    printf("Sum of elements = %d\n", sum);
    printf("Average of elements = %.2f\n", avg);

    free(dynamicArray);
    dynamicArray = NULL;

    printf("Memory released successfully.\n");

    return 0;
}
