/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Handler.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/31 17:46:54 by ferre         #+#    #+#                 */
/*   Updated: 2025/05/31 20:44:51 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Handler.hpp"

#include "Sending.hpp"

#include <iostream>
#include <string>

Handler::Handler()
{

}

Handler::~Handler()
{

}

void Handler::handleRequest(Request request)
{
	if (request.getData(Request::Data::Method) == "GET")
	{
		try
		{
			std::string path = request.getData(Request::Data::Page);
			path.replace(0, 1, "");
			//if (path == "") path = "html/home.html";
	
			//if (request.getData(Request::Data::Type) == "text/html")
			//{
			//	path.replace(0, 1, "html/");
			//	path.append(".html");
			//}
			//else if (request.getData(Request::Data::Type) == "text/css")
			//{
			//	path.replace(0, 1, "css/");
			//}
			Sending::sendPage(request.getSocket().descriptor, path, request);
		}
		catch(const std::exception& e)
		{
			std::cout << "eeeeeeeeeeeeerror" << std::endl;
			Sending::sendError(request.getSocket().descriptor);
		}
	}
}