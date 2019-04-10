#pragma once

template <class  T>
class vector
{
private:
	T* data = nullptr;

	int size, capacity = 0;

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
	int Max()   const { return capacity; }
	int Size()  const { return size; };
	T Last()  const { return data[size-1]; };
	T First() const { return data[0]; };
	bool Empty() const { return size == 0; };

	// Mutators
	void Clear() const { size = 0; };
	void Push_back(const T& val);
	void Insert(const T& val, int i);

private:
	void Alloc_new();
};

template <typename T>
vector<T>::vector<T>()
	: capacity(20)
	, size(0)
{
	data = new T[capacity];
}

template <typename T>
vector<T>::vector(int i)
	: capacity(i)
	, size(0)
{
	data = new T[capacity];
}

template <typename T>
vector<T>::vector(const vector& vec)
	: capacity(vec.capacity)
{	
	data = new T[capacity];

	for (int i = 0; size < vec.size; i++)
	{
		data[i] = vec.data[i];
		size++;
	}
}

template <typename T>
void vector<T>::Push_back(const T& val)
{
	if (size > capacity)
		Alloc_new();

	data[size++] = val;
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
	delete[] tmp;
}

template <typename T>
void vector<T>::Insert(const T& val, int index)
{
	if (size + 1 > capacity)
		Alloc_new();

	for (int i = capacity; i > index; i--)
	{
		if (i > index)
			data[i] = data[i] + 1;
		if (int i = index)
		{
			data[i +1] = val;
			size++;
			break;
		}
	}
}
