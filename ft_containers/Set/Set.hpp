/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 10:58:51 by wben-sai          #+#    #+#             */
/*   Updated: 2021/12/27 15:52:17 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "node.hpp"
#include "RBT/RBT.hpp"
#include <iostream>
#include "s_iterator.hpp"
#include "../Vector/Vector.hpp"
#include "../tools/reverse_iterator.hpp"
#include "../tools/enable_if.hpp"

namespace ft
{
    template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> > 
    class set
    {
        public :
            typedef T                                                                                           key_type;
            typedef T                                                                                           value_type;
            typedef Compare                                                                                     key_compare;
            typedef Compare                                                                                     value_compare;
            typedef Alloc                                                                                       allocator_type;
            typedef value_type&                                                                                 reference;
            typedef const value_type&                                                                           const_reference;
            typedef value_type*                                                                                 pointer;
            typedef const value_type*                                                                           const_pointer;
            typedef s_iterator<Rbt<key_type, key_compare>, Node<value_type>, key_compare, const key_type>       const_iterator;
            typedef s_iterator<Rbt<key_type, key_compare>, Node<value_type>, key_compare, key_type>             iterator;
            typedef reverse_iterator<const_iterator>                                                                        const_reverse_iterator;
            typedef reverse_iterator<iterator>                                                                              reverse_iterator;
            typedef std::ptrdiff_t                                                                              difference_type;
            typedef std::size_t                                                                                 size_type;

        private :
            ft::Rbt<key_type, key_compare>     _tree;
            key_compare     _mycomp;
            allocator_type  _alloc_type;
            
        public : 

            explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(), _mycomp(comp), _alloc_type(alloc){}

            template <class InputIterator>
            set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(), _mycomp(comp), _alloc_type(alloc){insert (first, last);}
            
            set (const set& x): _tree(), _mycomp(x._mycomp), _alloc_type(x._alloc_type) 
            {
                insert (x.begin(), x.end());
            }
            
            ~set(){clear();}

            set& operator= (const set& x)
            {
                clear();insert (x.begin(), x.end());return(*this);
            }


            
            // Iterators: ---------------------------------------------------------------------------------------------------
            iterator begin()
            {
                return (_tree.begin());
            }

            const_iterator begin() const
            {
                return (_tree.begin());
            }

            iterator end()
            {
               return (_tree.end());
            }

            const_iterator end() const
            {
                return (_tree.end());
            }

             reverse_iterator rbegin()
            {
                reverse_iterator temp(end());
                return(temp);
            }

            const_reverse_iterator rbegin() const
            {
                const_reverse_iterator temp(end());
                return(temp);
            }

            reverse_iterator rend(){
                reverse_iterator temp(begin());
                return(temp);
            }

            const_reverse_iterator rend() const
            {
                const_reverse_iterator temp(begin());
                return(temp);
            }

            //---------------------------------------------------------------------------------------------------------------
            
            // Capacity: ----------------------------------------------------------------------------------------------------

            bool empty() const{return(_tree.empty());}
            size_type size() const{return(_tree.size());}
            size_type max_size() const{return _tree.max_size();}
            //----------------------------------------------------------------------------------------------------------------

            // Modifiers: ---------------------------------------------------------------------------------------------------
            pair<iterator,bool> insert (const value_type& val)
            {
                return(_tree.insert(val));
            }
            
            iterator insert (iterator position, const value_type& val)
            {
                (void) position;
                return(_tree.insert(val).first);
            }

            template <class InputIterator>
            void insert (InputIterator first, InputIterator last)
            {
                while(first != last)
                {
                    insert(*first);
                    first++;
                }
            }
            
            size_type  erase(const value_type& val)
            {
                return(_tree.erase(val));
            }

            void erase (iterator position)
            {
                erase(*(position));
            }

            void erase (iterator first, iterator last)
            {
                ft::vector<key_type> v;
                while(first != last)
                {
                    v.push_back(*(first));
                    first++;
                }
                for(size_t i = 0; i < v.size(); i++)
                    erase(v[i]);
            }
            
            void swap (set& x)
            {
                _tree.swap(x._tree);
            }

            void clear()
            {
                _tree.clear();
            }
            
            //---------------------------------------------------------------------------------------------------------------

            // Observers: ---------------------------------------------------------------------------------------------------

            key_compare key_comp() const
            {
                return(_mycomp);
            }
            
            value_compare value_comp() const
            {
                return(_mycomp);
            }
            
            //---------------------------------------------------------------------------------------------------------------
            
            // Operations: --------------------------------------------------------------------------------------------------

            iterator find (const value_type& val) const
            {
                return(_tree.find(val));
            }

            size_type count (const value_type& val) const
            {
                return(_tree.count(val));
            }

            iterator lower_bound (const value_type& val) const
            {
                return(_tree.lower_bound(val));
            }

            iterator upper_bound (const value_type& val) const
            {
                return(_tree.upper_bound(val));
            }
            
            pair<iterator,iterator> equal_range (const value_type& val) const
            {
                return (ft::make_pair<iterator, iterator>(lower_bound(val), upper_bound(val)));
            }
            //---------------------------------------------------------------------------------------------------------------
            
        
            // Allocator: ---------------------------------------------------------------------------------------------------
            allocator_type get_allocator() const
            {
                return(_alloc_type);
            }
            
            //---------------------------------------------------------------------------------------------------------------
    };

        template <class T, class Compare, class Alloc>
        bool operator== ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs )
        {
            if(lhs.size() !=  rhs.size())
                return(false);
            return(ft::equal(lhs.begin(), lhs.end() ,rhs.begin()));
        }

        template <class T, class Compare, class Alloc>
        bool operator!= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs )
        {
            if(lhs.size() !=  rhs.size())
                return(true);
            return(!ft::equal(lhs.begin(), lhs.end() ,rhs.begin()));
        }

        template <class T, class Compare, class Alloc>
        bool operator<  ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs )
        {
            return(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
        }

        template <class T, class Compare, class Alloc>
        bool operator<= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs )
        {
           return(!ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
        }

        template <class T, class Compare, class Alloc>
        bool operator>  ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs )
        {
            return(ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
        }

        template <class T, class Compare, class Alloc>
        bool operator>= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs )
        {
            return(!ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
        }
        
        template <class T, class Compare, class Alloc>
        void swap (set<T,Compare,Alloc>& x, set<T,Compare,Alloc>& y)
        {
            x.swap(y);
        }
}