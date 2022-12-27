/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:59:03 by jrim              #+#    #+#             */
/*   Updated: 2022/12/27 17:36:16 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

//-------------- orthodox canonical form ----------------//
Converter::Converter(void) : _val(NULL), _flag(false)
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
std::string&    Converter::getRawValue(void) const
{

}

int Converter::getIntValue(void) const
{

}

double  Converter::getDoubleValue(void) const
{

}

float   Converter::getFloatValue(void) const
{

}

char    Converter::getCharValue(void) const
{

}

//------------------------ setter -----------------------//
void	Converter::setRawValue(std::string val)
{
    this->_val = val;
}

void	Converter::setIntValue(int val)
{
    this->_ival = val;
}

void	Converter::setDoubleValue(double val)
{
    this->_dval = val;
}

void	Converter::setFloatValue(float val)
{
    this->_fval = val;
}

void	Converter::setCharValue(char val)
{
    this->_cval = val;
}

//--------------------- converter -----------------------//
void	Converter::toIntValue(void)
{ 
	std::cout << "int: ";
	if (this->_flag || std::isnan(this->_val) || this->_val > INT_MAX)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(this->_val);
	std::cout << std::endl;
}

void	Converter::toDoubleValue(void)
{
	std::cout << "double: ";
	if (this->_flag || std::isnan(this->_val))
		std::cout << "nan";
	else
		std::cout << static_cast<double>(this->_val);
	std::cout << std::endl;
}

void	Converter::toFloatValue(void)
{
	std::cout << "float: ";
	if (this->_flag || std::isnan(this->_val) || this->_val > FLT_MAX)
		std::cout << "nanf";
	else
		std::cout << static_cast<float>(this->_val) << 'f';
	std::cout << std::endl;
}

void	Converter::toCharValue(void)
{
	std::cout << "char: ";
	if (this->_flag || std::isnan(this->_val))
		std::cout << "impossible";
	else if (isprint(this->_val) == false)
		std::cout << "Non displayable";
	else
		std::cout << static_cast<char>(this->_val);
	std::cout << std::endl;
}

//--------------------- insertion -----------------------//
std::ostream& operator<<(std::ostream& out, const Converter& c)
{
    out << "char: " << c.getCharValue() << std::endl;
	out << "int: " << c.getIntValue() << std::endl;
	out << "float: " << c.getFloatValue() << std::endl;
	out << "double: " << c.getDoubleValue() << std::endl;
	return (out);
}