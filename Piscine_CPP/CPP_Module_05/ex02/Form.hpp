/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 08:47:10 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/07 09:17:04 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
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

        class IsSignedException : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };
            
        Form(void);
        Form(Form const & src);
        ~Form(void);
        Form& operator=(Form const & src);

        Form(const std::string Name, const int Grade_to_sign_it, const int Grade_to_execute_it);
        const std::string getName() const;
        bool getIs_Signed() const;
        const int& getGrade_to_sign_it() const;
        const int& getGrade_to_execute_it() const;
        void beSigned(Bureaucrat &Bur);

        virtual void execute(Bureaucrat const & executor) const = 0;
        
    private:
        const std::string Name;
        bool Is_Signed;
        const int Grade_to_sign_it;
        const int Grade_to_execute_it;
};

std::ostream & operator<<(std::ostream & o ,Form const & src);

#endif
