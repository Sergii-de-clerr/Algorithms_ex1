#include "Three_mass.h"
#include <iostream>
#include <ctime>
#include <iomanip>

Threed_mass::Threed_mass()
{
	this->random();
}

void Threed_mass::random()
{
	srand(time(0));
	for (int i = 0; i < SIZE3; i++)
	{
		for (int j = 0; j < SIZE3; j++)
		{
			for (int g = 0; g < SIZE3; g++)
			{
				main_mass[i][j][g] = rand();
			}
		}
	}
}

void Threed_mass::print_arr()
{
	cout << "Array" << endl;
	for (int i = 0; i < SIZE3; i++)
	{
		cout << "p" << setw(2) << i << endl;
		for (int j = 0; j < SIZE3; j++)
		{
			cout << "st" << setw(2) << j << ": ";
			for (int g = 0; g < SIZE3; g++)
			{
				cout << setw(7) << main_mass[i][j][g];
			}
			cout << endl;
		}
		cout << endl;
	}
}

int Threed_mass::max_el()
{
	int res = main_mass[0][0][0];
	for (int i = 0; i < SIZE3; i++)
	{
		for (int j = 0; j < SIZE3; j++)
		{
			for (int g = 0; g < SIZE3; g++)
			{
				if (main_mass[i][j][g] > res)
					res = main_mass[i][j][g];
			}
		}
	}
	return res;
}

int Threed_mass::min_el()
{
	int res = main_mass[0][0][0];
	for (int i = 0; i < SIZE3; i++)
	{
		for (int j = 0; j < SIZE3; j++)
		{
			for (int g = 0; g < SIZE3; g++)
			{
				if (main_mass[i][j][g] < res)
					res = main_mass[i][j][g];
			}
		}
	}
	return res;
}

void Threed_mass::bubble_X_stonks()
{
	bool is_sort;
	for (int i = 0; i < SIZE3; i++)
	{
		for (int j = 0; j < SIZE3; j++)
		{
			do
			{
				is_sort = true;
				for (int g = 0; g < SIZE3 - 1; g++)
				{
					if (main_mass[i][j][g] > main_mass[i][j][g + 1])
					{
						is_sort = false;
						int fake = main_mass[i][j][g];
						main_mass[i][j][g] = main_mass[i][j][g + 1];
						main_mass[i][j][g + 1] = fake;
					}
				}
			} while (is_sort == false);
		}
	}
}

void Threed_mass::bubble_Y_stonks()
{
	bool is_sort;
	for (int i = 0; i < SIZE3; i++)
	{
		for (int g = 0; g < SIZE3; g++)
		{
			do
			{
				is_sort = true;
				for (int j = 0; j < SIZE3 - 1; j++)
				{
					if (main_mass[i][j][g] > main_mass[i][j + 1][g])
					{
						is_sort = false;
						int fake = main_mass[i][j][g];
						main_mass[i][j][g] = main_mass[i][j + 1][g];
						main_mass[i][j + 1][g] = fake;
					}
				}
			} while (is_sort == false);
		}
	}
}

void Threed_mass::bubble_Z_stonks()
{
	bool is_sort;
	for (int j = 0; j < SIZE3; j++)
	{
		for (int g = 0; g < SIZE3; g++)
		{
			do
			{
				is_sort = true;
				for (int i = 0; i < SIZE3 - 1; i++)
				{
					if (main_mass[i][j][g] > main_mass[i + 1][j][g])
					{
						is_sort = false;
						int fake = main_mass[i][j][g];
						main_mass[i][j][g] = main_mass[i + 1][j][g];
						main_mass[i + 1][j][g] = fake;
					}
				}
			} while (is_sort == false);
		}
	}
}