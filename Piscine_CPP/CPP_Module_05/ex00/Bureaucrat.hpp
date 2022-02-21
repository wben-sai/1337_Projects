/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:56:02 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/06 12:29:45 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

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
        
    private:
        const std::string Name;
        int Grade;
};

std::ostream & operator<<(std::ostream & o ,Bureaucrat const & src);

#endif