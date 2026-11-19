#include <stdio.h>

int main() {
    int rows = 2, cols = 3;
    int first[2][3], second[2][3], result[2][3];
    int i, j;

    // Input elements for the first matrix
    printf("Enter first matrix elements:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &first[i][j]);
        }
    }

    // Input elements for the second matrix
    printf("Enter second matrix elements:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &second[i][j]);
        }
    }

    // Perform addition
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = first[i][j] + second[i][j];
        }
    }

    // Display result matching the assignment format
    printf("\nOUTPUT: Addition of two matrices is:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}