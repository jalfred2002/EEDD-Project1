#ifndef player_hpp
#define player_hpp

#include <iostream>

using namespace std;

typedef enum { CPU, PLAYER } Type;

class Player{

	private:
		Type type;
		string color; /*dos colores que pueden tener los jugadores el 1 ero en rojo y 2 do en azul*/

	public:
		Player();

};


#endif