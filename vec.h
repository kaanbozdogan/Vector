#include<iostream>
#include<memory>

using namespace std;
		

template <typename T>
class Vec
{
public:

	class iterator
	{
	public:
		iterator(shared_ptr<T[]> dataPtr, size_t i);

		iterator& operator++(); //pre

		iterator operator++(int); //post

		iterator& operator--(); //pre

		iterator operator--(int); //post

		T& operator*();

		T& operator[](int n);

		ptrdiff_t operator-(iterator other);

		iterator operator+(int n);
		
		iterator operator-(int n);
		
		iterator operator+=(int n);
		
		iterator operator-=(int n);

		bool operator==(iterator other) const;

		bool operator!=(iterator other) const;

		bool operator<(iterator other) const;

		bool operator>(iterator other) const;

		bool operator<=(iterator other) const;

		bool operator>=(iterator other) const;
		
		//friend ostream& operator<<(ostream& os, const Vec<T>::iterator& curr);

	private:
		shared_ptr<T[]> data;
		size_t i;
	}; 

	Vec();

	//~Vec()
	
	Vec(const Vec &other);

	Vec(Vec&& other) noexcept;

	Vec& operator=(const Vec &other);

	Vec& operator=(Vec&& other);

	inline size_t capacity() const { return cap; }

	inline size_t sizee() const { return size; }

	inline bool empty() const { return size == 0; }

	void print();

	void push_back(const T& value);

	void pop_back();

	void clear();

	void resize(size_t n, T val);

	void reserve(size_t new_cap);

	void shrink_to_fit();

	void swap(Vec<T> other);

	inline int& front() { return data[0]; }

	inline const int& front() const { return data[0]; }

	inline int& back() { return data[size - 1]; }

	inline const int& back() const { return data[size - 1]; }

	inline T& operator[](size_t idx) { cout << "non-const" << endl; return data[idx]; }

	inline const T& operator[](size_t idx) const { cout << "const" << endl; return data[idx]; }

	Vec& operator=(initializer_list<T> ilist);

	iterator begin();

	iterator end();

/*
	friend ostream& operator<<(ostream& os, const Vec& v)
	{
		for(int i = 0; i < size; i++)
		{
			os << data[i] << ", ";
		}
		os << endl << "size: " << size << " - cap: " << cap << endl;

		return os;
	}
*/

private:
	shared_ptr<T[]> data;
	size_t size;
	size_t cap;

	void recapacitate_data(int newCap); 

};