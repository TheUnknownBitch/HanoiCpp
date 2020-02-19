#include "tower.h"

Tower::Tower(int MaxHeight): nb_disc(0), discs(MaxHeight, 0) {}

bool Tower::is_empty() const
{
	return this->nb_disc == 0;
}

bool Tower::is_full() const
{
	return this->nb_disc == this->discs.size();
}

int Tower::Top() const
{
	if ( this->is_empty() )
		return 0;
	else
		return this->discs[this->nb_disc - 1];
}

int Tower::disc_height(int const height) const
{
	if ( this->is_empty() or (height >= this->nb_disc))
		return 0;
	else
		return this->discs[height];
}

bool Tower::can_add_disc(int const disc) const
{
	if (this->is_empty())
		return true;
	else
		return (this->Top() > disc);
}

void Tower::Add_disc(int const disc)
{
	this->discs[this->nb_disc] = disc;
	this->nb_disc += 1;
}

void Tower::Remove_disc()
{
	this->nb_disc -= 1;
	this->discs[this->nb_disc] = 0;
}