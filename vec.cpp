#include"vec.h"

using namespace std;


template <typename T>
void Vec<T>::recapacitate_data()
{
    //init temp data
    std::shared_ptr<T[]> temp(new T[cap]);

    for(int i = 0; i < size; i++) 
        temp[i] = data[i];

    //resize data
    T* dataPtr = data.get();
    delete[] dataPtr;
    dataPtr = new T[cap];

    //reinit data
    for(int i = 0; i < size; i++) 
        data[i] = temp[i];

    data = temp;
}

template <typename T>
Vec<T>::Vec()
{
    cap = 10;
    size = 0;

    data = std::shared_ptr<T[]>(new T[cap]);
}

template <typename T>
Vec<T>::Vec(const Vec &other) :
    size(other.size), cap(other.cap)
{
    data = std::shared_ptr<T[]>(new T[cap]);

    for(int i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }
}

template <typename T>
Vec<T>::Vec(Vec&& other) noexcept :
    size(std::move(other.size)), cap(std::move(other.cap)), data(std::move(other.data))
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

    data = std::shared_ptr<T[]>(new T[cap]);

    for(int i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }

    return *this;
}

template <typename T>
Vec<T>& Vec<T>::operator=(Vec&& other)
{
    size = std::move(other.size);
    cap = std::move(other.cap);

    data = std::move(other.data);

    return *this;
}

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
        cap += 5;
        recapacitate_data();
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
            cap -= 5;
            recapacitate_data();
        }
    }
}           

template <typename T>
void Vec<T>::clear()
{
    size = 0;
    cap = 10;
    data = std::make_shared<T[]>(cap);
}

template <typename T>
Vec<T>::iterator::iterator(std::shared_ptr<T[]> data, size_t cap, size_t size, size_t i) :
    data(data), cap(cap), size(size), i(i)
{}

template <typename T>
Vec<T>::iterator Vec<T>::begin()
{
    return iterator(data, cap, size, 0);
}

template <typename T>
Vec<T>::iterator Vec<T>::end()
{
    return iterator(data, cap, size, size);
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

/*
template <typename T>
std::ostream& operator<<(std::ostream& os, const Vec<T>::iterator& curr) 
{
    return os;
}
*/