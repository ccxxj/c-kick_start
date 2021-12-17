#include <iostream>
#include "class.hpp"

Base * generate(void)
{
	srand(time(NULL));
	int a = rand() % 3;
	std::cout << a << std::endl;
	switch (a){
	case 0: return new A();
	case 1: return new B();
	case 2: return new C();
	}
	return nullptr;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try{
		A a;
		a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast){
	}
	try{
		B b;
		b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::bad_cast){
	}
	try{
		C c;
		c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::bad_cast){
	}

}

int main()
{
	Base *b = generate();
	identify(b);
	identify(*b);
	return 0;
}