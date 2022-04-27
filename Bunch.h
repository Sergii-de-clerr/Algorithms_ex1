#pragma once

#include <iostream>
#include <vector>

using namespace std;

const int SIZEB = 10;

class Bunch
{
public:
	Bunch();
	void random();
	void print_arr();
	int max_el();
	int min_el();
	void bubble_stonks();
	Bunch association(Bunch bunch);
	Bunch crossing(Bunch bunch);
	Bunch dlc(Bunch bunch);
	Bunch difference(Bunch bunch);
	Bunch symmetrical_difference(Bunch bunch);
	void clone_arr(Bunch arr);
private:
	void er_check();
	vector<int> main_mass;
};