/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:57:26 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/07 10:07:51 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class PresidentialPardonForm : public Form
{
    public:
    
        PresidentialPardonForm(void);
        PresidentialPardonForm(PresidentialPardonForm const & src);
        ~PresidentialPardonForm(void);
        PresidentialPardonForm& operator=(PresidentialPardonForm const & src);
        
        PresidentialPardonForm(std::string target);
        void execute(Bureaucrat const & executor) const;
        
    private:
        std::string target;
    
};

#endif