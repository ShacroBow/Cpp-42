#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP


# include <climits>
# include <cstdio>
# include <iomanip>
# include <iostream>
# include <limits>
# include <stdexcept>
# include <string>
# include <cmath>
# include <sstream>
# include <cstdlib>
# include <cerrno>
# include <exception>

class ScalarConverter
{
	private:
		// OCF (non instantiable)
		ScalarConverter();
		ScalarConverter(const ScalarConverter &cpy);
		ScalarConverter &operator=(const ScalarConverter &cpy);
		~ScalarConverter();
	
	public:
		class ImpossibleConversionException : public std::exception
		{
			public:
				const char *what() const throw() { return "impossible to convert"; }
		};
		
		class OverflowException : public std::exception
		{
			private:
				std::string _msg;
			public:
				OverflowException(const std::string &input)
					: _msg("Error: Overflow detected for: " + input) {}
				~OverflowException() throw() {}
				const char *what() const throw() { return _msg.c_str(); }
		};

		static void convert(std::string input);
};

#endif