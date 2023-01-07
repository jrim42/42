/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:36:53 by jrim              #+#    #+#             */
/*   Updated: 2023/01/07 17:36:54 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <list>
# include <deque>
# include <vector>

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define GRY "\033[90m"
# define DFT "\033[0;37m"

template <typename T>
typename T::iterator	easyfind(T& container, int value)
{
	typename T::iterator iter;

	iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end()) 
		throw std::runtime_error("Error: Value Not Found");
	return (iter);
}

#endif