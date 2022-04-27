#include "Two_mass.h"
#include <iostream>
#include <ctime>
#include <iomanip>

Twod_mass::Twod_mass()
{
	this->random();
}

void Twod_mass::random()
{
	srand(time(0));
	for (int i = 0; i < SIZE2; i++)
	{
		for (int j = 0; j < SIZE2; j++)
		{
			main_mass[i][j] = rand();
		}
	}
}

void Twod_mass::print_arr()
{
	cout << "Array" << endl;
	for (int i = 0; i < SIZE2; i++)
	{
		cout << "st" << setw(2)<< i << ": ";
		for (int j = 0; j < SIZE2; j++)
		{
			cout << setw(7) << main_mass[i][j];
		}
		cout << endl;
	}
}

int Twod_mass::max_el()
{
	int res = main_mass[0][0];
	for (int i = 0; i < SIZE2; i++)
	{
		for (int j = 0; j < SIZE2; j++)
		{
			if (main_mass[i][j] > res)
				res = main_mass[i][j];
		}
	}
	return res;
}

int Twod_mass::min_el()
{
	int res = main_mass[0][0];
	for (int i = 0; i < SIZE2; i++)
	{
		for (int j = 0; j < SIZE2; j++)
		{
			if (main_mass[i][j] < res)
				res = main_mass[i][j];
		}
	}
	return res;
}

void Twod_mass::bubble_right_stonks()
{
	bool is_sort;
	for (int i = 0; i < SIZE2; i++)
	{
		do
		{
			is_sort = true;
			for (int j = 0; j < SIZE2 - 1; j++)
			{
				if (main_mass[i][j] > main_mass[i][j + 1])
				{
					is_sort = false;
					int fake = main_mass[i][j];
					main_mass[i][j] = main_mass[i][j + 1];
					main_mass[i][j + 1] = fake;
				}
			}
		} while (is_sort == false);
	}
}

void Twod_mass::bubble_down_stonks()
{
	bool is_sort;
	for (int j = 0; j < SIZE2; j++)
	{
		do
		{
			is_sort = true;
			for (int i = 0; i < SIZE2 - 1; i++)
			{
				if (main_mass[i][j] > main_mass[i + 1][j])
				{
					is_sort = false;
					int fake = main_mass[i][j];
					main_mass[i][j] = main_mass[i + 1][j];
					main_mass[i + 1][j] = fake;
				}
			}
		} while (is_sort == false);
	}
}

void Twod_mass::snail_stonks()
{
	bool is_sort;
	int prev_i, prev_j, i, j;
	do
	{
		prev_i = 0, prev_j = 0, i = 0, j = 1;
		is_sort = true;
		for (int scale = 0; scale < (SIZE2 / 2) + 1; scale++)
		{
			for (; j < SIZE2 - scale; j++)
			{
				if (main_mass[prev_i][prev_j] > main_mass[i][j])
				{
					is_sort = false;
					int fake = main_mass[prev_i][prev_j];
					main_mass[prev_i][prev_j] = main_mass[i][j];
					main_mass[i][j] = fake;
				}
				prev_i = i;
				prev_j = j;
			}
			j--;
			for (; i < SIZE2 - scale; i++)
			{
				if (main_mass[prev_i][prev_j] > main_mass[i][j])
				{
					is_sort = false;
					int fake = main_mass[prev_i][prev_j];
					main_mass[prev_i][prev_j] = main_mass[i][j];
					main_mass[i][j] = fake;
				}
				prev_i = i;
				prev_j = j;
			}
			i--;
			for (; j > 0 + scale; j--)
			{
				if (main_mass[prev_i][prev_j] > main_mass[i][j])
				{
					is_sort = false;
					int fake = main_mass[prev_i][prev_j];
					main_mass[prev_i][prev_j] = main_mass[i][j];
					main_mass[i][j] = fake;
				}
				prev_i = i;
				prev_j = j;
			}
			for (; i > 1 + scale; i--)
			{
				if (main_mass[prev_i][prev_j] > main_mass[i][j])
				{
					is_sort = false;
					int fake = main_mass[prev_i][prev_j];
					main_mass[prev_i][prev_j] = main_mass[i][j];
					main_mass[i][j] = fake;
				}
				prev_i = i;
				prev_j = j;
			}
		}
	} while (is_sort == false);
}

void Twod_mass::snail_nostonks()
{
	bool is_sort;
	int prev_i, prev_j, i, j;
	do
	{
		prev_i = 0, prev_j = 0, i = 0, j = 1;
		is_sort = true;
		for (int scale = 0; scale < (SIZE2 / 2) + 1; scale++)
		{
			for (; j < SIZE2 - scale; j++)
			{
				if (main_mass[prev_i][prev_j] < main_mass[i][j])
				{
					is_sort = false;
					int fake = main_mass[prev_i][prev_j];
					main_mass[prev_i][prev_j] = main_mass[i][j];
					main_mass[i][j] = fake;
				}
				prev_i = i;
				prev_j = j;
			}
			j--;
			for (; i < SIZE2 - scale; i++)
			{
				if (main_mass[prev_i][prev_j] < main_mass[i][j])
				{
					is_sort = false;
					int fake = main_mass[prev_i][prev_j];
					main_mass[prev_i][prev_j] = main_mass[i][j];
					main_mass[i][j] = fake;
				}
				prev_i = i;
				prev_j = j;
			}
			i--;
			for (; j > 0 + scale; j--)
			{
				if (main_mass[prev_i][prev_j] < main_mass[i][j])
				{
					is_sort = false;
					int fake = main_mass[prev_i][prev_j];
					main_mass[prev_i][prev_j] = main_mass[i][j];
					main_mass[i][j] = fake;
				}
				prev_i = i;
				prev_j = j;
			}
			for (; i > 1 + scale; i--)
			{
				if (main_mass[prev_i][prev_j] < main_mass[i][j])
				{
					is_sort = false;
					int fake = main_mass[prev_i][prev_j];
					main_mass[prev_i][prev_j] = main_mass[i][j];
					main_mass[i][j] = fake;
				}
				prev_i = i;
				prev_j = j;
			}
		}
	} while (is_sort == false);
}

void Twod_mass::airport_stonks()
{
	bool is_sort;
	int prev_i, prev_j, i, j;
	do
	{
		prev_i = 0, prev_j = 0, i = 0, j = 1;
		is_sort = true;
		for (; i < SIZE2; i++)
		{
			if ((i % 2) == 0)
			{
				for (; j < SIZE2; j++)
				{
					if (main_mass[prev_i][prev_j] > main_mass[i][j])
					{
						is_sort = false;
						int fake = main_mass[prev_i][prev_j];
						main_mass[prev_i][prev_j] = main_mass[i][j];
						main_mass[i][j] = fake;
					}
					prev_i = i;
					prev_j = j;
				}
				j--;
			}
			else
			{
				for (; j >= 0; j--)
				{
					if (main_mass[prev_i][prev_j] > main_mass[i][j])
					{
						is_sort = false;
						int fake = main_mass[prev_i][prev_j];
						main_mass[prev_i][prev_j] = main_mass[i][j];
						main_mass[i][j] = fake;
					}
					prev_i = i;
					prev_j = j;
				}
				j++;
			}
		}
	} while (is_sort == false);
}

void Twod_mass::labyrinth_stonks()
{

}

void Twod_mass::clone_arr(Twod_mass arr)
{
	for (int i = 0; i < SIZE2; i++)
	{
		for (int j = 0; j < SIZE2; j++)
		{
			main_mass[i][j] = arr.main_mass[i][j];
		}
	}
}