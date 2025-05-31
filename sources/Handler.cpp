/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Handler.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/31 17:46:54 by ferre         #+#    #+#                 */
/*   Updated: 2025/05/31 18:00:22 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Handler.hpp"

#include "Sending.hpp"

#include <iostream>

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
			Sending::sendPage(request.getSocket().descriptor, request.getData(Request::Data::Page));
		}
		catch(const std::exception& e)
		{
			Sending::sendError(request.getSocket().descriptor);
		}
	}
}