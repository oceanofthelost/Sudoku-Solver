#include<iostream>
#include<string>
#include"SudokuSolver.h"
using namespace std;

//start using const and const reference variables

SudokuSolver::SudokuSolver(char*& rawBoard)
{
    string board(rawBoard);
    for(unsigned i = 0; i<9; i++)
    {
        for(unsigned j = 0; j<9; j++)
        {
            cell[i][j] = board[i*9+j] - '0';
        }
    }    
    cout<<"The initial game board"<<endl;
    print();
}

//user API for solving
void SudokuSolver::solve()
{
    if(backtrackSolve())
    {
        print();
    }
    else
    {
        cout<<"This is temperary"<<endl;
    }
}

//user API for print
void SudokuSolver::print()
{
    for(unsigned i = 0; i<9; i++)
    {
        for(unsigned j = 0; j<9; j++)
        {
            cout<< cell[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool SudokuSolver::backtrackSolve()
{
    unsigned row;
    unsigned column;
    unsigned result = openCell();
    bool valid;

    if(result < 0)
    {
        return true;
    }
    
    row     = result/10;
    column  = result%10; 

    for(unsigned k = 1; k <= 9; k++)
    {
        cell[row][column] = k;
        if(isValid(row,column))
        {
            if(backtrackSolve())
            {
                return true;
            }
        }
    }
    return false;
}

//return -1 if no open cells
//return xy for vali number. xy is a 2 digit number 
//      representing the row and column of the open cell
int SudokuSolver::openCell()
{
    for(unsigned row = 0; row < 9; row++)
    {
        for(unsigned column = 0; column < 9; column++)
        {
            if(cell[row][column]==0)
            {
                return row*10+column;
            }
        }
    }
    return -1;
}

bool isValid(unsigned row, unsigned column)
{
    bool valid = (validRow(row, column) && validColumn(row, column) && validBox(row,column));

    return valid;
}

#if 0
bool validRow(sudokuBoard passed,unsigned row, unsigned column)
{
    bool valid = true;

    for(auto i = 0;i<9;i++)
    {
        if(passed.space[row][column]==passed.space[row][i] && i != column)
        {
            valid = false;
        }
    }
    return valid;
}

bool validColumn(sudokuBoard passed, unsigned row, unsigned column)
{
    bool valid = true;

    for(auto i = 0;i<9;i++)
    {
        if(passed.space[row][column]==passed.space[i][column] && i != row)
        {
            valid = false;
        }
    }

    return valid;
}

bool validBox(sudokuBoard passed, unsigned row, unsigned column)
{
    bool valid = true;

    for(auto i = 0; i<9; i++)
    {
        if(passed.space[i/3][i%3] == passed.space[row][column] && ((i/3 != row) && (i%3 != column)))
        {
            valid = false;
        }
    }
    return valid;
}

bool isValid(sudokuBoard passed, unsigned row, unsigned column)
{
    bool valid = (validRow(passed, row, column) && validColumn(passed,row, column) && validBox(passed,row,column));

    return valid;
}
#endif

