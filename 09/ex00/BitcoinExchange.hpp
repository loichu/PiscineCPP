//
// Created by lhu on 07.02.24.
//

#ifndef EX00_BITCOINEXCHANGE_HPP
#define EX00_BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>

class BitcoinExchange
{
	private:
	std::map<std::string, std::string>    _data;

	std::string  previousDate(const std::string& date);
	std::string  nextDate(const std::string& date);
	std::string  trim(const std::string& str);

	void    validateNumber(const std::string &str);
	bool    fileExists(const std::string &filename);
	bool    fileIsEmpty(const std::string &filename);
	bool    validDate(const std::string &date);
	bool    isLeapYear(int year);
	bool    allOf(const std::string &str, int (*isDigit)(int));

	int         stoi(const std::string &str);
	double      stod(const std::string &str);
	std::string toString(int value);

	public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void run(const std::string &filename);
};

#endif //EX00_BITCOINEXCHANGE_HPP
