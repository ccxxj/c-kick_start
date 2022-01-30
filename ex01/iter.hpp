#pragma once

#include <iostream>

template <typename T, typename F>
void iter(T address, int lenth, F *f)
{
	assert(lenth > 0);
	for (int i = 0; i < lenth; i++)
	{
		f(*address);
		address++;
	}
}
