#include <stdio.h>

#define MAX 10

// Function prototypes
void inputMatrix(int matrix[MAX][MAX], int rows, int cols);
void displayMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void multiplyMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2);
void transposeMatrix(int matrix[MAX][MAX], int transpose[MAX][MAX], int rows, int cols);

int main() {
    int matA[MAX][MAX], matB[MAX][MAX], result[MAX][MAX], transposed[MAX][MAX];
    int r1, c1, r2, c2;

    printf("--- Matrix Dimensions ---\n");
    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &r2, &c2);

    // 1. Input Matrix A
    printf("\n--- Input Matrix A (%dx%d) ---\n", r1, c1);
    inputMatrix(matA, r1, c1);

    // 2. Input Matrix B
    printf("\n--- Input Matrix B (%dx%d) ---\n", r2, c2);
    inputMatrix(matB, r2, c2);

    // Display inputs
    printf("\nMatrix A:\n");
    displayMatrix(matA, r1, c1);
    printf("\nMatrix B:\n");
    displayMatrix(matB, r2, c2);

    // 3. Matrix Addition
    printf("\n=== Matrix Addition ===\n");
    if (r1 == r2 && c1 == c2) {
        addMatrices(matA, matB, result, r1, c1);
        printf("Result of Addition:\n");
        displayMatrix(result, r1, c1);
    } else {
        printf("Error: Matrices must have identical dimensions for addition.\n");
    }

    // 4. Matrix Multiplication
    printf("\n=== Matrix Multiplication ===\n");
    if (c1 == r2) {
        multiplyMatrices(matA, matB, result, r1, c1, c2);
        printf("Result of Multiplication:\n");
        displayMatrix(result, r1, c2);
    } else {
        printf("Error: Columns of Matrix A must equal Rows of Matrix B for multiplication.\n");
    }

    // 5. Matrix Transpose
    printf("\n=== Matrix Transpose ===\n");
    transposeMatrix(matA, transposed, r1, c1);
    printf("Transpose of Matrix A:\n");
    displayMatrix(transposed, c1, r1); // Note: rows and columns are swapped for display

    return 0;
}

// Function to take matrix input from user
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2) {
    // Initialize the result matrix with zeros
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }

    // Perform multiplication
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX][MAX], int transpose[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}
