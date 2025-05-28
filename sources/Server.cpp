/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Server.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 19:39:58 by ferre         #+#    #+#                 */
/*   Updated: 2025/05/28 22:34:18 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

#include <iostream>
#include <exception>

#include <unistd.h>

Server::Server()
{

}

Server::~Server()
{
	closeServer();
}

void Server::createServer()
{
	try
	{
		createServerSocket();
		createServerReactor();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw (std::runtime_error("failed to create server"));
	}
}

void Server::createServerSocket()
{
	serverSocket.createSocket(AF_INET, SOCK_STREAM, 0);
	serverSocket.bindSocket(AF_INET, 8080, INADDR_ANY);
}

void Server::createServerReactor()
{
	serverReactor.createReactor(serverSocket.getfd());
}

void Server::closeServer()
{
	try
	{
		serverSocket.closeSocket();
		serverReactor.closeReactor();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw (std::runtime_error("failed to close server"));
	}
	
}

void Server::startServer()
{
	serverSocket.startListening(5);
	epoll_event event;
	event.events = EPOLLIN;
	event.data.fd = serverSocket.getfd();
	serverReactor.addInterest(event);
	serverReactor.monitorInterests();

	//int clientSocket = accept(serverSocket.getfd(), nullptr, nullptr);
	//char buffer[1024] = {0};
	//recv(clientSocket, buffer, sizeof(buffer), 0);
	//std::cout << "Message from client: " << buffer << std::endl;
	//close(clientSocket);
}