#include"vec.h"

using namespace std;

template <typename T>
Vec<T>::iterator Vec<T>::end()
{
	return iterator(data, size);
}

template <typename T>
Vec<T>::iterator& Vec<T>::iterator::operator++() 
{
	i++;
	return *this;
}

template <typename T>
Vec<T>::iterator Vec<T>::iterator::operator++(int) 
{
	Vec<T>::iterator temp = *this;
	i++;
	return temp;
}

template <typename T>
Vec<T>::iterator& Vec<T>::iterator::operator--() 
{
	i--;
	return *this;
}

template <typename T>
Vec<T>::iterator Vec<T>::iterator::operator--(int) 
{
	Vec<T>::iterator temp = *this;
	i--;
	return temp;
}

template <typename T>
T& Vec<T>::iterator::operator*()
{
	return data[i];
}

template <typename T>
T& Vec<T>::iterator::operator[](int n)
{
	return data[i + n];
}

template <typename T>
std::ptrdiff_t Vec<T>::iterator::operator-(iterator other)
{
	return this->i - other.i;
}

template <typename T>
Vec<T>::iterator Vec<T>::iterator::operator+(int n)
{
	return iterator(*data, i + n);
}

template <typename T>
Vec<T>::iterator Vec<T>::iterator::operator-(int n)
{
	return iterator(*data, i - n);
}

template <typename T>
Vec<T>::iterator Vec<T>::iterator::operator+=(int n)
{
	this->i += n;
	return *this;
}

template <typename T>
Vec<T>::iterator Vec<T>::iterator::operator-=(int n)
{
	this->i -= n;
	return *this;
}

template <typename T>
bool Vec<T>::iterator::operator==(iterator other) const
{   
	return
	this->data.get() == other.data.get() && 
	this->i == other.i;
}

template <typename T>
bool Vec<T>::iterator::operator!=(iterator other) const
{
	return !(*this == other);
}

template <typename T>
bool Vec<T>::iterator::operator<(iterator other) const
{
	return 
	this->data.get() == other.data.get() &&
	this->i < other.i;
}

template <typename T>
bool Vec<T>::iterator::operator>(iterator other) const
{
	return
	this->data.get() == other.data.get() &&
	this->i > other.i;
}

template <typename T>
bool Vec<T>::iterator::operator<=(iterator other) const
{
	return 
	(*this < other) ||
	(*this == other);
}

template <typename T>
bool Vec<T>::iterator::operator>=(iterator other) const
{
	return 
	(*this > other) ||
	(*this == other);
}


