#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream file("data.csv");
	std::string line;

	std::getline(file, line); // skip first line
	while (std::getline(file, line))
	{
		size_t delim = line.find(',');

		std::string date = trim(line.substr(0, delim));
		std::string value = trim(line.substr(delim + 1, line.length()));

		_data[date] = value;
	}

	file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_data = other._data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::run(const std::string &filename)
{
	std::ifstream   file;
	std::string     line;

	file.open(filename.c_str());

	if (!file.is_open()) {
		std::cout << "Error: file does not exist" << std::endl;
		exit(EXIT_FAILURE);
	}

	if (file.peek() == std::ifstream::traits_type::eof()) {
		std::cout << "Error: file is empty" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::getline(file, line); // skip first line

	if (line != "date | value") {
		std::cout << "Error: invalid file format" << std::endl;
		exit(EXIT_FAILURE);
	}

	while (std::getline(file, line))
	{
		size_t delim = line.find('|');
		if (delim == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, delim));
		std::string value = trim(line.substr(delim + 1));

		try {
			if (!validDate(date))
				throw std::invalid_argument("invalid date: " + (date.empty() ? "\"\"" : "'" + date + "'"));

			if(value.empty())
				throw std::invalid_argument("invalid value: " + (value.empty() ? "\"\"" : "'" + value + "'"));

			validateNumber(value);

			std::map<std::string, std::string>::iterator it;
			std::string prevDate = date;
			it = _data.find(date);

			while (it == _data.end()) {
				const std::string& currentDate = prevDate;
				prevDate = previousDate(currentDate);
				it = _data.find(prevDate);
			}

			std::cout << date << " => " << value  << " = "
			          << stod(it->second) * stod(value) << std::endl;

		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

	}

	file.close();
}

bool BitcoinExchange::isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int BitcoinExchange::stoi(const std::string &str)
{
	std::stringstream ss(str);
	int value;

	ss >> value;

	return value;
}

double BitcoinExchange::stod(const std::string &str)
{
	std::stringstream ss(str);
	double value;

	ss >> value;

	return value;
}

std::string BitcoinExchange::toString(int value)
{
	std::stringstream ss;

	ss << value;

	return ss.str();
}

std::string BitcoinExchange::previousDate(const std::string& date) {
	int year = stoi(date.substr(0, 4));
	int month = stoi(date.substr(5, 2));
	int day = stoi(date.substr(8, 2));

	// Days in each month (for non-leap years)
	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (isLeapYear(year)) {
		daysInMonth[2] = 29; // February has 29 days in a leap year
	}

	// Decrement the day
	day--;

	// Check if day is 0 (previous month)
	if (day == 0) {
		month--;

		// Check if month is 0 (December)
		if (month == 0) {
			month = 12;
			year--;
		}

		day = daysInMonth[month];
	}

	// Format the previous date
	std::string newYear = toString(year);
	std::string newMonth = (month < 10) ? "0" + toString(month) : toString(month);
	std::string newDay = (day < 10) ? "0" + toString(day) : toString(day);

	return newYear + "-" + newMonth + "-" + newDay;
}

std::string BitcoinExchange::trim(const std::string& str) {
	size_t first = str.find_first_not_of(' ');
	if (std::string::npos == first)
		return str;

	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

bool BitcoinExchange::fileExists(const std::string &filename)
{
	std::fstream file;
	file.open(filename.c_str());
	bool exists = file.good();

	file.close();
	return exists;
}

bool BitcoinExchange::fileIsEmpty(const std::string &filename)
{
	std::ifstream file;
	file.open(filename.c_str());
	bool isEmpty = file.peek() == std::ifstream::traits_type::eof();

	file.close();
	return isEmpty;
}

void BitcoinExchange::validateNumber(const std::string &str) {
	double value;

	try {
		// If there's more than one decimal point, throw an error
		if (std::find(str.begin(), str.end(), '.') != str.end()) {
			size_t decimalPoint = str.find('.');
			if (std::find(str.begin() + decimalPoint + 1, str.end(), '.') != str.end())
				throw std::invalid_argument("too many decimal points");
		}

		// If there's a + or - sign check the next characters
		bool hasSign = str[0] == '+' || str[0] == '-';
		for (size_t i = hasSign ? 1 : 0; i < str.length(); i++) {
			if (::isdigit(str[i]) || str[i] == '.')
				continue;
			throw std::invalid_argument("not a number => " + str);
		}

		value = stod(str);

	} catch (std::exception &e) {
		throw std::invalid_argument("not a number => " + str);
	}

	if (value < 0)
		throw std::invalid_argument("not a positive number");

	if (value > 1000.0)
		throw std::invalid_argument("too large a number");
}


bool BitcoinExchange::allOf(const std::string& str, int (*isDigit)(int)) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!isDigit(str[i]))
			return false;
	}

	return true;
}

bool BitcoinExchange::validDate(const std::string &date)
{
	if (date.length() != 10)
		return false;

	if (date[4] != '-' || date[7] != '-')
		return false;

	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);


	if ((!allOf(year, &::isdigit)) ||
	    (!allOf(month, &::isdigit)) ||
	    (!allOf(day, &::isdigit)))
		return false;

	int yearInt, monthInt, dayInt;

	std::stringstream ssYear(year);
	std::stringstream ssMonth(month);
	std::stringstream ssDay(day);

	ssYear >> yearInt;
	ssMonth >> monthInt;
	ssDay >> dayInt;

	if ((yearInt < 2009 || yearInt > 2022) ||
	    (monthInt < 1 || monthInt > 12) ||
	    (dayInt < 1 || dayInt > 31))
		return false;

	// Check for specific months with 30 days
	if ((monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11) && dayInt > 30)
		return false;


	// Check for February
	if (monthInt == 2) {
		// Check for leap year
		bool isLeap = isLeapYear(yearInt);
		if (dayInt > (isLeap ? 29 : 28))
			return false;
	}

	return true;
}

std::string BitcoinExchange::nextDate(const std::string& date) {
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);

	int yearInt = stoi(year);
	int monthInt = stoi(month);
	int dayInt = stoi(day);

	// Days in each month (for non-leap years)
	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (isLeapYear(yearInt)) {
		daysInMonth[2] = 29; // February has 29 days in a leap year
	}

	// Increment the day
	dayInt++;

	// Check if day exceeds the maximum for the current month
	if (dayInt > daysInMonth[monthInt]) {
		dayInt = 1;
		monthInt++;

		// Check if month exceeds 12 (December)
		if (monthInt > 12) {
			monthInt = 1;
			yearInt++;
		}
	}

	// Format the next date
	std::string nextYear = toString(yearInt);
	std::string nextMonth = (monthInt < 10) ? "0" + toString(monthInt) : toString(monthInt);
	std::string nextDay = (dayInt < 10) ? "0" + toString(dayInt) : toString(dayInt);

	return nextYear + "-" + nextMonth + "-" + nextDay;
}