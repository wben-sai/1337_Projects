/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:15:43 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/07 13:29:08 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form("RobotomyRequest", 72, 45)
{
    std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
    return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequest", 72, 45)
{
    std::cout << "RobotomyRequestForm Constructor called" << std::endl;
    this->target = target;
    return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : Form(src)
{
    std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
    *this = src;
    return;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
    return;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
    std::cout << "Form Assignation operator called" << std::endl;
    this->target = src.target;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (this->getIs_Signed() == false)
        throw Form::IsSignedException();
    else if(executor.getGrade() > getGrade_to_execute_it())
        throw Form::GradeTooLowException();
    
    std::cout << "🔊" << "that "<< target << " has been robotomized successfully 50% of the time." <<std::endl;
}
