/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sending.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/30 17:40:22 by ferre         #+#    #+#                 */
/*   Updated: 2025/06/02 14:20:55 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Sending.hpp"

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include <netinet/in.h>
#include <unistd.h>

Sending::Sending()
{

}

Sending::~Sending()
{
	
}

std::string Sending::fileToString(std::string path)
{
	std::string content;
	std::string line;
					
	std::ifstream file(path);

	if (!file.is_open()) throw (std::runtime_error("failed to open file"));

	while (std::getline(file, line)) content.append(line);

	file.close();

	return (content);
}

void Sending::sendError(int target)
{
	std::stringstream headerStream;
	headerStream << "HTTP/1.1 404 Not Found\r\n";
    headerStream << "Content-Length: 0\r\n";
    headerStream << "Connection: close\r\n";
    headerStream << "\r\n";
	std::string header = headerStream.str();

	send(target, header.c_str(), header.length(), 0);
}

void Sending::sendHeader(int target, size_t size, Sending::HeaderType type)
{
	std::stringstream headerStream;

	if (type == Sending::HeaderType::Error) headerStream << "HTTP/1.1 404 Not Found\r\n";
	else headerStream << "HTTP/1.1 200 OK\r\n";

	if (type == Sending::HeaderType::Css) headerStream << "Content-Type: text/css; charset=UTF-8\r\n";
	else if (type == Sending::HeaderType::Html) headerStream << "Content-Type: text/html; charset=UTF-8\r\n";
	else if (type == Sending::HeaderType::Js) headerStream << "Content-Type: application/javascript; charset=UTF-8\r\n";

    headerStream << "Content-Length: " << size << "\r\n";

	if (type == Sending::HeaderType::Error) headerStream << "Connection: close\r\n";
    else headerStream << "Connection: keep-alive\r\n";

    headerStream << "\r\n";
	std::string header = headerStream.str();

	send(target, header.c_str(), header.length(), 0);
}

void Sending::sendContent(int target, std::string content)
{
	send(target, content.c_str(), content.length(), 0);
}

void Sending::sendPage(int target, std::string path, Request request)
{
	Sending::HeaderType type = Sending::HeaderType::Error;
	//if (request.getData(Request::Data::Type) == "document") type = Sending::HeaderType::Html;
	//else if (request.getData(Request::Data::Type) == "style") type = Sending::HeaderType::Css;
	//else if (request.getData(Request::Data::Type) == "script") type = Sending::HeaderType::Js;
	if (request.getData(Request::Data::Type).contains("text/html")) type = Sending::HeaderType::Html;
	else if (request.getData(Request::Data::Type).contains("text/css")) type = Sending::HeaderType::Css;
	else if (request.getData(Request::Data::Type) == "*/*") type = Sending::HeaderType::Js;

	//std::cout << path << " - " << (int)type << std::endl;

	std::string content = Sending::fileToString(path);

	Sending::sendHeader(target, content.length(), type);
	Sending::sendContent(target, content);

	//close(target);
}