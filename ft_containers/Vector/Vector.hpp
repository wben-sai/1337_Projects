/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:10:11 by wben-sai          #+#    #+#             */
/*   Updated: 2022/01/04 15:10:24 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "v_iterator.hpp"
#include "../tools/reverse_iterator.hpp"
#include "../tools/equal_lexicographical_compare.hpp"
#include "../tools/is_integral.hpp"
#include "../tools/enable_if.hpp"

#include <stdexcept>

namespace ft
{
    template < typename T, typename Alloc = std::allocator<T> > 
    class vector
    {
        public :
            typedef T                                   value_type;
            typedef Alloc                               allocator_type;
            typedef value_type&                         reference;
            typedef const value_type&                   const_reference;
            typedef value_type*                         pointer;
            typedef const value_type*                   const_pointer;
            typedef const ptrdiff_t                     difference_type;
            typedef size_t                              size_type;
            typedef v_iterator<const value_type>        const_iterator;
            typedef v_iterator<value_type>              iterator;
            typedef reverse_iterator<const_iterator>    const_reverse_iterator;
            typedef reverse_iterator<iterator>          reverse_iterator;
        
        private :
            allocator_type alloc_type;
            pointer ptr;
            size_t capacity_v;
            size_t size_v;
            
        public :

            explicit vector (const allocator_type& alloc = allocator_type())
            {
                alloc_type = alloc;
                size_v = 0;
                capacity_v = 0;
                ptr = NULL;
            }

            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
            {
                alloc_type = alloc;
                size_v = 0;
                capacity_v = 0;
                ptr = NULL;
                assign(n, val);
            }

            template <class InputIterator>
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = nullptr)
            {
                alloc_type = alloc;
                size_v = 0;
                capacity_v = 0;
                ptr = NULL;
                insert(begin(), first, last);
            }
            
            vector (const vector& x)
            {
                alloc_type = x.alloc_type;
                size_v = 0;
                capacity_v = 0;
                ptr = NULL;
                const_iterator ite = x.begin();
                capacity_v = x.capacity();
                ptr = alloc_type.allocate(capacity_v);
                while(ite != x.end())
                {
                    alloc_type.construct(&ptr[size_v], *ite);
                    size_v++;
                    ite++;
                }
            }
            
            ~vector()
            {
                if(capacity_v != 0)
                {
                    alloc_type.destroy(ptr);
                    alloc_type.deallocate(ptr, capacity_v);
                }
            }

            vector& operator= (const vector& x)
            {
                clear();
                size_v = 0;
                if(x.size() == 0)
                    return(*this);
                if(capacity_v == 0 || capacity_v < x.capacity())
                {
                
                    if(capacity_v > 0)
                    {
                        alloc_type.destroy(ptr);
                        alloc_type.deallocate(ptr, capacity_v);
                    }
                    capacity_v = x.size();
                    const_iterator ite = x.begin();
                    ptr = alloc_type.allocate(capacity_v);
                    while(ite != x.end())
                    {
                        alloc_type.construct(&ptr[size_v], *ite);
                        size_v++;
                        ite++;
                    }
                    return(*this);
                }
                else
                {
                    const_iterator ite = x.begin();
                    while(ite != x.end())
                    {
                        alloc_type.construct(&ptr[size_v], *ite);
                        size_v++;
                        ite++;
                    }
                    return(*this);
                }
            }

            //Iterators: --------------------------------------------------------------------------
            iterator begin(){iterator temp(ptr); return(temp);}
            const_iterator begin() const{const_iterator temp(ptr); return(temp);}
            iterator end(){iterator temp(ptr + size_v);return(temp);}
            const_iterator end() const{const_iterator temp(ptr + size_v);return(temp);}
            reverse_iterator rbegin(){reverse_iterator temp(end());return(temp);}
            const_reverse_iterator rbegin() const{const_reverse_iterator temp(end());return(temp);}
            reverse_iterator rend(){reverse_iterator temp(begin());return(temp);}
            const_reverse_iterator rend() const{const_reverse_iterator temp(begin());return(temp);}
            

             //Capacity: --------------------------------------------------------------------------
            size_type size() const{return(size_v);}
            size_type max_size() const{return(alloc_type.max_size());}
            void resize (size_type n, value_type val = value_type())
            {
                size_type i = 0;
                size_type ptr_cap = capacity_v;
                pointer temp;
                
                if(capacity_v == 0)
                {
                    capacity_v = n;
                    size_v = n;
                    ptr = alloc_type.allocate(capacity_v);
                    while(i < n)
                    {
                        alloc_type.construct(&ptr[i], val);
                        i++;
                    }
                }
                else if(capacity_v > n && size_v < n)
                {
                    while(size_v < n)
                    {
                        alloc_type.construct(&ptr[size_v], val);
                        size_v++;
                    }
                }
                else if(capacity_v < n)
                {
                    if(capacity_v * 2 <= n)
                    {
                        temp = alloc_type.allocate(n);
                        capacity_v = n;
                    }
                    else
                    {
                        capacity_v *=2;
                        temp = alloc_type.allocate(capacity_v);
                    }
                    while(i < size_v)
                    {
                        alloc_type.construct(&temp[i], ptr[i]);
                        i++;
                    }
                    while(i < n)
                    {
                        alloc_type.construct(&temp[i], val);
                        i++;
                    }
                    alloc_type.destroy(ptr);
                    alloc_type.deallocate(ptr, ptr_cap);
                    ptr = temp;
                    size_v = n;
                }
                else if(capacity_v > n && size_v > n)
                {
                    while(size_v > n)
                        pop_back();
                }
            }
            size_type capacity() const{return(capacity_v);}
            bool empty() const{return(size_v == 0);}
            void reserve (size_type n){
                size_t i = 0;
                if(n > capacity_v)
                {
                    pointer temp;
                    temp = alloc_type.allocate(n);
                    while(i < size_v)
                    {
                        alloc_type.construct(&temp[i], ptr[i]);
                        i++;
                    }
                    alloc_type.destroy(ptr);
                    alloc_type.deallocate(ptr, capacity_v);
                    capacity_v = n;
                    ptr = temp;
                }
            }
           
            //Element access --------------------------------------------------------------------------
            const_reference operator[] (size_type n) const{return(ptr[n]);}
            reference operator[] (size_type n){return(ptr[n]);}
            
            reference at (size_type n)
            {
                if(n >= size_v)
                    throw std::out_of_range("vector");
                return(ptr[n]);
            }
            const_reference at (size_type n) const
            {
                if(n >= size_v)
                    throw std::out_of_range("vector");
                return(ptr[n]);
            }

            reference front(){return(*ptr);}
            const_reference front() const{return(*ptr);}

            reference back(){return(ptr[size_v - 1]);}
            const_reference back() const{return(ptr[size_v - 1]);}
            

            //Modifiers: --------------------------------------------------------------------------
            void assign (size_type n, const value_type& val)
            {
                size_type i = 0;
                if(n < capacity_v)
                {
                    clear();
                    while(n > size_v)
                    {
                        alloc_type.construct(&ptr[size_v], val);
                        size_v++;
                    }
                }
                else
                {
                    if(capacity_v != 0)
                    {
                        alloc_type.destroy(ptr);
                        alloc_type.deallocate(ptr, capacity_v);
                    }
                    ptr = alloc_type.allocate(n);
                    while(n > i)
                    {
                        alloc_type.construct(&ptr[i], val);
                        i++;
                    }
                    size_v = n;
                    capacity_v = n;
                }
            }

            template <class InputIterator>
            void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = nullptr)
            {
                size_type i = 0;
                size_type len = last - first;
                
                
                if(len < capacity_v)
                {   
                    clear();
                    
                    while(first !=  last)
                    {
                        alloc_type.construct(&ptr[i], *first);
                        i++;
                        first++;
                    }
                    size_v = len;
                }
                else
                {
                    if(size_v > 0)
                    {
                        alloc_type.destroy(ptr);
                        alloc_type.deallocate(ptr, capacity_v);
                    }
                    ptr = alloc_type.allocate(len);
                    while(first !=  last)
                    {
                        alloc_type.construct(&ptr[i], *first);
                        i++;
                        first++;
                    }
                    size_v = len;
                    capacity_v = len;
                }
            } 
            
            void push_back (const value_type& val)
            {
                
                size_t i = 0;
                if (capacity_v == 0)
                    ptr = alloc_type.allocate(++capacity_v);
                if (size_v == capacity_v)
                {
                    i = 0;
                    pointer temp;
                    temp = alloc_type.allocate(capacity_v * 2);
                    while(i < size_v)
                    {
                        alloc_type.construct(&temp[i], ptr[i]);
                        i++;
                    }
                    alloc_type.destroy(ptr);
                    alloc_type.deallocate(ptr, capacity_v);
                    capacity_v *=2;
                    ptr = temp;
                }
                alloc_type.construct(&ptr[size_v], val);
                size_v += 1;
            }
            
            void pop_back(){ptr[size_v - 1].~T();size_v--;}
            iterator insert (iterator position, const value_type& val)
            {
                size_t i = 0;
                size_t j = size_v;
                iterator ite(ptr);
                
                if(size_v == 0)
                    push_back(val);
                else
                {
                    if(position ==end())
                    {
                        push_back(val);
                        ite = ptr + size_v - 1;
                        return(ite);
                    }
                    while(begin() + i != end())
                    {
                        if(ite == position)
                        {
                            push_back(val);
                            while(j > i)
                            {
                                alloc_type.construct(&ptr[j], ptr[j - 1]);
                                j--;
                            }
                            alloc_type.construct(&ptr[j], val);
                            ite = ptr + i;
                            break;
                        }
                        i++;
                        ite++;
                    }
                }
                if(i == size_v - 1)
                    ite = ptr;
                return(ite);
            }
            void insert (iterator position, size_type n, const value_type& val)
            {
                size_t i = 0, j = 0;
                size_t ptr_cap = capacity_v;
                iterator ite(ptr);
                pointer temp;
                
                if(capacity_v == 0)
                {
                    capacity_v = n;
                    ptr = alloc_type.allocate(capacity_v);
                    while(size_v < n)
                    {
                        alloc_type.construct(&ptr[size_v], val);
                        size_v++;
                    }
                }
                else
                {
                    while(begin() + i != end() || begin() + i == position)
                    {
                        if(ite == position)
                        {
                            if(capacity_v >= size_v + n)
                            {
                                while(size_v - i > j)
                                {
                                    alloc_type.construct(&ptr[size_v - 1 + n - j], ptr[size_v - 1 - j]);
                                    j++;
                                }
                                size_v += n;
                                j = 0;
                                while(n > j)
                                {
                                    alloc_type.construct(&ptr[i + j], val);
                                    j++;
                                }
                                break;
                            }
                            else if(capacity_v < size_v + n)
                            {
                                if(capacity_v * 2 >= size_v + n)
                                    capacity_v *=2;
                                else
                                    capacity_v = size_v + n;
                                temp = alloc_type.allocate(capacity_v);
                                while(i > j)
                                {
                                    alloc_type.construct(&temp[j] , ptr[j]);
                                    j++;
                                }
                                while(n != 0)
                                {
                                    alloc_type.construct(&temp[j] , val);
                                    n--;
                                    j++;
                                }
                                while(i < size_v)
                                {
                                    alloc_type.construct(&temp[j] , ptr[i]);
                                    j++;
                                    i++;
                                }
                                if(ptr_cap != capacity_v)
                                {
                                    alloc_type.destroy(ptr);
                                    alloc_type.deallocate(ptr, ptr_cap);
                                }
                                size_v = j;
                                ptr = temp;
                                break;
                            }
                        }
                        ite++;
                        i++;
                    }
                }
            }
             
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = nullptr)
            {
                vector<value_type> rang;
                while(first != last)
                {
                    rang.push_back(*first);
                    first++;
                }
                size_t i = 0, j = 0;
                size_t len = rang.size();
                if(capacity_v == 0)
                {
                    ptr = alloc_type.allocate(len);
                    while(i < len)
                    {
                        alloc_type.construct(&ptr[i] , rang[i]);
                        i++;
                    }
                    size_v = len;
                    capacity_v = len;
                    return;
                }
                else
                {
                    if(len == 0)
                        return;
                    pointer temp;
                    size_t capacity = capacity_v;
                    iterator it;
                    while(begin() + i != end())
                    {
                        it = ptr + i;
                        if(it == position)
                        {
                            if(len + size_v <= capacity_v)
                            {
                                while(size_v - i > j)
                                {
                                    alloc_type.construct(&ptr[size_v - 1 + len - j] , ptr[size_v - 1 - j]);
                                    j++;
                                }
                                size_v += len;
                                j = 0;
                                while(len > j)
                                {
                                    alloc_type.construct(&ptr[i + j] , rang[j]);
                                    j++;
                                }
                            }
                            else
                            {
                                if(capacity_v * 2 >= size_v + len)
                                    while(len + size_v > capacity_v)
                                        capacity_v *= 2;
                                else
                                    capacity_v = size_v + len;
                                temp = alloc_type.allocate(capacity_v);
                                while(i > j)
                                {
                                    alloc_type.construct(&temp[j] , ptr[j]);
                                    j++;
                                }
                                size_t x = 0;
                                while(x < len)
                                {
                                    alloc_type.construct(&temp[j] , rang[x]);
                                    x++;
                                    j++;
                                }
                                while(size_v > i)
                                {
                                    alloc_type.construct(&temp[j] , ptr[i]);
                                    i++;
                                    j++;
                                }
                                alloc_type.destroy(ptr);
                                alloc_type.deallocate(ptr, capacity);
                                ptr = temp;
                                size_v += len;
                            }
                            break;
                        }
                        i++;
                    }
                }
            }
            iterator erase (iterator position){return (erase(position, position + 1));}
            iterator erase (iterator first, iterator last)
            {
                size_t i = 0;
                size_t j = 0;
                size_t len = last - first;;
                iterator ite(ptr);
                while(begin() + i != end())
                {
                    if(ite + i == first)
                    {
                        while(j < size_v - i - len)
                        {
                           alloc_type.construct(&ptr[i + j] , ptr[i + len + j]);
                           j++;
                        }
                        j = 0;
                        while (len > j)
                        {
                            pop_back();
                            j++;
                        }
                        break;
                    }
                    i++;
                }
                ite = ptr + i;
                return(ite);
            }
            
            void swap (vector& x)
            {
                pointer temp;
                size_t capacity;
                size_t size;
                
                temp = ptr;
                ptr = x.ptr;
                x.ptr = temp;
                capacity = capacity_v;
                size = size_v;
                capacity_v = x.capacity_v;
                size_v = x.size_v;
                x.capacity_v = capacity;
                x.size_v = size;
            }
            void clear()
            {
                size_t i = size_v;
                while(i != 0)
                {
                    pop_back();
                    i--;
                }
            }
            
            //Allocator: --------------------------------------------------------------------------
            allocator_type get_allocator() const
            {
                return(alloc_type);
            }
    };

    //Non-member function overloads: -------------------------------------------------------
    
    template <class OT, class OAlloc>
    bool operator== (const vector<OT,OAlloc>& lhs, const vector<OT,OAlloc>& rhs)
    {
        if(lhs.size() !=  rhs.size())
            return(false);
        return(ft::equal(lhs.begin(), lhs.end() ,rhs.begin()));
    }

    template <class OT, class OAlloc>
    bool operator!= (const vector<OT,OAlloc>& lhs, const vector<OT,OAlloc>& rhs)
    {
        if(lhs.size() !=  rhs.size())
            return(true);
        return(!ft::equal(lhs.begin(), lhs.end() ,rhs.begin()));
    }

    template <class OT, class OAlloc>
    bool operator< (const vector<OT,OAlloc>& lhs, const vector<OT,OAlloc>& rhs)
    {
        return(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template <class OT, class OAlloc>
    bool operator> (const vector<OT,OAlloc>& lhs, const vector<OT,OAlloc>& rhs)
    {
        return(ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
    }

    template <class OT, class OAlloc>
    bool operator<= (const vector<OT,OAlloc>& lhs, const vector<OT,OAlloc>& rhs)
    {
        return(!ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
    }

    template <class OT, class OAlloc>
    bool operator>= (const vector<OT,OAlloc>& lhs, const vector<OT,OAlloc>& rhs)
    {
        return(!ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        x.swap(y);
    }
}
