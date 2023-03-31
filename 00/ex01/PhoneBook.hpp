#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		void add(Contact contact);
		void search();
	private:
		int		_index;
		int		_count;
		Contact _contacts[8];
};

#endif
