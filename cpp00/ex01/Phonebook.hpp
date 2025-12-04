
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook
{
private:
	Contact	_contacts[8];
	int		_idx;
public:
	Phonebook(void);
	~Phonebook(void);

	void	add(void);
	void	search(void);
	void	print(Contact contact);
	
	Contact	get_contact(int idx);
};

int	contact_list(Contact contacts[8]);


#endif
