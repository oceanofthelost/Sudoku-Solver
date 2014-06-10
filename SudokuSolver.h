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
			bool validRow(const unsigned short&,const unsigned short&);
			bool validColumn(const unsigned short&,const unsigned short&);
			bool validBox(const unsigned short&,const unsigned short&,const unsigned short&);
			bool isValid(const unsigned short&,const unsigned short&,const unsigned short&);
			short openCell();
			bool backtrackSolve(unsigned,unsigned);

	};



#endif