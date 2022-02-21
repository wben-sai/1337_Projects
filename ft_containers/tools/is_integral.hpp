/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:00:08 by wben-sai          #+#    #+#             */
/*   Updated: 2022/01/04 12:57:51 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
    template <class T> 
    struct is_integral
    {
        typedef bool   value_type;
        const static value_type value = false;
    };
 
    template <>
    struct is_integral<bool>
    {
        typedef bool   value_type;
        const static value_type value = true;
    };
        
    template <>
    struct is_integral<char>
    {        
        typedef bool    value_type;
        const static    value_type value = true;
    };
    
    template <>
    struct is_integral<char16_t>
    {
        typedef bool    value_type;
        const static    value_type value = true;
    };
    
    template <>
    struct is_integral<char32_t>
    {        
        typedef bool    value_type;
        const static    value_type value = true;
    };
    
    template <>
    struct is_integral<wchar_t>{
        typedef bool    value_type;
        const static    value_type value = true;
    };
    
    template <>
    struct is_integral<signed char>{
        typedef bool    value_type;
        const static    value_type value = true;
    };
    
    template <>
    struct is_integral<short int>{
        typedef bool    value_type;
        const static    value_type value = true;
    };
    
    template <>
    struct is_integral<int>{        
        typedef bool    value_type;
        const static    value_type value = true;
    };
    
    template <>
    struct is_integral<long int>{        
        typedef bool    value_type;
        const static    value_type value = true;
    };
    
    template <>
    struct is_integral<long long int>{        
        typedef bool    value_type;
        const static    value_type value = true;
    };
    
    template <>
    struct is_integral<unsigned char>{        
        typedef bool    value_type;
        const static    value_type value = true;
    };
    
    template <>
    struct is_integral<unsigned short int>{        
        typedef bool    value_type;
        const static    value_type value = true;
    };
    
    template <>
    struct is_integral<unsigned int>{        
        typedef bool    value_type;
        const static    value_type value = true;
    };
    
    template <>
    struct is_integral<unsigned long int>{        
        typedef bool    value_type;
        const static    value_type value = true;
    };
    
    template <>
    struct is_integral<unsigned long long int>{        
        typedef bool    value_type;
        const static    value_type value = true;
    };
} 
