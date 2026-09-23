/*
 * TASK 2: Medium - Matrix Operations
 * Implements Matrix Addition, Matrix Multiplication, and Transpose
 * using functions and 2D arrays for better modularity.
 */

#include <stdio.h>

#define MAX 10

void inputMatrix(int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void displayMatrix(int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = a[i][j] + b[i][j];
}

void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX],
                       int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transposeMatrix(int mat[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[j][i] = mat[i][j];
}

int main() {
    int choice;
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2;

    printf("===== Matrix Operations =====\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Multiplication\n");
    printf("3. Transpose\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter rows and columns of matrices (must match): ");
            scanf("%d %d", &r1, &c1);
            r2 = r1;
            c2 = c1;

            printf("Enter elements of Matrix A:\n");
            inputMatrix(a, r1, c1);
            printf("Enter elements of Matrix B:\n");
            inputMatrix(b, r2, c2);

            addMatrices(a, b, result, r1, c1);

            printf("\nMatrix A:\n");
            displayMatrix(a, r1, c1);
            printf("Matrix B:\n");
            displayMatrix(b, r2, c2);
            printf("Sum (A + B):\n");
            displayMatrix(result, r1, c1);
            break;

        case 2:
            printf("Enter rows and columns of Matrix A: ");
            scanf("%d %d", &r1, &c1);
            printf("Enter rows and columns of Matrix B: ");
            scanf("%d %d", &r2, &c2);

            if (c1 != r2) {
                printf("Error: Number of columns of A must equal number of rows of B.\n");
                break;
            }

            printf("Enter elements of Matrix A:\n");
            inputMatrix(a, r1, c1);
            printf("Enter elements of Matrix B:\n");
            inputMatrix(b, r2, c2);

            multiplyMatrices(a, b, result, r1, c1, c2);

            printf("\nMatrix A:\n");
            displayMatrix(a, r1, c1);
            printf("Matrix B:\n");
            displayMatrix(b, r2, c2);
            printf("Product (A x B):\n");
            displayMatrix(result, r1, c2);
            break;

        case 3:
            printf("Enter rows and columns of the matrix: ");
            scanf("%d %d", &r1, &c1);

            printf("Enter elements of the matrix:\n");
            inputMatrix(a, r1, c1);

            transposeMatrix(a, result, r1, c1);

            printf("\nOriginal Matrix:\n");
            displayMatrix(a, r1, c1);
            printf("Transpose:\n");
            displayMatrix(result, c1, r1);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}/*
 * TASK 2: Medium - Matrix Operations
 * Implements Matrix Addition, Matrix Multiplication, and Transpose
 * using functions and 2D arrays for better modularity.
 */

#include <stdio.h>

#define MAX 10

void inputMatrix(int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void displayMatrix(int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = a[i][j] + b[i][j];
}

void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX],
                       int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transposeMatrix(int mat[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[j][i] = mat[i][j];
}

int main() {
    int choice;
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2;

    printf("===== Matrix Operations =====\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Multiplication\n");
    printf("3. Transpose\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter rows and columns of matrices (must match): ");
            scanf("%d %d", &r1, &c1);
            r2 = r1;
            c2 = c1;

            printf("Enter elements of Matrix A:\n");
            inputMatrix(a, r1, c1);
            printf("Enter elements of Matrix B:\n");
            inputMatrix(b, r2, c2);

            addMatrices(a, b, result, r1, c1);

            printf("\nMatrix A:\n");
            displayMatrix(a, r1, c1);
            printf("Matrix B:\n");
            displayMatrix(b, r2, c2);
            printf("Sum (A + B):\n");
            displayMatrix(result, r1, c1);
            break;

        case 2:
            printf("Enter rows and columns of Matrix A: ");
            scanf("%d %d", &r1, &c1);
            printf("Enter rows and columns of Matrix B: ");
            scanf("%d %d", &r2, &c2);

            if (c1 != r2) {
                printf("Error: Number of columns of A must equal number of rows of B.\n");
                break;
            }

            printf("Enter elements of Matrix A:\n");
            inputMatrix(a, r1, c1);
            printf("Enter elements of Matrix B:\n");
            inputMatrix(b, r2, c2);

            multiplyMatrices(a, b, result, r1, c1, c2);

            printf("\nMatrix A:\n");
            displayMatrix(a, r1, c1);
            printf("Matrix B:\n");
            displayMatrix(b, r2, c2);
            printf("Product (A x B):\n");
            displayMatrix(result, r1, c2);
            break;

        case 3:
            printf("Enter rows and columns of the matrix: ");
            scanf("%d %d", &r1, &c1);

            printf("Enter elements of the matrix:\n");
            inputMatrix(a, r1, c1);

            transposeMatrix(a, result, r1, c1);

            printf("\nOriginal Matrix:\n");
            displayMatrix(a, r1, c1);
            printf("Transpose:\n");
            displayMatrix(result, c1, r1);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
