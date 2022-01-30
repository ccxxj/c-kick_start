#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>
#include <cmath>

class Fixed{

public:
	Fixed();
	~Fixed();

	Fixed(Fixed const & new_Fixed);
	Fixed(int a);
	Fixed(float a);
	Fixed &operator = (const Fixed& assignment);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat (void) const;
	int toInt(void) const;

private:
	int fixed_point_value;
	static const int fraction_bits = 8;

};

std::ostream& operator << (std::ostream& os, const Fixed& assignment);


#endif