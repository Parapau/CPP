/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequest.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:57:50 by pafranco          #+#    #+#             */
/*   Updated: 2025/11/24 19:46:12 by tv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUEST_HPP
# define ROBOTOMYREQUEST_HPP

#include "AForm.hpp"

class RobotomyRequest: public Form
{
	private:
		std::string		_target;
	public: 
		RobotomyRequest(void);
		RobotomyRequest(std::string target);
		~RobotomyRequest(void);

		std::string		getTarget(void);

		void			setTarget(std::string target);

		void			execute(Bureaucrat &bar);
};

#endif
