/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 09:04:54 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/16 15:27:11 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

#define MAX_VAL 10000

int main()
{
    try
    {
        int i = -1;
        span sp =  span(MAX_VAL);
        while(++i < MAX_VAL)
            sp.addNumber(i);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        
        span sp2 =  span(100);
        std::vector<int> range;
        i = -1;
        while(++i < 100)
            range.push_back(i);
        sp2.addNumber(range.begin(), range.end());
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
        
    }
    catch(std::exception *e)
    {
        std::cout << e->what() << '\n';
    }
    return(0);
}