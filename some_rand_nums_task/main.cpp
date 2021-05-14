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
#include <vector>



// вские параметры чтобы быстро тут поменять


// максимальное значение для генерируемых чисел
#define GEN_MOD_DEF 100u
// число генерируемых значений
#define COUNT_RND_NUMS_DEF 10u
// число интервалов для исследования
#define COUNT_INTERVALS_DEF 2u
// длина каждого интервала
#define INTERVAL_LENTH_DEF GEN_MOD_DEF / COUNT_INTERVALS_DEF

// название файла, куда будут записаны результаты
#define OUTPUT_FILENAME "exp_probs.txt"
// параметры инициализации генератора
#define A_GEN_INIT 10
#define B_GEN_INIT 2
#define C_GEN_INIT 6
#define K_GEN_INIT 5u


// параметры закончились \
начался код



int main(int argc, char* argv) {

	// рандомизация дэфолтного рандомайзера
	srand(GetTickCount64());

	// объект класса генератора (можно оставть без параметров, будут заданы значения по умолчанию)
	FibRand Rand(A_GEN_INIT, B_GEN_INIT, C_GEN_INIT, K_GEN_INIT, GEN_MOD_DEF);

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


	// открытие файла для записи чисел тобы потом график сделать красиво (вау)
	std::ofstream fout(OUTPUT_FILENAME, std:: ios::trunc);

	std::cout << "Generator experimental probabilites:\n";
	for (auto i = 0; i < COUNT_INTERVALS_DEF; i++) {

		expProbs[i] = double(numsInIntrvls[i]) / COUNT_RND_NUMS_DEF;
		std::cout << expProbs[i] << "\n";

		// а теперь в файл, чтобы сделать из этого график потом
		fout << expProbs[i] << "\n";

	}
	std::cout << "\nTheoretical Probability:\n" << 1.0 / COUNT_INTERVALS_DEF << std::endl;


	return 0;

}
