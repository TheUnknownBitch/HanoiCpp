#include <iostream>
#include "hanoi_txt.h"

using namespace std;

Hanoi_txt::Hanoi_txt(Hanoi& game) : game_hanoi(game), nb_movement(0){}

Hanoi& Hanoi_txt::Game()
{ return this->game_hanoi; }

const Hanoi& Hanoi_txt::Game() const
{ return this->game_hanoi; }

int Hanoi_txt::Ask_Start()
{
	int startTower;
	cout << "Start tower : " ;
	cin >> startTower;
	return startTower - 1;
}

int Hanoi_txt::Ask_Arrival()
{
	int ArrivalTower;
	cout << "End Tower : ";
	cin >> ArrivalTower;
	return ArrivalTower - 1;
}

void Hanoi_txt::DisplayGame() const
{
	for(int layer = this->Game().Height() - 1; layer >= 0; --layer)
	{
		for (int tower = 0; tower < 3; ++tower)
		{
			std::cout << " " << this->Layer_chain(tower, layer) << " ";
		}
		cout << endl;
	}
}
int Hanoi_txt::Nb_Mouvements() const
{ return this->nb_movement; }
void Hanoi_txt::Step()
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
string Hanoi_txt::Layer_chain(int const tower, int const layer) const
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

void Hanoi_txt::Solution()
{
	string line(40, '-');
	cout << line << endl << "SOLUTION" << endl << line << endl;
	vector<pair<int, int> > soluce;
	this->Game().Solution(soluce);
	this->Game().Initialise(this->Game().Height());
	this->DisplayGame();
	cout << line << endl;
	for (int hint_movement = 0; hint_movement < soluce.size(); ++hint_movement)
	{
		this->Game().move_disc(soluce[hint_movement].first, soluce[hint_movement].second);
		this->nb_movement += 1;
		this->DisplayGame();
		cout << line << endl;
	}
}