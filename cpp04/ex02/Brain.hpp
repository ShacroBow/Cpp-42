#pragma once

#include <iostream>

class Brain {
	
	private:

	public:
		std::string	ideas[100];

		Brain();
		Brain(const Brain& brain);
		~Brain();

		Brain&	operator=(const Brain& brain);
};