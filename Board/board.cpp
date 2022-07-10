#include "board.hpp"

using namespace std;

Board::Board(){
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			this->BOARD[i][j] = EMPTY;
}

void Board::print(){
    for(int i = 0; i < R; i++){
        cout << "\n\t\t-----------------------------\n\t\t";
        for(int j = 0; j < C; j++){
            if(this->BOARD[i][j] == EMPTY) cout << "|   ";
            if(this->BOARD[i][j] == P1) cout << "| x ";
            if(this->BOARD[i][j] == P2) cout << "| o ";
        }
        cout << "|";
    }
        cout << "\n\t\t-----------------------------" << endl;
}