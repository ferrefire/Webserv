/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Server.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 18:28:31 by ferre         #+#    #+#                 */
/*   Updated: 2025/05/30 21:56:41 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Socket.hpp"
#include "Reactor.hpp"

#include <vector>

#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>

class Reactor;

class Server
{
	private:
		Socket* serverSocket;
		Reactor serverReactor;
		std::vector<Socket*> activeSockets;

	public:
		Server();
		~Server();

		void createServer();
		void createServerSocket();
		void createServerReactor();

		void closeServer();
		void closeSockets();

		void startServer();
		Socket* getNewSocket();
};