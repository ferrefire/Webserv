/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Reactor.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 20:10:52 by ferre         #+#    #+#                 */
/*   Updated: 2025/05/31 17:22:58 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Reactor.hpp"

#include "Sending.hpp"
#include "Server.hpp"
#include "Request.hpp"

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

void Reactor::createReactor(Server* server, int serverDescriptor)
{
	this->server = server;
	this->serverDescriptor = serverDescriptor;
	fd = epoll_create(1);

	if (fd < 0) throw (std::runtime_error("failed to create reactor"));

	addInterest(serverDescriptor, EPOLLIN);
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

void Reactor::addInterest(int interest, uint32_t mask)
{
	epoll_event event;
	event.data.fd = interest;
	event.events = mask;

	addInterest(event);
}

void Reactor::removeInterest(int interest)
{
	if (epoll_ctl(fd, EPOLL_CTL_DEL, interest, nullptr) < 0) throw (std::runtime_error("failed to remove interest"));
	//epoll_ctl(fd, EPOLL_CTL_DEL, interest, nullptr);
}

void Reactor::monitorInterests()
{
	while (true)
	{
		epoll_event events[5];

		int count = epoll_wait(fd, events, 5, -1);

		for (int i = 0; i < count; i++)
		{
			int event = events[i].data.fd;

			if (event == serverDescriptor)
			{
				//std::cout << "can read: " << ((events[i].events & EPOLLIN) == EPOLLIN) << std::endl;
				//std::cout << "can write: " << ((events[i].events & EPOLLOUT) == EPOLLOUT) << std::endl;

				Socket* newSocket = server->getNewSocket();
				newSocket->descriptor = accept(serverDescriptor, (sockaddr *)&newSocket->address, &newSocket->length);

				addInterest(newSocket->descriptor);
				std::cout << "added new client: " << newSocket->descriptor << std::endl;
			}
			else
			{
				//std::cout << "can read: " << ((events[i].events & EPOLLIN) == EPOLLIN) << std::endl;
				//std::cout << "can write: " << ((events[i].events & EPOLLOUT) == EPOLLOUT) << std::endl;

				char buffer[1024] = {0};
				int n = recv(event, buffer, sizeof(buffer), 0);
				if (n > 0)
				{
					std::cout << buffer << std::endl;

					Request req(*server->getSocket(event), buffer);
					std::cout << req << std::endl;

					Sending::sendPage(event, "html/test.html");
				}
			}
		}
	}
}