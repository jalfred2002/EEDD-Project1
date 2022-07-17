#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Board/board.hpp"

using namespace std;

//------------------------------ declaracion de las funciones del main ------------------------------
int  human(bool,Board);
int  cpu(bool,Board);
void game(int(bool,Board),int(bool,Board));
void menu(char&);


// --------------------- main -------------------------

int main(){

	srand(time(NULL));
	char opc = '\0';

	while(opc != '0'){
		
		system("color E");
		menu(opc); // Mostramos el menu y leemos la opcion
		
		if(opc == '1') game(human, human);
		if(opc == '2') game(human, cpu);
		if(opc == '3') game(cpu, cpu);
	}

	return 0;
}

// ---------------------- funciones del main -----------------------

void menu(char& opc){
	system("cls || clear"); //Limpiamos la pantalla

	cout << "\t\t------ Elija una opcion ------" << endl;
	cout << "\t\t    [1] Player vs Player" << endl;
	cout << "\t\t    [2] Player vs CPU" << endl;
	cout << "\t\t    [3] CPU vs CPU" << endl;
	cout << "\t\t    [0] salir" << endl;
	cout << "\t\t    OPC [ ]\b\b";

	cin >> opc;
	fflush(stdin);

	return;
}

int human(bool player, Board board){
	int column;
	
	cout << "\n\t\tIngresa tu jugada: ";
	do { cin >> column; }while(column < 0 || column > 6);

	return column;
}

int cpu(bool player, Board board){

	for(int i = 0; i < C; i++){
		board.addMove(player,i);
		if( board.checkWinner(i) )
			return i;
		else
			board.removeMove(i);
	}

	for(int i = 0; i < C; i++){
		board.addMove(!player,i);
		if( board.checkWinner(i) )
			return i;
		else
			board.removeMove(i);
	}

	return rand() % 7;
}

void game(int functionJ1(bool,Board), int functionJ2(bool,Board)){
	Board board;
	bool player = true;
	int column;

	do{
		player? system("color A") : system("color B");
		board.print();

		column = player? functionJ1(player,board) : functionJ2(player,board);
		
		board.addMove(player, column);
		player = !player;

	}while( !board.checkWinner(column) );

	board.print();
	system("pause");

	return;
}
