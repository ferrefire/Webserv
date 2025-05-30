/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 21:27:17 by ferre         #+#    #+#                 */
/*   Updated: 2025/05/30 21:16:06 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Manager.hpp"

#include <iostream>
#include <exception>

int main()
{
	try
	{
		Manager::start();
		Manager::createServers();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		perror("error");
	}

	std::cout << "end of program" << std::endl;

	Manager::closeApplication();

	return (0);
}