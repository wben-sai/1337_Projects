/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 12:13:54 by wben-sai          #+#    #+#             */
/*   Updated: 2021/09/22 15:01:04 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#ifndef ZOMBIE__H
#define ZOMBIE__H

class Zombie
{
    public :
        void announce( void );
        Zombie(std::string name);
        Zombie(void);
        ~Zombie( void );
    private:
        std::string _name;
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);
#endif
