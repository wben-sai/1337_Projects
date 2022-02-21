/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:35:29 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/07 13:33:01 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout << "Intern Default Constructor called" << std::endl;
    return;
}

Intern::Intern(Intern const & src)
{
    std::cout << "Intern Copy constructor called" << std::endl;
    *this = src;
    return;
}

Intern::~Intern(void)
{
    std::cout << "Intern Destructor called" << std::endl;
    return;
}


Intern& Intern::operator=(Intern const & src)
{
    (void)src;
    std::cout << "Intern Assignation operator called" << std::endl;
    return *this;
}


Form* Intern::makeForm(std::string name, std::string target)
{
    int i = -1;
    int j = -1;
    Form *lst[4] = {new PresidentialPardonForm(target), new ShrubberyCreationForm(target), new RobotomyRequestForm(target), NULL};

    while(3 > ++i)
    {
        if(name == lst[i]->getName())
        {
            j = -1;
            while(j++ < 3)
                if(i != j)
                    delete lst[j];
            std::cout << "Intern creates " << name << std::endl;
            return (lst[i]);
        }
    }
    while(j++ > 3)
        delete lst[j];
    std::cout << "inco " << name << std::endl;
    return NULL;
}
