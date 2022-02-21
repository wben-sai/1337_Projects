/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:53:39 by wben-sai          #+#    #+#             */
/*   Updated: 2022/01/03 20:38:22 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "../../tools/Make_pair.hpp"
#include "../node.hpp"
#include "../m_iterator.hpp"

namespace ft
{
    template < class K, class V, class Compare = std::less<K>, class Alloc = std::allocator<ft::pair<const K,V> > >
    class Rbt
    {
        public :
            typedef K                                                                                   key_type;
            typedef V                                                                                   mapped_type;
            typedef ft::pair<const key_type,mapped_type>                                                value_type;
            typedef Compare                                                                             key_compare;
            typedef Alloc                                                                               allocator_type;
            typedef std::size_t                                                                         size_type;
            typedef Node<value_type>                                                                    Node_val;
            typedef Node<value_type>&                                                                   Node_ref;
            typedef Node<value_type>*                                                                   Node;
            typedef m_iterator<Rbt<key_type, mapped_type, key_compare>, Node_val, key_compare, const value_type>     const_iterator;
            typedef m_iterator<Rbt<key_type, mapped_type, key_compare>, Node_val, key_compare, value_type>           iterator;
            
            
            
        private : 
            size_type                                         _rbt_size;
            allocator_type                                    _alloc_type;
            typename Alloc::template rebind<Node_val>::other  _alloc_node;
            Node                                              _tree;
            key_compare                                       _mycomp;
            Node                                              _last_node;
            Node                                              _first_node;
            
        public :
        
            explicit Rbt (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _rbt_size(0), _alloc_type(alloc), _tree(NULL), _mycomp(comp), _last_node(NULL), _first_node(NULL){}
            ~Rbt(){}

            bool empty() const{return(_rbt_size == 0);}
            size_type size() const{return(_rbt_size);}
            size_type max_size() const{return _alloc_type.max_size();}

            iterator begin() const
            {
                Node temp_node = _tree;
                while(temp_node && temp_node->left)
                    temp_node = temp_node->left;
                iterator it(temp_node, this);
                return(it);
            }
            
            iterator end() const
            {
                Node temp_node = _tree;
                while(temp_node && temp_node->right)
                    temp_node = temp_node->right;
                iterator it(temp_node, this);
                if(temp_node)
                    return(++it);
                return(it);
            }

            Node get_end() const 
            {
                Node temp_node = _tree;
                while(temp_node && temp_node->right)
                    temp_node = temp_node->right;
                return(temp_node);
            }

            mapped_type& operator[] (const key_type& k)
            {
                Node temp_node = _tree;
                while(temp_node)
                {
                    if(_mycomp(k, temp_node->data->first))
                        temp_node = temp_node->left;
                    else if (_mycomp(temp_node->data->first, k))
                        temp_node = temp_node->right;
                    else
                    {
                        return (temp_node->data->second);
                    }
                }
                pair<const key_type, mapped_type> pa(k,mapped_type());
                return (insert(pa).first->second);
            }

            void swap (Rbt& x)
            {
                Node  last_node = NULL;
                Node  first_node = NULL;
                Node temp = NULL;
                size_t size;
                
                last_node = _last_node;
                _last_node = x._last_node;
                x._last_node = last_node;

                first_node = _first_node;
                _first_node = x._first_node;
                x._first_node = first_node;

                temp = _tree;
                _tree = x._tree;
                x._tree = temp;
                
                size = _rbt_size;
                _rbt_size = x._rbt_size;
                x._rbt_size = size;
            }

            iterator find (const key_type& k) const
            {
                Node temp_node = _tree;
                while(temp_node)
                {
                    if(_mycomp(k, temp_node->data->first))
                        temp_node = temp_node->left;
                    else if (_mycomp(temp_node->data->first, k))
                        temp_node = temp_node->right;
                    else
                        return (iterator(temp_node, this));
                }
                return (end());
            }

            size_type count (const key_type& k) const
            {
                Node temp = _tree;
                while(temp)
                {
                    if(_mycomp(k, temp->data->first))
                        temp = temp->left;
                    else if (_mycomp(temp->data->first, k))
                        temp = temp->right;
                    else
                        return (1);
                }
                return (0);
            }

            iterator lower_bound (const key_type& k) const
            {
                Node temp_node = _tree;
                Node temp;
                while(temp_node)
                {
                    if(_mycomp(k, temp_node->data->first))
                    {
                        temp = temp_node;
                        temp_node = temp_node->left;
                    }
                    else if (_mycomp(temp_node->data->first, k))
                        temp_node = temp_node->right;
                    else
                        return (iterator(temp_node, this));
                }
                return (iterator(temp, this));
            }

            iterator upper_bound (const key_type& k) const
            {
                Node temp_node = _tree;
                Node temp;
                while(temp_node)
                {
                    if(_mycomp(k, temp_node->data->first))
                    {
                        temp = temp_node;
                        temp_node = temp_node->left;
                    }
                    else if (_mycomp(temp_node->data->first, k))
                        temp_node = temp_node->right;
                    else
                    {
                        iterator it2(temp_node, this);
                        return (++it2);
                    }
                }
                return (iterator(temp, this));
            }

            void clear()
            {
                while(_rbt_size != 0)
                    erase(_tree->data->first);
            }

            size_type  erase(const key_type& k)
            {
                if(_rbt_size == 0)
                    return (0);
                Node temp_node = _tree;
                while(temp_node)
                {
                    if(_mycomp(k, temp_node->data->first))
                        temp_node = temp_node->left;
                    else if (_mycomp(temp_node->data->first, k))
                        temp_node = temp_node->right;
                    else
                    {
                        
                        if(temp_node->is_begin || temp_node->is_end)
                            update_first_last(*temp_node);
                        delete_node(*temp_node);
                        if(_rbt_size > 1)
                            while(_tree->parent)
                                _tree = _tree->parent;
                        if(_rbt_size > 0)
                            _rbt_size--;
                        if(_rbt_size == 0)
                            _tree = NULL;
                        return (1);
                    }
                }
                return (0);
            }

            pair<iterator,bool> insert (const value_type& val)
            {
                if(_rbt_size == 0) //if tree is empty create new node as root node with color black 
                {
                    _tree = create_node(val);
                    if(_rbt_size == 0)
                    {
                        _last_node = _tree;
                        _first_node = _tree;
                    }
                    _rbt_size++;
                    return (ft::make_pair<iterator, bool>(iterator(_tree, this), true));
                }
                else  //if tree is not empty
                {     // create now node as leef node with color red
                    Node newnode = create_node(val);;
                    Node temp_node = _tree;
                    while(true)
                    {
                        if(_mycomp(newnode->data->first, temp_node->data->first))
                        {
                            if(temp_node->left == NULL)
                            {
                                temp_node->left = newnode;
                                newnode->parent = temp_node;
                                break;
                            }
                            else
                                temp_node = temp_node->left;
                        }
                        else if (_mycomp(temp_node->data->first, newnode->data->first))
                        {
                            if(temp_node->right == NULL)
                            {
                                temp_node->right = newnode;
                                newnode->parent = temp_node;
                                break;
                            }
                            else
                                temp_node = temp_node->right;
                        }
                        else
                        {
                            //free awingh
                            _alloc_type.destroy(newnode->data);
                            _alloc_type.deallocate(newnode->data, 1);
                            _alloc_node.deallocate(newnode, 1);
                            return (ft::make_pair<iterator, bool>(iterator(temp_node, this), false));
                        }
                    }

                    if(_mycomp(newnode->data->first, _first_node->data->first))
                    {
                        _first_node->is_begin = false;
                        _first_node = newnode;
                        _first_node->is_begin = true;
                    }
                    if(_mycomp(_last_node->data->first, newnode->data->first))
                    {
                        _last_node->is_end = false;
                        _last_node = newnode;
                        _last_node->is_end = true;
                    }
                    
                    Node recheck = newnode;
                    while (true)
                    {                    
                        if(recheck->parent->isblack)                            // if parent of new node is black then exit
                        { 
                            _rbt_size++;
                            return (ft::make_pair<iterator, bool>(iterator(newnode, this), true));
                        }
                        else                                                    //if parent of new node is Red
                        { 
                            temp_node = get_sibling(recheck->parent);     //then check the color of parent sibling of new node
                            if(temp_node == NULL || temp_node->isblack)   
                                set_retations(*recheck, get_retation(recheck));
                            else                                              //if color is red then recolor and also check if parent's
                            {                                                 // parent of new node is not root node then recolor it   
                                recheck->parent->isblack = true;              // and recheck
                                temp_node->isblack = true;
                                if(!recheck->parent->parent->isroot)
                                {
                                    recheck->parent->parent->isblack = false;
                                    recheck = recheck->parent->parent;
                                    continue;
                                }
                            }
                        }
                        break;
                    }
                    while(recheck->parent)
                        recheck = recheck->parent;
                    _tree = recheck;
                    _rbt_size++;
                    return (ft::make_pair<iterator, bool>(iterator(newnode, this), true));
                }
            }

            
        private : 
            
            Node create_node(const value_type& val)
            {
                Node    new_node;
                new_node = _alloc_node.allocate(1);
                new_node->data = _alloc_type.allocate(1);
                _alloc_type.construct(new_node->data, val);
                new_node->left = NULL;
                new_node->right = NULL;
                new_node->parent = NULL;
                new_node->isdb = false;
                new_node->isblack = (_rbt_size == 0) ? true : false;
                new_node->isroot = (_rbt_size == 0) ? true : false;
                new_node->is_end = (_rbt_size == 0) ? true : false;
                new_node->is_begin = (_rbt_size == 0) ? true : false;
                return(new_node);
            }
    
            Node get_sibling(Node node)
            {
                if(node->parent->left == node)
                        return (node->parent->right);
                else if(node->parent->right == node)
                    return (node->parent->left);
                return (NULL);
            }

            int get_retation(Node node)
            {
                Node temp_node = node->parent->parent;
                if(!temp_node)
                    return(0);
                if(temp_node->right && temp_node->right->right && node == temp_node->right->right)
                    return(1);
                else if(temp_node->left && temp_node->left->left && node ==  temp_node->left->left)
                    return(2);
                else if(temp_node->left && temp_node->left->right && node ==  temp_node->left->right)
                    return(3);
                else if(temp_node->right && temp_node->right->left && node ==  temp_node->right->left)
                    return(4);
                else
                    return(0);
            }

               
            void set_retations(Node_ref node, int type)
            {
                Node temp_node;
                Node temp;
                if(type == 1) // Right Right Case (RR rotation):
                {
                    temp = NULL;
                    temp_node = NULL;
                    if(node.parent->parent->parent != NULL)
                        temp = node.parent->parent->parent;
                    if(node.parent->left != NULL)
                    {
                        temp_node = node.parent->left;
                        temp_node->parent = node.parent->parent;
                    }
                    node.parent->left = node.parent->parent;
                    node.parent->left->right = temp_node;
                    
                    if(temp != NULL)
                    {
                        if(temp->left == node.parent->parent)
                            temp->left = node.parent;
                        else
                            temp->right = node.parent;
                    }
                    node.parent->parent = temp;
                    node.parent->left->parent = node.parent;
                    node.parent->isblack = true;
                    node.parent->left->isblack = false;
                    if(temp == NULL)
                    {
                        node.parent->isroot = true;
                        node.parent->left->isroot = false;
                    }
                }
                if(type == 2) // Left Left Case (LL rotation)
                {
                    temp = NULL;
                    temp_node = NULL;
                    if(node.parent->parent->parent != NULL)
                        temp = node.parent->parent->parent;
                    if(node.parent->right != NULL)
                    {
                        temp_node = node.parent->right;
                        temp_node->parent = node.parent->parent;
                    }
                    node.parent->right = node.parent->parent;
                    node.parent->right->left = temp_node;
                    
                    if(temp != NULL)
                    {
                        if(temp->right == node.parent->parent)
                            temp->right = node.parent;
                        else
                            temp->left = node.parent;
                    }
                    node.parent->parent = temp;
                    node.parent->right->parent = node.parent;
                    node.parent->isblack = true;
                    node.parent->right->isblack = false;
                    if(temp == NULL)
                    {
                        node.parent->isroot = true;
                        node.parent->right->isroot = false;
                    }
                }
                if(type == 3) // Left Right Case (LR rotation)
                {
                    temp = node.left;
                    if(temp != NULL)
                        temp->parent = node.parent;
                    node.parent->parent->left = &node;
                    node.parent->right = temp;
                    node.left =  node.parent;
                    node.parent = node.left->parent;
                    node.left->parent = &node;
                    
                    set_retations(*node.left, 2);
                }
                if(type == 4) // Right Left Case (RL rotation)
                {
                    temp = node.right;
                    if(temp != NULL)
                        temp->parent = node.parent;
                    node.parent->parent->right = &node;
                    node.parent->left = temp;
                    node.right =  node.parent;
                    node.parent = node.right->parent;
                    node.right->parent = &node;
                    
                    set_retations(*node.right, 1);
                }
                if(type == 5)       // triangle rotation to left case
                {
                    temp = node.parent->right->left;
                    if(node.parent->parent)
                    {
                        if(node.parent->parent->right == node.parent)
                            node.parent->parent->right = node.parent->right;
                        else
                            node.parent->parent->left = node.parent->right;
                        node.parent->right->parent = node.parent->parent;
                    }
                    else
                    {
                        node.parent->right->parent = NULL;
                        node.parent->right->isroot = true;
                    }
                    node.parent->right->left = node.parent;
                    node.parent->parent = node.parent->right;
                    node.parent->right = temp;
                    if(temp)
                        temp->parent = node.parent;
                    node.parent->isroot = false;
                }
                if(type == 6)       // triangle rotation to right case
                {
                    temp = node.parent->left->right;
                    if(node.parent->parent)
                    {
                        if(node.parent->parent->right == node.parent)
                            node.parent->parent->right = node.parent->left;
                        else
                            node.parent->parent->left = node.parent->left;
                        node.parent->left->parent = node.parent->parent;
                    }
                    else
                    {
                        node.parent->left->parent = NULL;
                        node.parent->left->isroot = true;
                    }
                    node.parent->left->right = node.parent;
                    node.parent->parent = node.parent->left;
                    node.parent->left = temp;
                    if(temp)
                        temp->parent = node.parent;
                    node.parent->isroot = false;
                }
                else if(type == 7)       // triangle rotation to left case with null 
                {
                    temp = node.right;
                    node.parent->left = temp;
                    temp->parent = node.parent;
                    node.parent = temp;
                    node.right = temp->left;
                    if(temp->left)
                        temp->left->parent = &node;
                    temp->left = &node;
                }
                else if(type == 8)       // triangle rotation to right case with null 
                {
                    temp = node.left;
                    node.parent->right = temp;
                    temp->parent = node.parent;
                    node.parent = temp;
                    node.left = temp->right;
                    if(temp->right)
                        temp->right->parent = &node;
                    temp->right = &node;
                }
            }

            void delete_node(Node_ref node)
            {
                Node max_or_min = NULL;
                value_type *temp;
                Node sibling_temp;
                Node delete_temp = NULL;
                bool is_begin;
                bool is_end;
                Node temp_node = &node;
                
                while (true)
                { 
                    if(_rbt_size == 1)
                        break;
                    if(!temp_node->isblack && !temp_node->left && !temp_node->right)    // case 1 
                    {                                                                   // if node to be delete is red
                        if(temp_node->parent->left == temp_node)                        //and he's childrens is NUll
                            temp_node->parent->left = NULL;
                        else
                            temp_node->parent->right = NULL;
                        break;
                    }
                    else
                    {
                        while((temp_node->left || temp_node->right) && !temp_node->isdb)
                        {
                            if(temp_node->left)
                            {
                                max_or_min = temp_node->left;
                                while(max_or_min->right)
                                    max_or_min = max_or_min->right;
                            }
                            else
                            {
                                max_or_min = temp_node->right;
                                while(max_or_min->left)
                                    max_or_min = max_or_min->left;
                            }
                            
                            is_begin = temp_node->is_begin;
                            temp_node->is_begin = max_or_min->is_begin;
                            max_or_min->is_begin = is_begin; 
                            
                            is_end = temp_node->is_end;
                            temp_node->is_end = max_or_min->is_end;
                            max_or_min->is_end = is_end; 
                            
                            temp = temp_node->data;
                            temp_node->data = max_or_min->data;
                            max_or_min->data = temp; 

                            
                            temp_node = max_or_min;
                        }
                        if(!temp_node->isblack)
                            continue;
                        if (temp_node->isroot && temp_node->isdb)                              //case 2 if root is DB, 
                        {                                                                      // then romove the DB and root node becomes black
                            temp_node->isdb = false;
                            break;
                        }
                        else
                            temp_node->isdb = true;
                        
                        sibling_temp = get_sibling(temp_node);
                        if(sibling_temp && sibling_temp->isblack && ((sibling_temp->left                                    //case 3 if sibling is black 
                        && sibling_temp->right && sibling_temp->left->isblack && sibling_temp->right->isblack)               // and both its childern  
                        || (!sibling_temp->left && !sibling_temp->right)))                                                  //are also black
                        {
                            temp_node->isdb = false;
                            if(!temp_node->parent->isblack)
                            {
                                temp_node->parent->isblack = true;
                                if(temp_node->parent->left == temp_node && !delete_temp)
                                    temp_node->parent->left = NULL;
                                else if(temp_node->parent->right == temp_node && !delete_temp)
                                    temp_node->parent->right = NULL;
                                delete_temp = temp_node;
                                sibling_temp->isblack = false;
                                break;
                            }
                            else
                            {
                                temp_node->parent->isdb = true;
                                sibling_temp->isblack = false;
                                if(!delete_temp)
                                {
                                    if(temp_node->parent->left == temp_node)
                                        temp_node->parent->left = NULL;
                                    else
                                        temp_node->parent->right = NULL;
                                }
                                delete_temp = temp_node;
                                temp_node = temp_node->parent;
                                continue;
                            }
                        }
                        else if(sibling_temp && !sibling_temp->isblack)  // case 4 if DB's sibling is red
                        {
                            temp_node->parent->isblack = false;
                            sibling_temp->isblack = true;
                            if(temp_node->parent->left == temp_node)
                                set_retations(*temp_node, 5);
                            else
                                set_retations(*temp_node, 6);
                            continue;
                        }
                        else if(sibling_temp && sibling_temp->isblack && ((sibling_temp->left && !sibling_temp->left->isblack ) ||  (sibling_temp->right && !sibling_temp->right->isblack )))
                        {
                            if(((temp_node->parent->left == temp_node) && sibling_temp->left && !sibling_temp->left->isblack && (!sibling_temp->right || (sibling_temp->right && sibling_temp->right->isblack)))       //case 5 if DB's sibling is blck and sibling's child
                            || ((temp_node->parent->right == temp_node) && sibling_temp->right && !sibling_temp->right->isblack && (!sibling_temp->left || (sibling_temp->left && sibling_temp->left->isblack))))    //  who is for from DB is black , but near child to DB is red
                            {
                                sibling_temp->isblack = false;
                                if(temp_node->parent->left == temp_node)
                                {
                                    sibling_temp->left->isblack = true;
                                    if (sibling_temp->right)
                                        set_retations(*sibling_temp->right, 6);
                                    else
                                        set_retations(*sibling_temp, 8);
                                }
                                else
                                {
                                    sibling_temp->right->isblack = true;
                                    if (sibling_temp->left)
                                        set_retations(*sibling_temp->left, 5);
                                    else
                                        set_retations(*sibling_temp, 7);
                                }
                            }
                            else    //case 6 if DB's sibling is blck and sibling's child
                            {      //  who is for from DB is red , but near child to DB is blck
                                bool temp_color = sibling_temp->isblack;
                                sibling_temp->isblack = temp_node->parent->isblack; 
                                temp_node->parent->isblack = temp_color;
                                if(temp_node->parent->left == temp_node)
                                {
                                    set_retations(*temp_node, 5);
                                    sibling_temp->right->isblack = true;
                                    if(!delete_temp)
                                        temp_node->parent->left = NULL;
                                    delete_temp = temp_node;
                                }
                                else
                                {
                                    set_retations(*temp_node, 6);
                                    sibling_temp->left->isblack = true;
                                    if(!delete_temp)
                                        temp_node->parent->right = NULL;
                                    delete_temp = temp_node;
                                }
                                temp_node->isdb = false;
                                break;
                            }
                        }
                    }    
                }
                if(max_or_min)
                {
                    _alloc_type.destroy(max_or_min->data);
                    _alloc_type.deallocate(max_or_min->data, 1);
                    _alloc_node.deallocate(max_or_min, 1);
                }
                else
                {
                    _alloc_type.destroy(node.data);
                    _alloc_type.deallocate(node.data, 1);
                    _alloc_node.deallocate(&node, 1);
                }
            }

            void update_first_last(Node_ref ptr)
            {
                Node temp = &ptr;
                if(temp->is_begin)
                {
                    if(!temp->left && !temp->right && temp->parent && temp->parent->left == temp)
                    {
                        temp->parent->is_begin = true;
                        _first_node = temp;
                    }
                    else if (temp->right)
                    {
                        temp = temp->right;
                        while(temp->left)
                            temp = temp->left;
                        temp->is_begin = true;
                        _first_node = temp;
                    }
                    else
                    {
                        while(temp->parent)
                        {
                            temp = temp->parent;
                            if(_mycomp(temp->data->first, temp->data->first))
                            {
                                temp->is_begin = true;
                                _first_node = temp;
                                break;
                            }
                        }
                    }
                }
                else
                {
                    if(!temp->left && !temp->right && temp->parent && temp->parent->right == temp)
                    {
                        temp->parent->is_end = true;
                        _last_node = temp;
                    }
                    else if (temp->left)
                    {
                        temp = temp->left;
                        while(temp->right)
                            temp = temp->right;
                        temp->is_end = true;
                        _last_node = temp;
                    }
                    else
                    {
                        while(temp->parent)
                        {
                            temp = temp->parent;
                            if(_mycomp(temp->data->first, temp->data->first))
                            {
                                temp->is_end = true;
                                _last_node = temp;
                                break;
                            }
                        }
                    }
                }
            }
            
            public :
            
                void printBT(const std::string& prefix, const Node node1, bool isLeft)
                {
                    if( node1 != NULL )
                    {
                        std::cout << prefix;

                        std::cout << (isLeft ? "├──" : "└──" );

                        // print the value of the node1
                        std::cout << node1->data->first << " ";
                        std::cout << (isLeft ? "(L) " : "(R) ") << (node1->isblack ? "(black)" : "(red)") << "is_begin="<<node1->is_begin << " is_end="<<node1->is_end;
                        if(node1->parent)
                            std::cout << " parent " << node1->parent->data->first;
                        std::cout << "\n";
                        // enter the next tree level - left and right branch
                        printBT( prefix + (isLeft ? "│   " : "    "), node1->left, true);
                        printBT( prefix + (isLeft ? "│   " : "    "), node1->right, false);
                    }
                }
                void printBT()
                {
                    printBT("", _tree, false);
                }
    };
}