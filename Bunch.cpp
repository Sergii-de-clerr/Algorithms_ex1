#include "Bunch.h"
#include <iostream>
#include <ctime>

Bunch::Bunch()
{
	this->random();
	this->bubble_stonks();
	this->er_check();
}

void Bunch::random()
{
	for (int i = 0; i < SIZEB; i++)
	{
		main_mass.push_back(rand() % 50);
	}
}

void Bunch::print_arr()
{
	cout << "Array" << endl;
	for (int i = 0; i < main_mass.size(); i++)
	{
		cout << "el" << i << ": " << main_mass[i] << endl;
	}
}

int Bunch::max_el()
{
	int res = main_mass[0];
	for (int i = 0; i < SIZEB; i++)
	{
		if (main_mass[i] > res)
			res = main_mass[i];
	}
	return res;
}

int Bunch::min_el()
{
	int res = main_mass[0];
	for (int i = 0; i < SIZEB; i++)
	{
		if (main_mass[i] < res)
			res = main_mass[i];
	}
	return res;
}

void Bunch::bubble_stonks()
{
	bool is_sort;
	do
	{
		is_sort = true;
		for (int i = 0; i < main_mass.size() - 1; i++)
		{
			if (main_mass[i] > main_mass[i + 1])
			{
				is_sort = false;
				int fake = main_mass[i];
				main_mass[i] = main_mass[i + 1];
				main_mass[i + 1] = fake;
			}
		}
	} while (is_sort == false);
}

Bunch Bunch::association(Bunch bunch)
{
	Bunch res;
	//this->main_mass = {8, 10, 12, 14, 16, 17, 27};
	//bunch.main_mass = {0, 11, 13, 15, 16, 27, 30};
	res.clone_arr(*this);
	int i = (main_mass.size() - 1), j = (bunch.main_mass.size() - 1);
	while ((i != -1) && (j != -1))
	{
		if (main_mass[i] < bunch.main_mass[j])
		{
			res.main_mass.push_back(bunch.main_mass[j]);
			j--;
		}
		else if (main_mass[i] > bunch.main_mass[j])
		{
			i--;
		}
		else
		{
			i--;
			j--;
		}
	}
	if (main_mass[0] > bunch.main_mass[0])
	{
		res.main_mass.push_back(bunch.main_mass[j]);
		j--;
	}
	return res;
}

Bunch Bunch::crossing(Bunch bunch)
{
	Bunch res;
	/*this->main_mass = {8, 10, 12, 14, 16, 17, 27};
	bunch.main_mass = {0, 11, 13, 15, 16, 27, 30};*/
	res.main_mass.clear();
	//res.clone_arr(*this);
	int i = (main_mass.size() - 1), j = (bunch.main_mass.size() - 1);
	while ((i != -1) && (j != -1))
	{
		if (main_mass[i] < bunch.main_mass[j])
		{
			j--;
		}
		else if (main_mass[i] > bunch.main_mass[j])
		{
			i--;
		}
		else
		{
			res.main_mass.push_back(bunch.main_mass[j]);
			i--;
			j--;
		}
	}
	return res;
}

Bunch Bunch::dlc(Bunch bunch)
{
	Bunch res;
	this->main_mass = {8, 10, 12, 14, 16, 17, 27};
	bunch.main_mass = {0, 11, 13, 15, 16, 27, 30};
	res.main_mass.clear();
	//res.clone_arr(*this);
	int i = (main_mass.size() - 1), j = (bunch.main_mass.size() - 1);
	while ((i != -1) && (j != -1))
	{
		if (main_mass[i] < bunch.main_mass[j])
		{
			j--;
		}
		else if (main_mass[i] > bunch.main_mass[j])
		{
			res.main_mass.push_back(bunch.main_mass[j]);
			i--;
		}
		else
		{
			i--;
			j--;
		}
	}
	if (main_mass[0] < bunch.main_mass[0])
	{
		res.main_mass.push_back(bunch.main_mass[j]);
		i--;
	}
	return res;
}

//Bunch Bunch::difference(Bunch bunch)
//{
//
//}
//
//Bunch Bunch::symmetrical_difference(Bunch bunch)
//{
//
//}

void Bunch::clone_arr(Bunch arr)
{
	main_mass = arr.main_mass;
}

void Bunch::er_check()
{
	vector<int> res;
	res.push_back(main_mass[0]);
	for (int i = 1; i < main_mass.size(); i++)
	{
		if (main_mass[i] != main_mass[i - 1])
		{
			res.push_back(main_mass[i]);
		}
	}
	main_mass = res;
}