#include <bits/stdc++.h>
using namespace std;

class Sudoku
{
    vector<tuple<int,int>> errorCoordinates;
    vector<tuple<int,int>> defaultCoordinates;
    char board[9][9];
    int error;

public:
    Sudoku(char b[9][9])
    {
        this->error = 0;
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                this->board[i][j] = b[i][j];
    }
    void defaultElementLocation()
    {
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(board[i][j]!='X')
                    defaultCoordinates.push_back({i,j});
    }

    int countBlankSpaces()
    {
        int count = 0;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == 'X')
                    count++;
            }
        }
        return count;
    }

    int insertElement(int r, int c, char element)
    {
        if (board[r][c] == 'X')
        {
            board[r][c] = element;
            return 1;
        }
        else if(board[r][c]!='X')
        {
            for(int i=0;i<defaultCoordinates.size();i++)
            {
                if(r==get<0>(defaultCoordinates[i]) and c == get<1>(defaultCoordinates[i]))
                    return -1;
            }
            board[r][c] = element;
            return 1;
        }
        else
            return -1;
        return -1;
    }

    bool checkNonet(int r, int c)
    {
        int nrs, ncs;
        int nre, nce;
        if (0 <= r and r <= 2)
        {
            nrs = 0;
            nre = 2;
            if (c >= 0 and c <= 2)
            {
                ncs = 0;
                nce = 2;
            }
            else if (c >= 3 and c <= 5)
            {
                ncs = 3;
                nce = 5;
            }
            else
            {
                ncs = 6;
                nce = 8;
            }
        }
        else if (3 <= r and r <= 5)
        {
            nrs = 3;
            nre = 5;
            if (c >= 0 and c <= 2)
            {
                ncs = 0;
                nce = 2;
            }
            else if (c >= 3 and c <= 5)
            {
                ncs = 3;
                nce = 5;
            }
            else
            {
                ncs = 6;
                nce = 8;
            }
        }
        else if(r>=6 and r<=8)
        {
            nrs = 6;
            nre = 8;
            if (c >= 0 and c <= 2)
            {
                ncs = 0;
                nce = 2;
            }
            else if (c >= 3 and c <= 5)
            {
                ncs = 3;
                nce = 5;
            }
            else
            {
                ncs = 6;
                nce = 8;
            }
        }

        int a[9] = {0};
        for (int i = nrs; i <= nre; i++)
        {
            for (int j = ncs; j <= nce; j++)
            {
                if((int)board[i][j]!='X')
                    a[(int)board[i][j] - 49] += 1;
            }
        }
        for (int i = 0; i < 9; i++)
        {
            if (a[i] > 1)
                return false;
        }
        return true;
    }

    bool checkRowColumn(int r, int c)
    {
        int a[9] = {0};
        int b[9] = {0};
        for (int i = 0; i < 9; i++)
        {
            if (board[r][i] != 'X')
                a[(int)board[r][i] - 49] += 1;
            if (board[i][c] != 'X')
                b[(int)board[i][c] - 49] += 1;
        }
        for (int i = 0; i < 9; i++)
        {
            if (a[i] > 1 || b[i] > 1)
                return false;
        }
        return true;
    }

    void errorsDisplay()
    {
        cout << "Number of errors: " << error << endl;
        cout << "Errors in:" << endl;
        if(error!=0)
            for (int i = 0; i < errorCoordinates.size(); i++)
                cout << "Row: " << get<0>(errorCoordinates[i]) << " Column: " << get<1>(errorCoordinates[i]) << endl;
        else
            cout<<"None"<<endl;
    }

    int errorUpdate(int i,int j)
    {

        if (checkRowColumn(i, j) != true or checkNonet(i, j) != true)
        {
            errorCoordinates.push_back({i,j});
            //errorColNo.push_back(j);
            error++;
        }
        
        errorsDisplay();
        return error;
    }

    void clearing()
    {
        error = 0;
        errorCoordinates.clear();
    }

    void displayBoard()
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }


};
