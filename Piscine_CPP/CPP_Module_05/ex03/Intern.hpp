/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:32:19 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/07 12:41:14 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H

#include <string>
#include <iostream>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Form;

class Intern
{
    public:

        Intern(void);
        Intern(Intern const & src);
        ~Intern(void);
        Intern& operator=(Intern const & src);
        
        Form* makeForm(std::string name, std::string target);
    private:
    
};


#endif