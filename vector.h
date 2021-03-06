#pragma once

#include <assert.h>

template <class  T>
class Vector
{
private:
	T* _data = nullptr;

	int _size, _capacity = 0;

public:

	// Constructors
	Vector<T>() 
		: _capacity(20)
		, _size(0)
	{
		_data = new T[_capacity];
	}

	Vector<T>(int i) 
		: _capacity(i)
		, _size(0)
	{
		_data = new T[_capacity];
	}

	Vector(const Vector& vec) 
		: _capacity(vec._capacity)
		, _size(vec._size)
	{
		_data = new T[_capacity];

		for (int i = 0; _size < vec._size; i++)
		{
			_data[i] = vec._data[i];
			_size++;
		}
	}

	// Destructor
	~Vector() { delete[] _data; };

	// Operator[], return element at index
	T& operator[](int i) const { return _data[i]; };

	// Checks
	bool isEmpty()	const { return _size == 0;		}
	int max()		const { return _capacity;		}
	int length()	const { return _size;			}
	T* begin()		const { return _data;			}
	T* end()		const { return _data + _size;	}
	int search(const T& val) const ;

	// Mutators
	void sort();
	void swap(T& first, T& second);
	void insert(int index, const T& val);
	void push_back(const T& val);
	void clear() { _size = 0; }

private:
	void alloc_new();
};

template <class  T>
int Vector<T>::search(const T& val) const
{
	int low = 0;
	int mid = 0;
	int high = _size - 1;

	for (int i = 0; i < _size; i++)
	{
		mid = (low + high) / 2;

		if (val == _data[mid])
		{
			printf("value found at index %d", mid);
			return mid;
		}
		else if (val > _data[mid])
		{
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	printf("value not found");
	return 0;
}

template <class T>
void Vector<T>::swap(T& first, T& second)
{
	//lel gör om så att funktionen tar index inte värde edjot
	//assert(first + _size && second < _size && "index out of bounds.");

	T tmp = first;
	first = second;
	second = tmp;
}

template <class  T>
void Vector<T>::sort()
{
	for (int i = 0; i < _size; i++)
	{
		T smallest = _data[i];
		int smallestIndex = i;

		for (int j = i; j < _size; j++)
		{
			if (_data[j] < smallest)
			{
				smallest = _data[j];
				smallestIndex = j;
			}
		}
		swap(_data[i], _data[smallestIndex]);
	}
}

template <typename T>
void Vector<T>::push_back(const T& val)
{
	if (_size + 1 > _capacity)
		alloc_new();

	_data[_size++] = val;
}

template <typename T>
void Vector<T>::alloc_new()
{
	_capacity *= 2;

	T* tmp = _data;
	_data = new T[_capacity];

	for (int i = 0; i < _size; i++)
	{
		_data[i] = tmp[i];
	}
	delete[] tmp;
}

template <typename T>
void Vector<T>::insert(int index, const T& val)
{
	assert (_size + 1 > index && "index out of bounds.");
	if (_size + 1 > _capacity)
		alloc_new();

	T* tmp = _data;
	_data = new T[_capacity];
	_size++;

	for (int i = 0; i < _size; i++)
	{
		if (i < index)
		{
			_data[i] = tmp[i];
		}
		else if (i == index)
		{
			_data[i]++;
		}
		else
		{
			_data[i] = tmp[i - 1];
		}
	}
	
	_data[index] = val;
	delete[] tmp;
}
