#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Tower
{
public:
	Tower(int MaxHeight): nb_disc(0), discs(MaxHeight, 0)
	{}
	bool is_empty() const
	{
		return this->nb_disc == 0;
	}
	bool is_full() const
	{
		return this->nb_disc == this->discs.size();
	}
	int Top() const
	{
		if ( this->is_empty() )
			return 0;
		else
			return this->discs[this->nb_disc - 1];
	}
	int disc_height(int const height) const
	{
		if ( this->is_empty() or (height >= this->nb_disc))
			return 0;
		else
			return this->discs[height];
	}
	bool can_add_disc(int const disc) const
	{
		if (this->is_empty())
			return true;
		else
			return (this->Top() > disc);
	}
	void Add_disc(int const disc)
	{
		this->discs[this->nb_disc] = disc;
		this->nb_disc += 1;
	}
	void Remove_disc()
	{
		this->nb_disc -= 1;
		this->discs[this->nb_disc] = 0;
	}
private:
	int nb_disc;
	vector<int> discs;
}; //class tower


class Hanoi
{
public:
	Hanoi(): max_height(0), towers(){}

	void Initialise(int const nb_disc)
	{
		this->towers.clear();
		this->towers.resize(3, Tower(nb_disc));
		for (int disc = nb_disc; disc > 0; --disc)
		{
			this->towers[0].Add_disc(disc);
		}
		this->max_height = nb_disc;
	}
	int Height() const
	{ return this->max_height; }
	const Tower& a_tower(int const i) const
	{
		return this->towers[i];
	}
	bool start_valid(int const start) const {
		if ( (start < 0) or (start > 2) )
			return false;
		return (not this->towers[start].is_empty());
	}
	bool arrival_valid(int const start, int const arrival) const
	{
		if ( (arrival < 0 ) or (arrival > 2))
			return false;
		int start_disc = this->towers[start].Top();
		return this->towers[arrival].can_add_disc(start_disc);
	}
	void move_disc(int const start, int const arrival)
	{
		int disc = this->towers[start].Top();
		this->towers[start].Remove_disc();
		this->towers[arrival].Add_disc(disc);
	}
	bool GameOver() const
	{
		return this->towers[2].is_full();
	}
private:
	int max_height;
	std::vector<Tower> towers;

}; //class Hanoi
