/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:17:21 by pafranco          #+#    #+#             */
/*   Updated: 2026/02/20 15:36:05 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../BitcoinExchange.hpp"


/*************************************DATE*************************************/

//CONSTRUCTORS

Date::Date(void):_year(0), _month(0), _day(0), _value(0)
{
}

Date::Date(Date &og):_year(og.getYear()), _month(og.getMonth()), _day(og.getDay()), _value(og.getValue())
{
}

Date::Date(long long y, long long m, long long d):_year(y), _month(m), _day(d), _value(-1)
{
}

Date::Date(long long y, long long m, long long d, double v):_year(y), _month(m), _day(d), _value(v)
{
}

//DESTRUCTORS

Date::~Date(void)
{
}

//METHODS

static Date		*parseDate(std::string input)
{
	std::stringstream	s(input);
	std::string			nums[5];

	//TODO check for errors in line and throw errors
	getline(s, nums[0], '-');
	getline(s, nums[1], '-');
	if (input.rfind(" - ", std::string::npos))
	{
		getline(s, nums[2], ' ');
		getline(s, nums[3], ' ');
	}
	else
		getline(s, nums[2], ',');
	getline(s, nums[3]);
	Date	*date = new Date(std::atol(nums[0].c_str()), std::atol(nums[1].c_str())
			, std::atoi(nums[2].c_str()), std::atof(nums[3].c_str()));
	return (date);
}

void		Date::checkDate(void) const
{
	if (getYear() < 0 || getMonth() < 0 || getDay() < 0 || getValue() < 0)
		throw (NegativeValue());
	if (getMonth() > 12)
		throw (BadDate());
	if (getMonth() == 2 && getDay() > 28 + (getYear() % 4 == 0))
		throw (BadDate());
	if (getDay() > 30 + ((getMonth() % 2 != 0) && (getMonth() < 8)) + ((getMonth() % 2 == 0) && (getMonth() >= 8)))
		throw (BadDate());
	if (getYear() > INT_MAX  || getMonth() > INT_MAX || getDay() > INT_MAX || getValue() > (double) INT_MAX)
		throw (BigNumber());
}

//GETTERS

long long		Date::getYear(void) const
{
	return (this->_year);
}

long long		Date::getMonth(void) const
{
	return (this->_month);
}

long long		Date::getDay(void) const
{
	return (this->_day);
}

float	Date::getValue(void) const
{
	return (this->_value);
}

//OVERLOADS

Date	&Date::operator=(Date &og)
{
	this->_year = og.getYear();
	this->_month = og.getMonth();
	this->_day = og.getDay();
	this->_value = og.getValue();
	return (*this);
}

bool	Date::operator==(Date &o) const
{
	return (getYear() == o.getYear() && getMonth() == o.getMonth()
			&& o.getDay() == getDay());
}

bool	Date::operator!=(Date &o) const
{
	return (getYear() != o.getYear() || getMonth() != o.getMonth()
			|| o.getDay() != getDay());
}

bool	Date::operator>=(Date &o) const
{
	return (*this == o || getYear() > o.getYear()
			|| (getYear() == o.getYear() && getMonth() > o.getMonth())
			|| (getYear() == o.getYear() && getMonth() == o.getMonth() && getDay() > o.getDay()));
}

bool	Date::operator<=(Date &o) const
{
	return (*this == o || getYear() < o.getYear()
			|| (getYear() == o.getYear() && getMonth() < o.getMonth())
			|| (getYear() == o.getYear() && getMonth() == o.getMonth() && getDay() < o.getDay()));
}

bool	Date::operator>(Date &o) const
{
	return (getYear() > o.getYear()
			|| (getYear() == o.getYear() && getMonth() > o.getMonth())
			|| (getYear() == o.getYear() && getMonth() == o.getMonth() && getDay() > o.getDay()));
}

bool	Date::operator<(Date &o) const
{
	return (getYear() < o.getYear()
			|| (getYear() == o.getYear() && getMonth() < o.getMonth())
			|| (getYear() == o.getYear() && getMonth() == o.getMonth() && getDay() < o.getDay()));
}

std::ostream&	operator<<(std::ostream &o, Date &og)
{
	o << og.getYear() << '-' << og.getMonth() << '-' << og.getDay();
	return (o);
}

//EXCEPTIONS

const char		*Date::BadDate::what() const throw()
{
	return ("This date makes no sense ");
}

const char		*Date::NegativeValue::what() const throw()
{
	return ("Negative Value ");
}

const char		*Date::BigNumber::what() const throw()
{
	return ("This number is to large ");
}

/*********************************BITCOIN EXCHANGE*****************************/

//CONSTRUCTORS

BitcoinExchange::BitcoinExchange(void)
{
}


//DESTRUCTORS

BitcoinExchange::~BitcoinExchange(void)
{
}

//METHODS

void		BitcoinExchange::parseData(void)
{
	std::fstream		file;
	std::set<Date *>		data;
	std::string			line;

	file.open("data.csv", std::ios::out);
	if (file.basic_ios::rdstate() == std::ios::failbit)
		throw (MissingDataFile());
	while (!file.eof())
	{
		std::getline(file, line);
		getData().insert(parseDate(line));
	}
	file.close();
	setData(data);
}

std::set<Date *>	&BitcoinExchange::parseData(std::string input)
{
	std::fstream		file;
	std::set<Date *>		*data = new std::set<Date *>;
	std::string			line;

	file.open(input.c_str(), std::ios::out);
	if (file.basic_ios::rdstate() == std::ios::failbit)
		throw (MissingInputFile());
	while (!file.eof())
	{
		std::getline(file, line);
		data->insert(Date::parseDate(line));
	}
	file.close();
	return(*data);//TODO again, may be leaking polong longers
}

void	BitcoinExchange::doYourThing(std::string str)
{
	std::set<Date *>				input;
	std::set<Date *>::iterator		it;
	double							value;

	value = 0;
	try
	{
		parseData();
		input = parseData(str);
	}
	catch (BitcoinExchange::BadFile &e)
	{
		std::cout << e.what() << std::endl;
		return ;
	}
	for (std::set<Date *>::iterator date = input.begin() ; date != input.end() ; date++)
	{
		try
		{
			(*date)->checkDate();
			value = (*date)->getValue() * findDate(*date)->getValue();
			std::cout << *date << " => " << value << std::endl;
		}
		catch (Date::BadDate &e)
		{
			std::cout << e.what() << *date;
		}
		catch (Date::NegativeValue &e)
		{
			std::cout << e.what();
		}
		catch (Date::BigNumber &e)
		{
			std::cout << e.what();
		}
	}
}

Date	*BitcoinExchange::findDate(Date *date)
{
	std::set<Date *>::iterator	it;

	it = getData().begin();
	while (**it < *date && it != getData().end())
		it++;
	it--;
	return (*it);
}

//GETTERS

std::set<Date *>	&BitcoinExchange::getData(void)
{
	return (this->_data);
}

//SETTERS

void	BitcoinExchange::setData(std::set<Date *> data)
{
	this->_data = data;
}

//EXCEPTIONS

const char		*BitcoinExchange::BadFile::what() const throw()
{
	return ("This file is absolute garbage");
}

const char		*BitcoinExchange::BadDataFile::what() const throw()
{
	return ("Bad formatting of data file");
}

const char		*BitcoinExchange::BadInputFile::what() const throw()
{
	return ("Bad formatting of inout file");
}

const char		*BitcoinExchange::MissingDataFile::what() const throw()
{
	return ("Data file is missing");
}

const char		*BitcoinExchange::MissingInputFile::what() const throw()
{
	return ("Input file is missing");
}
