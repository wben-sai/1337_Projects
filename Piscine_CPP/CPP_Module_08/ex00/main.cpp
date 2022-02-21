/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:42:06 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/16 08:50:15 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{

    try 
    {
        std::array<int, 5> ary = {121,45,8,87,19};
        
        std::cout << easyfind(ary, 19) << "\n";
        //std::cout << easyfind(ary, 15) << "\n"; //Exception

        std::vector<int> vec;
        for (int i = 1; i <= 5; i++)
            vec.push_back(i);
            
        std::cout << easyfind(vec, 3) << "\n";
        //std::cout << easyfind(vec, 7) << "\n";; //Exception
    }
    catch(std::exception *e)
    {
        std::cout  << e->what();
    }
    
    return (0);
}