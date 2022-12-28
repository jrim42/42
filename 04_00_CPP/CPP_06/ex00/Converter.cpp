/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:59:03 by jrim              #+#    #+#             */
/*   Updated: 2022/12/28 20:09:02 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

//-------------- orthodox canonical form ----------------//
Converter::Converter(void) : _val(NULL), _flag(true)
{
	// std::cout << GRY << "(Converter: default constructor)" << DFT << std::endl;
}

Converter::Converter(const Converter& ref)
{
	// std::cout << GRY << "(Converter: copy constructor)" << DFT << std::endl;
	*this = ref;
}

Converter& Converter::operator=(const Converter& ref)
{
	if (this == &ref)
		return (*this);
	this->_val = ref._val;
	this->_ival = ref._ival;
	this->_dval = ref._dval;
	this->_fval = ref._fval;
	this->_cval = ref._cval;
	this->_flag = ref._flag;
	return (*this);
}

Converter::~Converter(void)
{
	// std::cout << GRY << "(Converter: destructor)" << DFT << std::endl;
}

//------------------------ getter -----------------------//
std::string    Converter::getRawValue(void) const
{
	return (this->_val);
}

int Converter::getIntValue(void) const
{
	return (this->_ival);
}

double  Converter::getDoubleValue(void) const
{
	return (this->_dval);
}

float   Converter::getFloatValue(void) const
{
	return (this->_fval);
}

char    Converter::getCharValue(void) const
{
	return (this->_cval);
}

bool	Converter::getFlag(void) const
{
	return (this->_flag);
}

//--------------------- converter -----------------------//
int	Converter::toIntValue(void)
{ 
	return (static_cast<int>(this->_dval));
}

double	Converter::toDoubleValue(void)
{
	return (static_cast<double>(this->_dval));
}

float	Converter::toFloatValue(void)
{
	return (static_cast<float>(this->_dval));
}

char	Converter::toCharValue(void)
{
	return (static_cast<char>(this->_dval));
}

//--------------------- insertion -----------------------//
std::ostream& operator<<(std::ostream& out, const Converter& c)
{
    printChar(out, c);
    printInt(out, c);
    printFloat(out, c);
    printDouble(out, c);
	return (out);
}

static void 	printInt(std::ostream& out, const Converter& c)
{

}

static void 	printDouble(std::ostream& out, const Converter& c)
{

}

static void 	printFloat(std::ostream& out, const Converter& c)
{

}

static void 	printChar(std::ostream& out, const Converter& c)
{

}
