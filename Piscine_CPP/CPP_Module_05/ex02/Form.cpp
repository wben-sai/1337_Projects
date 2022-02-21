/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 08:48:34 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/07 09:19:34 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : Name("Name"), Is_Signed(false), Grade_to_sign_it(150), Grade_to_execute_it(150)
{
    std::cout << "Form Default Constructor called" << std::endl;
    return;
}

Form::Form(Form const & src) : Name(src.Name), Grade_to_sign_it(src.Grade_to_sign_it), Grade_to_execute_it(src.Grade_to_execute_it)
{
    std::cout << "Form Copy constructor called" << std::endl;
    *this = src;
    return;
}

Form::~Form(void)
{
    std::cout << "Form Destructor called" << std::endl;
    return;
}

Form& Form::operator=(Form const & src)
{
    std::cout << "Form Assignation operator called" << std::endl;
    this->Is_Signed =src.Is_Signed;
    return *this;
}


Form::Form(const std::string Name, const int Grade_to_sign_it, const int Grade_to_execute_it) : Name(Name), Is_Signed(false), Grade_to_sign_it(Grade_to_sign_it), Grade_to_execute_it(Grade_to_execute_it)
{
    if(Grade_to_sign_it > 150 || Grade_to_execute_it > 150)
        throw Form::GradeTooLowException();
    else if (Grade_to_sign_it < 1 || Grade_to_execute_it < 1)
        throw Form::GradeTooHighException();
    std::cout << "Form Constructor called" << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Exception : Grade Too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Exception : Grade Too Low";
}

const char* Form::IsSignedException::what() const throw()
{
    return "Exception : The Form is not signed";
}

const std::string Form::getName() const
{
    return (Name);
}

bool Form::getIs_Signed() const
{
    return (Is_Signed);
}

const int& Form::getGrade_to_sign_it() const
{
    return (Grade_to_sign_it);
}

const int& Form::getGrade_to_execute_it() const
{
    return (Grade_to_execute_it);
}

std::ostream & operator<<(std::ostream & o ,Form const & src)
{
    o << "Name : " << src.getName() << " Is Signed : " << src.getIs_Signed() << " Grade to sign it : " << src.getGrade_to_sign_it()<< " Grade to execute it : " << src.getGrade_to_execute_it();
    return(o);
}

void Form::beSigned(Bureaucrat &Bur)
{
    if(Grade_to_sign_it > Bur.getGrade())
        Is_Signed = true;
    else
        throw Form::GradeTooLowException();
}

