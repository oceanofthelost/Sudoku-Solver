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
   // print();
   // cout<<endl<<endl;
}

//user API for solving
void SudokuSolver::solve()
{
    if(backtrackSolve())
    {
        //print();
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
    //cout<<"I am inside"<<endl;
    unsigned short row;
    unsigned short column;
    short result = openCell();

    if(result < 0)
    {
        return true;
    }
    
    row     = result/10;
    column  = result%10; 

    for(unsigned k = 1; k <= 9; k++)
    {
        if(isValid(row,column,k))
        {
            cell[row][column] = k;
            if(backtrackSolve())
            {
                return true;
            }
            cell[row][column] = 0;
        }
    }
    return false;
}

//return -1 if no open cells
//return xy for vali number. xy is a 2 digit number 
//      representing the row and column of the open cell
short SudokuSolver::openCell()
{
    for(short row = 0; row < 9; row++)
    {
        for(short column = 0; column < 9; column++)
        {
            if(cell[row][column]==0)
            {
                return row*10+column;
            }
        }
    }
    return -1;
}

bool SudokuSolver::isValid(const unsigned short& row, const unsigned short& column,const unsigned short& num)
{
    bool valid = (validRow(row,num) && validColumn(column,num) && validBox(row,column,num));
    
    return valid;
}


bool SudokuSolver::validRow(const unsigned short& row, const unsigned short& num)
{
    bool valid = true;

    for(unsigned short column = 0; column<9;column++)
    {
        if(cell[row][column]==num)
        {
             valid = false;
        }
    }
   
    return valid;
}

bool SudokuSolver::validColumn(const unsigned short& column, const unsigned short& num)
{
    bool valid = true;

    for(unsigned short row = 0; row<9;row++)
    {
        if(cell[row][column]==num)
        {
            valid = false;
        }
    }
   
    return valid;
}

bool SudokuSolver::validBox(const unsigned short& row, const unsigned short& column,const unsigned short& num)
{
    
    for(unsigned short i = 0; i<3; i++)
    {
        for(unsigned short j = 0; j<3;j++)
        {
            if(cell[i+(row-row%3)][j+(column-column%3)]==num && ((i+(row-row%3)) != row && (j+(column-column%3))!=column))
            {
                return false;
            }
        }
    }
    
    return true;
}
