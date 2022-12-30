#include <iostream>

//-------------- orthodox canonical form ----------------//
template <typename T>
Array<T>::Array(void) : _len(0), _content(NULL)
{
	// std::cout << GRY << "(Array: default constructor)" << DFT << std::endl;
}

template <typename T>
Array<T>::Array(std::size_t len) : _len(len), _content(NULL)
{
	// std::cout << GRY << "(Array: constructor)" << DFT << std::endl;
    if (_len)
        _content = new T[_len];
}

template <typename T>
Array<T>::Array(const Array<T>& ref) : _len(ref._len), _content(NULL)
{
	// std::cout << GRY << "(Array: copy constructor)" << DFT << std::endl;
    if (_len)
        _content = new T[_len];
    for (std::size_t i = 0 ; i < _len ; ++i)
        _content[i] = a[i];
}

template <typename T>
Array<T>&  Array<T>::operator=(const Array<T>& ref)
{
	// std::cout << GRY << "(Array: copy assignment)" << DFT << std::endl;
    if (this != &ref) 
    {
        if (_len) 
        {
            delete[] _content;
            _content = NULL;
            _len = 0;
        }
        _len = ref.size();
        if (_len)
            _content = new T[_len];
        for (std::size_t i = 0 ; i < _len ; ++i)
            _content[i] = ref[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array(void)
{
	// std::cout << GRY << "(Array: destructor)" << DFT << std::endl;
    if (_len) 
    {
        delete[] _content;
        _content = NULL;
        _len = 0;
    }
}

//---------------------- exception ----------------------//
template <typename T>
const char *Array<T>::OutOfRangeException::what(void) const throw()
{
	return ("Error: Out of Range");
}

//------------------------ utils ------------------------//
template <typename T>
size_t  Array<T>::size(void) const 
{
    return (_len);
}

//----------------------- operator ----------------------//
template <typename T>
T&  Array<T>::operator[](std::size_t i) 
{
    if (i >= _len)
        throw OutofRange();
    return _content[i];
}

template <typename T>
const T&    Array<T>::operator[](std::size_t i) const 
{
    if (i >= _len)
        throw OutofRange();
    return _content[i ];
}