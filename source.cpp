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
    // these variables move back one in the row and up one in the column
    int checkCol = inCol - 1;
    int checkRow = inRow - 1;
    while (checkCol >= 0 && checkRow >= 0)
    {
        if (board[checkRow][checkCol] == 'Q')
        {
            return false;
        }

        // take where you are now and move back one and up one...
        checkRow--;
        checkCol--;
        //...until loop ends
    }

    // check my lower left diagonal
    checkCol = inCol - 1;
    checkRow = inRow + 1;
    while (checkCol >= 0 && checkRow < SIZE)
    {
        if (board[checkRow][checkCol] == 'Q')
        {
            return false;
        }

        // take where you are now and move back one and up one...
        checkRow++;
        checkCol--;
        //...until loop ends
    }
    return true;
}

//***THIS BLOCK IS VERY IMPORTANT FOR PROJECT 2!!!***
// PROJECT 2: don't worry about checking columns
bool solveBoard(int colForNextQueen)
{
    // if you've gotten beyond right edge of board, you've placed a queen in every other column, so you have solved the problem.
    // this actually counts the number of queens we've places as well **IMPORTANT FOR PROJECT 2!!!!**
    if (colForNextQueen >= SIZE)
    {
        return true;
    }
    // try every row in this column
    for (int rowNumber = 0; rowNumber < SIZE; rowNumber++)
    {
        if (canPlace(rowNumber, colForNextQueen))
        {
            // put a queen here!
            board[rowNumber][colForNextQueen] = 'Q';

            if (solveBoard(colForNextQueen + 1))
            {
                return true;
            }
            // if we get here, the placed queen didn't work ...
            //  .. so we should "remove" it
            // putting a dot in this char it leaves a breadcrum of where it tried to place a queen and failed
            // putting a space leaves no trace
            board[rowNumber][colForNextQueen] = ' ';
        }
    }
    // tried every possible row, but none worked if we get here (i.e. completed for lopp)
    return false;
}

int main(int argc, char *argv[])
{
    initBoard();
    cout << "The unsolved board is:" << endl;
    printBoard();
    if (solveBoard(0))
    {
        cout << "The solved board is:" << endl;
        printBoard();
    }
    else
    {
        cout << "No solution!!!" << endl;
    }

    return 0;
}