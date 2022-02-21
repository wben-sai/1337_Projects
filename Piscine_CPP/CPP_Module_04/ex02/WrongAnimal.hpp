/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 09:17:25 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/02 14:28:48 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

class WrongAnimal
{
    public :
        WrongAnimal(void);
        WrongAnimal(WrongAnimal const & src);
        ~WrongAnimal(void);
        WrongAnimal& operator=(WrongAnimal const & src);
    
        WrongAnimal(std::string type);
        void makeSound() const;
        std::string getType() const;
    protected:
        std::string type;
};

#endif