/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sending.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/30 17:39:21 by ferre         #+#    #+#                 */
/*   Updated: 2025/05/30 22:03:14 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Sending
{
	private:
		Sending();
		~Sending();

	public:
		static std::string fileToString(std::string path);
		static void sendError(int target);
		static void sendHeader(int target, size_t size);
		static void sendContent(int target, std::string content);
		static void sendPage(int target, std::string path);
};