#ifndef TOWER_H
#define TOWER_H 1
#include <vector>

class Tower
{
public:
	Tower(int MaxHeight);
	bool is_empty() const;
	bool is_full() const;
	int Top() const;
	int disc_height(int const height) const;
	bool can_add_disc(int const disc) const;
	void Add_disc(int const disc);
	void Remove_disc();
private:
	int nb_disc;
	std::vector<int> discs;
}; //class tower

#endif