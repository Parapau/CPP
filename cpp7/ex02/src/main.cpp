/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:25:41 by pafranco          #+#    #+#             */
/*   Updated: 2026/01/27 14:35:54 by tv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Array.hpp"
#include <cstdlib>

int main(void)
{
    Array<std::string>      arr1(void);
    Array<std::string>      arr2(5);

    for (int i = 0 ; i < 5 ; i++)
        arr2[i] = "Gugridigugridigu";
    for (int i = 0 ; i < 5 ; i++)
        std:: cout << arr2[i] << i << std::endl;
    Array<std::string>      arr3(arr2);
    arr3[3] = "patata";
    std::cout << std::endl << std::endl;
    for (int i = 0 ; i < 5 ; i++)
        std:: cout << arr2[i] << i << std::endl;
    std::cout << std::endl << std::endl;
    for (int i = 0 ; i < 5 ; i++)
        std:: cout << arr3[i] << i << std::endl;
    try
    {
        std::cout << std::endl;
        arr2[420] = "patata";
    }
    catch (std::exception & e)
    {
        std::cout << "index out of bounds for array" << std::endl;
    }
}

//main provided by 42 i prefer mine :)

/*
#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " if you just throw a basic exception you should specify what happened int the catch >:( " << std::endl;
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception&e)
    {
        std::cerr << e.what() << " if you just throw a basic exception you should specify what happened int the catch >:( " << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}*/
