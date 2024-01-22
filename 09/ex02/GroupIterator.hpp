//
// Created by lhu on 25.12.23.
//

#ifndef EX02_GROUPITERATOR_HPP
# define EX02_GROUPITERATOR_HPP

# include <iostream>

void test_group_iterator();

template<typename Iterator>
class GroupIterator {
private:

	Iterator _it;
	std::size_t _size;

public:

	// TYPES
	typedef typename std::iterator_traits<Iterator>::reference reference;
	typedef typename std::iterator_traits<Iterator>::pointer pointer;
	typedef typename std::iterator_traits<Iterator>::difference_type difference_type;
	typedef typename std::iterator_traits<Iterator>::iterator_category iterator_category;
	typedef typename std::iterator_traits<Iterator>::value_type value_type;
	typedef Iterator iterator_type;

	// CONSTRUCTORS
	GroupIterator() {};
	GroupIterator(Iterator it, std::size_t size) : _it(it), _size(size) {};
	GroupIterator(GroupIterator it, std::size_t size) : _it(it.base()), _size(size * it._size()) {};

	GroupIterator & operator = (GroupIterator const & git)
	{
		_size = git._size;
		_it = git._it;
		return *this;
	};

	// GETTERS
	Iterator base() const { return _it; };
	std::size_t size() const { return _size; };

	// ACCESS OPERATORS
	reference operator * () const { return _it[_size - 1]; };
	pointer operator -> () const { return &(operator*()); };

	// INCREMENTATION OPERATORS
	GroupIterator & operator ++ () { _it += _size; return *this; };
	GroupIterator & operator += (std::size_t i) { _it += _size * i; return *this; };
	GroupIterator operator ++ (int) {
		GroupIterator tmp = *this;
		operator++();
		return tmp;
	};

	// DECREMENTATION OPERATORS
	GroupIterator & operator -- () { _it -= _size; return *this; };
	GroupIterator & operator -= (std::size_t i) { _it -= _size * i; return *this; };
	GroupIterator operator -- (int) {
		GroupIterator tmp = *this;
		operator--();
		return tmp;
	};

	// ELEMENTS OPERATORS
	int operator [] (std::size_t p) { return  _it[p * _size + _size - 1]; };
	int operator [] (std::size_t p) const { return  _it[p * _size + _size - 1]; };
};

// RELATIONAL OPERATORS
template<typename Iterator>
bool operator < (const GroupIterator<Iterator> & lhs,
				 const GroupIterator<Iterator> & rhs)
{
	return lhs.base() < rhs.base();
}

template<typename Iterator>
bool operator <= (const GroupIterator<Iterator> & lhs,
                 const GroupIterator<Iterator> & rhs)
{
	return lhs.base() <= rhs.base();
}

template<typename Iterator>
bool operator > (const GroupIterator<Iterator> & lhs,
                 const GroupIterator<Iterator> & rhs)
{
	return lhs.base() > rhs.base();
}

template<typename Iterator>
bool operator >= (const GroupIterator<Iterator> & lhs,
                 const GroupIterator<Iterator> & rhs)
{
	return lhs.base() >= rhs.base();
}

template<typename Iterator>
bool operator == (const GroupIterator<Iterator> & lhs,
                  const GroupIterator<Iterator> & rhs)
{
	return lhs.base() == rhs.base();
}

template<typename Iterator>
bool operator != (const GroupIterator<Iterator> & lhs,
                  const GroupIterator<Iterator> & rhs)
{
	return lhs.base() != rhs.base();
}

// ARITHMETIC OPERATORS
template<typename Iterator>
typename GroupIterator<Iterator>::difference_type operator - (
		const GroupIterator<Iterator> & lhs,
        const GroupIterator<Iterator> & rhs)
{
	return (lhs.base() - rhs.base()) / lhs.size();
}

template<typename Iterator>
GroupIterator<Iterator> operator + (GroupIterator<Iterator> it,
				                    std::size_t size)
{
	return it += size;
}

template<typename Iterator>
GroupIterator<Iterator> operator + (std::size_t size,
				                    GroupIterator<Iterator> it)
{
	return it += size;
}

template<typename Iterator>
GroupIterator<Iterator> make_group_iterator(Iterator it, std::size_t size)
{
	return  GroupIterator<Iterator>(it, size);
}

template<typename Iterator>
GroupIterator<Iterator> make_group_iterator(GroupIterator<Iterator> it, std::size_t size)
{
	return  GroupIterator<Iterator>(it.base(), size * it.size());
}

template<typename Iterator>
void test_recursive(Iterator start, Iterator end)
{
	Iterator it = start;
	while (it < end)
		std::cout << *it++ << " " << std::flush;
	std::cout << std::endl;
	std::size_t distance = std::distance(start, end);
	std::cout << "distance: " << distance << std::endl;
	if (distance < 2)
		return;
	test_recursive(make_group_iterator(start, 2),
	               make_group_iterator(end, 2));
}

#endif //EX02_GROUPITERATOR_HPP
