/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:58:58 by jrim              #+#    #+#             */
/*   Updated: 2022/12/30 18:03:45 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <climits>
# include <cmath>
# include <float.h>
# include <ctype.h>

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define GRY "\033[90m"
# define DFT "\033[0;37m"

class Converter
{
	private:
        std::string _raw;
        double      _dval;
		bool		_flag;

	public:
		Converter(void);
		Converter(std::string raw);
		Converter(const Converter& ref);
		Converter& operator=(const Converter& ref);
		~Converter(void);

		std::string		getRawValue(void) const;
		int				getIntValue(void) const;
		double			getDoubleValue(void) const;
		float			getFloatValue(void) const;
		char			getCharValue(void) const;
		bool			getFlag(void) const;

		int		toIntValue(void);
		double	toDoubleValue(void);
		float	toFloatValue(void);
		char	toCharValue(void);
};

std::ostream& operator<<(std::ostream& out, Converter& c);
// static void 	printInt(std::ostream& out, Converter& c);
// static void 	printDouble(std::ostream& out, Converter& c);
// static void 	printFloat(std::ostream& out, Converter& c);
// static void 	printChar(std::ostream& out, Converter& c);

#endif