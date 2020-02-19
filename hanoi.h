#ifndef HANOI_H
#define HANOI_H
#include <vector>
#include "tower.h"

typedef std::pair<int, int> Deplacement;
typedef std::vector<Deplacement> Tab_Deplacements;

class Hanoi
{
public:
	Hanoi();

	void Initialise(int const nb_disc);
	int Height() const;
	const Tower& a_tower(int i) const;
	bool start_valid(int const start) const;
	bool arrival_valid(int const start, int const arrival) const;
	void move_disc(int const start, int const arrival);
	bool GameOver() const;
	void Solution(Tab_Deplacements& soluce) const;
private:
	int max_height;
	std::vector<Tower> towers;

}; //class Hanoi
void Hanoi_Solution(int nb_disc, int start, int pivot, int finish, Tab_Deplacements& soluce);
#endif