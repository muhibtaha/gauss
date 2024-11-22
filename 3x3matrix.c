#include <stdio.h>

/* find the row with the largest element in the pivot column */
int find_max(float matrix[3][4], int col) {
    int max_line = col;
    for (int i = col + 1; i < 3; i++) {
        if (matrix[i][col] > matrix[max_line][col]) {
            max_line = i;
        }
    }
    return max_line;
}

/* partial pivoting and gauss elimination */
void gaussian_elimination(float matrix[3][4]) {
    for (int col = 0; col < 3; col++) {
        /* find the row with the largest element */
        int change_line = find_max(matrix, col);

        /* swap rows if necessary */
        if (change_line != col) {
            for (int i = 0; i < 4; i++) {
                float temp = matrix[col][i];
                matrix[col][i] = matrix[change_line][i];
                matrix[change_line][i] = temp;
            }
        }

        /* make the pivot element 1 */
        float pivot = matrix[col][col];
        for (int i = col; i < 4; i++) {
            matrix[col][i] /= pivot;
        }

        /* zero out other elements in the pivot column */
        for (int i = 0; i < 3; i++) {
            if (i != col) {
                float factor = matrix[i][col];
                for (int j = col; j < 4; j++) {
                    matrix[i][j] -= factor * matrix[col][j];
                }
            }
        }
    }

    /* print the solutions */
    float solution[3];
    for (int i = 0; i < 3; i++) {
        solution[i] = matrix[i][3];
        printf("x%d = %.2f\n", i + 1, solution[i]);
    }
}

int main(void) {
    float matrix[3][4] = {
        {2, 1, -1, 8},
        {-3, -1, 2, -11},
        {-2, 1, 2, -3}
    };

    gaussian_elimination(matrix);
    return 0;
}
