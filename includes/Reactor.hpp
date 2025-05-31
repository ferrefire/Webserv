/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Reactor.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 20:08:26 by ferre         #+#    #+#                 */
/*   Updated: 2025/05/31 16:26:31 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>

#include <sys/epoll.h>
#include <netinet/in.h>

class Server;

class Reactor
{
	private:
		Server* server = nullptr;
		int fd = -1;
		int serverDescriptor = -1;

	public:
		Reactor();
		~Reactor();

		void createReactor(Server* server, int serverDescriptor);

		void closeReactor();

		void addInterest(epoll_event event);
		void addInterest(int interest, uint32_t mask = (EPOLLIN));
		void removeInterest(int interest);
		void monitorInterests();
};