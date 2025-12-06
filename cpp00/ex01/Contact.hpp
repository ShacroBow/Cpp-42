#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class	Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
	public:
		Contact(void);
		~Contact(void);
		/*******Getters and Setters*******/
		std::string	m_getFirst(void) const;
		std::string	m_getLast(void)	const;
		std::string	m_getNick(void) const;
		std::string	m_getPhoneNum(void) const;
		std::string	m_getSecret(void) const;
		void		m_setFirst(std::string str);
		void		m_setLast(std::string str);
		void		m_setNick(std::string str);
		void		m_setPhoneNum(std::string str);
		void		m_setSecret(std::string str);
		bool		m_exists(void) const;

};

#endif
