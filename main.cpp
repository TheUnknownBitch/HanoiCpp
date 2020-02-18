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


class Hanoi_txt
{
public:
	Hanoi_txt(Hanoi& game) : game_hanoi(game), nb_movement(0){}

	Hanoi& Game()
	{ return this->game_hanoi; }

	const Hanoi& Game() const
	{ return this->game_hanoi; }

	int Ask_Start()
	{
		int startTower;
		cout << "Start tower : " ;
		cin >> startTower;
		return startTower - 1;
	}

	int Ask_Arrival()
	{
		int ArrivalTower;
		cout << "End Tower : ";
		cin >> ArrivalTower;
		return ArrivalTower - 1;
	}

	void DisplayGame() const
	{
		for(int layer = this->Game().Height(); layer >= 0; --layer)
		{
			for (int tower = 0; tower < 3; ++tower)
			{
				std::cout << " " << this->Layer_chain(tower, layer) << " ";
			}
			cout << endl;
		}
	}
	int Nb_Mouvements() const
	{ return this->nb_movement; }
	void Step()
	{
		int startTower = this->Ask_Start();
		if(this->Game().start_valid(startTower))
		{
			int endTower = this->Ask_Arrival();
			if(this->Game().arrival_valid(startTower, endTower))
			{
				this->Game().move_disc(startTower, endTower);
				this->nb_movement += 1;
			}
			else
				cout << "Invalid end tower!" << endl;
		}
		else
			cout << "Invalid start tower!" << endl;
	}
	string Layer_chain(int const tower, int const layer) const
	{
		int max_width = this->Game().Height();
		int disc = this->Game().a_tower(tower).disc_height(layer);
		string space(max_width - disc, ' ');
		string chain;
		if( disc > 0 )
		{
			string line(disc, '=');
			chain = space + "<" + line + "!" + line + ">" + space;
		}
		else
		{
			chain = space + " ! " + space;
		}
		return chain;
	}
protected:
	Hanoi& game_hanoi;
	int nb_movement;

}; //class Hanoi_txt
