/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Socket.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 18:33:03 by ferre         #+#    #+#                 */
/*   Updated: 2025/05/28 21:07:54 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <sys/socket.h>
#include <netinet/in.h>

class Socket
{
	private:
		int fd = -1;
		sockaddr_in address;

	public:
		Socket();
		~Socket();

		void createSocket(int domain, int type, int protocol);

		void closeSocket();

		void bindSocket(int domain, int port, in_addr_t ip);
		void startListening(int backlog);
		int getfd() const;
};