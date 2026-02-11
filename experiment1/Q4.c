#include <stdio.h>
#include <stdlib.h>

// Function to create matrix dynamically
int **createMatrix(int r, int c)
{
    int **mat;
    mat = (int **)malloc(r * sizeof(int *));
    
    for (int i = 0; i < r; i++)
    {
        mat[i] = (int *)malloc(c * sizeof(int));
    }
    return mat;
}

// Function to input matrix elements
void inputMatrix(int **mat, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

// Function to display matrix
void displayMatrix(int **mat, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Free allocated memory
void freeMatrix(int **mat, int r)
{
    for (int i = 0; i < r; i++)
    {
        free(mat[i]);
    }
    free(mat);
}

int main()
{
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0)
    {
        printf("Invalid matrix size!\n");
        return 1;
    }

    int **matrixA = createMatrix(rows, cols);
    int **matrixB = createMatrix(rows, cols);
    int **resultAdd = createMatrix(rows, cols);
    int **resultSub = createMatrix(rows, cols);

    printf("\nEnter elements of Matrix A:\n");
    inputMatrix(matrixA, rows, cols);

    printf("\nEnter elements of Matrix B:\n");
    inputMatrix(matrixB, rows, cols);

    // Perform Addition & Subtraction
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            resultAdd[i][j] = matrixA[i][j] + matrixB[i][j];
            resultSub[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }

    printf("\nMatrix Addition Result:\n");
    displayMatrix(resultAdd, rows, cols);

    printf("\nMatrix Subtraction Result:\n");
    displayMatrix(resultSub, rows, cols);

    // Free memory
    freeMatrix(matrixA, rows);
    freeMatrix(matrixB, rows);
    freeMatrix(resultAdd, rows);
    freeMatrix(resultSub, rows);

    printf("\nMemory deallocated successfully.\n");

    return 0;
}
