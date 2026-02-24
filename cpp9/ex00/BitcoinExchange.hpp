/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:17:00 by pafranco          #+#    #+#             */
/*   Updated: 2026/02/24 12:25:28 by pafranco         ###   ########.fr       */
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
#include <cstdlib>
#include <limits.h>

class Date
{
	private:
		long long		_year;
		long long		_month;
		long long		_day;
		double			_value;
		std::string		_badInput;

	public:
		Date(void);
		Date(Date &og);
		Date(std::string input);
		Date(long long y, long long m, long long d);
		Date(long long y, long long m, long long d, double v);
		~Date(void);

		Date			&operator=(Date &og);
		bool			operator>(Date &other) const;
		bool			operator<(Date &other) const;
		bool			operator>=(Date &other) const;;
		bool			operator<=(Date &other) const;;
		bool			operator==(Date &other) const;;
		bool			operator!=(Date &other) const;;
		bool			operator>(const Date &other) const;
		bool			operator<(const Date &other) const;
		bool			operator>=(const Date &other) const;;
		bool			operator<=(const Date &other) const;;
		bool			operator==(const Date &other) const;;
		bool			operator!=(const Date &other) const;;

		long long		getYear(void) const;
		long long		getMonth(void) const;
		long long		getDay(void) const;
		float			getValue(void) const;
		std::string		&getBadInput(void);

		void			checkDate(void) const;
		static Date		*parseDate(std::string d, int mode);

	class BadDate: public std::exception
	{
		public:
			const char* what() const throw();
	};

	class NegativeValue: public std::exception
	{
		public:
			const char* what() const throw();
	};

	class BigNumber: public std::exception
	{
		public:
			const char* what() const throw();
	};
};

std::ostream&	operator<<(std::ostream &o, Date &og);

class BitcoinExchange
{
	private:
		std::set<Date *>			_data;

		void						parseData(void);
		std::set<Date *>			&parseData(std::string input);
		std::set<Date *>			&getData(void);
		void						setData(std::set<Date *> &data);
		Date						*findDate(Date *date);
		Date						*findDate(std::set<Date *>::iterator date);
	public:
		BitcoinExchange(void);
		~BitcoinExchange(void);

		void	doYourThing(std::string input);
		void	print(void);
		void	print(std::set<Date *>);


	class BadFile: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class BadDataFile: public BadFile
	{
		public:
			const char* what() const throw();
	};

	class BadInputFile: public BadFile
	{
		public:
			const char* what() const throw();
	};

	class MissingInputFile: public BadFile
	{
		public:
			const char* what() const throw();
	};

	class MissingDataFile: public BadFile
	{
		public:
			const char* what() const throw();
	};
};

#endif
