/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:47:04 by jrim              #+#    #+#             */
/*   Updated: 2022/11/28 13:05:16 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define GRY "\033[90m"
# define DFT "\033[0;37m"

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		int					_s_grade;
		int					_e_grade;

	public:
		Form(void);
		// Form(std::string name, bool signed, int s_grade, int e_grade);
		Form(const Form& ref);
		Form& operator=(const Form& ref);
		~Form(void);

		const std::string&	getName(void) const;
		bool				getSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		
		class GradeTooHighException : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};

		void	beSigned(Bureaucrat b);
		void	signForm(Bureaucrat b);
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif