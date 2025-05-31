/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Request.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/31 16:27:03 by ferre         #+#    #+#                 */
/*   Updated: 2025/05/31 17:33:36 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Socket.hpp"

#include <string>
#include <map>
#include <ostream>

class Request
{
	public:
		Request(Socket& socket, std::string content);
		~Request();

		enum class Data {Method, Page, Host, Port, Referer, Connection};
		std::pair<std::string, std::string> searchRanges[6] = 
			{{"", " "}, {" ", " "}, {"Host: ", ":"}, {":", "\n"}, {"Referer: ", "\n"}, {"Connection: ", "\n"}};

		std::string getData(Request::Data type);

	private:
		Socket& socket;
		std::string content;
		std::map<Request::Data, std::string> contentData;

		std::string extractData(Request::Data type);
};

std::ostream &operator<<(std::ostream &out, Request &request);