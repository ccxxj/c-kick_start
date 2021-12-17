#include <stdint.h>
#include <iostream>

typedef struct{
	int test;
	int result;
} Data;

uintptr_t serialize(Data* ptr)
{
	// return reinterpret_cast<uintptr_t>(&(ptr->test));
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	// Data *a;
	return reinterpret_cast<Data*>(raw);
	// a->test = reinterpret_cast<int>(*raw);
	// return a;
}

int main()
{
	Data a;
	a.test = 100;
	a.result = 200;
	uintptr_t b = serialize(&a);
	std::cout << deserialize(b)->test << std::endl;
	std::cout << deserialize(b)->result << std::endl;
}