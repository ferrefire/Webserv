/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 21:27:17 by ferre         #+#    #+#                 */
/*   Updated: 2025/05/28 21:55:09 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

#include <iostream>
#include <exception>

int main()
{
	try
	{
		Server server;
		server.createServer();
		server.startServer();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		perror("error");
	}

	std::cout << "end of program" << std::endl;

	return (0);
}