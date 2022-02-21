/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:44:51 by wben-sai          #+#    #+#             */
/*   Updated: 2022/01/03 10:57:15 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "m_iterator.hpp"
#include <string>
#include "node.hpp"
#include "../tools/Make_pair.hpp"
#include "RBT/RBT.hpp"
#include <iostream>
#include "../Vector/Vector.hpp"
#include "../tools/reverse_iterator.hpp"
#include "../tools/enable_if.hpp"

namespace ft
{
    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
    class map
    {
        public :
            typedef Key                                                                                                     key_type;
            typedef T                                                                                                       mapped_type;
            typedef ft::pair<const key_type,mapped_type>                                                                    value_type;
            typedef Compare                                                                                                 key_compare;
            typedef Alloc                                                                                                   allocator_type;
            typedef value_type&                                                                                             reference;
            typedef const value_type&                                                                                       const_reference;
            typedef value_type*                                                                                             pointer;
            typedef const value_type*                                                                                       const_pointer;
            typedef m_iterator<Rbt<key_type, mapped_type, key_compare>, Node<value_type>, key_compare, const value_type>    const_iterator;
            typedef m_iterator<Rbt<key_type, mapped_type, key_compare>, Node<value_type>, key_compare, value_type>          iterator;
            typedef reverse_iterator<const_iterator>                                                                        const_reverse_iterator;
            typedef reverse_iterator<iterator>                                                                              reverse_iterator;
            typedef std::ptrdiff_t                                                                                          difference_type;
            typedef std::size_t                                                                                             size_type;
            typedef class value_compare : public std::binary_function<value_type,value_type,bool>
            {
                friend class map;
                protected:
                    Compare comp;
                    value_compare (Compare c) : comp(c) {}
                public:
                    bool operator() (const value_type& x, const value_type& y) const
                    {
                        return comp(x.first, y.first);
                    }
            } value_compare;
        
        private :
            ft::Rbt<key_type, mapped_type, key_compare>     _tree;
            key_compare                                     _mycomp;
            allocator_type                                  _alloc_type;
        
        public :
            
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(), _mycomp(comp), _alloc_type(alloc){}

            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(), _mycomp(comp), _alloc_type(alloc){insert (first, last);}

            map (const map& x) : _tree(), _mycomp(x._mycomp), _alloc_type(x._alloc_type) 
            {
                insert (x.begin(), x.end());
            }
            
            map& operator= (const map& x){clear();insert (x.begin(), x.end());return(*this);}

            ~map(){clear();}
            
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

            // Element access: -----------------------------------------------------------------------------------------------
            mapped_type& operator[] (const key_type& k)
            {
                return(_tree.operator[](k));
            }
            //---------------------------------------------------------------------------------------------------------------
            
           
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
            
            size_type  erase(const key_type& k)
            {
                return(_tree.erase(k));
            }

            void erase (iterator position)
            {
                erase(position->first);
            }

            void erase (iterator first, iterator last)
            {
                ft::vector<key_type> v;
                while(first != last)
                {
                    v.push_back(first->first);
                    first++;
                }
                for(size_t i = 0; i < v.size(); i++)
                    erase(v[i]);
            }
            
            void swap (map& x)
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
                return(value_compare(_mycomp));
            }
            
            //---------------------------------------------------------------------------------------------------------------
            
            // Operations: --------------------------------------------------------------------------------------------------

            iterator find (const key_type& k)
            {
                return(_tree.find(k));
            }

            const_iterator find (const key_type& k) const
            {
                return(_tree.find(k));
            }

            size_type count (const key_type& k) const
            {
                return(_tree.count(k));
            }
            
            iterator lower_bound (const key_type& k)
            {
                return(_tree.lower_bound(k));
            }

            const_iterator lower_bound (const key_type& k) const
            {
                return(_tree.lower_bound(k));
            }
            
            iterator upper_bound (const key_type& k)
            {
                return(_tree.upper_bound(k));
            }

            const_iterator upper_bound (const key_type& k) const
            {
                return(_tree.upper_bound(k));
            }
            pair<iterator,iterator> equal_range (const key_type& k)
            {
                return (ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
            }

            pair<const_iterator,const_iterator> equal_range (const key_type& k) const
            {
                return (ft::make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
            }
            
            //---------------------------------------------------------------------------------------------------------------

            // Allocator: ---------------------------------------------------------------------------------------------------
            allocator_type get_allocator() const
            {
                return(_alloc_type);
            }
            
            //---------------------------------------------------------------------------------------------------------------
    };

    template <class Key, class T, class Compare, class Alloc>
    bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
    {
            if(lhs.size() !=  rhs.size())
                return(false);
            return(ft::equal(lhs.begin(), lhs.end() ,rhs.begin()));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator!= ( const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs )
    {
        if(lhs.size() !=  rhs.size())
            return(true);
        return(!ft::equal(lhs.begin(), lhs.end() ,rhs.begin()));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator<  ( const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs )
    {
        return(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator<= ( const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs )
    {
        return(!ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator>  ( const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs )
    {
        return(ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator>= ( const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs )
    {
        return(!ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template <class Key, class T, class Compare, class Alloc>
    void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
    {
        x.swap(y);
    }
    
}