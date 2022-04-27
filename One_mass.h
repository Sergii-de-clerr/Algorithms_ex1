#pragma once

#include <iostream>

using namespace std;

const int SIZE = 150;

class Oned_mass
{
public:
	Oned_mass();
	void random();
	void print_arr();
	int max_el();
	int min_el();
	void bubble_nostonks();
	void bubble_stonks();
	void middle_stonks();
	void chess_stonks();
	void twogroup_stonks();
private:
	void clone_arr(Oned_mass arr);
	int main_mass[SIZE];
};