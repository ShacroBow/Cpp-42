#include "BitcoinExchange.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) : _db(other._db) {}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
	if (this != &other)
		_db = other._db;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::validDate(std::string const &date) const
{
	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	std::string y = date.substr(0, 4);
	std::string m = date.substr(5, 2);
	std::string d = date.substr(8, 2);

	for (size_t i = 0; i < y.size(); ++i)
		if (!std::isdigit(y[i])) return false;
	for (size_t i = 0; i < m.size(); ++i)
		if (!std::isdigit(m[i])) return false;
	for (size_t i = 0; i < d.size(); ++i)
		if (!std::isdigit(d[i])) return false;

	int yi = std::atoi(y.c_str());
	int mi = std::atoi(m.c_str());
	int di = std::atoi(d.c_str());

	if (mi < 1 || mi > 12 || di < 1 || di > 31)
		return false;
	if (yi < 2009)
		return false;

	int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (yi % 4 == 0 && (yi % 100 != 0 || yi % 400 == 0))
		days[1] = 29;
	if (di > days[mi - 1])
		return false;

	return true;
}

bool BitcoinExchange::validValue(std::string const &val, float &out) const
{
	if (val.empty())
		return false;

	std::stringstream ss(val);
	ss >> out;
	if (ss.fail() || !ss.eof())
		return false;
	if (out < 0)
		return false;
	if (out > 1000)
		return false;
	return true;
}

void BitcoinExchange::loadDatabase(std::string const &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("could not open database");

	std::string line;
	while (std::getline(file, line))
	{
		size_t comma = line.find(',');
		if (comma == std::string::npos)
			continue;

		std::string date = line.substr(0, comma);
		std::string rateStr = line.substr(comma + 1);

		if (date == "date")
			continue;
		if (!validDate(date))
			continue;

		std::stringstream ss(rateStr);
		float rate;
		ss >> rate;
		if (ss.fail())
			continue;

		_db[date] = rate;
	}
	file.close();
}

float BitcoinExchange::getRate(std::string const &date) const
{
	std::map<std::string, float>::const_iterator it = _db.lower_bound(date);

	if (it == _db.end() || it->first != date)
	{
		if (it == _db.begin())
			return -1;
		--it;
	}
	return it->second;
}

void BitcoinExchange::evaluate(std::string const &filename) const
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	while (std::getline(file, line))
	{
		size_t pipe = line.find('|');
		if (pipe == std::string::npos)
		{
			if (!line.empty())
				std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, pipe);
		std::string valStr = line.substr(pipe + 1);

		if (date.find("date") != std::string::npos)
			continue;

		size_t end = date.find_last_not_of(' ');
		size_t start = date.find_first_not_of(' ');
		if (end != std::string::npos && start != std::string::npos)
			date = date.substr(start, end - start + 1);
		else
			date = "";

		end = valStr.find_last_not_of(' ');
		start = valStr.find_first_not_of(' ');
		if (end != std::string::npos && start != std::string::npos)
			valStr = valStr.substr(start, end - start + 1);
		else
			valStr = "";

		if (!validDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		float val;
		if (!validValue(valStr, val))
		{
			std::stringstream test(valStr);
			float tmp;
			test >> tmp;
			if (test.fail() || !test.eof())
				std::cerr << "Error: bad input => " << line << std::endl;
			else if (tmp < 0)
				std::cerr << "Error: not a positive number." << std::endl;
			else
				std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		float rate = getRate(date);
		if (rate < 0)
		{
			std::cerr << "Error: no exchange rate for date => " << date << std::endl;
			continue;
		}

		std::cout << date << " => " << valStr << " = " << val * rate << std::endl;
	}
	file.close();
}
