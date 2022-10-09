#include "Sudo.h"
int main()
{
    int row, column;
    char element;
    char board[9][9] =
        {{'5', '3', 'X', 'X', '7', 'X', 'X', 'X', 'X'},
         {'6', 'X', '8', '1', '9', '5', 'X', 'X', 'X'},
         {'X', '9', 'X', 'X', 'X', 'X', 'X', '6', 'X'},
         {'8', 'X', 'X', 'X', '6', 'X', 'X', 'X', '3'},
         {'4', 'X', 'X', '8', 'X', '3', 'X', 'X', '1'},
         {'7', 'X', 'X', 'X', '2', 'X', 'X', 'X', '6'},
         {'X', '6', 'X', 'X', 'X', 'X', '2', '8', 'X'},
         {'X', 'X', 'X', '4', '1', '9', 'X', 'X', '5'},
         {'X', 'X', 'X', 'X', '8', 'X', 'X', '7', '9'}};
    Sudoku s(board);
    while (s.countBlankSpaces() != 0)
    {
        s.displayBoard();
        cout << "Enter the row and column number where the element is to be inserted\n";
        cin >> row;
        cin >> column;
        cout << "Enter the element to be inserted: ";
        cin >> element;
        if (s.insertElement(row - 1, column - 1, element) == -1)
        {
            cout << "Wrong Place" << endl;
        }
        else
            s.insertElement(row - 1, column - 1, element);
        s.errorUpdate(row-1,column-1);
        cout<<"No. of blank spaces remaining: "<<s.countBlankSpaces()<<endl;
    }
    return 0;
}