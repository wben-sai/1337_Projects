/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:57:26 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/07 10:56:16 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class RobotomyRequestForm : public Form
{
    public:
    
        RobotomyRequestForm(void);
        RobotomyRequestForm(RobotomyRequestForm const & src);
        ~RobotomyRequestForm(void);
        RobotomyRequestForm& operator=(RobotomyRequestForm const & src);

        RobotomyRequestForm(std::string target);
        void execute(Bureaucrat const & executor) const;
        
    private:
        std::string target;
    
};

#endif