#include "pch.h"
#include <iostream>
#include "Vector.h"

int main()
{
	Vector<int> vec;

	for (int i = 0; i < 25; i++)
	{
		vec.push_back(i);
	}
	
	vec.swap(vec[5], vec[12]);
	vec.sort();

	for (int i = 0; i < vec.length(); i++)
	{
		std::cout << vec[i] << ", " << vec.length() << ", " << vec.max() << std::endl;
	}

	vec.search(2);

	std::system("pause");
}
