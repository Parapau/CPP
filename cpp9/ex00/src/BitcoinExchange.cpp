/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:17:21 by pafranco          #+#    #+#             */
/*   Updated: 2026/02/17 15:48:14 by pafranco         ###   ########.fr       */
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

Date::Date(int y, int m, int d):_year(y), _month(m), _day(d), _value(-1)
{
}

Date::Date(int y, int m, int d, float v):_year(y), _month(m), _day(d), _value(v)
{
}

//DESTRUCTORS

Date::~Date(void)
{
}

//METHODS

static Date		parseDate(std::string input)
{
	std::stringstream	s(input);
	std::string			nums[5];
	int					i;

	i = 0;
	getline(s, nums[0], '-');
	getline(s, nums[1], '-');
	getline(s, nums[2], ',');
	i = input.rfind(" - ", std::string::npos);
	if (i == std::string::npos)
		getline(s, nums[3]);
	else
	while (i <= 3)
		i += 1 + (nums[i].empty() * 10);
	getline(s, nums[4]);
	if (i > 6 || !nums[4].empty())
		throw(Date::BadDate());
	Date				date(std::atoi(nums[0].c_str()), std::atoi(nums[1].c_str())
			, std::atoi(nums[2].c_str()), std::atof(nums[3].c_str()));
	return (date);
}

//GETTERS

int		Date::getYear(void) const
{
	return (this->_year);
}

int		Date::getMonth(void) const
{
	return (this->_month);
}

int		Date::getDay(void) const
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

bool	Date::operator==(Date &o)
{
	return (getYear() == o.getYear() && getMonth() == o.getMonth()
			&& o.getDay() == getDay());
}

bool	Date::operator!=(Date &o)
{
	return (getYear() != o.getYear() || getMonth() != o.getMonth()
			|| o.getDay() != getDay());
}

bool	Date::operator>=(Date &o)
{
	return (*this == o || getYear() > o.getYear()
			|| (getYear() == o.getYear() && getMonth() > o.getMonth())
			|| (getYear() == o.getYear() && getMonth() == o.getMonth() && getDay() > o.getDay()));
}

bool	Date::operator<=(Date &o)
{
	return (*this == o || getYear() < o.getYear()
			|| (getYear() == o.getYear() && getMonth() < o.getMonth())
			|| (getYear() == o.getYear() && getMonth() == o.getMonth() && getDay() < o.getDay()));
}

bool	Date::operator>(Date &o)
{
	return (getYear() > o.getYear()
			|| (getYear() == o.getYear() && getMonth() > o.getMonth())
			|| (getYear() == o.getYear() && getMonth() == o.getMonth() && getDay() > o.getDay()));
}

bool	Date::operator<(Date &o)
{
	return (getYear() < o.getYear()
			|| (getYear() == o.getYear() && getMonth() < o.getMonth())
			|| (getYear() == o.getYear() && getMonth() == o.getMonth() && getDay() < o.getDay()));
}

/*********************************BITCOIN EXCHANGE*****************************/

//CONSTRUCTORS

BitcoinExchange::BitcoinExchange(void):_data(parseData())
{
}

//DESTRUCTORS

BitcoinExchange::~BitcoinExchange(void)
{
}

//METHODS

std::set<Date>		parseData(void)
{
	std::fstream		file;
	std::set<Date>		data;
	std::string			line;

	file.open("data.csv", std::ios::out);
	while (!file.eof())
	{
		std::getline(file, line);
		data.insert(Date::parseDate(line));
	}
	return (data);
}

std::set<Date>		parseData(std::string input)
{
}

void	doYourThing(std::string str)
{
	std::set<Date>				input;
	std::set<Date>::iterator	it;

	input = parseData(str);
}
