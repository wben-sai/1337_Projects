/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:56:02 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/07 10:18:44 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    public:
    
        class GradeTooHighException : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };

        Bureaucrat(void);
        Bureaucrat(Bureaucrat const & src);
        ~Bureaucrat(void);
        Bureaucrat& operator=(Bureaucrat const & src);
        
        Bureaucrat(std::string Name, int Grade);
        const std::string getName() const;
        const int& getGrade() const;
        void incrementGrade();
        void decrementGrade();

        //ex01
        void signForm(Form &frm);

        //ex02
        void executeForm(Form const & form);
        
    private:
        const std::string Name;
        int Grade;
};

std::ostream & operator<<(std::ostream & o ,Bureaucrat const & src);

#endif
