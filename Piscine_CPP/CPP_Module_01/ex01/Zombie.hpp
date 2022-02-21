/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 12:13:54 by wben-sai          #+#    #+#             */
/*   Updated: 2021/09/20 09:55:26 by wben-sai         ###   ########.fr       */
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
        Zombie();
        ~Zombie( void );
        void setter(std::string name);
        std::string getter();
    private:
        std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
