/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Reactor.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 20:08:26 by ferre         #+#    #+#                 */
/*   Updated: 2025/05/28 22:32:21 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>

#include <sys/epoll.h>
#include <netinet/in.h>

class Reactor
{
	private:
		int fd = -1;
		int server = -1;
		//std::vector<epoll_event> events;

	public:
		Reactor();
		~Reactor();

		void createReactor(int server);

		void closeReactor();

		void addInterest(epoll_event event);
		void monitorInterests();
};