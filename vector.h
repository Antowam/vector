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
	int Clear()	   	   { return size = 0; };
	int Max()    const { return capacity; }
	int Size()   const { return size; };
	int Last()   const { return data[size - 1]; };
	int First()	 const { return data[0]; };
	bool Empty() const { return size == 0; };

	// Mutators
	void Push_back(T val);
	void Insert(int i, T val);
	void For_each(const vector& vec);

private:
	void Alloc_new();
};

template <typename T>
vector<T>::vector()
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
void vector<T>::Push_back(T val)
{
	if (size >= capacity)
		Alloc_new();

	data[size] = val;
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
	delete[] tmp;
}

template <typename T>
void vector<T>::Insert(int index, T val)
{
	if (size >= capacity)
		Alloc_new();

	data[Size()] = data[index];
	data[index] = val;

	size++;
}

template <typename T>
void vector<T>::For_each(const vector& vec)
{

}
