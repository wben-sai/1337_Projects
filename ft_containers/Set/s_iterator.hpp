/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:04:18 by wben-sai          #+#    #+#             */
/*   Updated: 2021/12/11 10:59:25 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iterator>
#include <iostream>

namespace ft
{
    template <typename T, typename T2, typename Compare, typename key>
    class s_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
        public:
            typedef Compare             key_compare;
            typedef key                 value_type;
            typedef key*                pointer;
            typedef key&                reference;
            typedef T*                  Rbt_pointer;
            typedef const T*            const_Rbt_pointer;
            typedef T                   Rbt_value_type;
            typedef T&                  Rbt_reference;
            typedef T2                  Node;
            typedef T2*                 Node_pointer;
            
        private :
            const_Rbt_pointer           _tree;
            key_compare                 _comp;
            Node_pointer                _node;
            bool                        _in_end;
        public :
            s_iterator(Node_pointer node, const_Rbt_pointer param, bool in_end = false) :  _tree(param), _node(node), _in_end(in_end){}
            s_iterator(): _tree(NULL), _node(NULL){}
            s_iterator(s_iterator<Rbt_value_type, Node, key_compare, value_type> const & src) :  _tree(src._tree), _node(src._node), _in_end(src._in_end){*this = src;}
            
            s_iterator<Rbt_value_type, Node, key_compare, value_type>& operator=(s_iterator<Rbt_value_type, Node, key_compare, value_type> const & src)
            {
                this->_tree = src._tree;
                this->_node = src._node;
                this->_in_end = src._in_end;
                return (*this);
            }
         
            pointer operator->() {return(_node->data);}

            pointer operator->() const {return(_node->data);}

            reference operator*(){return(*(_node->data));}

            reference operator*() const {return(*(_node->data));}
            
            operator s_iterator<Rbt_value_type, Node, key_compare, const value_type>() 
            {
                return s_iterator<Rbt_value_type, Node, key_compare, const value_type>(_node, _tree, _in_end);
            }

            s_iterator<Rbt_value_type, Node, key_compare, value_type>& operator++()
            {
                Node_pointer temp_node = _node;
                while(true)
                {
                    if(!_node->right && _node->parent && _node->parent->left == _node)
                        _node = _node->parent;
                    else if (_node->right)
                    {
                        _node = _node->right;
                        while(_node->left)
                            _node = _node->left;
                    }
                    else
                    {
                        temp_node = _node;
                        while(_node->parent && !_node->is_end)
                        {
                            if(_comp(*(temp_node->data), *(_node->data)))
                                break;
                            _node = _node->parent;
                        }
                        if(temp_node->is_end || (!_node->parent && !_node->left && !_node->right))
                        {
                            _in_end = true;
                            _node = NULL;
                        }
                    }
                    break;
                }
                return(*this);
            }

            s_iterator<Rbt_value_type, Node, key_compare, value_type> operator++(int)
            {
                s_iterator<Rbt_value_type, Node, key_compare, value_type> temp(*this);
                ++(*this);
                return (temp);
            }

            s_iterator<Rbt_value_type, Node, key_compare, value_type>& operator--()
            {
                Node_pointer temp;
                while(true)
                {
                    if(_in_end == true)
                    {
                        _in_end = false;
                        _node = _tree->get_end();
                        return(*this);
                    }
                    if(!_node->left && !_node->right && _node->parent && _node->parent->right == _node)
                        _node = _node->parent;
                    else if (_node->left)
                    {
                        _node = _node->left;
                        while(_node->right)
                            _node = _node->right;
                    }
                    else
                    {
                        temp = _node;
                        while(_node->parent && !_node->is_begin)
                        {
                            if(_comp(*(_node->data), *(temp->data)))
                                break;
                            _node = _node->parent;
                        }
                        if(temp->is_begin || (!_node->parent && !_node->left && !_node->right))
                            _node = NULL;
                    }
                    break;
                }
                return (*this);
            }

            s_iterator<Rbt_value_type, Node, key_compare, value_type> operator--(int)
            {
                s_iterator<Rbt_value_type, Node, key_compare, value_type> temp(*this);
                --(*this);
                return (temp);
            }

        template <typename iter, typename iter2>
        friend bool operator ==(const iter &a, const iter2 &b);

        template <typename iter, typename iter2>
        friend bool operator !=(const iter &a, const iter2 &b);

    };

    template <typename iter, typename iter2>
    bool operator ==(const iter &a, const iter2 &b){return(a._node == b._node);}

    template <typename iter, typename iter2>
    bool operator !=(const iter &a, const iter2 &b){return(a._node != b._node);}
}
