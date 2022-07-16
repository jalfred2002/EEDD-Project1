#include "board.hpp"

using namespace std;

Board::Board(){
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			BOARD[i][j] = EMPTY;

    for (int i = 0; i < C; ++i)
        high[i] = 0;
}

void Board::print(){
    cout << "\n\t\t-----------------------------\n\t\t| 0 | 1 | 2 | 3 | 4 | 5 | 6 |";

    for(int i = 0; i < R; i++){
        cout << "\n\t\t-----------------------------\n\t\t";
        
        for(int j = 0; j < C; j++){
            if(BOARD[i][j] == EMPTY) cout << "|   ";
            if(BOARD[i][j] == P1) cout << "| x ";
            if(BOARD[i][j] == P2) cout << "| o ";
        }
        
        cout << "|";
    }
        
    cout << "\n\t\t-----------------------------" << endl;
    return;
}

bool Board::checkRow(int row, int col){
    int cont = 1; 
    
    for(int i = 1; (row+i) < R && BOARD[row][col] == BOARD[row+i][col]; i++)
        cont++;

    return cont >= 4;
}

bool Board::checkCol(int row, int col){
    int cont = 1;
    
    for(int i = 1; (col+i) < C && BOARD[row][col] == BOARD[row][col+i]; i++) 
        cont++;
    
    for(int i = 1; (col-i) >= 0 && BOARD[row][col] == BOARD[row][col-i]; i++)
        cont++;

    return cont >= 4;
}

bool checkMajDiagonal(int row, int col){

    int cont = 1;
    
    for(int i = 1; (col+i) < C && (row-i) >= 0 && BOARD[row][col] == BOARD[row-i][col+i]; i++)
        cont++;

    for(int i = 1; (col-i) >= 0 && (row+i) < F && BOARD[row][col] == BOARD[row+i][col-i]; i++)
        cont++;

    return cont >= 4;    
}

bool checkMinDiagonal(int row, int col){

    int cont = 1;
    
    for(int i = 1; (col+i) < C && (row+i) < F && BOARD[row][col] == BOARD[row+i][col+i]; i++)
        cont++;

    for(int i = 1; (col-i) >= 0 && (row-i) >= 0 && BOARD[row][col] == BOARD[row-i][col-i]; i++)
        cont++;

    return cont >= 4;
}

bool Board::checkWinner(int col){
    int row = high[col];
    return checkRow(row,col) || checkCol(row,col) || checkMaj(row,col) || checkMin(row,col);
}

bool Board::addMove(const string ficha){ 
    for (int i = 0; i <= R; i++){
        if (i == R){
            BOARD[i-1][col] = ficha; 
            return true;
        }

        if (BOARD[i][col] != EMPTY){
            BOARD[i-1][col] = ficha; 
            return true;/*retorna la posicion de i*/
        }
    }

    return false;
}

// BOARD[R][C]