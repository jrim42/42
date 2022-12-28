/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:47:04 by jrim              #+#    #+#             */
/*   Updated: 2022/12/28 17:38:54 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define GRY "\033[90m"
# define DFT "\033[0;37m"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_sign;
		const int			_s_grade;
		const int			_e_grade;
		std::string			_target;

	public:
		AForm(void);
		AForm(std::string name, int s_grade, int e_grade, std::string target);
		AForm(const AForm& ref);
		AForm& operator=(const AForm& ref);
		virtual ~AForm(void);

		const std::string&	getName(void) const;
		bool				getSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		const std::string&	getTarget(void) const;

		void			beSigned(const Bureaucrat& b);
		virtual void	execute(const Bureaucrat& b) const = 0;

		void	checkGrade(int grade, int min, int max) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
		class AlreadySignedException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
		class NotSignedException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif