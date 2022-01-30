#include <Array.hpp>

int main()
{
try{
	Array<int> sample1(12);
	std::cout << sample1.size() << std::endl;
}
catch(std::exception &a){
	std::cout << a.what() << std::endl;
}
try{
	Array<int> sample2(5);
	std::cout << sample2[2] << std::endl;
}
catch(std::exception &a){
	std::cout << a.what() << std::endl;
}
try{
	Array<int> sample3(5);
	std::cout << sample3[7] << std::endl;
}
catch(std::exception &a){
	std::cout << a.what() << std::endl;
}
}