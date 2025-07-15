/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tv <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:11:46 by tv                #+#    #+#             */
/*   Updated: 2025/07/15 18:37:26 by tv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account(int initial_deposit)
{
	this._totalAmount = initial_deposit;
}

~Account(void)
{
}

int	Account::getNbAccounts(void)
{
	return (this._nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (this._totalAmount);
}

int	getNbDeposits(void);

static int	getNbWithdrawals(void);
static void	displayAccountsInfos(void);
