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

	public:
		Board();
		void print();


};

#endif