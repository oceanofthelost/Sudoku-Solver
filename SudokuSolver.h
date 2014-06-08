#ifndef _SUDOKU_SOLVER_SDA
#define _SUDOKU_SOLVER_SDA
	
	#include<iostream>
	#include<string>
	using namespace std;

	class SudokuSolver
	{
		public:
			SudokuSolver(char* &);
			void solve();
			void print();
		private:
			unsigned cell[9][9];
			bool validRow(unsigned,unsigned);
			bool validColumn(unsigned,unsigned);
			bool validBox(unsigned,unsigned);
			bool isValid(unsigned,unsigned);
			int openCell();
			bool backtrackSolve();
	};



#endif