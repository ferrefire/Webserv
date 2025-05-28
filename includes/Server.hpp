/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Server.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 18:28:31 by ferre         #+#    #+#                 */
/*   Updated: 2025/05/28 21:17:29 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Socket.hpp"
#include "Reactor.hpp"

#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>

class Server
{
	private:
		Socket serverSocket;
		Reactor serverReactor;

	public:
		Server();
		~Server();

		void createServer();
		void createServerSocket();
		void createServerReactor();

		void closeServer();

		void startServer();
};