#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Board/board.hpp"

using namespace std;

//------------------------------ declaracion de las funciones del main ------------------------------
int  human(bool, Board);
int  cpu(bool, Board);
void game1(int(bool, Board), int(bool, Board));
void game2(int(bool, Board), int(bool, Board));
void menu(char&);

// --------------------- main -------------------------

int main(){
	srand(time(NULL));
	char opc = '\0';

	while(opc != '0'){
		
		system("color E");
		menu(opc); // Mostramos el menu y leemos la opcion
		
		if(opc == '1') { game1(human, human); }
		if(opc == '2') { game1(human, cpu); }
		if(opc == '3') { game1(cpu, cpu); }
		if(opc == '4') { game2(human, human); }
		if(opc == '5') { game2(human, cpu); }
		if(opc == '6') { game2(cpu, cpu); }
	}

	return 0;
}

// ---------------------- funciones del main -----------------------

void menu(char& opc){
	system("cls || clear"); //Limpiamos la pantalla

	cout << "\n\t\t------------	ELIJA SU MODO	------------" << endl;
	cout << "\t\t\t[1] Tradicional (Player vs Player)" << endl;
	cout << "\t\t\t[2] Tradicional (Player vs CPU)" << endl;
	cout << "\t\t\t[3] Tradicional (CPU vs CPU)" << endl;
	cout << "\t\t\t[4] Tablero lleno (Player vs Player)" << endl;
	cout << "\t\t\t[5] Tablero lleno (Player vs CPU)" << endl;
	cout << "\t\t\t[6] Tablero lleno (CPU vs CPU)" << endl;
	cout << "\t\t\t[0] salir" << endl;
	cout << "\t\t\tOPC [ ]\b\b";

	cin >> opc;
	fflush(stdin);
	return;
}

int human(bool player, Board board){
	int column;
	
	cout << "\n\t\tIngresa tu jugada: ";

	do { cin >> column; } while((column < 0 || column > 6) or board.fullColumn(column));
	return column;
}

int cpu(bool player, Board board){
	int res;

	for(int i = 0; i < C; i++){
		if(!board.fullColumn(i)){
			board.addMove(player,i);
			if( board.checkWinner(i) )
				return i;
			else
				board.removeMove(i);
		}
	}

	for(int i = 0; i < C; i++){
		if(!board.fullColumn(i)){
			board.addMove(!player,i);
			if( board.checkWinner(i) )
				return i;
			else
				board.removeMove(i);
		}
	}

	do { res = rand() % 7; } while(board.fullColumn(res));
	return res;
}

 void game1(int functionJ1(bool, Board), int functionJ2(bool, Board)){
	Board board;
	bool player = true;
	int column;
	int cont = 0;

	do{
		player? system("color A") : system("color B");
		board.print(); // se imprime el tablero

		column = player? functionJ1(player, board) : functionJ2(player, board); // se dicide el jugador
		
		board.addMove(player, column); // se coloca el movimiento
		player = !player;
	}while( /*!board.checkWinner(column) &&*/ !board.full());

	board.print();
	if(board.checkWinner(column))
		cout << "\n\n\t\tFelicidades " << (!player? "Jugador 1 " : "Jugador 2 ") << "ha ganado!!" << endl;
	else
		cout << "\n\n\t\tHa sido un empate" << endl;

	system("pause");
	return; 
} 

void game2(int functionJ1(bool, Board), int functionJ2(bool, Board) ){
	Board board;
	bool player = true;
	int column;
	int cont1 = 0;
	int cont2 = 0;

	do{
		player? system("color A") : system("color B");
		board.print(); // se imprime el tablero
		cout << "\n\t\tLineas Contadas: \n\t\t\tPlayer 1: " << cont1 << "\tPlayer 2:" << cont2 << endl;


		column = player? functionJ1(player, board) : functionJ2(player, board); // se dicide el jugador
		
		board.addMove(player, column); // se coloca el movimiento

		if(board.checkWinner(column))
			player? cont1++ : cont2++;

		player = !player;
	}while( !board.full() );

	board.print();
	cout << "Ha ganado el jugador " << (cont1 > cont2? "1" : "2") << endl;

	system("pause");
	return;
}

