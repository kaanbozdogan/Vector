#ifndef VEC_H
#define VEC_H

#include<iostream>
#include<memory>
		

template <typename T>
class Vec
{
public:

	template <typename U, typename TIterator>
	class abstract_iterator
	{
	public:
		friend class Vec<T>;
		friend TIterator;

		U& operator*()
		{
			return dataPtr[i];
		}

		inline U& operator[](int n)
		{
			return dataPtr[i + n];
		}

		ptrdiff_t operator-(TIterator other)
		{
			return this->i - other.i;
		}

		TIterator operator+(int n)
		{
			return return_iterator(dataPtr, i + n);
		}
		
		TIterator operator-(int n)
		{
			return return_iterator(dataPtr, i - n);
		}
		
		TIterator operator+=(int n)
		{
			i += n;
			return *this;
		}
		
		TIterator operator-=(int n)
		{
			i -= n;
			return *this;
		}

		bool operator==(TIterator other) const
		{   
			return
				this->dataPtr == other.dataPtr && 
				this->i == other.i;
		}

		bool operator!=(TIterator other) const
		{
			return !(*this == other);
		}

		bool operator<(TIterator other) const
		{
			return 
				this->dataPtr == other.dataPtr &&
				this->i < other.i;
		}

		bool operator>(TIterator other) const
		{
			return
				this->dataPtr == other.dataPtr &&
				this->i > other.i;
		}

		bool operator<=(TIterator other) const
		{
			return 
				(*this < other) ||
				(*this == other);
		}

		bool operator>=(TIterator other) const
		{
			return 
				(*this > other) ||
				(*this == other);
		}

	private:
		U* dataPtr;
		std::size_t i;

		static TIterator return_iterator(U* data, int i)
		{
			TIterator iter;
			iter.dataPtr = data;
			iter.i = i;
			return iter;
		}
	};

	class iterator : public abstract_iterator<T, iterator>
	{
	public:
		friend abstract_iterator<T, iterator>;

		iterator& operator++()
		{
			this->i++;
			return *this;
		}

		iterator operator++(int)
		{
			auto temp = *this;
			this->i++;
			return temp;
		}

		iterator& operator--()
		{
			this->i--;
			return *this;
		}

		iterator operator--(int)
		{
			auto temp = *this;
			this->i--;
			return temp;
		}

	private:
		iterator()
		{}

		iterator(abstract_iterator<T, iterator> other)
		{
			this->dataPtr = other.dataPtr;
			this->i = other.i;
		}
	};

	class const_iterator : public abstract_iterator<const T, const_iterator>
	{
	public:
		friend abstract_iterator<const T, const_iterator>;

		const_iterator& operator++()
		{
			this->i++;
			return *this;
		}

		const_iterator operator++(int)
		{
			auto temp = *this;
			this->i++;
			return temp;
		}

		const_iterator& operator--()
		{
			this->i--;
			return *this;
		}

		const_iterator operator--(int)
		{
			auto temp = *this;
			this->i--;
			return temp;
		}

	private:
		const_iterator()
		{}

		const_iterator(abstract_iterator<T, const_iterator> other)
		{
			this->dataPtr = other.dataPtr;
			this->i = other.i;
		}
	};

	Vec();

	explicit Vec(std::size_t size, T val = 0);

	Vec(std::initializer_list<T> ilist);

	Vec(const T *pbegin, const T *pend);

	Vec(Vec<T>::const_iterator beg, Vec<T>::const_iterator end);

	//~Vec()
	
	Vec(const Vec &other);

	Vec(Vec&& other) noexcept;

	Vec& operator=(const Vec &other);

	Vec& operator=(Vec&& other);

	inline std::size_t capacity() const 
	{ 
		return cap; 
	}

	inline std::size_t sizee() const 
	{ 
		return size; 
	}

	inline bool empty() const 
	{ 
		return size == 0;
	}

	inline T* data() 
	{ 
		m_data.get(); 
	}

	inline const T* data() const
	{ 
		m_data.get(); 
	}

	void print();

	void push_back(const T& value);

	void pop_back();

	void clear();

	void resize(std::size_t n, T val = 0);

	void reserve(std::size_t new_cap);

	inline void shrink_to_fit()
	{
		recapacitate_data(size);
	}

	void swap(Vec<T>& other);

	inline T& front()
	{
		return m_data[0]; 
	}

	inline const T& front() const 
	{
		return m_data[0]; 
	}

