/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:21:18 by wben-sai          #+#    #+#             */
/*   Updated: 2022/01/03 10:58:39 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <class T1>
struct Node
{
    typedef T1  mypair;
    
    T1 *data;
    Node *left;
    Node *right;
    Node *parent;
    bool isblack;
    bool isroot;
    bool isdb;
    bool is_end;
    bool is_begin;
};
