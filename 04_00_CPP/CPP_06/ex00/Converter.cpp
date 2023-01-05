/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:04:04 by jrim              #+#    #+#             */
/*   Updated: 2023/01/03 19:04:05 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

//-------------- orthodox canonical form ----------------//
Converter::Converter(void) : _raw(NULL), _dval(0.0), _flag(true)
{
	// std::cout << GRY << "(Converter: default constructor)" << DFT << std::endl;
}

Converter::Converter(std::string raw) : _raw(raw), _dval(0.0), _flag(true)
{
	// std::cout << GRY << "(Converter: constructor)" << DFT << std::endl;
	try 
	{
		const char	*nptr = _raw.c_str();
		char 		*endptr = NULL;

		_dval = std::strtod(nptr, &endptr);
		if (*endptr && std::strcmp(endptr, "f"))
			throw std::bad_alloc();
		else if (_dval == 0.0 && (_raw[0] != '+' && _raw[0] != '-' && !std::isdigit(_raw[0])))
			throw std::bad_alloc();
  	} 
  	catch (std::exception&) 
	{
    	_flag = false;
  	}
}

Converter::Converter(const Converter& ref) : _raw(ref._raw), _dval(ref._dval), _flag(ref._flag)
{
	// std::cout << GRY << "(Converter: copy constructor)" << DFT << std::endl;
}

Converter& Converter::operator=(const Converter& ref)
{
	// std::cout << GRY << "(Converter: copy assignment)" << DFT << std::endl;
	if (this == &ref)
		return (*this);
	this->_raw = ref._raw;
	this->_dval = ref._dval;
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
	return (this->_raw);
}

double  Converter::getDoubleValue(void) const
{
	return (this->_dval);
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
static void 	printChar(std::ostream& out, Converter& c)
{
	out << "char: ";
  	if (std::isnan(c.getDoubleValue()) || std::isinf(c.getDoubleValue()))
    	out << "impossible" << std::endl;
	else if (c.getDoubleValue() > CHAR_MAX || c.getDoubleValue() < CHAR_MIN)
    	out << "impossible" << std::endl;
  	else if (std::isprint(c.toCharValue()))
    	out << "'" << c.toCharValue() << "'" << std::endl;
  	else
    	out << "Non displayable" << std::endl;
}

static void 	printInt(std::ostream& out, Converter& c)
{
	out << "int: ";
  	if (std::isnan(c.getDoubleValue()) || std::isinf(c.getDoubleValue()))
    	out << "impossible" << std::endl;
	else if (c.getDoubleValue() > INT_MAX)
    	out << "overflow" << std::endl;
	else if (c.getDoubleValue() < INT_MIN)
    	out << "underflow" << std::endl;
  	else
    	out << c.toIntValue() << std::endl;
}

static void 	printFloat(std::ostream& out, Converter& c)
{
	out << "float: ";
  	if (std::isnan(c.getDoubleValue()) || std::isinf(c.getDoubleValue()))
   		out << std::showpos << c.toFloatValue() << "f" << std::endl;
	else if (c.getDoubleValue() > __FLT_MAX__)
		out << "overflow" << std::endl;
	else if (c.getDoubleValue() < -__FLT_MAX__)
    	out << "underflow" << std::endl;
  	else if (c.toFloatValue() == static_cast<int64_t>(c.toFloatValue()))
		out << c.toFloatValue() << ".0f" << std::endl;
	else
		out << std::setprecision(std::numeric_limits<float>::digits10)
     		<< c.toFloatValue() << "f" << std::endl;
}

static void 	printDouble(std::ostream& out, Converter& c)
{
	out << "double: ";
  	if (std::isnan(c.getDoubleValue()) || std::isinf(c.getDoubleValue()))
    	out << std::showpos << c.toDoubleValue() << std::endl;
	else if (c.toDoubleValue() == static_cast<int64_t>(c.toDoubleValue()))
	    out <<  c.toDoubleValue() << ".0" << std::endl;
	else
    	out << std::setprecision(std::numeric_limits<double>::digits10)
      		<< c.toDoubleValue() << std::endl;
}

std::ostream& operator<<(std::ostream& out, Converter& c)
{
	if (c.getFlag() == false)
	{
		out << "Error: Bad Alloc" << std::endl;
		return (out);
	}	
    printChar(out, c);
    printInt(out, c);
    printFloat(out, c);
    printDouble(out, c);
	return (out);
}
