
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class Phonebook
{
private:
	Contact	_contacts[8];
	int		_idx;
public:
	Phonebook(void);
	~Phonebook(void);
	void	m_add(void);
	void	m_search(void);
	void	m_print(Contact contact);
	
	Contact	m_getContact(int idx);
};

int	ft_contactList(Contact contacts[8]);


#endif
