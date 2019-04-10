#include "pch.h"
#include <iostream>
#include "vector.h"

int main()
{
	int hello = 1;

	vector<int> vec;

	for (int i = 0; i < 20; i++)
	{
		vec.Push_back(i);
		std::cout << vec[i] << ", " << vec.Size() << ", " << vec.Max() << std::endl;
	}


	std::cin >> hello;

}
