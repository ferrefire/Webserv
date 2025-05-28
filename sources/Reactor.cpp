/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Reactor.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 20:10:52 by ferre         #+#    #+#                 */
/*   Updated: 2025/05/28 22:34:05 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Reactor.hpp"

#include <stdexcept>
#include <iostream>

#include <unistd.h>

Reactor::Reactor()
{

}

Reactor::~Reactor()
{
	closeReactor();
}

void Reactor::createReactor(int server)
{
	this->server = server;
	fd = epoll_create(1);

	if (fd < 0) throw (std::runtime_error("failed to create reactor"));
}

void Reactor::closeReactor()
{
	if (fd < 0) return;

	if (close(fd) < 0) throw (std::runtime_error("failed to close reactor"));
	fd = -1;
}

void Reactor::addInterest(epoll_event event)
{
	if (epoll_ctl(fd, EPOLL_CTL_ADD, event.data.fd, &event) < 0) throw (std::runtime_error("failed to add interest"));
}

void Reactor::monitorInterests()
{
	//while (true)
	{
		epoll_event events[5];

		int count = epoll_wait(fd, events, 5, -1);

		for (int i = 0; i < count; i++)
		{
			int event = events[i].data.fd;

			if (event == server)
			{
				int clientSocket = accept(server, nullptr, nullptr);
				char buffer[1024] = {0};
				recv(clientSocket, buffer, sizeof(buffer), 0);
				std::cout << "Message from client: " << buffer << std::endl;
				close(clientSocket);
			}
		}
	}
}