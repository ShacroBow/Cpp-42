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
		std::string	_note;
	public:
		Contact(void);
		~Contact(void);
		/*******Getters and Setters*******/
		std::string	get_first(void) const;
		std::string	get_last(void)	const;
		std::string	get_nick(void) const;
		std::string	get_phone_num(void) const;
		std::string	get_note(void) const;
		bool		exists(void) const;
		void		set_first(std::string str);
		void		set_last(std::string str);
		void		set_nick(std::string str);
		void		set_phoneNum(std::string str);
		void		set_note(std::string str);

};

#endif
