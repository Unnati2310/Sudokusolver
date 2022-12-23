// sudokusolver
#include <iostream>
#include <cmath>
using namespace std;

void Print(int board[][9], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
bool isvalid(int board[][9], int i, int j, int num, int n)
{
    for (int x = 0; x < n; x++)
    {
        if (board[i][x] == num || board[x][j] == num)
        {
            return false;
        }
    }
    int r = sqrt(n);
    int i1 = i - i % r;
    int j1 = j - j % r;
    for (int x = i1; x < i1 + r; x++)
    {
        for (int y = j1; y < j1 + r; y++)
        {
            if (board[x][y] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool Sudoku(int board[][9], int i, int j, int n)
{
    // base case
    if (i == n)
    {
        Print(board, n);
        return true;
    }
    if (j == n)
    {
        return Sudoku(board, i + 1, 0, n);
    }

    if (board[i][j] != 0)
    {
        return Sudoku(board, i, j + 1, n);
    }

    for (int num = 1; num <= 9; num++)
    {
        if (isvalid(board, i, j, num, n))
        {
            board[i][j] = num;
            bool Ans1 = Sudoku(board, i, j + 1, n);
            if (Ans1)
            {
                return true;
            }
            // backtracking: undo the change
            board[i][j] = 0;
        }
    }
    return false;
}

int main()
{ // given a filled board
    int n = 9;
    int board[9][9] = {{0, 0, 7, 1, 0, 0, 0, 6, 0},
                       {1, 0, 5, 2, 0, 8, 0, 0, 0},
                       {6, 0, 0, 0, 0, 7, 1, 2, 0},
                       {3, 1, 2, 4, 0, 5, 0, 0, 8},
                       {0, 0, 6, 0, 9, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 3, 0, 0, 1},
                       {0, 0, 1, 0, 0, 4, 9, 8, 6},
                       {8, 0, 3, 9, 0, 6, 0, 0, 0},
                       {0, 6, 0, 0, 8, 2, 7, 0, 3}};

    Sudoku(board, 0, 0, n);
    return 0;
}
