#ifndef HANOI_TXT_H
#define HANOI_TXT_H
#include <vector>
#include <string>
#include "hanoi.h"


class Hanoi_txt
{
public:
	Hanoi_txt(Hanoi& game);

	Hanoi& Game();

	const Hanoi& Game() const;

	int Ask_Start();

	int Ask_Arrival();

	void DisplayGame() const;
	int Nb_Mouvements() const;
	void Step();
	std::string Layer_chain(int const tower, int const layer) const;
	void Solution();
protected:
	Hanoi& game_hanoi;
	int nb_movement;
}; //class Hanoi_txt

#endif