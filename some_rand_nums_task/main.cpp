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

#include "FibRand.h"

// максимальное значение для генерируемых чисел
#define GEN_MOD_DEF 100u
// число генерируемых значений
#define COUNT_RND_NUMS_DEF 100u
// число интервалов для исследования
#define COUNT_INTERVALS_DEF 20u
// длина каждого интервала
#define INTERVAL_LENTH_DEF GEN_MOD_DEF / COUNT_INTERVALS_DEF


int main() {

	srand(time(NULL));

	// массив сгененрированных N чисел
	std::vector<int> rndValues(COUNT_RND_NUMS_DEF);
	// сюда мы запишем сколько чисел попало в каждый из интервалов
	static unsigned int numsInIntrvls[COUNT_INTERVALS_DEF];
	// эксперементальные вероятности
	double expProbs[COUNT_INTERVALS_DEF];

	init(10, 2, 3, 5u, GEN_MOD_DEF);
	seed(5, rand(), rand(), rand(), rand(), rand());

	// генерация чисел (и сохранение в массив)
	for (auto& index : rndValues) {
		index = getRand();
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

	// открытие файла для записи чисел тобы потом график сделать красиво (вау)
	std::ofstream fout("results.txt", std::ios::trunc);

	// вывод эксперементальных вероятностей в файл
	for (auto i = 0; i < COUNT_INTERVALS_DEF; i++) {
		expProbs[i] = double(numsInIntrvls[i]) / COUNT_RND_NUMS_DEF;
		fout << expProbs[i] << "\n";
	}


	return 0;

}