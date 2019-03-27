#include "pch.h"
#include <iostream>
#include "vector.h"

int main()
{
	int hello = 1;

	vector<int> vec;

	for (int i = 0; i < 30; i++)
	{
		vec.Push_back(i);
	}
	
	vec.Insert(3, 5);

	for (int i = 0; i < vec.Size(); i++)
	{
		std::cout << vec[i] << ", " << vec.Size() << ", " << vec.Max() << std::endl;
	}

	vec[0] = 45;

	std::cout << vec.Empty() << std::endl;
	std::cout << vec.Last() << std::endl;
	std::cout << vec.First() << std::endl;

	vec.Clear();

	std::cout << vec.Size() << std::endl;

	std::cin.get();

}
