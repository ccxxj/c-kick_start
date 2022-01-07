#pragma once
#include <iostream>


template <typename T>
class Array{

public:
	Array(){
		array = new T[0]();
		arraySize = 0;
	}

	Array(unsigned int n){
		array = new T[n];
		arraySize = n;
	}

	Array(Array &a){
		int size = a.size();
		array = new T[size]();
		arraySize = size;
		for (int i = 0; i < size; i++)
			array[i] = a.array[i];
	}

	Array &operator=(Array &a){
		int size = a.size();
		arraySize = size;
		array = new T[size]();
		for (int i = 0; i < size; i++)
			array[i] = a.array[i];
		return *this;
	}

	T &operator[](unsigned int n){
		if (n < 0 || n >= arraySize)
			throw std::range_error("beyond range");
		return array[n];
	}

	~Array() { delete [] array;}

	int size(void) const{return arraySize;}

private:
	unsigned int arraySize;
	T	*array;
};
