#include <iostream>
#include "Board/board.hpp"

using namespace std;

//------------------------------ declaracion de las funciones del main ------------------------------
void menu(char&);
void playerVsPlayer();
void playerVsCpu();

// --------------------- main -------------------------

int main(){	
	Board board;
	char opc = '\0';

	while(opc != '0'){
		board.Board(); // rellenamos la matriz || reiniciamos  
		
		menu(opc); // Mostramos el menu y leemos la opcion
		
		if(opc == '1') 
			playerVsPlayer(array);
		else if(opc == '2')
			playerVsCpu();
	}

	return 0;
}

// ---------------------- funciones del main -----------------------

void menu(char& opc){
	system("cls || clear"); //Limpiamos la pantalla

	cout << "\t\t------ Elija una opcion ------" << endl;
	cout << "\t\t    [1] player vs player" << endl;
	cout << "\t\t    [2] player vs cpu" << endl;
	cout << "\t\t    [0] salir" << endl;
	cout << "\t\t    [ ] opcion\b\b\b\b\b\b\b\b\b";

	cin >> opc;
	fflush(stdin);

	return;
}

void playerVsPlayer(){

	int col = 0;
	board.print();

	cout << "\n\n\t\tIngresar una posicion: ";
	cin >> col;

	// 

	board.adddMove(/* ficha */);
	board.checkWinner(int col);




	return;
}
