/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:37:16 by jrim              #+#    #+#             */
/*   Updated: 2023/01/07 18:11:29 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define GRY "\033[90m"
# define DFT "\033[0;37m"

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack(void) {};
        MutantStack(const MutantStack& ref) {*this = ref;};
        MutantStack&    operator=(const MutantStack& ref) {*this = ref; return (*this);}
        ~MutantStack(void) {};
        
        typedef typename MutantStack<T>::stack::container_type::iterator                iterator;
        typedef typename MutantStack<T>::stack::container_type::const_iterator          const_iterator;
        typedef typename MutantStack<T>::stack::container_type::reverse_iterator        reverse_iterator;
        typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator  const_reverse_iterator;
        
        iterator    begin(void) {return (this->c.begin());}
        iterator    end(void) {return (this->c.end());}

        const_iterator  cbegin(void) {return (this->c.cbegin());}
        const_iterator  cend(void) {return (this->c.cend());}

        reverse_iterator    rbegin(void) {return (this->c.rbegin());}
        reverse_iterator    rend(void) {return (this->c.rend());}

        const_iterator  crbegin(void) {return (this->c.crbegin());}
        const_iterator  crend(void) {return (this->c.crend());}
};

#endif