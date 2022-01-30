#include "Fixed.hpp"

//default constructor
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point_value = 0;//set default to 0
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixed_point_value;
}

void Fixed::setRawBits(int const raw)
{
	fixed_point_value = raw;
}

// Fixed Fixed::operator = (const Fixed assignment)
// {
// 	std::cout << "Assignation operator called" << std::endl;
// 	setRawBits(assignment.getRawBits());
// 	return *this;
// }
//why this goes into endless looop??

Fixed& Fixed::operator = (const Fixed& assignment)
{
	std::cout << "Assignation operator called" << std::endl;
	setRawBits(assignment.getRawBits());
	return *this;
}

//copy constructor
Fixed::Fixed(Fixed const & new_Fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = new_Fixed;
}
