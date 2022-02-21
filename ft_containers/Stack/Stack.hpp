/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:31:58 by wben-sai          #+#    #+#             */
/*   Updated: 2022/01/03 17:23:24 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Vector/Vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
        public :
            typedef T                               value_type;
            typedef Container                       container_type;
            typedef size_t                          size_type;
            
        protected :
            Container container;
        
        public :
            explicit stack (const container_type& ctnr = container_type())
            {
                container = ctnr;
            }
            
            bool empty() const
            {
                return(container.empty());
            }
            
            size_type size() const
            {
                return(container.size());
            }

            void push (const value_type& val)
            {
                container.push_back(val);
            }

            void pop()
            {
                container.pop_back();
            }

            value_type& top()
            {
                return(container[container.size() -1]);
            }

            const value_type& top() const
            {
                return(container[container.size() -1]);
            }
            
            template <class OT, class OContainer>
            friend bool operator== (const stack<OT, OContainer>& lhs, const stack<OT, OContainer>& rhs);

            template <class OT, class OContainer>
            friend bool operator!= (const stack<OT, OContainer>& lhs, const stack<OT, OContainer>& rhs);

            template <class OT, class OContainer>
            friend bool operator> (const stack<OT, OContainer>& lhs, const stack<OT, OContainer>& rhs);

            template <class OT, class OContainer>
            friend bool operator>= (const stack<OT, OContainer>& lhs, const stack<OT, OContainer>& rhs);

            template <class OT, class OContainer>
            friend bool operator< (const stack<OT, OContainer>& lhs, const stack<OT, OContainer>& rhs);

            template <class OT, class OContainer>
            friend bool operator<= (const stack<OT, OContainer>& lhs, const stack<OT, OContainer>& rhs);
    };

    template <class OT, class OContainer>
    bool operator== (const stack<OT, OContainer>& lhs, const stack<OT, OContainer>& rhs)
    {
        return (lhs.container == rhs.container);
    }

    template <class OT, class OContainer>
    bool operator!= (const stack<OT, OContainer>& lhs, const stack<OT, OContainer>& rhs)
    {
        return (lhs.container != rhs.container);
    }

    template <class OT, class OContainer>
    bool operator<  (const stack<OT, OContainer>& lhs, const stack<OT, OContainer>& rhs)
    {
        return (lhs.container < rhs.container);
    }

    template <class OT, class OContainer>
    bool operator<= (const stack<OT, OContainer>& lhs, const stack<OT, OContainer>& rhs)
    {
        return (lhs.container <= rhs.container);
    }

    template <class OT, class OContainer>
    bool operator>  (const stack<OT, OContainer>& lhs, const stack<OT, OContainer>& rhs)
    {
        return (lhs.container > rhs.container);
    }

    template <class OT, class OContainer>
    bool operator>= (const stack<OT, OContainer>& lhs, const stack<OT, OContainer>& rhs)
    {
        return (lhs.container >= rhs.container);
    }
}