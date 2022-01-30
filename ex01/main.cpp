#include "iter.hpp"

const std::string red("\033[0;31m");
const std::string reset("\033[0m");

template <typename T>
void print(T a)
{
	std::cout << a << std::endl;
}

template <typename T>
void printAdd(T a)
{
	a++;
	std::cout << a << std::endl;
}

int main()
{
	int array[4] = {1, 2, 3, 4};

	std::cout << red;
	iter(array, 4, print<int>);
	std::cout << reset;
	iter(array, 4, printAdd<int>);
	char array2[3] = {'a', 'b', 'c'}; 
	std::cout << red;
	iter(array2, 3, print<char>);
	std::cout << reset;
	iter(array2, 3, printAdd<char>);
}