#include "hanoi.h"

Hanoi::Hanoi(): max_height(0), towers(){}

void Hanoi::Initialise(int const nb_disc)
{
	this->towers.clear();
	this->towers.resize(3, Tower(nb_disc));
	for (int disc = nb_disc; disc > 0; --disc)
	{
		this->towers[0].Add_disc(disc);
	}
	this->max_height = nb_disc;
}
int Hanoi::Height() const
{ return this->max_height; }
const Tower& Hanoi::a_tower(int const i) const
{
	return this->towers[i];
}
bool Hanoi::start_valid(int const start) const {
	if ( (start < 0) or (start > 2) )
		return false;
	return (not this->towers[start].is_empty());
}
bool Hanoi::arrival_valid(int const start, int const arrival) const
{
	if ( (arrival < 0 ) or (arrival > 2))
		return false;
	int start_disc = this->towers[start].Top();
	return this->towers[arrival].can_add_disc(start_disc);
}
void Hanoi::move_disc(int const start, int const arrival)
{
	int disc = this->towers[start].Top();
	this->towers[start].Remove_disc();
	this->towers[arrival].Add_disc(disc);
}
bool Hanoi::GameOver() const
{
	return this->towers[2].is_full();
}

void Hanoi::Solution(Tab_Deplacements& soluce) const
{
	Hanoi_Solution(this->max_height, 0, 1, 2, soluce);
}

void Hanoi_Solution(int nb_disc, int start, int pivot, int finish, Tab_Deplacements& soluce)
{
	if( nb_disc == 1)
	{
		soluce.push_back(std::make_pair(start, finish));
	}
	else
	{
		Hanoi_Solution(nb_disc - 1, start, finish, pivot, soluce);
		Hanoi_Solution(1, start, pivot, finish, soluce);
		Hanoi_Solution(nb_disc - 1, pivot, start, finish, soluce);
	}
}