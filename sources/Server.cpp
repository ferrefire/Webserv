/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Server.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 19:39:58 by ferre         #+#    #+#                 */
/*   Updated: 2025/05/31 17:22:09 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

#include "Sending.hpp"

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
	serverSocket = getNewSocket();
	serverSocket->client = false;
	serverSocket->descriptor = socket(AF_INET, SOCK_STREAM, 0);

	if (serverSocket->descriptor < 0) throw (std::runtime_error("failed to create socket"));

	int opt = 1;
	if (setsockopt(serverSocket->descriptor, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
		throw (std::runtime_error("failed to set socket option"));

	serverSocket->address.sin_family = AF_INET;
	serverSocket->address.sin_port = htons(8080);
	serverSocket->address.sin_addr.s_addr = INADDR_ANY;
	serverSocket->length = sizeof(serverSocket->address);

	if (bind(serverSocket->descriptor, (sockaddr *)&serverSocket->address, serverSocket->length) < 0) throw (std::runtime_error("failed to bind socket"));
}

void Server::createServerReactor()
{
	serverReactor.createReactor(this, serverSocket->descriptor);
}

void Server::closeServer()
{
	std::cout << "closing server" << std::endl;

	closeSockets();
	serverReactor.closeReactor();

	//try
	//{
	//	closeSockets();
	//	serverReactor.closeReactor();
	//}
	//catch(const std::exception& e)
	//{
	//	std::cerr << e.what() << '\n';
	//	throw (std::runtime_error("failed to close server"));
	//}
}

void Server::closeSockets()
{
	for (Socket* socket : activeSockets)
	{
		if (socket->descriptor >= 0)
		{
			//if (socket->client) Sending::sendError(socket->descriptor);
			//serverReactor.removeInterest(socket->descriptor);
			close(socket->descriptor);
		}
		delete (socket);
	}
	activeSockets.clear();
}

void Server::startServer()
{
	if (listen(serverSocket->descriptor, 5) < 0) throw (std::runtime_error("socket failed to start listening"));
	serverReactor.monitorInterests();
}

Socket* Server::getNewSocket()
{
	Socket* newSocket = new Socket();
	activeSockets.push_back(newSocket);

	return (newSocket);
}

Socket* Server::getSocket(int descriptor)
{
	for (Socket* socket : activeSockets)
	{
		if (socket->descriptor == descriptor) return (socket);
	}

	return (nullptr);
}