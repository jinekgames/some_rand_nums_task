//////////////////////////////////////////////////////////////////////
//																	//
// main.cpp															//
//																	//
// Тестирование работы генератора случайных чисел (вариант 10)		//
//																	//
//////////////////////////////////////////////////////////////////////


#include <iostream>
#include <fstream>
#include <Windows.h>
#include <math.h>
#include "FibRand.h"

// максимальное значение для генерируемых чисел
#define GEN_MOD_DEF 100u
// число генерируемых значений
#define COUNT_RND_NUMS_DEF 100u

#define A 10
#define B 2
#define C 3


int main() {

	srand(time(NULL));

	// массив X сгененрированных чисел
	std::vector<int> Xrnd(COUNT_RND_NUMS_DEF);
	// массив X сгененрированных чисел
	std::vector<int> Yrnd(COUNT_RND_NUMS_DEF);

	init(A, B, C, 5u, GEN_MOD_DEF);
	seed(5, rand(), rand(), rand(), rand(), rand());

	// генерация чисел (и сохранение в массив)
	for (auto& index : Xrnd) {
		index = getRand();
	}

	// вычисление второго массива
	for (auto i = 0; i < COUNT_RND_NUMS_DEF; i++) {
		Yrnd[i] = A * sin(Xrnd[i]) * sin(Xrnd[i]) + B * sin(Xrnd[i]) + C;
	}


	// хз че терь с этим делать, вывести на экран могу :/
	for (auto i = 0; i < COUNT_RND_NUMS_DEF; i++) {
		std::cout << Xrnd[i] << "\t" << Yrnd[i] << std::endl;
	}


	return 0;

}