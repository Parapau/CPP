/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:17:00 by pafranco          #+#    #+#             */
/*   Updated: 2026/02/17 14:33:11 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

class Date
{
	private:
		int		_year;
		int		_month;
		int		_day;
		float	_value;

	public:
		Date(void);
		Date(Date &og);
		Date(int y, int m, int d);
		Date(int y, int m, int d, float v);
		~Date(void);

		Date	&operator=(Date &og);
		bool	operator>(Date &other);
		bool	operator<(Date &other);
		bool	operator>=(Date &other);
		bool	operator<=(Date &other);
		bool	operator==(Date &other);
		bool	operator!=(Date &other);

		int		getYear(void) const;
		int		getMonth(void) const;
		int		getDay(void) const;
		float	getValue(void) const;

		static Date		parseDate(std::string d);

	class BadDate: public std::exception
	{
		public:
			const char* what() const throw();
	};
};

class BitcoinExchange
{
	private:
		std::set<Date>				_data;

		std::set<Date>				parseData(void);
		static std::set<Date>		parseData(std::string);
		static std::set<Date>		getData(void);
	public:
		BitcoinExchange(void);
		~BitcoinExchange(void);

		void	doYourThing(void);


	class BadDataFile: public std::exception
	{
		public:
			const char* what() const throw();
	};

	class BadInputFile: public std::exception
	{
		public:
			const char* what() const throw();
	};
};






#endif
