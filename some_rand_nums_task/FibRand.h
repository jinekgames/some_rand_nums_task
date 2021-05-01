//////////////////////////////////////////////////////////////////////
//																	//
// FibRand.h														//
//																	//
// Генератора случайных чисел (вариант 10 (на числах Фибоначчи)		//
//																	//
//////////////////////////////////////////////////////////////////////


#pragma once

#include <list>
#include <vector>


typedef int TYPE;
//template<class TYPE>
class FibRand {

public:
	FibRand() noexcept;
	FibRand(int a, int b, int c, unsigned int k, unsigned int m) noexcept;
	~FibRand() noexcept = default;

public:
	TYPE getValue();
	void seed(std::vector<TYPE> startValues);
	void seed(std::list<TYPE> startValues);
	void seed(TYPE n, ...);

private:
	// коэффициенты
	int A = 1;
	int B = 2;
	int C = 3;
	unsigned int K = 5u;		// также определяет размер буфера (дб целочисленным)
	unsigned int M = 30u;
	// буфер с вычисленными ранее значениями
	std::list<TYPE> buf;

};





/*

// коэффициенты

int A = 1;
int B = 2;
int C = 3;
unsigned int K = 5u;		// также определяет размер буфера (дб целочисленным)
unsigned int M = 30u;


//тип данных вычисляемых значений
typedef int TYPE;

// буфер с вычисленными ранее значениями
std::list<TYPE> v(K);

// функция подсчета нового элемента
TYPE calculate() {

	// вычисляемый элемент
	TYPE newValue;

	// x(n-1)
	auto prevElemTag = v.end();
	prevElemTag--;
	TYPE prevElem = *prevElemTag;
	// x(n-k)
	TYPE lastElem = *(v.begin());


	// собственно вычисление
	newValue = (A * prevElem + B * lastElem + C) % M;


	// удаление первого элемента буфера
	v.pop_front();
	// добавление вычисленного значения в буфер
	v.push_back(newValue);

	// возврат вычисленного значения
	return newValue;

}

// инициализация модуля
void init(int a, int b, int c, unsigned int k, unsigned int m) {

	A = a;
	B = b;
	C = c;
	K = k;
	M = m;

	//изменение длины буфера
	//

}

// задание начальных значений
void seed(std::vector<TYPE> startValues) {

	auto indexSeed = startValues.begin();

	for (auto& indexList : v) {

		indexList = *(indexSeed++);

	}

}
// задание начальных значений
void seed(std::list<TYPE> startValues) {

	auto indexSeed = startValues.begin();

	for (auto& indexList : v) {

		indexList = *(indexSeed++);

	}

}
// задание начальных значений
void seed(TYPE n, ...) {

	TYPE* ptr = &n;
	unsigned int index = 1;

	for (auto& indexList : v) {

		indexList = ptr[index];

		index++;
		if (index > n) {
			return;
		}

	}

}



// получение случайного числа
TYPE getRand() {

	return calculate();

}

*/
