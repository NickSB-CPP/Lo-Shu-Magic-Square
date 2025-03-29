#include <string.h> 
#include <stdbool.h>
#include <stdlib.h> 
#include <stdio.h>

static bool isMagicSquare(int array[3][3]) 
{
    int sums[8] = {0};

    // Calculate the sums of rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sums[i] += array[i][j]; // Calculate row sums
            sums[j + 3] += array[i][j]; // Calculate column sums
            if (i == j) sums[2 * 3] += array[i][j]; // Calculate main diagonal sum
            if (i + j == 3 - 1) sums[2 * 3 + 1] += array[i][j]; // Calculate secondary diagonal sum
        }
    }

    // Check if all sums are equal to the first row sum (index 0)
    for (int k = 1; k < 3 * 2 + 2; k++) {
        if (sums[k] != sums[0]) {
            return false; // If any sum is not equal, it's not a Lo Shu Magic Square
        }
    }

    return true;
}

