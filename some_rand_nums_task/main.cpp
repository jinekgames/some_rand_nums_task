﻿//////////////////////////////////////////////////////////////////////
//																	//
// main.cpp															//
//																	//
// Тестирование работы генератора случайных чисел (вариант 10)		//
//																	//
//////////////////////////////////////////////////////////////////////


#include <iostream>
#include <Windows.h>

#include "FibRand.h"
#include <vector>


// максимальное значение для генерируемых чисел
#define GEN_MOD_DEF 100u
// число генерируемых значений
#define COUNT_RND_NUMS_DEF 10u
// число интервалов для исследования
#define COUNT_INTERVALS_DEF 2u
// длина каждого интервала
#define INTERVAL_LENTH_DEF GEN_MOD_DEF / COUNT_INTERVALS_DEF


int main(int argc, char* argv) {

	unsigned int genMod,
				countRndNums,
				countIntrvls;

	// считывание					\
		модуля генерируемых чисел	\
		числа генерируемых значений	\
		и числа интервалов			\
	   из командной строки (или заполнение дефолтными значениями)
	if (argc < 4) {
		genMod = GEN_MOD_DEF;
		countRndNums = COUNT_RND_NUMS_DEF;
		countIntrvls = COUNT_INTERVALS_DEF;
	} else {
		// да ну в пизду крч
	}



	// рандомизация дэфолтного рандомайзера
	srand(GetTickCount64());

	// объект класса генератора (можно оставть без параметров, будут заданы значения по умолчанию)
	FibRand Rand(10,2,6,5,GEN_MOD_DEF);

	// рандомизация генератора рандомными значениями дэфолтного рандомайзера
	Rand.seed(5, rand(), rand(), rand(), rand(), rand());


	// массив сгененрированных N чисел
	std::vector<int> rndValues(COUNT_RND_NUMS_DEF);
	// сюда мы запишем сколько чисел попало в каждый из интервалов
	static unsigned int numsInIntrvls[COUNT_INTERVALS_DEF];
	// эксперементальные вероятности
	double expProbs[COUNT_INTERVALS_DEF];


	// генерация чисел (и сохранение в массив)
	for (auto& index : rndValues) {
		index = Rand.getValue();
	}


	// подсчет чисел, попавших в заданные интервалы
	for (auto index : rndValues) {
		for (auto i = 0; i < COUNT_INTERVALS_DEF; i++) {

			index -= INTERVAL_LENTH_DEF;
			if (index < 0) {
				numsInIntrvls[i]++;
				break;
			}

		}
	}


	std::cout << "Generator experimental probabilites:\n";
	for (auto i = 0; i < COUNT_INTERVALS_DEF; i++) {
		expProbs[i] = double(numsInIntrvls[i]) / COUNT_RND_NUMS_DEF;
		std::cout << expProbs[i] << "\n";
	}
	std::cout << "\nTheoretical Probability:\n" << 1.0 / COUNT_INTERVALS_DEF << std::endl;


	return 0;

}
