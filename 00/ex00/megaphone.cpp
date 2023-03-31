/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:18:04 by lhumbert          #+#    #+#             */
/*   Updated: 2023/03/31 15:55:57 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctype.h>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int w = 1; w < argc; ++w)
	{
		for (int c = 0; argv[w][c]; ++c)
		{
			std::cout << char(toupper(argv[w][c]));
		}
	}
	std::cout << std::endl;
	return (0);
}
