/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:27:53 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/07 11:14:06 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat B1("Bureaucrat1", 3);
        
        ShrubberyCreationForm F1("Form1");
        RobotomyRequestForm F2("Form2");
        PresidentialPardonForm F3("Form2");
        
        //F1.execute(B1);                   //Exception
        B1.signForm(F1);
        B1.signForm(F2);
        B1.signForm(F3);
        
        B1.executeForm(F1);
        B1.executeForm(F2);
        B1.executeForm(F3);
        
    }
    catch (Bureaucrat::GradeTooHighException & e)
    {
        std::cout << e.what() << std::endl; 
    }
    catch (Bureaucrat::GradeTooLowException & e)
    {
        std::cout << e.what() << std::endl; 
    }
    catch (Form::GradeTooHighException & e)
    {
        std::cout << e.what() << std::endl; 
    }
    catch (Form::GradeTooLowException & e)
    {
        std::cout << e.what() << std::endl; 
    }
    catch (Form::IsSignedException & e)
    {
        std::cout << e.what() << std::endl; 
    }
    
    return(0);
}