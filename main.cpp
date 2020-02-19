#include <iostream>
#include <vector>
#include <string>
#include "hanoi_txt.h"

using namespace std;


int main(int argc, char const *argv[])
{
	int max_height;
	cout << "Number of disc for the game : ";
	cin >> max_height;
	Hanoi the_game;
	the_game.Initialise(max_height);
	Hanoi_txt interface(the_game);
	while( not the_game.GameOver() )
	{
		interface.DisplayGame();
		interface.Step();
	}
	interface.DisplayGame();
	cout << "Congrats you finished the game in " << interface.Nb_Mouvements() << " movements!" << endl;
	return 0;
}
