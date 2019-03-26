#pragma once

template <class  T>
class vector
{
public:

	// Constructors
	vector<T>();
	vector(const vector&);

	// Destuctor
	~vector() { delete[] vector; };

	// Operator [], return element at index
	T&	operator[](int i) { return data[i]; };
	T	at(int i) const { return data[i] } ;

	void push_back(T val);
	void insert(T val);
	void for_each(T val);

private:
	T* data;

	int size,capacity;
};

template <typename T>
void vector<T>::push_back(T val)
{
	if (size + 1 > capacity)
		capacity *= 2;

	T* tmp = data;
	data = new T[capacity];

	for (int i = 0; i < size; i++)
	{
		data[i] = tmp[i];
	}
	delete tmp;

	return data;
}

template <typename T>
vector<T>::vector<T>()
{
	capacity = 20;
	vec = new T[capacity];
	size = 0;
}
