/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:58:58 by jrim              #+#    #+#             */
/*   Updated: 2022/12/28 20:08:48 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
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
        std::string _val;
        int         _ival;
        double      _dval;
        float       _fval;
        char        _cval;
		bool		_flag;

	public:
		Converter(void);
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

		// void 	printInt(std::ostream& out, const Converter& c);
		// void 	printDouble(std::ostream& out, const Converter& c);
		// void 	printFloat(std::ostream& out, const Converter& c);
		// void 	printChar(std::ostream& out, const Converter& c);
};

std::ostream& operator<<(std::ostream& out, const Converter& c);

#endif