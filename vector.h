#pragma once

template <class  T>
class Vector
{
private:
	T* data = nullptr;

	int size, capacity;

public:

	// Constructors
	Vector<T>()
		: capacity(20)
		, size(0)
	{
		data = new T[capacity];
	}

	Vector<T>(int i)
		: capacity(i)
		, size(0)
	{
		data = new T[capacity];
	}

	Vector(const Vector& vec)
		: capacity(vec.capacity)
	{
		data = new T[capacity];

		for (int i = 0; size < vec.size; i++)
		{
			data[i] = vec.data[i];
			size++;
		}
	}

	// Destructor
	~Vector() { delete[] data; };

	// Operator[], return element at index
	T& operator[](int i) const { return data[i]; };

	// Getters
	int Clear() { return size = 0; }
	int Max() const { return capacity; }
	int Size() const { return size; }
	int Last() const { return data[size - 1]; }
	int First() const { return data[0]; }
	bool Empty() const { return size == 0; }

	// Mutators
	void PushBack(T val);
	void Insert(int i, T val);

private:
	void AllocNew();
};

template <typename T>
void Vector<T>::PushBack(T val)
{
	if (size >= capacity)
		AllocNew();

	data[size] = val;
	size++;
}

template <typename T>
void Vector<T>::AllocNew()
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
void Vector<T>::Insert(int index, T val)
{
	if (size >= capacity)
		AllocNew();

	data[size] = data[index];
	data[index] = val;

	size++;
}
