#pragma once

template <class  T>
class vector
{
public:

	// Constructors
	vector<T>();
	vector(const vector&); // copy constructor

	// Destuctor
	~vector() { delete[] vector; data = nullptr; };

	// Operator [], return element at index
	T&	operator[](int i) { return data[i]; };

	void push_back(T val);
	void insert(T val);
	void for_each(T val);

private:
	T* data = nullptr;
	int size, capacity;

	void alloc_new();
};

template <typename T>
void vector<T>::push_back(T val)
{
	if (size + 1 > capacity)
		alloc_new();

	size++
}

template <typename T>
vector<T>::vector<T>()
{
	capacity = 20;
	data = new T[capacity];
	size = 0;
}

template <typename T>
void vector<T>::alloc_new()
{
	capacity *= 2;

	T* tmp = data;
	data = new T[capacity];

	for (int i = 0; i < size; i++)
	{
		data[i] = tmp[i];
	}
	delete tmp;
}
