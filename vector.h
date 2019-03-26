#pragma once

template <class  T>
class vector
{
public:

	// Constructors
	vector<T>();
	vector<T>(int i);
	vector(const vector& vec);

	// Destuctor
	~vector() { delete[] vector; data = nullptr; };

	// Operator [], return element at index
	T&	operator[](int i) const { return data[i]; };

	void push_back(T val);
	void insert(T val, int i);
	void for_each(T val);

private:
	T* data = nullptr;
	int size, capacity;

	void alloc_new();
};

template <typename T>
vector<T>::vector<T>()
{
	capacity = 20;
	data = new T[capacity];
	size = 0;
}

template <typename T>
vector<T>::vector(int i)
{
	capacity = i;
	data = new T[capacity];
	size = 0;
}

template <typename T>
vector<T>::vector(const vector& vec)
{
	if (vec.size > capacity)
		alloc_new();

	for (int i = 0; vec.size > size; i++)
	{
		data[i] = vec.data[i];
		size++;
	}
}

template <typename T>
void vector<T>::push_back(T val)
{
	if (size + 1 > capacity)
		alloc_new();

	size++
}

template <typename T>
void vector<T>::insert(T val, int i)
{
	if (i <= size)
	{
		for (int i = 0; i < size; i++)
		{
			if (i = data[i])
				data[i] = val;
		}
	}
	else
		// Throw exception
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