	inline T& back() 
	{ 
		return m_data[size - 1]; 
	}

	inline const T& back() const 
	{ 
		return m_data[size - 1]; 
	}

	inline T& operator[](std::size_t idx) 
	{ 
		return m_data[idx]; 
	}

	inline const T& operator[](std::size_t idx) const
	{
		return m_data[idx];
	}

	Vec& operator=(std::initializer_list<T> ilist);

	iterator insert(iterator where, T val);

	iterator insert(iterator where, iterator source_beg, iterator source_end);

	iterator erase(iterator where);

	iterator erase(iterator beg, iterator end);

	void assign(std::size_t n, T val);

	void assign(std::initializer_list<T> ilist);

	void assign(const T* pbeg, const T* pend);

	inline iterator begin() 
	{ 
		return iterator::return_iterator(m_data.get(),0);
	}

	inline iterator end() 
	{ 
		return iterator::return_iterator(m_data.get(),size);
	}

	inline const_iterator cbegin() const 
	{ 
		return const_iterator::return_iterator(m_data.get(),0);
	};
	
	inline const_iterator cend() const 
	{ 
		return const_iterator::return_iterator(m_data.get(),size);
	};

	template <typename U>
	friend std::ostream& operator<<(std::ostream& os, const Vec<U>& v);


private:
	std::unique_ptr<T[]> m_data;
	std::size_t size;
	std::size_t cap;

	void recapacitate_data(int newCap); 

	int find_iterator_index(iterator where);
};





/*---HELPER---*/

template <typename T>
void Vec<T>::recapacitate_data(int newCap)
{		
	if (cap != newCap) {	
		cap = newCap;

		if (size > cap)
		{
			size = cap;
		}

		//init temp data
		std::unique_ptr<T[]> temp(new T[cap]);

		for(int i = 0; i < size; i++)
		{
			temp[i] = m_data[i];
		}	

		m_data = std::move(temp);
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

	m_data = std::unique_ptr<T[]>(new T[cap]);
}

template <typename T>
Vec<T>::Vec(const Vec &other) :
	size(other.size), cap(other.cap)
{
	m_data = std::unique_ptr<T[]>(new T[cap]);

	for(int i = 0; i < size; i++)
	{
		m_data[i] = other.m_data[i];
	}
}

template <typename T>
Vec<T>::Vec(Vec&& other) noexcept :
	size(std::move(other.size)), cap(std::move(other.cap)), m_data(std::move(other.m_data))
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

	m_data = std::unique_ptr<T[]>(new T[cap]);

	for(int i = 0; i < size; i++)
	{
		m_data[i] = other.m_data[i];
	}

	return *this;
}

template <typename T>
Vec<T>& Vec<T>::operator=(Vec&& other)
{
	size = std::move(other.size);
	cap = std::move(other.cap);

	m_data = std::move(other.m_data);

	return *this;
}


/*---CONSTRUCTOR---*/

template <typename T>
Vec<T>::Vec(std::size_t size, T val)
{
	this->size = size;
	cap = size + 5;
	m_data = std::unique_ptr<T[]>(new T[cap]);

	for (std::size_t i = 0; i < size; i++)
	{
		m_data[i] = val;
	}
	
}

template <typename T>
Vec<T>::Vec(std::initializer_list<T> ilist) 
{
	size = ilist.size();
	cap = size + 5;
	m_data = std::unique_ptr<T[]>(new T[cap]);

	int i = 0;
	for(auto e : ilist)
	{
		m_data[i] = e;
		i++;
	}
}

template <typename T>
Vec<T>::Vec(const T *pbegin, const T *pend)
{
	size = 0;
	cap = 10;
	m_data = std::unique_ptr<T[]>(new T[cap]);

	while (pbegin != pend)
	{
		push_back(*pbegin);
		pbegin++;
	}
}

template <typename T>
Vec<T>::Vec(Vec<T>::const_iterator beg, Vec<T>::const_iterator end)
{
	size = 0;
	cap = 10;
	m_data = std::unique_ptr<T[]>(new T[cap]);

	while (beg != end && beg.i < 6)
	{
		push_back(*beg);
		beg++;
	}
}


/*---OPERATOR---*/

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vec<T>& v)
{
	os << "[";

	for(int i = 0; i < v.sizee(); i++)
	{
		os << v.m_data[i] << " ";
	}
	os << "]";

	os << std::endl << "size: " << v.sizee() << " - cap: " << v.capacity() << std::endl;

	return os;
}


