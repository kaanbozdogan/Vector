#include"vec.h"

using namespace std;


/*---HELPER---*/

template <typename T>
void Vec<T>::recapacitate_data(int newCap){
		
	if (cap != newCap) {	
		cap = newCap;

		//init temp data
		shared_ptr<T[]> temp(new T[cap]);

		for(int i = 0; i < size; i++)
		{
			temp[i] = data[i];
		}

		data = move(temp);
	}
}


/*---SPECIAL MEMBER---*/

template <typename T>
Vec<T>::Vec()
{
	cap = 10;
	size = 0;

	data = shared_ptr<T[]>(new T[cap]);
}

template <typename T>
Vec<T>::Vec(const Vec &other) :
	size(other.size), cap(other.cap)
{
	data = shared_ptr<T[]>(new T[cap]);

	for(int i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

template <typename T>
Vec<T>::Vec(Vec&& other) noexcept :
	size(move(other.size)), cap(move(other.cap)), data(move(other.data))
{}

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec &other)
{
	//check for self asssignment
	if (&other == this)
		return *this;

	//copy data
	size = other.size;
	cap = other.cap;

	data = shared_ptr<T[]>(new T[cap]);

	for(int i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}

	return *this;
}

template <typename T>
Vec<T>& Vec<T>::operator=(Vec&& other)
{
	size = move(other.size);
	cap = move(other.cap);

	data = move(other.data);

	return *this;
}


/*---OPERATOR---*/

/*
template <typename T>
ostream& operator<<(ostream& os, const Vec<T>::iterator& curr) 
{
	return os;
}
*/


/*---MEMBER---*/

template <typename T>
void Vec<T>::print() {
	for(int i = 0; i < size; i++)
	{
		cout << data[i] << ", ";
	}
	cout << endl << "size: " << size << " - cap: " << cap << endl;
}

template <typename T>
void Vec<T>::push_back(const T& value)
{
	if (size >= cap)
	{
		recapacitate_data(cap + 5);
	}

	data[size] = value;
	size++;
}

template <typename T>
void Vec<T>::pop_back()
{
	if (size > 0)
	{
		size--;

		if (size + 10 < cap)
		{
			recapacitate_data(cap - 5);
		}
	}
}           

template <typename T>
void Vec<T>::clear()
{
	size = 0;
	cap = 10;
	data = make_shared<T[]>(cap);
}

template <typename T>
void Vec<T>::resize(size_t n, T val)
{
	size = n;
	recapacitate_data(size + 5);
	data = make_shared<T[]>(cap);

	for (size_t i = 0; i < size; i++)
	{
		data[i] = val;
	}
	 
}

template <typename T>
void Vec<T>::reserve(size_t new_cap)
{
	recapacitate_data(new_cap);

	if (size < cap)
	{
		size = cap;
	}
}

template <typename T>
void Vec<T>::shrink_to_fit()
{
	recapacitate_data(size);
}

template <typename T>
Vec<T>& Vec<T>::operator=(initializer_list<T> ilist)
{
	resize(ilist.size(), (new int(1)));

	T* curr = ilist.begin();
	T* end = ilist.end();
	
	int i = 0;
	while (curr != end)
	{
		data[i] = *curr;
		i++;
		curr++;
	}

	return *this;
}


/*---ITERATOR---*/

template <typename T>
Vec<T>::iterator::iterator(shared_ptr<T[]> data, size_t i) :
	data(data), i(i)
{}

template <typename T>
Vec<T>::iterator Vec<T>::begin()
{
	return iterator(data, 0);
}

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






