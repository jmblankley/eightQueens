#include <iostream>
using namespace std;
#define SIZE 8
#define EMPTY ' '

char board[SIZE][SIZE];

void initBoard()
{
    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            board[r][c] = EMPTY;
        }
    }
}

void printRow(int row)
{
    // iterate through each column
    for (int c = 0; c < SIZE; c++)
    {
        // print out the value in each column
        cout << '|' << board[row][c];
    }
    cout << '|' << endl;
}

void printBorder()
{
    // print a series of + and - at SIZE
    for (int c = 0; c < SIZE; c++)
    {
        cout << '+' << '-';
    }
    cout << '+' << endl;
}

void printBoard()
{
    // iterate through each row
    for (int r = 0; r < SIZE; r++)
    {
        printBorder();
        // print out the row
        printRow(r);
    }
    printBorder();
}

bool canPlace(int inRow, int inCol)
{
    // check my row
    for (int c = 0; c < inCol; c++)
    {
        // is there a queen in the position we are checking?
        if (board[inRow][c] == 'Q')
        {
            return false;
        }
    }

    // check upper left diagonal

    // check my lower left diagonal
    return true;
}

void solveBoard(int colForNextQueen)
{
    // if you've gotten beyond right edge of board, you've placed a queen in every other column, so you have solved the problem.
    if (colForNextQueen >= SIZE)
    {
        return;
    }
    // try every row in this column
    for (int r = 0; r < SIZE; r++)
    {
        if (canPlace(r, colForNextQueen))
        {
            // put a queen here!
            board[r][colForNextQueen] = 'Q';

            // if so, try next columm...
            solveBoard(colForNextQueen + 1);
        }
    }
}

int main(int argc, char *argv[])
{
    initBoard();
    cout << "The unsolved board is:" << endl;
    printBoard();
    solveBoard(0);
    cout << "The solved board is:" << endl;
    printBoard();

    return 0;
}