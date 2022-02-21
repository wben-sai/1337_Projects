/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:02:12 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/06 12:39:11 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : Name("unknown"), Grade(150)
{
    std::cout << "Bureaucrat Default Constructor called" << std::endl;
    return;
}

Bureaucrat::Bureaucrat(std::string Name, int Grade) : Name(Name)
{
    if(Grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (Grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->Grade = Grade;
    std::cout << "Bureaucrat Default Constructor called" << std::endl;
    return;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : Name(src.Name)
{
    std::cout << "Bureaucrat Copy constructor called" << std::endl;
    *this = src;
    return;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat Destructor called" << std::endl;
    return;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const & src)
{
    std::cout << "Bureaucrat Assignation operator called" << std::endl;
    this->Grade = src.Grade;
    return *this;
}

const std::string Bureaucrat::getName() const
{
    return (Name);    
}

const int& Bureaucrat::getGrade() const 
{
    return (Grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Exception : Grade Too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Exception : Grade Too Low";
}

std::ostream & operator<<(std::ostream & o ,Bureaucrat const & src)
{
    o << src.getName() << ", bureaucrat grade " << src.getGrade();
    return(o);
}

void Bureaucrat::incrementGrade()
{
    if (Grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        Grade--;
}

void Bureaucrat::decrementGrade()
{
    if (Grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        Grade++;
}
