#pragma once

#include <iostream>

using namespace std;

const int SIZE2 = 15;

class Twod_mass
{
public:
	Twod_mass();
	void random();
	void print_arr();
	int max_el();
	int min_el();
	void bubble_right_stonks();
	void bubble_down_stonks();
	void snail_stonks();
	void snail_nostonks();
	void airport_stonks();
	void labyrinth_stonks();
private:
	void clone_arr(Twod_mass arr);
	int main_mass[SIZE2][SIZE2];
};