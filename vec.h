#include<iostream>
#include<memory>

template <typename T>
class Vec
{
private:
    std::shared_ptr<T[]> data;
    size_t size;
    size_t cap;

    void recapacitate_data();

public:

    class iterator
    {
    private:
        std::shared_ptr<T[]> data;
        size_t cap;
        size_t size;
        size_t i;

    public:
        iterator(std::shared_ptr<T[]> data, size_t cap, size_t size, size_t i);

        iterator& operator++(); //pre

        iterator operator++(int); //post

        iterator& operator--(); //pre

        iterator operator--(int); //post

        T& operator*();

        //friend std::ostream& operator<<(std::ostream& os, const Vec<T>::iterator& curr);
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

    inline int& operator[](size_t i) { return data[i]; }

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

    

};