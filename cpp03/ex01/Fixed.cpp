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
	return this->fixed_point_value;
}

void Fixed::setRawBits(int const raw)
{
	fixed_point_value = raw;
}

Fixed& Fixed::operator = (const Fixed& assignment)
{
	std::cout << "Assignation operator called" << std::endl;
	setRawBits(assignment.getRawBits());
	return *this;
}

std::ostream& operator << (std::ostream& os, const Fixed& assignment)
{
	os << assignment.toFloat();
	return os;
}

float Fixed::toFloat (void) const//convert the fixed point value to a floating point value
{
	float a = (float)fixed_point_value / (1 << fraction_bits);
	return a;
}

int Fixed::toInt(void) const//convert the fixed point value to an integer value
{
	int a = fixed_point_value >> fraction_bits;
	return a;
}

//copy constructor
Fixed::Fixed(Fixed const & new_Fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = new_Fixed;
}

Fixed::Fixed(int a)
{
	std::cout << "Int constructor called" << std::endl;
	fixed_point_value = a << fraction_bits;
}

Fixed::Fixed(float a)
{
	std::cout << "Float constructor called" << std::endl;
	fixed_point_value = roundf(a * (1 << this->fraction_bits));
}
