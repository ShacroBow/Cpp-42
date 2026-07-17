#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array {
	private:
		T            *_data;
		unsigned int  _size;

	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(Array const &other);
		
		Array &operator=(Array const &other);
		T       &operator[](unsigned int index);
		const T &operator[](unsigned int index) const;
		unsigned int size() const;
};

#include "Array.tpp"

#endif
