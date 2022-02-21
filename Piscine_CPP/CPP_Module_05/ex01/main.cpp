/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:27:53 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/06 13:37:13 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat B1("Bureaucrat1", 3);
        Bureaucrat B2("Bureaucrat2", 15);
        //Form F1("Form1", 199, 3); //Exception
        Form F1("Form1", 8, 3);
        B2.signForm(F1);
        B1.signForm(F1);
        
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
    
    return(0);
}