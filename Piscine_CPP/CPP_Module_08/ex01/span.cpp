/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:18:38 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/16 15:27:33 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

span::span(unsigned int N)
{
    this->N = N;
}

span::~span()
{
}

span::span(span const & src)
{
    *this = src;
    return;
}

span& span::operator=(span const & src)
{
    this->N = src.N;
    this->vec = src.vec;
    return *this;
}

void span::addNumber(int nbr)
{
    if(this->vec.size() > this->N)
        throw new std::exception;
    this->vec.push_back(nbr);
}


void span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    this->vec.insert(this->vec.end(), begin, end);
    if(this->vec.size() > this->N)
        throw new std::exception;
}

int span::longestSpan()
{
    int res;
    if(this->vec.size() == 1 || this->vec.size()== 0)
        throw new std::exception;
    res = *max_element(this->vec.begin(), this->vec.end()) - *min_element(this->vec.begin(), this->vec.end());
    if (res < 0)
        res *= -1;
    return (res);
}

int span::shortestSpan()
{
    std::vector<int> vec2 = this->vec;
    int res = this->longestSpan();
    if(vec2.size() == 1 || vec2.size()== 0)
        throw new std::exception;
    std::sort(vec2.begin(), vec2.end());
    std::vector<int>::iterator i = vec2.begin();
    while(i != vec2.end() -1)
    {   
        if(res > (*(i + 1) - *i))
            res = (*(i + 1) - *i);

        i++;
    }
    return(res);
}
