/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:15:43 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/07 14:04:26 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("Shrubbery Creation", 145, 137)
{
    std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery Creation", 145, 137)
{
    std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
    this->target = target;
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : Form(src)
{
    std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
    *this = src;
    return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
    return;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
    std::cout << "Form Assignation operator called" << std::endl;
    this->target = src.target;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (this->getIs_Signed() == false)
        throw Form::IsSignedException();
    else if(executor.getGrade() > getGrade_to_execute_it())
        throw Form::GradeTooLowException();
    
    std::ofstream MyFile(target + "_shrubbery");
    
    MyFile << "     ccee88oo          " << std::endl;
    MyFile << "  C8O8O8Q8PoOb o8oo    " << std::endl;
    MyFile << " dOB69QO8PdUOpugoO9bD  " << std::endl;
    MyFile << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
    MyFile << "    6OuU  /p u gcoUodpP" << std::endl;
    MyFile << "      \\\\//  /douUP    " << std::endl;
    MyFile << "        \\\\////        " << std::endl;
    MyFile << "         |||/\\         " << std::endl;
    MyFile << "         |||\\/         " << std::endl;
    MyFile << "         |||||         " << std::endl;
    MyFile << "   .....//||||\\....    " << std::endl;
    
    MyFile.close();
}
