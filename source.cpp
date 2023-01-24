#include <iostream>
using namespace std;
#define SIZE 8
#define EMPTY '.'

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

void printBoard()
{
    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            cout << board[r][c];
        }
        cout << endl;
    }
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