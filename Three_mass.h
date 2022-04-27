#pragma once

#include <iostream>

using namespace std;

const int SIZE3 = 6;

class Threed_mass
{
public:
	Threed_mass();
	void random();
	void print_arr();
	int max_el();
	int min_el();
	void bubble_X_stonks();
	void bubble_Y_stonks();
	void bubble_Z_stonks();
private:
	int main_mass[SIZE3][SIZE3][SIZE3];
};