#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Tower
{
	int nb_disc;
	std::vector<int> discs;
	Tower(int const MaxHeight): nb_disc(0), discs(MaxHeight, 0)
	{

	}
};

struct Hanoi
{
	int Height;
	std::vector<Tower> towers;

	Hanoi(int const MaxHeight) : Height(MaxHeight), towers(3, Tower(MaxHeight))
	{
		for (int i = 0; i < MaxHeight; ++i)
		{
			this->towers[0].discs[i] = MaxHeight - i;
		}
		this->towers[0].nb_disc = MaxHeight;
	}
};


string RowDraw(int const length, int const width)
{
	string space(width - length, ' ');
	string chain;
	if ( length > 0 )
	{
		string disc(length, '=');
		chain = space + "<" + disc + "!" + disc + ">" + space;
	}
	else
	{
		chain = space + " ! " + space;
	}
	return chain;
}

void printGame (Hanoi const& input)
{
	for (int i = input.Height - 1; i >= 0 ; --i)
	{
		for (int x = 0; x < 3 ; ++x)
		{
			cout << " " << RowDraw(input.towers[x].discs[i], input.Height) << " ";
		}
		cout << endl;
	}
}

bool Done(Hanoi const& input)
{
	return input.towers[2].nb_disc == input.Height;
}

bool startTowerValid(Hanoi const& input, int const startTower)
{
	if ( (startTower < 0) or (startTower > 2) )
	{
		return false;
	}
	return input.towers[startTower].nb_disc > 0;
}

int askStartTower(Hanoi const& input)
{
	int startTower;
	cout << "Start tower : ";
	cin >> startTower;

	return startTower - 1;
}

int askEndTower(Hanoi const& input)
{
	int arrivalTower;
	cout << "arrival tower : ";
	cin >> arrivalTower;

	return arrivalTower - 1;
}

bool arrivalTowerValid(Hanoi const& input, int start, int arrival)
{
	if ( (arrival < 0) or (arrival > 2) )
	{
		return false;
	}
	if (input.towers[arrival].nb_disc == 0)
	{
		return true;
	}
	return input.towers[arrival].discs[input.towers[arrival].nb_disc - 1] > input.towers[start].discs[input.towers[start].nb_disc - 1];
}

bool isNumberDiscValid(int const& input)
{
	if((input > 2) && (input < 11))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int askNumberOfDisc()
{
	int number;
	cout << "With how many discs do you wanna play? Please choose between 3 and 10." << endl << "Your choice : ";
	cin >> number;
	while(0 == 0)
	{
		if (isNumberDiscValid(number))
		{
			return number;
		}
		else
		{
			cout << "Please choose a number between 3 and 10" << endl << "Your choice : ";
			cin >> number;
		}
	}
}

void moveDisc(Hanoi& input, int const start, int const arrival)
{
	input.towers[arrival].discs[input.towers[arrival].nb_disc] = input.towers[start].discs[input.towers[start].nb_disc - 1];
	input.towers[start].discs[input.towers[start].nb_disc - 1] = 0;
	input.towers[start].nb_disc -= 1;
	input.towers[arrival].nb_disc +=1;
}

int main(int argc, char const *argv[])
{
	Hanoi Game(askNumberOfDisc());
	int start;
	int arrival;

	while(!Done(Game))
	{
		printGame(Game);
		start = askStartTower(Game);
		arrival = askEndTower(Game);
		if (startTowerValid(Game, start) && arrivalTowerValid(Game, start, arrival))
			moveDisc(Game, start, arrival);
		else
			cout << "Invalid Choice! Please try something smarter!" << endl;
	}
	printGame(Game);
	cout << "Congrats you made it!" << endl;

	return 0;
}