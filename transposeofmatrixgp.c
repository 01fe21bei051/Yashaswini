#include <stdio.h>

#define MAX_SIZE 100

void readMatrixFromFile(char fileName[], int matrix[MAX_SIZE][MAX_SIZE], int *rows, int *cols) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    fscanf(file, "%d %d", rows, cols);

    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }

    fclose(file);
}

void writeMatrixToFile(char fileName[], int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    fprintf(file, "%d %d\n", cols, rows);

    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            fprintf(file, "%d ", matrix[j][i]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int transposedMatrix[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            transposedMatrix[i][j] = matrix[j][i];
        }
    }

    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            matrix[i][j] = transposedMatrix[i][j];
        }
    }
}

int main() {
    char inputFileName[] = "input.txt";
    char outputFileName[] = "output.txt";
    int matrix[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    readMatrixFromFile(inputFileName, matrix, &rows, &cols);

    transposeMatrix(matrix, rows, cols);

    writeMatrixToFile(outputFileName, matrix, cols, rows);

    printf("Matrix transposed and written to the file successfully.\n");

    return 0;
}

