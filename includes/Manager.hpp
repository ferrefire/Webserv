/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Manager.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/30 20:36:04 by ferre         #+#    #+#                 */
/*   Updated: 2025/05/30 21:12:04 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Server.hpp"

#include <vector>

class Manager
{
	private:
		static std::vector<Server*> activeServers;

	public:
		Manager();
		~Manager();

		static void start();

		static void createServers();

		static void closeApplication();
		static void closeServers();	

		static Server* getNewServer();
};