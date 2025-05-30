/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Manager.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/30 20:38:02 by ferre         #+#    #+#                 */
/*   Updated: 2025/05/30 22:30:46 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Manager.hpp"

#include <iostream>
#include <csignal>

void interrupt(int sig)
{
	if (sig == SIGINT) Manager::closeApplication();
}

Manager::Manager()
{
	
}

Manager::~Manager()
{
	closeApplication();
}

void Manager::start()
{
	signal(SIGINT, interrupt);
}

void Manager::createServers()
{
	Server* server = getNewServer();
	server->createServer();
	server->startServer();
}

void Manager::closeApplication()
{
	Manager::closeServers();
	exit(EXIT_SUCCESS);
}

void Manager::closeServers()
{
	for (Server* server : activeServers)
	{
		server->closeServer();
		delete (server);
	}
	activeServers.clear();
}

Server* Manager::getNewServer()
{
	Server* newServer = new Server();
	activeServers.push_back(newServer);

	return (newServer);
}

std::vector<Server*> Manager::activeServers;