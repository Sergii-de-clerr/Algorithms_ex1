#include "One_mass.h"
#include "Two_mass.h"
#include "Three_mass.h"
#include "Bunch.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ukr");

#pragma region Exercise 1

	/*Oned_mass arr;
	arr.print_arr();

	cout << "Найбiльший елемент:" << arr.max_el() << endl;
	cout << "Найменший елемент:" << arr.min_el() << endl;*/

	/*arr.bubble_nostonks();
	arr.print_arr();

	arr.bubble_stonks();
	arr.print_arr();

	arr.middle_stonks();
	arr.print_arr();

	arr.chess_stonks();
	arr.print_arr();*/
	
	/*arr.twogroup_stonks();
	arr.print_arr();

	system("pause");*/

#pragma endregion Завдання 1

#pragma region Exercise 2

	/*Twod_mass arr;
	arr.print_arr();

	cout << "Найбiльший елемент:" << arr.max_el() << endl;
	cout << "Найменший елемент:" << arr.min_el() << endl;*/

	/*arr.bubble_right_stonks();
	arr.print_arr();

	arr.bubble_down_stonks();
	arr.print_arr();*/

	/*arr.snail_stonks();
	arr.print_arr();*/

	/*arr.snail_nostonks();
	arr.print_arr();*/

	/*arr.airport_stonks();
	arr.print_arr();*/

	//system("pause");

#pragma endregion Завдання 2

#pragma region Exercise 3

	/*Threed_mass arr;
	arr.print_arr();

	cout << "Найбiльший елемент:" << arr.max_el() << endl;
	cout << "Найменший елемент:" << arr.min_el() << endl;*/

	/*arr.bubble_X_stonks();
	arr.print_arr();*/

	/*arr.bubble_Y_stonks();
	arr.print_arr();*/

	/*arr.bubble_Z_stonks();
	arr.print_arr();

	system("pause");*/

#pragma endregion Завдання 3

#pragma region Exercise 4

	//vector<int> t;
	srand(time(NULL));

	Bunch arr1;
	Bunch arr2;
	Bunch arrres;

	arr1.print_arr();
	arr2.print_arr();

	/*arrres.clone_arr(arr1.association(arr2));
	arrres.print_arr();*/

	/*arrres.clone_arr(arr1.crossing(arr2));
	arrres.print_arr();*/

	arrres.clone_arr(arr1.dlc(arr2));
	arrres.print_arr();

	system("pause");

#pragma endregion Завдання 4
}