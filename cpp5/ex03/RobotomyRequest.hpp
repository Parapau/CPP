/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequest.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:57:50 by pafranco          #+#    #+#             */
/*   Updated: 2025/12/17 17:23:36 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUEST_HPP
# define ROBOTOMYREQUEST_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <time.h>

class RobotomyRequest: public Form
{
	private:
		std::string		_target;
	public: 
		RobotomyRequest(void);
		RobotomyRequest(std::string target);
		RobotomyRequest	&operator=(RobotomyRequest &og);
		~RobotomyRequest(void);

		std::string		getTarget(void);

		void			setTarget(std::string target);

		void			carryOut(Bureaucrat &bar);
};

#endif
