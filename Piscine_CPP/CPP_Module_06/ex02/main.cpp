/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 10:35:29 by wben-sai          #+#    #+#             */
/*   Updated: 2021/10/12 11:31:21 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <time.h>
#include <string>

class Base
{
    private:
    public:
        virtual ~Base();
};

Base::~Base(){
    return;
}

class A : public Base{};
class B : public Base{};
class C : public Base{};



Base * generate(void)
{
    srand(time(0));
    int res = (rand() % 3) + 1;
    //std::cout << res;   
    if(res == 1)
        return(new A());
    else if(res == 2)
        return(new B());
    else
        return(new C());
        
}

void identify(Base* p)
{
    A *a = dynamic_cast<A*>(p);
    B *b = dynamic_cast<B*>(p);
    C *c = dynamic_cast<C*>(p);
    if(a != NULL)
        std::cout << "A\n";
    if(b != NULL)
        std::cout << "B\n";
    if(c != NULL)
        std::cout << "C\n";
}

void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A\n";
    }
    catch(const std::exception& e){}
    
    try
    {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B\n";
    }
    catch(const std::exception& e){}

    try
    {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C\n";
    }
    catch(const std::exception& e){}
}

int main()
{
    Base *ptr = generate();
    
    identify(ptr);
    identify(*ptr);
    delete(ptr);
    return (0);
}