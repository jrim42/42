/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:37:08 by jrim              #+#    #+#             */
/*   Updated: 2023/01/07 17:37:08 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

#define CONTOUR "-------------------------------------------------" 

void    test1_MutantStack(void);
void    test2_List(void);

int main(void)
{
    std::cout << CONTOUR << std::endl;
    test1_MutantStack();
    std::cout << CONTOUR << std::endl;
    test2_List();
    return (0);
}

void    test1_MutantStack(void)
{
    std::cout << GRY << "(case1: mutant stack)" << DFT << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << "top : " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "iterator check: ";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    std::stack<int> s(mstack);
}

void    test2_List(void)
{
    std::cout << GRY << "(case2: list)" << DFT << std::endl;
    std::list<int> lst;

    lst.push_back(5);
    lst.push_back(17);
    std::cout << "back: "<< lst.back() << std::endl;
    lst.pop_back();
    std::cout <<  "size: " << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << "iterator check: ";
    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();
    
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    std::list<int> s(lst);
}