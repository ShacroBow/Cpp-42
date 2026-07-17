#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _db;

		float getRate(std::string const &date) const;
		bool validDate(std::string const &date) const;
		bool validValue(std::string const &value, float &out) const;
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &other);
		BitcoinExchange &operator=(BitcoinExchange const &other);
		~BitcoinExchange();

		void loadDatabase(std::string const &filename);
		void evaluate(std::string const &filename) const;
};

#endif
