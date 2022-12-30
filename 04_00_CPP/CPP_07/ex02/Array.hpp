#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>
#include <iostream>

template <typename T>
class Array 
{
	private:
		std::size_t	_len;
		T			*_data;

	public:
	class OutofRange
		: public std::exception {
	public:
		const char* what(void) const throw() {
			return "Out of Range";
		}
	};

	size_t size(void) const {
		return _len;
	}

	T& operator[](std::size_t i) {
		if (i >= _len)
		throw OutofRange();
		return _data[i];
	}

	const T& operator[](std::size_t i) const {
		if (i >= _len)
		throw OutofRange();
		return _data[i];
	}

	Array& operator=(const Array& a) {
		if (this != &a) {
		if (_len) {
			delete[] _data;
			_data = NULL;
			_len = 0;
		}
		_len = a.size();
		if (_len)
			_data = new T[_len];
		for (std::size_t i = 0 ; i < _len ; ++i)
			_data[i] = a[i];
		}
		return *this;
	}

	Array(void)
		: _len(0), _data(NULL) {}

	explicit Array(std::size_t n)
		: _len(n), _data(NULL) {
		if (_len)
		_data = new T[_len];
	}

	Array(const Array& a)
		: _len(a.size()), _data(NULL) {
		if (_len)
		_data = new T[_len];
		for (std::size_t i = 0 ; i < _len ; ++i)
		_data[i] = a[i];
	}

	~Array(void) {
		if (_len) {
		delete[] _data;
		_data = NULL;
		_len = 0;
		}
	}
};

#endif