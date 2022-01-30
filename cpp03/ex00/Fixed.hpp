#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>

class Fixed{

public:
	Fixed();
	~Fixed();

	Fixed(Fixed const & new_Fixed);
	Fixed &operator = (const Fixed& assignment);
	// Fixed operator = (const Fixed assignment);
	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int fixed_point_value;
	static const int fraction_bits = 8;

};

#endif