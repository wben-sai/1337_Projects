/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:06:31 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/16 15:16:52 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <vector>

class span
{
    private:
        unsigned int N;
        std::vector<int> vec;
    public:
        span(unsigned int N);
        ~span();
        span(void);
        span(span const & src);
        span& operator=(span const & src);

        void addNumber(int nbr);
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();
};

#endif