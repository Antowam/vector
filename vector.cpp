#include "pch.h"
#include <iostream>
#include "Vector.h"

int main()
{
	int hello = 1;

	Vector<int> vec;

	for (int i = 0; i < 25; i++)
	{
		vec.push_back(i);
	}
	
	vec.swap(vec[5], vec[22]);
	vec.sort();

	for (int i = 0; i < vec.length(); i++)
	{
		std::cout << vec[i] << ", " << vec.length() << ", " << vec.max() << std::endl;
	}

	std::system("pause");
}
