/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:15:43 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/07 14:03:41 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardon", 25, 5)
{
    std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
    return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardon", 25, 5)
{
    std::cout << "PresidentialPardonForm Constructor called" << std::endl;
    this->target = target;
    return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : Form(src)
{
    std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
    *this = src;
    return;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
    return;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
    std::cout << "Form Assignation operator called" << std::endl;
    this->target = src.target;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->getIs_Signed() == false)
        throw Form::IsSignedException();
    else if(executor.getGrade() > getGrade_to_execute_it())
        throw Form::GradeTooLowException();
    
    std::cout << target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
