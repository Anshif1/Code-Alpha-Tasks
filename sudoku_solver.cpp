#include <iostream>
using namespace std;


#define N 9

void printGrid(int grid[N][N])
{
    int row, col;
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            cout << grid[row][col] << " ";
        }
        cout << "\n";
    }
}

int usedInRow(int grid[N][N], int row, int num)
{
    int col;
    for (col = 0; col < N; col++)
        if (grid[row][col] == num)
            return 1;
    return 0;
}

int usedInCol(int grid[N][N], int col, int num)
{
    int row;
    for (row = 0; row < N; row++)
        if (grid[row][col] == num)
            return 1;
    return 0;
}

int usedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
    int row, col;
    for (row = 0; row < 3; row++)
        for (col = 0; col < 3; col++)
            if (grid[row + boxStartRow][col + boxStartCol] == num)
                return 1;
    return 0;
}

int isSafe(int grid[N][N], int row, int col, int num)
{
    return !usedInRow(grid, row, num) &&
           !usedInCol(grid, col, num) &&
           !usedInBox(grid, row - row % 3, col - col % 3, num);
}

int findEmpty(int grid[N][N], int *row, int *col)
{
    for (*row = 0; *row < N; (*row)++)
        for (*col = 0; *col < N; (*col)++)
            if (grid[*row][*col] == 0)
                return 1;
    return 0;
}

int solveSudoku(int grid[N][N])
{
    int row, col, num;

    if (!findEmpty(grid, &row, &col))
        return 1;

    for (num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;

            if (solveSudoku(grid))
                return 1;

            grid[row][col] = 0;
        }
    }
    return 0;
}

int main()


{
    int grid[N][N] =
    {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},

        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},

        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };



    if (solveSudoku(grid))
    {
        cout << "Solved Sudoku:\n\n";
        printGrid(grid);
    }
    else
    {
        cout << "No solution exists";
    }

    return 0;
}