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
}

//user API for solving
void SudokuSolver::solve()
{
    backtrackSolve(0,0);
}

//user API for print
void SudokuSolver::print()
{
    for(unsigned row = 0; row<9; ++row)
    {
        for(unsigned column = 0; column<9; ++column)
        {
            cout<< cell[row][column]<<" ";
        }
        cout<<endl;
    }
}

bool SudokuSolver::backtrackSolve(unsigned row, unsigned column)
{
    //finds next open cell
    while(row<9 and cell[row][column] != 0)
    {
        ++column;
        if(column==9)
        {
            ++row;
            column=0;
        }
    }
    
    //if row is equal to 9 we have iterated over the whole board
    if(row == 9)
    {
        return true;
    }
    for(unsigned k = 1; k<=9;++k)
    {
        if(isValid(row,column,k))
        {
            cell[row][column] = k;
            if(backtrackSolve(row,column))
            {
                return true;
            }
            cell[row][column] = 0;
        }
    }
    return false;
}


bool SudokuSolver::isValid(const unsigned short& row, const unsigned short& column,const unsigned short& num)
{
    //return (validRow(row,num) and validColumn(column,num) and validBox(row,column,num));
    return (validRow(row,num) and validColumn(column,num) and validBox((row/3)*3,(column/3)*3,num));

}


bool SudokuSolver::validRow(const unsigned short& row, const unsigned short& num)
{
    bool valid = true;

    for(unsigned short column = 0; column<9;++column)
    {
        if(cell[row][column]==num)
        {
             valid = false;
             break;
        }
    }
   
    return valid;
}

bool SudokuSolver::validColumn(const unsigned short& column, const unsigned short& num)
{
    bool valid = true;

    for(unsigned short row = 0; row<9;++row)
    {
        if(cell[row][column]==num)
        {
            valid = false;
            break;
        }
    }
   
    return valid;
}
/*
bool SudokuSolver::validBox(const unsigned short& row, const unsigned short& column,const unsigned short& num)
{
    bool valid = true;

    for(unsigned short i = 0; i<3; ++i)
    {
        for(unsigned short j = 0; j<3;++j)
        {
            if(cell[i+(row-row%3)][j+(column-column%3)]==num)
            {
                valid = false;
                break;
            }
        }
    }
    
    return valid;
}
*/

bool SudokuSolver::validBox(const unsigned short& rowOffset, const unsigned short& columnOffset,const unsigned short& num)
{
    bool valid = true;
    for(unsigned short k=0; k<9;k++)
    {
        if(cell[k/3+rowOffset][k%3+columnOffset] == num)
        {
            valid = false;
            break;
        }
    }

       
    return valid;
}

