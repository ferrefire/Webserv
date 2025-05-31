/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Handler.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/31 17:44:53 by ferre         #+#    #+#                 */
/*   Updated: 2025/05/31 17:46:44 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Request.hpp"

class Handler
{
	private:
		
	public:
		Handler();
		~Handler();

		void handleRequest(Request request);
};