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
			void print() const;
		private:
			unsigned cell[9][9];
			bool backtrackSolve(unsigned,unsigned);
			bool isValid(const unsigned &,const unsigned &,const unsigned &) const;
			bool validRow(const unsigned &,const unsigned &) const;
			bool validColumn(const unsigned &,const unsigned &) const;
			bool validBox(const unsigned &,const unsigned &,const unsigned &) const;
	};
#endif