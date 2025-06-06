/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Socket.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 18:33:03 by ferre         #+#    #+#                 */
/*   Updated: 2025/05/30 22:33:18 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <sys/socket.h>
#include <netinet/in.h>

class Socket
{
	private:

	public:
		Socket();
		Socket(int descriptor, sockaddr_in address, socklen_t length);
		~Socket();

		int descriptor = -1;
		sockaddr_in address = {};
		socklen_t length = {};
		bool client = true;
};