/*---MEMBER---*/


template <typename T>
void Vec<T>::push_back(const T& value)
{
	if (size >= cap)
	{
		recapacitate_data(cap + 5);
	}

	m_data[size] = value;
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
	m_data = std::unique_ptr<T[]>(new T[cap]);
}

template <typename T>
void Vec<T>::resize(std::size_t n, T val)
{
	if (size != n)
	{
		recapacitate_data(n + 5);
		std::size_t old_size = size;
		size = n;

		// new size is bigger new elements are added
		if (old_size < n)
		{
			for (std::size_t i = old_size; i < size; i++)
			{
				m_data[i] = val;
			}
			
		}		
	}	 
}

template <typename T>
void Vec<T>::reserve(std::size_t new_cap)
{
	if (new_cap > cap && new_cap > size) {
		recapacitate_data(new_cap);
	}
}

template <typename T>
void Vec<T>::swap(Vec<T>& other)
{
	std::unique_ptr<T[]> temp_d;
	std::size_t temp_c, temp_s;

	temp_d = std::move(this->m_data);
	temp_c = std::move(this->cap);
	temp_s = std::move(this->size);

	this->m_data = std::move(other.m_data);
	this->cap = std::move(other.cap);
	this->size = std::move(other.size);

	other.m_data = std::move(temp_d);
	other.cap = std::move(temp_c);
	other.size = std::move(temp_s);
}

template <typename T>
Vec<T>& Vec<T>::operator=(std::initializer_list<T> ilist)
{
	resize(ilist.size(), 0);

	auto curr = ilist.begin();
	auto end = ilist.end();
	
	int i = 0;
	while (curr != end)
	{
		m_data[i] = *curr;
		i++;
		curr++;
	}

	return *this;
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
			m_data[i] = m_data[i - 1];
		}
		m_data[idx] = val;
	}

	return Vec<T>::iterator::return_iterator(this->m_data.get(), idx);
}

template <typename T>
Vec<T>::iterator Vec<T>::insert(Vec<T>::iterator where, Vec<T>::iterator source_beg, Vec<T>::iterator source_end)
{
	int idx = find_iterator_index(where);

	//insertion index found
	if (idx != -1)
	{
		auto it = source_beg;
		std::size_t source_size = 0;

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
			m_data[i] = m_data[i - source_size];
		}
		
		//insert source
		it = source_beg;
		for (std::size_t i = 0; i < source_size; i++)
		{
			m_data[i + idx] = *it;
			it++;
		}
	}

	return Vec<T>::iterator::return_iterator(this->m_data.get(), idx);
}

template <typename T>
Vec<T>::iterator Vec<T>::erase(iterator where)
{
	int idx = find_iterator_index(where);

	//index found
	if (idx != -1)
	{
		size--;

		//shift data to erase
		for (std::size_t i = idx; i < size; i++)
		{
			m_data[i] = m_data[i + 1];
		}
	}

	return Vec<T>::iterator::return_iterator(this->m_data.get(), idx);
}

template <typename T>
Vec<T>::iterator Vec<T>::erase(iterator beg, iterator end)
{
	int idx = find_iterator_index(beg);

	//index found
	if (idx != -1)
	{
		auto it = beg;
		std::size_t source_size = 0;

		//get size of the source
		while (it != end)
		{
			it++;
			source_size++;
		}

		size -= source_size;

		//shift data to erase
		for (std::size_t i = idx; i < size; i++)
		{
			m_data[i] = m_data[i + source_size];
		}
	}

	return Vec<T>::iterator::return_iterator(this->m_data.get(), idx);
}

template <typename T>
void Vec<T>::assign(std::size_t n, T val)
{
	size = n;
	recapacitate_data(size + 5);

	for (std::size_t i = 0; i < size; i++)
	{
		m_data[i] = val;
	}
	
}

template <typename T>
void Vec<T>::assign(std::initializer_list<T> ilist)
{
	size = ilist.size();
	recapacitate_data(size + 5);

	int i = 0;
	for(auto e : ilist)
	{
		m_data[i] = e;
		i++;
	}
}
	
template <typename T>
void Vec<T>::assign(const T* pbeg, const T* pend)
{
	clear();
	
	while (pbeg != pend)
	{
		push_back(*pbeg);
		pbeg++;
	}
}

#endif