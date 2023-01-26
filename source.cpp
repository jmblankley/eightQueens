#include <iostream>
using namespace std;
#define SIZE 8
#define EMPTY '*'

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
void solveBoard()
{
}

int main(int argc, char *argv[])
{
    initBoard();
    cout << "The unsolved board is:" << endl;
    printBoard();
    solveBoard();
    cout << "The solved board is:" << endl;
    printBoard();

    return 0;
}