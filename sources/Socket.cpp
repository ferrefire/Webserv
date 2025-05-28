/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Socket.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 18:52:17 by ferre         #+#    #+#                 */
/*   Updated: 2025/05/28 21:08:04 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Socket.hpp"

#include <stdexcept>

#include <unistd.h>

Socket::Socket()
{

}

Socket::~Socket()
{
	closeSocket();
}

void Socket::createSocket(int domain, int type, int protocol)
{
	fd = socket(domain, type, protocol);

	if (fd < 0) throw (std::runtime_error("failed to create socket"));
}

void Socket::closeSocket()
{
	if (fd < 0) return;

	if (close(fd) < 0) throw (std::runtime_error("failed to close socket"));
	fd = -1;
}

void Socket::bindSocket(int domain, int port, in_addr_t ip)
{
	address.sin_family = domain;
	address.sin_port = htons(port);
	address.sin_addr.s_addr = ip;

	if (bind(fd, (sockaddr *)&address, sizeof(address)) < 0) throw (std::runtime_error("failed to bind socket"));
}

void Socket::startListening(int backlog)
{
	if (listen(fd, backlog) < 0) throw (std::runtime_error("socket failed to start listening"));
}

int Socket::getfd() const
{
	return (fd);
}