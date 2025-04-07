#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 15

void printSolution(int board[MAX_N][MAX_N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[MAX_N][MAX_N], int row, int col, int n) {
    // Check this column on the upper side
    for (int i = 0; i < row; i++) {
        if (board[i][col]) {
            return false;
        }
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check upper diagonal on the right side
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

void solveNQueensUtil(int board[MAX_N][MAX_N], int row, int n, int *solutionCount) {
    if (row >= n) {
        (*solutionCount)++;
        printSolution(board, n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            solveNQueensUtil(board, row + 1, n, solutionCount);
            board[row][col] = 0; // Backtrack
        }
    }
}

void solveNQueens(int n) {
    int board[MAX_N][MAX_N] = {0};
    int solutionCount = 0;

    solveNQueensUtil(board, 0, n, &solutionCount);

    printf("Number of solutions: %d\n", solutionCount);
}

int main() {
    int n = 8; // Change this value for different board sizes
    solveNQueens(n);
    return 0;
}