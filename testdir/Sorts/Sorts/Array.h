#ifndef ARRAY_H
#define ARRAY_H
#define MIN(a, b) ((a < b) ? a : b)
#include "Exception.h"

template <typename T>
class Array
{
public:
	//CTOR
	Array();

	//2-ARG CTOR
	Array(int length, int start_index = 0);

	//DTOR
	~Array();

	//COPY CTOR
	Array(const Array<T> & copy);

	//OP=
	Array & operator=(const Array<T> & rhs);

	//OP[]
	T & operator[](int index);

	//SETTERS AND Gex() const;
	int GetLength() const;
	int GetStartIndex() const;
	void SetStartIndex(int start_index);
	void SetLength(int length);

private:
	T * m_array;
	int m_length;
	int m_start_index;
};

//CTOR
template <typename T>
Array<T>::Array() : m_array(nullptr),
m_start_index(0), m_length(0)
{
}

//2-ARG CTOR
template <typename T>
Array<T>::Array(int length, int start_index) :
	m_length(length), m_start_index(start_index), m_array(nullptr)
{
	//if less than 0
	if (length < 0)
	{
		m_length = 0;
		throw Exception("Error");
	}
	else if (length == 0)
	{
		m_array = nullptr;
	}
	else
	{
		m_array = new T[length];
	}
}

//DTOR
template <typename T>
Array<T>::~Array()
{
	delete[] m_array;
	m_array = nullptr;
	m_length = 0;
	m_start_index = 0;
}

//COPY-CTOR
template <typename T>
Array<T>::Array(const Array<T> & copy)
	: m_length(copy.m_length),
	m_start_index(copy.m_start_index)
{
	m_array = new T[copy.m_length];
	for (int length = 0; length < copy.m_length; ++length)
	{
		m_array[length] = copy.m_array[length];
	}
}

//OP=
template <typename T>
Array<T> & Array<T>::operator=(const Array<T> & rhs)
{
	if (this != &rhs)
	{
		delete[] m_array;
		m_length = rhs.m_length;
		m_start_index = rhs.m_start_index;
		if (rhs.m_length == 0)
		{
			m_array = nullptr;
		}
		else
		{
			m_array = new T[rhs.m_length];
			for (int length = 0; length < rhs.m_length; ++length)
			{
				m_array[length] = rhs.m_array[length];
			}
		}
	}
	return *this;

}

//OP[]
template <typename T>
T & Array<T>::operator[](int index)
{
	if (index < m_start_index)
		throw Exception("ERROR");
	else if (index >= m_start_index + m_length)
		throw Exception("Error");

	return m_array[index - m_start_index];
}

//SETTER/GETTERS
template <typename T>
void Array<T>::SetLength(int length)
{
	if (length < 0)
	{
		throw Exception("Error");
	}
	else if (length == 0)
	{
		delete[] m_array;
		m_array = nullptr;
		m_length = length;
	}
	else
	{
		//create new array pointer
		T * newArray = new T[length];
		//find smallest length
		int smallestLength = MIN(m_length, length);
		//copy contents over
		for (int i = 0; i < smallestLength; ++i)
		{
			newArray[i] = m_array[i];
		}
		delete[] m_array;
		m_array = newArray;
		m_length = length;
	}
}

template <typename T>
void Array<T>::SetStartIndex(int start_index)
{
	m_start_index = start_index;
}

template <typename T>
int Array<T>::GetLength() const
{
	return m_length; //
}

template <typename T>
int Array<T>::GetStartIndex() const
{
	return m_start_index;
}

#endif //ARRAY_H