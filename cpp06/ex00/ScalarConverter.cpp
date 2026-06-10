#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() 
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
	(void)cpy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &cpy)
{
	(void)cpy;
	return *this;
}

ScalarConverter::~ScalarConverter() 
{
}


static int isChar(std::string input)
{
	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0])
		&& input[0] != '+' && input[0] != '-' && input[0] != '.')
		return 1;
	return 0;
}

static int islegal(std::string input)
{
	size_t i = 0;
	
	if (input[i] == '-' || input[i] == '+')
		i++;
	if (i >= input.length())
		return 0;
	
	size_t start = i;
	while (i < input.length() && std::isdigit(input[i]))
		i++;
	if (i == start)
		return 0;
	
	if (i < input.length() && input[i] == '.')
	{
		i++;
		start = i;
		while (i < input.length() && std::isdigit(input[i]))
			i++;
		if (i == start)
			return 0;
	}
	
	if (i < input.length() && input[i] == 'f' && i == input.length() - 1)
		i++;
	
	return (i == input.length()) ? 1 : 0;
}

static void printImpossible();

static void printit(std::string input)
{
	double tmp = 0;
	char *end = NULL;

	if (!islegal(input))
		throw ScalarConverter::ImpossibleConversionException();

	errno = 0;
	tmp = std::strtold(input.c_str(), &end);
	
	if (*end == 'f')
		end++;
	if (*end != '\0' || errno == ERANGE) //|| std::isinf(tmp))
		throw ScalarConverter::OverflowException(input);
	
	if (std::isnan(tmp) || std::isinf(tmp))
		std::cout << "char: impossible\n";
	else if (tmp >= 0 && tmp <= 127)
	{
		char c = static_cast<char>(tmp);
		if (std::isprint(c))
			std::cout << "char: '" << c << "'\n";
		else
			std::cout << "char: Non displayable\n";
	}
	else
		std::cout << "char: impossible\n";
	
	// --- int ---
	if (std::isnan(tmp) || std::isinf(tmp))
		std::cout << "int: impossible\n";
	else if (tmp < static_cast<double>(INT_MIN) || tmp > static_cast<double>(INT_MAX))
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(tmp) << "\n";
	
	// --- float ---
	if (std::isnan(tmp))
		std::cout << "float: nanf\n";
	else if (std::isinf(tmp))
		std::cout << "float: " << (tmp > 0 ? "+inff" : "-inff") << "\n";
	else
	{
		float f = static_cast<float>(tmp);
		if (std::isinf(f) && !std::isinf(tmp))
			std::cout << "float: impossible\n";
		else
			std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n"; //remove setprecision during eval.
	}
	
	// --- double ---
	if (std::isnan(tmp))
		std::cout << "double: nan\n";
	else if (std::isinf(tmp))
		std::cout << "double: " << (tmp > 0 ? "+inf" : "-inf") << "\n";
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(tmp) << "\n";

}

static void printImpossible()
{
	std::cout	<< "char: impossible\n" 
				<< "int: impossible\n" 
				<< "float: impossible\n" 
				<< "double: impossible\n" ;
	return ;
}

static void printSpecial(std::string input)
{
	std::cout << "char: impossible\n" ;
	std::cout << "int: impossible\n" ;
	if (input == "nan" || input == "nanf")
	{
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
	}
	else if (input == "+inf" || input == "+inff")
	{
		std::cout << "float: +inff\n";
		std::cout << "double: +inf\n";
	}
	else
	{
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
	}
}

static void printChar(char c)
{
	std::cout	<< "char: '" << c << "'\n"
				<< "int: " << static_cast<int>(c) << "\n"
				<< "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f\n"
				<< "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << "\n";
	return ;
}


void ScalarConverter::convert(std::string input)
{
	try
	{
		if (input.empty())
			throw ScalarConverter::ImpossibleConversionException();

		if (input == "nan" || input == "nanf" || input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff")
		{
			printSpecial(input);
			return ;
		}
		
		if (isChar(input))
		{
			printChar(input[0]);
			return ;
		}
		
		if (islegal(input))
		{
			printit(input);
			return ;
		}

		throw ScalarConverter::ImpossibleConversionException();
	}
	catch (const ScalarConverter::ImpossibleConversionException &e)
	{
		std::cerr << "fail " << e.what() << "\n";
		printImpossible();
	}
	catch (const ScalarConverter::OverflowException &e)
	{
		std::cerr << "fail " << e.what() << "\n";
		printImpossible();
	}
}
