/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:27:53 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/06 12:47:03 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat B1("Bureaucrat1", 1);
        Bureaucrat B2("Bureaucrat2", 150);

        
        //Bureaucrat B3("Bureaucrat3", 322);  //Exception
        //Bureaucrat B4("Bureaucrat4", 0);    //Exception


        //B2.decrementGrade();                //Exception
        std::cout <<B2 << std::endl; 
        B2.incrementGrade();
        std::cout  << B2 << std::endl;


        //B1.incrementGrade();                //Exception
        std::cout <<B1<< std::endl;
        B1.decrementGrade();
        std::cout <<B1<< std::endl;
        
    }
    catch (Bureaucrat::GradeTooHighException & e)
    {
        std::cout << e.what() << std::endl; 
    }
    catch (Bureaucrat::GradeTooLowException & e)
    {
        std::cout << e.what() << std::endl; 
    }
    
    return(0);
}