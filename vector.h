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

	// Operator[], return element at index
	T&	operator[](int i) const { return data[i]; };

	// Getters
	void Clear() const { return size = 0; };
	void Size()  const { return size; };
	void Max()	 const { return capacity; }
	void First() const { return data[0]; };
	void Last()	 const { return data[size]; };
	bool Empty() const { return size == 0; };

	// Mutators
	void Push_back(T val);
	void Insert(T val, int i);

private:
	T* data = nullptr;
	int size, capacity;

	void Alloc_new();
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
		Alloc_new();

	for (int i = 0; vec.size > size; i++)
	{
		data[i] = vec.data[i];
		size++;
	}
}

template <typename T>
void vector<T>::Push_back(T val)
{
	if (size + 1 > capacity)
		Alloc_new();

	size++;
}

template <typename T>
void vector<T>::Insert(T val, int i)
{
	if (i <= size)
	{
		for (int i = 0; i < size; i++)
		{
			if (i = data[i])
				data[i] = val;
		}
	}
	// else
		// Throw exception
}

template <typename T>
void vector<T>::Alloc_new()
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
