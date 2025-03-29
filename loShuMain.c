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
            sums[i] += array[i][j]; // Calculate sums of row
            sums[j + 3] += array[i][j]; // Calculate sums of column
            if (i == j) sums[2 * 3] += array[i][j]; // Calculate first diagonal sums
            if (i + j == 3 - 1) sums[2 * 3 + 1] += array[i][j]; // Calculate second diagonal sums
        }
    }

    // Checks if all sums are equal
    for (int k = 1; k < 3 * 2 + 2; k++) {
        if (sums[k] != sums[0]) {
            return false; // If any sum is not, return false
        }
    }

    return true;
}

void printArray(int array[3][3]) //printing function for multi-dimensional array
{
    if(isMagicSquare(array) == true) //checks if it even should print
    {
        for (int i = 0; i < 3; i++) { //loops through the rows
            for (int j = 0; j < 3; j++) //loops through the columns
            {
                //for formating
                if(j == 0)
                    {
                        printf("["); 
                        printf("%d ", array[i][j]);
                    }
                else if(j == 1)
                    {
                        printf("%d ", array[i][j]);
                    }         
                else if(j == 2)
                    {
                        printf("%d", array[i][j]);
                        printf("]");
                    }              
            }
            printf("\n");
        }
    }
    else if(isMagicSquare(array) == false) //if false, then it is not a magic square
    {
        printf("This array is not a Lo Shu Magic Square\n\n");
    }
}

int main(){ 
    int loShu[3][3] = { {4, 9, 2}, {3, 5, 7}, {8, 1, 6} };
    int notLoShu[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int randomLoShu[3][3];
    printf("\nChecking if 'notLoShu' is magic square array.\n");
    printArray(notLoShu);
    printArray(loShu);
    printf("\n");

    int attempts = 0;
    do {
        attempts++;
        int nums[9] = {0}; // Array tracks used numbers

        // Populates array with random numbers from 1 to 9 w/o used numbers
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num;
                do {
                    num = rand() % 9 + 1;
                } while (nums[num - 1] != 0); // no repetition of numbers
                nums[num - 1] = 1; // Marks number as used
                randomLoShu[i][j] = num;
            }
        }
    } while (!isMagicSquare(randomLoShu));
    printArray(randomLoShu);
    printf("\n");
    printf("Attempts: %d", attempts);
    return 0;
}
