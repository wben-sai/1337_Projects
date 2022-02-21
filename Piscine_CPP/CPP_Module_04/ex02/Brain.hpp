/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 14:53:36 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/03 15:07:35 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#ifndef BRAIN_H
#define BRAIN_H

class Brain
{
    public :
        Brain(void);
        Brain(Brain const & src);
        ~Brain(void);
        Brain& operator=(Brain const & src);
    
    private:
        std::string ideas[100];
};

#endif