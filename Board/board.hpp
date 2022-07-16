#ifndef board_hpp
#define board_hpp

#include <iostream>

using namespace std;

typedef enum { EMPTY, P1, P2 } state;

const int R = 6; //Rows = Filas
const int C = 7; //Columns = Columnas

class Board{

	private:
		state BOARD[R][C];
		int high[C];

		bool checkRow(int, int);
		bool checkCol(int, int);
		bool checkMaj(int, int);
		bool checkMin(int, int);

	public:
		Board();
		bool addMove();
		void print();


};

#endif