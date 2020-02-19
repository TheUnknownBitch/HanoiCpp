#include "hanoi.h"
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