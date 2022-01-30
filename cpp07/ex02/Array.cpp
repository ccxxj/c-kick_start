#include "Array.hpp"


template <typename T>
Array::Array()
{
	array = new T[0]();
	arraySize = 0;
}

template <typename T>
Array::Array(unsigned int n)
{
	array = new T[n];
	arraySize = n;
}

template <typename T>
Array &Array::operator[](unsigned int n)
{
	if (n < 0 || n >= arraySize)
		throw std::exception;
	return array[n];
}

int Array::size(void) const { return arraySize; }

Array::~Array()
{
	delete [] array;
}