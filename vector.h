#pragma once

template <class  T>
class vector
{
private:
	T* data = nullptr;

	int size, capacity;

public:

	// Constructors
	vector<T>();
	vector<T>(int i);
	vector(const vector& vec);

	// Destructor
	~vector() { delete[] data; };

	// Operator[], return element at index
	T& operator[](int i) const { return data[i]; };

	// Getters
	void Clear() const { return size = 0; };
	void Size()  const { return size; };
	void Max()   const { return capacity; }
	void First() const { return data[0]; };
	void Last()  const { return data[size]; };
	bool Empty() const { return size == 0; };

	// Mutators
	void Push_back(T val);
	void Insert(T val, int i);

private:
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
	capacity = vec.capacity;
	
	data = new T[capacity];

	for (int i = 0; size < vec.size; i++)
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

	data[size + 1] = val;
	size++;
}

template <typename T>
void vector<T>::Alloc_new()
{
	capacity *= 2;

	T* tmp = data;
	data = new T[capacity];

	for (int i = 0; i < capacity; i++)
	{
		data[i] = tmp[i];
	}
	delete tmp;
}

template <typename T>
void vector<T>::Insert(T element, int index)
{
	if (index <= capacity)
	{
		for (int i = 0; i < size; i++)
		{
			if (i = index)
				data[element];
		}
	}
	// else
		// Throw exception
}
