/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:12:46 by pafranco          #+#    #+#             */
/*   Updated: 2025/07/28 21:25:12 by pafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main()
{
	std::ofstream MyFile("a.txt");
	MyFile << "Puta espanya";
	MyFile.close();
}
