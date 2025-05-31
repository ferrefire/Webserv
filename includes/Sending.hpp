/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sending.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/30 17:39:21 by ferre         #+#    #+#                 */
/*   Updated: 2025/05/31 19:39:15 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Request.hpp"

#include <string>

class Sending
{
	private:
		Sending();
		~Sending();

	public:
		enum class HeaderType {Html, Css, Js, Error};

		static std::string fileToString(std::string path);
		static void sendError(int target);
		static void sendHeader(int target, size_t size, Sending::HeaderType type);
		static void sendContent(int target, std::string content);
		static void sendPage(int target, std::string path, Request request);
};