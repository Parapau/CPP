/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:17:21 by pafranco          #+#    #+#             */
/*   Updated: 2026/02/24 15:19:17 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../BitcoinExchange.hpp"


/*************************************DATE*************************************/

//CONSTRUCTORS

Date::Date(void):_year(0), _month(0), _day(0), _value(0)
{
}

Date::Date(std::string input):_year(0), _month(0), _day(0), _value(0), _badInput(input)
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

static bool		checkLine(std::string input, int mode)
{
	std::string::iterator		i;
	int							decimal;

	i = input.begin();
	decimal = mode;//if mode == 1 then you can have one decimal point
	if (input.empty())
		return (false);
	if (*i == '-')
		i++;
	while (i != input.end())
	{
		if (!std::isdigit(*i))
		{
			if (decimal == 0 || !std::isdigit(*(i + 1)))
				return (false);
			else
			{
				if (*i == '.')
					decimal = 0;
				else
					return (false);
			}
		}
		i++;
	}
	return (true);
}

Date		*parseDate(std::string input, int mode)
{
	std::stringstream	s(input);
	std::string			nums[5];
	int					i;

	i = 0;
	getline(s, nums[0], '-');
	getline(s, nums[1], '-');
	if (mode == 1)
	{
		getline(s, nums[2], ' ');
		getline(s, nums[3], ' ');
	}
	else
		getline(s, nums[2], ',');
	getline(s, nums[3]);
	while (i < 4)
	{
		if (!checkLine(nums[i], i == 3))
			return (new Date(input));
		i++;
	}
	return (new Date(std::atol(nums[0].c_str()), std::atol(nums[1].c_str())
			, std::atoi(nums[2].c_str()), std::atof(nums[3].c_str())));
}

void		Date::checkDate(void) const
{
	if (!_badInput.empty())
		throw (BadDate());
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

std::string		&Date::getBadInput(void)
{
	return (this->_badInput);
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
	if (og.getBadInput().empty())
		o << og.getYear() << '-' << og.getMonth() << '-' << og.getDay();// << '-' << og.getValue();
	else
		o << og.getBadInput();
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

void		deleteSet(std::set<Date *> date);

//CONSTRUCTORS

BitcoinExchange::BitcoinExchange(void)
{
}


//DESTRUCTORS

BitcoinExchange::~BitcoinExchange(void)
{
	deleteSet(getData());
}

//METHODS

void		deleteSet(std::set<Date *> data)
{
	for (std::set<Date *>::iterator i = data.begin() ; i != data.end() ; i++)
		delete (*i);
}

void		BitcoinExchange::parseData(void)
{
	std::fstream		file;
	std::set<Date *>		data;
	std::string			line;

	file.open("data.csv", std::ios::in);
	if (file.basic_ios::rdstate() == std::ios::failbit)
		throw (MissingDataFile());
	std::getline(file, line);//removefirst info line
	while (!file.eof())
	{
		std::getline(file, line);
		if (!line.empty())
			getData().insert(parseDate(line, 0));
	}
	file.close();
}

std::set<Date *>	*BitcoinExchange::parseData(std::string input)
{
	std::fstream		file;
	std::set<Date *>		*data = new std::set<Date *>;
	std::string			line;

	file.open(input.c_str(), std::ios::in);
	if (file.basic_ios::rdstate() == std::ios::failbit)
		throw (MissingInputFile());
	std::getline(file, line);//removefirst info line
	while (!file.eof())
	{
		std::getline(file, line);
		if (!line.empty())
			data->insert(parseDate(line, 1));
	}
	file.close();

	return(data);//TODO again, may be leaking polong longers
}

void	BitcoinExchange::doYourThing(std::string str)
{
	std::set<Date *>				*input;
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
	//print();
	//print(input);
	for (std::set<Date *>::iterator date = (*input).begin() ; date != (*input).end() ; date++)
	{
		try
		{
			(*date)->checkDate();
			value = (*date)->getValue() * (findDate(*date)->getValue());
			std::cout << **date << " => " << value << std::endl;
		}
		catch (Date::BadDate &e)
		{
			std::cout << e.what() << **date << std::endl;
		}
		catch (Date::NegativeValue &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (Date::BigNumber &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	deleteSet(*input);
	delete (input);
}

void	BitcoinExchange::print(void)
{
	for (std::set<Date *>::iterator i = getData().begin() ; i != getData().end() ; i++)
		std::cout << **i << std::endl;
}

void	BitcoinExchange::print(std::set<Date *> data)
{
	for (std::set<Date *>::iterator i = data.begin() ; i != data.end() ; i++)
		std::cout << **i << std::endl;
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

void	BitcoinExchange::setData(std::set<Date *> &data)
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
	return ("Bad formatting of input file");
}

const char		*BitcoinExchange::MissingDataFile::what() const throw()
{
	return ("Data file is missing");
}

const char		*BitcoinExchange::MissingInputFile::what() const throw()
{
	return ("Input file is missing");
}
