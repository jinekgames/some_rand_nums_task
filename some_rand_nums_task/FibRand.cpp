//////////////////////////////////////////////////////////////////////
//																	//
// FibRand.cpp														//
//																	//
//////////////////////////////////////////////////////////////////////


#include "FibRand.h"


FibRand::FibRand() noexcept
	:
	A(1), B(2), C(3), K(5), M(30),
	buf(K)
{}

FibRand::FibRand(int a, int b, int c, unsigned int k, unsigned int m) noexcept
	:
	A(a), B(b), C(c), K(k), M(m),
	buf(K)
{}

TYPE FibRand::getValue()
{

	// вычисляемый элемент
	TYPE newValue;

	// x(n-1)
	auto prevElemTag = buf.end();
	prevElemTag--;
	TYPE prevElem = *prevElemTag;
	// x(n-k)
	TYPE lastElem = *(buf.begin());


	// собственно вычисление
	newValue = (A * prevElem + B * lastElem + C) % M;


	// удаление первого элемента буфера
	buf.pop_front();
	// добавление вычисленного значения в буфер
	buf.push_back(newValue);

	// возврат вычисленного значения
	return newValue;

}

void FibRand::seed(std::vector<TYPE> startValues)
{

	auto indexSeed = startValues.begin();

	for (auto& indexList : buf) {

		indexList = *(indexSeed++);

	}

}

void FibRand::seed(std::list<TYPE> startValues)
{
	auto indexSeed = startValues.begin();

	for (auto& indexList : buf) {

		indexList = *(indexSeed++);

	}

}

void FibRand::seed(TYPE n, ...)
{

	TYPE* ptr = &n;
	unsigned int index = 1;

	for (auto& indexList : buf) {

		indexList = ptr[index];

		index++;
		if (index > n) {
			return;
		}

	}

}
