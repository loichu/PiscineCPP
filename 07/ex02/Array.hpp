//
// Created by lhu on 15.11.23.
//

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <class T>
class Array
{
	public:
	Array() {
		a = new T[0];
		len = 0;
	}

	Array(unsigned int n) {
		a = new T[n];
		len = n;
	}

	Array( const Array& rhs ) {
		a = NULL;
		len = 0;
		*this = rhs;
	};

	~Array() {
		delete[] a;
	}

	Array& operator=( const Array& rhs ) {
		if ( this != &rhs ) {
			delete[] a;
			len = rhs.len;
			a = new T[len];
			for ( unsigned int i( 0 ); i < len; i++ )
				a[i] = rhs.a[i];
		}
		return *this;
	}


	T & operator [] (unsigned int n) const {
		if (n > len - 1)
			throw std::exception();
		return a[n];
	};

	unsigned int size () {
		return len;
	}

	private:
	T *             a;
	unsigned int    len;
};

#endif
