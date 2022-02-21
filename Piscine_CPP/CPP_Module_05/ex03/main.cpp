/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:27:53 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/07 13:30:14 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Bureaucrat B1("Bureaucrat1", 3);
        
        Intern I1;

        I1.makeForm("PresidentialPardon", "Bender");
        
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