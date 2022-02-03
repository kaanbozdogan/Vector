#ifndef VEC_H
#define VEC_H

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

	private:
		shared_ptr<T[]> data;
		size_t i;
	};


	class const_iterator
	{
	public:
		const_iterator(shared_ptr<T[]> data, size_t i);

		const_iterator& operator++();

		const_iterator operator++(int);

		const_iterator& operator--();

		const_iterator operator--(int);

		const T& operator*();

		const T& operator[](int n);

		ptrdiff_t operator-(const_iterator other);

		const_iterator operator+(int n);
		
		const_iterator operator-(int n);
		
		const_iterator operator+=(int n);
		
		const_iterator operator-=(int n);

		bool operator==(const_iterator other) const;

		bool operator!=(const_iterator other) const;

		bool operator<(const_iterator other) const;

		bool operator>(const_iterator other) const;

		bool operator<=(const_iterator other) const;

		bool operator>=(const_iterator other) const;

	private:
		shared_ptr<const T[]> data;
		size_t i;
	};


	Vec();

	explicit Vec(size_t size, T val = 0);

	Vec(initializer_list<T> ilist);

	Vec(const T *pbegin, const T *pend);

	Vec(Vec<T>::const_iterator beg, Vec<T>::const_iterator end);

	//~Vec()
	
	Vec(const Vec &other);

	Vec(Vec&& other) noexcept;

	Vec& operator=(const Vec &other);

	Vec& operator=(Vec&& other);

	inline size_t capacity() const { return cap; }

	inline size_t sizee() const { return size; }

	inline bool empty() const { return size == 0; }

	inline T* dataa() { data.get(); }

	inline const T* dataa() const { data.get(); }

	void print();

	void push_back(const T& value);

	void pop_back();

	void clear();

	void resize(size_t n, T val = 0);

	void reserve(size_t new_cap);

	void shrink_to_fit();

	void swap(Vec<T>& other);

	inline T& front() { return data[0]; }

	inline const T& front() const { return data[0]; }

	inline T& back() { return data[size - 1]; }

	inline const T& back() const { return data[size - 1]; }

	inline T& operator[](size_t idx) { return data[idx]; }

	inline const T& operator[](size_t idx) const { return data[idx]; }

	Vec& operator=(initializer_list<T> ilist);

	iterator insert(iterator where, T val);

	iterator insert(iterator where, iterator source_beg, iterator source_end);

	iterator erase(iterator where);

	iterator erase(iterator beg, iterator end);

	void assign(size_t n, T val);

	void assign(initializer_list<T> ilist);

	void assign(const T* pbeg, const T* pend);

	inline iterator begin() { return iterator(data, 0); }

	inline iterator end() { return iterator(data, size); }

	inline const_iterator cbegin() const { return const_iterator(data, 0); };
	
	inline const_iterator cend() const { return const_iterator(data, size); };

	template <typename U>
	friend ostream& operator<<(ostream& os, const Vec<U>& v);


private:
	shared_ptr<T[]> data;
	size_t size;
	size_t cap;

	void recapacitate_data(int newCap); 

	int find_iterator_index(iterator where);
};


#endif