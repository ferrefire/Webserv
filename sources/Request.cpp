/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Request.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/31 16:39:59 by ferre         #+#    #+#                 */
/*   Updated: 2025/05/31 17:38:21 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Request.hpp"

Request::Request(Socket& socket, std::string content) : socket(socket), content(content)
{

}

Request::~Request()
{

}

std::string Request::extractData(Request::Data type)
{
	size_t start = 0;
	size_t end = 0;
	size_t len = 0;

	if (type == Request::Data::Port) start = content.find("Host: ") + 6;
	std::string startSearch = searchRanges[(int)type].first;
	if (startSearch != "") start = content.find(searchRanges[(int)type].first, start);

	if (start == std::string::npos) return ("");

	start += searchRanges[(int)type].first.length();
	end = content.find(searchRanges[(int)type].second, start);

	if (end == std::string::npos) return ("");

	len = end - start;

	return (content.substr(start, len));
}

std::string Request::getData(Request::Data type)
{
	if (!contentData.contains(type)) contentData[type] = extractData(type);

	return (contentData[type]);
}

std::ostream &operator<<(std::ostream &out, Request &request)
{
	out << "Method: " << request.getData(Request::Data::Method) << std::endl;
	out << "Page: " << request.getData(Request::Data::Page) << std::endl;
	out << "Host: " << request.getData(Request::Data::Host) << std::endl;
	out << "Port: " << request.getData(Request::Data::Port) << std::endl;
	out << "Referer: " << request.getData(Request::Data::Referer) << std::endl;
	out << "Connection: " << request.getData(Request::Data::Connection) << std::endl;

	return (out);
}