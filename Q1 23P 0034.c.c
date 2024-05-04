#include "stdio.h"

#define ROWS 20
#define COLS 20

int grid[ROWS][COLS] = {
    {  8,  2, 22, 97, 38, 15,  0, 40,  0, 75,  4,  5,  7, 78, 12, 52, 50, 77, 91,  8 },
    { 49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48,  4, 56, 62,  0 },
    { 81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30,  3, 49, 13, 36, 65 },
    { 52, 70, 95, 23,  4, 60, 11, 42, 69, 24, 68, 56,  1, 32, 56, 71, 37,  2, 36, 91 },
    { 22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80 },
    { 24, 47, 32, 60, 99,  3, 45,  2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50 },
    { 21, 36, 23,  9, 75,  0, 76, 44, 20, 45, 35, 14,  0, 61, 33, 97, 34, 31, 33, 95 },
    { 78, 17, 53, 28, 22, 75, 31, 67, 15, 94,  3, 80,  4, 62, 16, 14,  9, 53, 56, 92 },
    { 16, 39,  5, 42, 96, 35, 31, 47, 55, 58, 88, 24,  0, 17, 54, 24, 36, 29, 85, 57 },
    { 86, 56,  0, 48, 35, 71, 89,  7,  5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58 },
    { 19, 80, 81, 68,  5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77,  4, 89, 55, 40 },
    {  4, 52,  8, 83, 97, 35, 99, 16,  7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66 },
    { 20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74,  4, 36, 16 },
    { 20, 73, 35, 29, 78, 31, 90,  1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57,  5, 54 },
    {  1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52,  1, 89, 19, 67, 48 }
};

int calculateProduct(int row, int col, int rowDir, int colDir) {
    int product = 1;
    for (int i = 0; i < 4; i++) {
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
            return 0;
        }
        product *= grid[row][col];
        row += rowDir;
        col += colDir;
    }
    return product;
}

int main() {
    int maxProduct = 0;
    char direction[20];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int temp = calculateProduct(i, j, 0, 1); // Horizontal
            if (temp > maxProduct) {
                maxProduct = temp;
                sprintf(direction, "horizontal");
            }
            temp = calculateProduct(i, j, 1, 0); // Vertical
            if (temp > maxProduct) {
                maxProduct = temp;
                sprintf(direction, "vertical");
            }
            temp = calculateProduct(i, j, 1, 1); // Diagonal down-right
            if (temp > maxProduct) {
                maxProduct = temp;
                sprintf(direction, "diagonal down-right");
            }
            temp = calculateProduct(i, j, -1, 1); // Diagonal up-right
            if (temp > maxProduct) {
                maxProduct = temp;
                sprintf(direction, "diagonal up-right");
            }
        }
    }

    printf("The largest product of four adjacent numbers is %d, direction: %s.\n", maxProduct, direction);
    return 0;
}