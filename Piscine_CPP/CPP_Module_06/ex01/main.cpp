/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 10:35:29 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/12 09:18:54 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdint>
#include <iostream>

struct Data
{
    int a;
    int b;
};

uintptr_t serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

int main()
{

    Data *ptr = new Data();
    ptr->a = 10;
    ptr->b = 20;
    
    std::cout << ptr << std::endl;
    
    uintptr_t raw = serialize(ptr);
    Data *test = deserialize(raw);
    
    std::cout << test << std::endl;

    
    std::cout << test->a << "\n" << test->b << std::endl;
    return (0);
}