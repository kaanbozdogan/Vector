#include"vec.h"

using namespace std;


/*---HELPER---*/

template <typename T>
void Vec<T>::recapacitate_data(int newCap)
{		
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

template <typename T>
int Vec<T>::find_iterator_index(Vec<T>::iterator where)
{
	auto it = begin();
	auto e = end();
	int idx = 0;

	//find inseriton index
	while (it != e && it != where)
	{
		it++;
		idx++;
	}

	if (it != where)
	{
		idx = -1;
	}

	return idx;
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


/*---CONSTRUCTOR---*/

template <typename T>
Vec<T>::Vec(size_t size, T val)
{
	this->size = size;
	cap = size + 5;
	data = make_shared<int[]>(cap);

	for (size_t i = 0; i < size; i++)
	{
		data[i] = val;
	}
	
}




/*---OPERATOR---*/

template <typename T>
ostream& operator<<(ostream& os, const Vec<T>& v)
{
	for(int i = 0; i < v.sizee(); i++)
	{
		os << v.data[i] << ", ";
	}
	os << endl << "size: " << v.sizee() << " - cap: " << v.capacity() << endl;

	return os;
}


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
void Vec<T>::swap(Vec<T>& other)
{
	shared_ptr<T[]> temp_d;
	size_t temp_c, temp_s;

	temp_d = move(this->data);
	temp_c = move(this->cap);
	temp_s = move(this->size);

	this->data = move(other.data);
	this->cap = move(other.cap);
	this->size = move(other.size);

	other.data = move(temp_d);
	other.cap = move(temp_c);
	other.size = move(temp_s);
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
Vec<T>::iterator Vec<T>::insert(Vec<T>::iterator where, T val)
{	
	int idx = find_iterator_index(where);

	//insertion index found
	if (idx != -1)
	{
		//check if new capacity  is needed
		if (size == cap)
		{
			recapacitate_data(cap + 5);
		}
		size++;

		//shift data and insert
		for (int i = size - 1; i > idx; i--)
		{
			data[i] = data[i - 1];
		}
		data[idx] = val;
	}

	return iterator(data, idx);
}

template <typename T>
Vec<T>::iterator Vec<T>::insert(Vec<T>::iterator where, Vec<T>::iterator source_beg, Vec<T>::iterator source_end)
{
	int idx = find_iterator_index(where);

	//insertion index found
	if (idx != -1)
	{
		auto it = source_beg;
		size_t source_size = 0;

		//get size of the source
		while (it != source_end)
		{
			it++;
			source_size++;
		}

		//check if new capacity is needed
		if (size + source_size > cap)
		{
			recapacitate_data(cap + source_size + 5);
		}
		size += source_size;

		//shift data
		for (int i = size - 1; i >= idx + source_size; i--)
		{
			data[i] = data[i - source_size];
		}
		
		//insert source
		it = source_beg;
		for (size_t i = 0; i < source_size; i++)
		{
			data[i + idx] = *it;
			it++;
		}
	}

	return iterator(data, idx);
}

template <typename T>
Vec<T>::iterator Vec<T>::erase(iterator where)
{
	int idx = find_iterator_index(where);

	//insertion index found
	if (idx != -1)
	{
		size--;

		//shift data and insert
		for (size_t i = idx; i < size; i++)
		{
			data[i] = data[i + 1];
		}
	}

	return iterator(data, idx);
}

template <typename T>
Vec<T>::iterator Vec<T>::erase(iterator beg, iterator end)
{
	int idx = find_iterator_index(beg);

	//insertion index found
	if (idx != -1)
	{
		auto it = beg;
		size_t source_size = 0;

		//get size of the source
		while (it != end)
		{
			it++;
			source_size++;
		}

		size -= source_size;

		//shift data and insert
		for (size_t i = idx; i < size; i++)
		{
			data[i] = data[i + source_size];
		}
	}

	return iterator(data, idx);
}

template <typename T>
void Vec<T>::assign(size_t n, T val)
{
	size = n;
	recapacitate_data(size + 5);

	for (size_t i = 0; i < size; i++)
	{
		data[i] = val;
	}
	
}

template <typename T>
void Vec<T>::assign(initializer_list<int> ilist)
{
	size = ilist.size();
	recapacitate_data(size + 5);

	int i = 0;
	for(auto e : ilist)
	{
		data[i] = e;
		i++;
	}
}
	
template <typename T>
void Vec<T>::assign(const T* pbeg, const T* pend)
{
	clear();
	const T* beg = pbeg;
	
	while (beg != pend)
	{
		push_back(*beg);
		beg++;
	}
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






