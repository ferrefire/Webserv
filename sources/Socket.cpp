/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Socket.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 18:52:17 by ferre         #+#    #+#                 */
/*   Updated: 2025/05/30 19:57:55 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Socket.hpp"

#include <stdexcept>

#include <unistd.h>

Socket::Socket()
{

}

Socket::Socket(int descriptor, sockaddr_in address, socklen_t length) : descriptor(descriptor), address(address), length(length)
{

}

Socket::~Socket()
{
	
}