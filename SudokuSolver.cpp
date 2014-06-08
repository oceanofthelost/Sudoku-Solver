#include<iostream>
#include<string>
using namespace std;

//start using const and const reference variables

struct sudokuBoard
{
    unsigned space[9][9];
};

bool validRow(sudokuBoard, unsigned);
bool validColumn(sudokuBoard, unsigned);
bool validBox(sudokuBoard, unsigned, unsigned);
bool isValid(sudokuBoard,unsigned,unsigned);
sudokuBoard setup(string);
void solve(sudokuBoard);


int main(int argc, char* argv[])
{
    sudokuBoard board;
    if(argc != 2)
    {
        cout<<"Proper ussage is SudokuSolver [Board]"<<endl;
    }
    else
    {
        cout<<"Lets Solve This"<<endl;
        board = setup(argv[1]);
    }
}
#if 0
bool validRow(unsigned value, unsigned row)
{
    bool valid = false;

    return valid;
}

bool validColumn(unsigned value, unsigned column)
{
    bool valid = false;

    return valid;
}

bool validBox(unsigned value, unsigned row, unsigned column)
{
    bool valid = false;

    return valid;
}
#endif
sudokuBoard setup(string gameBoard)
{
    sudokuBoard board;

    for(auto i = 0; i<9; i++)
    {
        for(auto j = 0; j<9; j++)
        {
            board.space[i][j] = gameBoard[i*9+j] - '0';
        }
    }
/*    
    cout<<"The initial game board"<<endl;
    for(auto i = 0; i<9; i++)
    {
        for(auto j = 0; j<9; j++)
        {
            cout<< board.space[i][j]<<" ";
        }
        cout<<endl;))
    }
*/
    return board;
}

void solve(sudokuBoard passed)
{
    for(auto i = 0; i<9; i++)
    {
        for(auto j = 0; j<9; j++)
        {
            for(auto k = 1;k<=10;k++)
            {
                if(passed.space[i][j]==0)
                {
                    if(isValid(passed,i,j))
                    {
                        passed[i][j] = k; 
                    }
                }
            }
        }
    }
 
}
