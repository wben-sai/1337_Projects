/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:40:42 by wben-sai          #+#    #+#             */
/*   Updated: 2022/01/04 15:24:15 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#include <sys/time.h>

#if 0 //CREATE A REAL STL EXAMPLE
# include <map>
# include <set>
# include <stack>
# include <vector>
namespace ft = std;
#else
# include "Map/Map.hpp"
//# include "Set/Set.hpp"
# include "Stack/Stack.hpp"
# include "Vector/Vector.hpp"
#endif

#include <stdlib.h>

#define GREEN "\e[1;32m"
#define YELLOW "\e[0;33m"
#define RESET "\e[0m"

time_t get_time(void)
{
	struct timeval time_now;

	gettimeofday(&time_now, NULL);
	time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
	return (msecs_time);
}

void vector_test()
{
	std::cout.width(40); std::cout << std::internal << GREEN << "TESTING VECTOR" << RESET << std::endl;
	std::cout << YELLOW << "Constructors" << RESET << std::endl;
	{
		ft::vector<int> first;
		time_t s1 = get_time();
		ft::vector<int> second (1e5,1337);
		time_t e1 = get_time();
		std::cout << "fill constructor time: " << e1 - s1 << "ms" << std::endl;

		time_t s2 = get_time();
		ft::vector<int> third (second.begin(),second.end());
		time_t e2 = get_time();
		std::cout << "range constructor time: " << e2 - s2 << "ms" << std::endl;

		time_t s3 = get_time();
		ft::vector<int> fourth (third);
		time_t e3 = get_time();
		std::cout << "copy constructor time: " << e3 - s3 << "ms" << std::endl;

		int myints[] = {16,2,77,29};
		ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

		for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
	}
	std::cout << YELLOW << "Operator =()" << RESET << std::endl;
	{
		ft::vector<int> foo (1e6,0);
		ft::vector<int> bar (1e5,0);

		time_t s1 = get_time();
		bar = foo;
		time_t e1 = get_time();
		std::cout << "time: " << e1 - s1 << "ms" << std::endl;
		foo = ft::vector<int>();

		std::cout << "Size of foo: " << int(foo.size()) << '\n';
		std::cout << "Size of bar: " << int(bar.size()) << '\n';
	}
	std::cout << YELLOW << "begin() and end()" << RESET << std::endl;
	{
		ft::vector<int> myvector;
		for (int i=1; i<=30; i++) myvector.push_back(i);

		time_t s1 = get_time();
		ft::vector<int>::iterator it = myvector.begin();
		time_t e1 = get_time();
		std::cout << "begin() time: " << e1 - s1 << "ms" << std::endl;

		time_t s2 = get_time();
		ft::vector<int>::iterator eit = myvector.end();
		time_t e2 = get_time();
		std::cout << "end() time: " << e2 - s2 << "ms" << std::endl;

		for (; it != eit; ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	std::cout << YELLOW << "rbegin() and rend()" << RESET << std::endl;
	{
		ft::vector<int> myvector;
		for (int i=1; i<=30; i++) myvector.push_back(i);

		time_t s1 = get_time();
		ft::vector<int>::reverse_iterator it = myvector.rbegin();
		time_t e1 = get_time();
		std::cout << "rbegin() time: " << e1 - s1 << "ms" << std::endl;

		time_t s2 = get_time();
		ft::vector<int>::reverse_iterator eit = myvector.rend();
		time_t e2 = get_time();
		std::cout << "rend() time: " << e2 - s2 << "ms" << std::endl;

		for (; it != eit; ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	std::cout << YELLOW << "size() and max_size()" << RESET << std::endl;
	{
		ft::vector<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<10; i++) myints.push_back(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.insert (myints.end(),10, 100);
		std::cout << "2. size: " << myints.size() << '\n';

		myints.pop_back();
		std::cout << "3. size: " << myints.size() << '\n';

		std::cout << "vector<int> max_size: " << ft::vector<int>().max_size() << std::endl;
		std::cout << "vector<string> max_size: " << ft::vector<std::string>().max_size() << std::endl;
		std::cout << "vector<float> max_size: " << ft::vector<float>().max_size() << std::endl;
	}
	std::cout << YELLOW << "resize() and capacity()" << RESET << std::endl;
	{
		ft::vector<std::string> v(1e4, "1337");

		time_t s1 = get_time();
		v.resize(1e6, "42");
		time_t e1 = get_time();
		std::cout << "resize() time: " << e1 - s1 << "ms" << std::endl;

		ft::vector<int> myvector;

		for (int i=1;i<10;i++) myvector.push_back(i);

		myvector.resize(5);
		std::cout << "size: " << myvector.size() << ", capacity: " << myvector.capacity() << '\n';
		myvector.resize(8, 100);
		std::cout << "size: " << myvector.size() << ", capacity: " << myvector.capacity() << '\n';
		myvector.resize(33);
		std::cout << "size: " << myvector.size() << ", capacity: " << myvector.capacity() << '\n';

		std::cout << "myvector contains:";
		for (int i=0;i<(int)myvector.size();i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	std::cout << YELLOW << "empty()" << RESET << std::endl;
	{
		ft::vector<int> myvector;
		int sum (0);

		for (int i=1;i<=30;i++) myvector.push_back(i);

		while (!myvector.empty())
		{
			sum += myvector.back();
			myvector.pop_back();
		}

		std::cout << "total: " << sum << '\n';
	}
	std::cout << YELLOW << "reserve()" << RESET << std::endl;
	{
		ft::vector<int> v(1e3, 1337);

		time_t s1 = get_time();
		v.reserve(1e6);
		time_t e1 = get_time();
		std::cout << "reserve() time: " << e1 - s1 << "ms" << std::endl;

		ft::vector<int>::size_type sz;

		ft::vector<int> foo;
		sz = foo.capacity();
		std::cout << "making foo grow:\n";
		for (int i=0; i<100; ++i) {
			foo.push_back(i);
			if (sz!=foo.capacity()) {
				sz = foo.capacity();
				std::cout << "capacity changed: " << sz << '\n';
			}
		}

		ft::vector<int> bar;
		sz = bar.capacity();
		bar.reserve(100);
		std::cout << "making bar grow:\n";
		for (int i=0; i<100; ++i) {
			bar.push_back(i);
			if (sz!=bar.capacity()) {
				sz = bar.capacity();
				std::cout << "capacity changed: " << sz << '\n';
			}
		}
	}
	std::cout << YELLOW << "operator []()" << RESET << std::endl;
	{
		ft::vector<int> myvector (10);

		ft::vector<int>::size_type sz = myvector.size();

		// assign some values:
		for (unsigned i=0; i<sz; i++) myvector[i]=i;

		std::cout << "myvector contains:";
		for (unsigned i=0; i<sz; i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	std::cout << YELLOW << "at()" << RESET << std::endl;
	{
		ft::vector<std::string> v(1e6, "1337");

		time_t s1 = get_time();
		v.at(1e5);
		time_t e1 = get_time();
		std::cout << "at() time: " << e1 - s1 << "ms" << std::endl;

		ft::vector<int> myvector(10);

		// assign some values:
		for (unsigned i=0; i<myvector.size(); i++)
			myvector.at(i)=i;

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector.at(i);
		std::cout << '\n';
	}
	std::cout << YELLOW << "front() and back()" << RESET << std::endl;
	{
		ft::vector<int> myvector;

		myvector.push_back(12);
		myvector.push_back(45);
		myvector.push_back(578);
		myvector.push_back(917);

		std::cout << "myvector.front(): " << myvector.front() << '\n';
		std::cout << "myvector.back(): " << myvector.back() << '\n';
	}
	std::cout << YELLOW << "assign()" << RESET << std::endl;
	{
		ft::vector<int> v;
		ft::vector<int> v1;

		time_t s1 = get_time();
		v.assign(1e6,1337);
		time_t e1 = get_time();
		std::cout << "assign(fill) time: " << e1 - s1 << "ms" << std::endl;

		time_t s2 = get_time();
		v1.assign(v.begin(),v.end());
		time_t e2 = get_time();
		std::cout << "assign(range) time: " << e2 - s2 << "ms" << std::endl;

		ft::vector<int> first;
		ft::vector<int> second;
		ft::vector<int> third;

		first.assign (7,100);

		ft::vector<int>::iterator it;
		it=first.begin()+1;

		second.assign (it,first.end()-1);

		int myints[] = {1776,7,4};
		third.assign (myints,myints+3);

		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << '\n';
		std::cout << "Size of third: " << int (third.size()) << '\n';
	}
	std::cout << YELLOW << "push_back() and pop_back()" << RESET << std::endl;
	{
		ft::vector<int> v(1e6,42);

		time_t s1 = get_time();
		v.push_back(1337);
		time_t e1 = get_time();
		std::cout << "push_back() time: " << e1 - s1 << "ms" << std::endl;
		std::cout << "back(): "<< v.back() << '\n';
		time_t s2 = get_time();
		v.pop_back();
		time_t e2 = get_time();
		std::cout << "pop_back() time: " << e2 - s2 << "ms" << std::endl;
		std::cout << "back() after pop(): "<< v.back() << '\n';
	}
	std::cout << YELLOW << "insert()" << RESET << std::endl;
	{
		{
			ft::vector<int> v(1e6,1337);
			ft::vector<int> v1;

			time_t s1 = get_time();
			v.insert(v.begin()+1e5, 42);
			time_t e1 = get_time();
			std::cout << "insert(single elem) time: " << e1 - s1 << "ms" << std::endl;

			v.reserve(1e8);
			time_t s2 = get_time();
			v.insert(v.begin()+10, 1e2, 42);
			time_t e2 = get_time();
			std::cout << "insert(fill) time: " << e2 - s2 << "ms" << std::endl;

			time_t s3 = get_time();
			v1.insert(v1.begin(), v.begin(), v.end());
			time_t e3 = get_time();
			std::cout << "insert(range) time: " << e3 - s3 << "ms" << std::endl;
		}

		ft::vector<int> myvector (3,100);
		ft::vector<int>::iterator it;

		it = myvector.begin();
		it = myvector.insert ( it , 200 );

		myvector.insert (it,2,300);

		it = myvector.begin();

		ft::vector<int> anothervector (2,400);
		myvector.insert (it+2,anothervector.begin(),anothervector.end());

		int myarray [] = { 501,502,503 };
		myvector.insert (myvector.begin(), myarray, myarray+3);

		std::cout << "myvector contains:";
		for (it=myvector.begin(); it<myvector.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	std::cout << YELLOW << "erase()" << RESET << std::endl;
	{
		{
			ft::vector<int> v(1e6,1337);

			time_t s1 = get_time();
			v.erase(v.begin()+1e5);
			time_t e1 = get_time();
			std::cout << "erase(single elem) time: " << e1 - s1 << "ms" << std::endl;

			time_t s3 = get_time();
			v.erase(v.begin()+1, v.end());
			time_t e3 = get_time();
			std::cout << "erase(range) time: " << e3 - s3 << "ms" << std::endl;

		}
		ft::vector<int> myvector;

		for (int i=1; i<=10; i++) myvector.push_back(i);

		myvector.erase (myvector.begin()+5);

		myvector.erase (myvector.begin(),myvector.begin()+3);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	std::cout << YELLOW << "swap()" << RESET << std::endl;
	{
		{
			ft::vector<int> v(1e6,1337);
			ft::vector<int> v1(1e6,42);

			time_t s1 = get_time();
			v.swap(v1);
			time_t e1 = get_time();
			std::cout << "swap() time: " << e1 - s1 << "ms" << std::endl;

		}
		ft::vector<int> foo (3,100);
		ft::vector<int> bar (5,200);

		foo.swap(bar);

		std::cout << "foo contains:";
		for (unsigned i=0; i<foo.size(); i++)
			std::cout << ' ' << foo[i];
		std::cout << '\n';

		std::cout << "bar contains:";
		for (unsigned i=0; i<bar.size(); i++)
			std::cout << ' ' << bar[i];
		std::cout << '\n';
	}
	std::cout << YELLOW << "clear()" << RESET << std::endl;
	{
		{
			ft::vector<int> v(1e6,1337);

			time_t s1 = get_time();
			v.clear();
			time_t e1 = get_time();
			std::cout << "clear() time: " << e1 - s1 << "ms" << std::endl;

		}
		ft::vector<int> myvector;
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';

		myvector.clear();
		myvector.push_back (1101);
		myvector.push_back (2202);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	std::cout << YELLOW << "get_allocator()" << RESET << std::endl;
	{
		ft::vector<int> myvector;
		int * p;
		unsigned int i;

		p = myvector.get_allocator().allocate(5);

		for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

		std::cout << "The allocated array contains:";
		for (i=0; i<5; i++) std::cout << ' ' << p[i];
		std::cout << '\n';

		for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
		myvector.get_allocator().deallocate(p,5);
	}
	std::cout << YELLOW << "relational operators" << RESET << std::endl;
	{
		ft::vector<int> foo (3,100);
		ft::vector<int> bar (2,200);

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}
	std::cout << YELLOW << "swap() overload" << RESET << std::endl;
	{
		ft::vector<int> foo (3,100);
		ft::vector<int> bar (5,200);

		swap(foo, bar);

		std::cout << "foo contains:";
		for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "bar contains:";
		for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
}

void map_test()
{
	std::cout.width(40); std::cout << std::internal << GREEN << "TESTING MAP" << RESET << std::endl;
	std::cout << YELLOW << "Constructors" << RESET << std::endl;
	{
		ft::map<char,int> first;

		first['a']=10;
		first['b']=30;
		first['c']=50;
		first['d']=70;

		time_t s1 = get_time();
		ft::map<char,int> second (first.begin(),first.end());
		time_t e1 = get_time();
		std::cout << "range const() time: " << e1 - s1 << "ms" << std::endl;

		time_t s2 = get_time();
		ft::map<char,int> third (second);
		time_t e2 = get_time();
		std::cout << "copy const() time: " << e2 - s2 << "ms" << std::endl;

	}
	std::cout << YELLOW << "Operator =()" << RESET << std::endl;
	{
		{
			ft::map<int,int> m;
			ft::map<int,int> m1;
			
			for (int i = 1; i <= 1e4; i++)
				m.insert(ft::make_pair(i,i));

			time_t s1 = get_time();
			m1 = m;
			time_t e1 = get_time();
			std::cout << "time: " << e1 - s1 << "ms" << std::endl;
		}
		ft::map<char,int> first;
		ft::map<char,int> second;

		first['x']=8;
		first['y']=16;
		first['z']=32;

		second=first;
		first=ft::map<char,int>();

		std::cout << "Size of first: " << first.size() << '\n';
		std::cout << "Size of second: " << second.size() << '\n';
	}
	std::cout << YELLOW << "begin() and end()" << RESET << std::endl;
	{
		ft::map<char,int> mymap;

		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;

		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	std::cout << YELLOW << "rbegin() and rend()" << RESET << std::endl;
	{
		ft::map<char,int> mymap;

		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;

		for (ft::map<char,int>::reverse_iterator it=mymap.rbegin(); it!=mymap.rend(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	std::cout << YELLOW << "empty()" << RESET << std::endl;
	{
		ft::map<int,int> m;
		ft::map<char,int> m1;
		
		if (m.empty()) std::cout << "map is empty\n";
		
		m1['a']=10;
		m1['b']=20;
		m1['c']=30;	
		
		while (!m1.empty())
		{
			std::cout << m1.begin()->first << " => " << m1.begin()->second << '\n';
			m1.erase(m1.begin());
		}
	}
	std::cout << YELLOW << "size() and max_size()" << RESET << std::endl;
	{
		ft::map<char,int> mymap;
		mymap['a']=101;
		mymap['b']=202;
		mymap['c']=302;

		std::cout << "mymap.size() is " << mymap.size() << '\n';
		std::cout << "mymap.max_size() is " << mymap.max_size() << '\n';
	}
	std::cout << YELLOW << "operaor []" << RESET << std::endl;
	{
		{
			ft::map<int,int> m;
			
			for (int i = 1; i <= 1e4; i++)
				m.insert(ft::make_pair(i,i));

			time_t s1 = get_time();
			m[1e3] = 42;
			time_t e1 = get_time();
			std::cout << "time: " << e1 - s1 << "ms" << std::endl;
		}
		ft::map<char,std::string> mymap;

		mymap['a']="an element";
		mymap['b']="another element";
		mymap['c']=mymap['b'];

		std::cout << "mymap['a'] is " << mymap['a'] << '\n';
		std::cout << "mymap['b'] is " << mymap['b'] << '\n';
		std::cout << "mymap['c'] is " << mymap['c'] << '\n';
		std::cout << "mymap['d'] is " << mymap['d'] << '\n';

		std::cout << "mymap now contains " << mymap.size() << " elements.\n";
	}
	std::cout << YELLOW << "insert()" << RESET << std::endl;
	{
		{
			ft::map<int,int> m;
			ft::map<int,int> m1;
			
			for (int i = 1; i <= 1e5; i++)
			{
				m.insert(ft::make_pair(i,i));
				m1.insert(ft::make_pair(i,i));
			}

			time_t s1 = get_time();
			m.insert(ft::make_pair(1e4+5, 1337));
			time_t e1 = get_time();
			std::cout << "insert(single elem) time: " << e1 - s1 << "ms" << std::endl;
		
			time_t s2 = get_time();
			m1.insert(m.begin(), m.end());
			time_t e2 = get_time();
			std::cout << "insert(range) time: " << e2 - s2 << "ms" << std::endl;
		}
		ft::map<char,int> mymap;

		// first insert function version (single parameter):
		mymap.insert ( ft::pair<char,int>('a',100) );
		mymap.insert ( ft::pair<char,int>('z',200) );

		ft::pair<ft::map<char,int>::iterator,bool> ret;
		ret = mymap.insert ( ft::pair<char,int>('z',500) );
		if (ret.second==false) {
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << '\n';
		}

		// second insert function version (with hint position):
		ft::map<char,int>::iterator it = mymap.begin();
		mymap.insert (it, ft::pair<char,int>('b',300));
		mymap.insert (it, ft::pair<char,int>('c',400));

		// third insert function version (range insertion):
		ft::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));

		// showing contents:
		std::cout << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "anothermap contains:\n";
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	std::cout << YELLOW << "erase()" << RESET << std::endl;
	{
		{
			ft::map<int,int> m;
			
			for (int i = 1; i <= 1e5; i++)
				m.insert(ft::make_pair(i,i));

			ft::map<int,int>::iterator it = m.find(1e3-2);
			time_t s1 = get_time();
			m.erase(it);
			time_t e1 = get_time();
			std::cout << "erase(it) time: " << e1 - s1 << "ms" << std::endl;
		
			time_t s2 = get_time();
			m.erase(40);
			time_t e2 = get_time();
			std::cout << "erase(key) time: " << e2 - s2 << "ms" << std::endl;
			
			time_t s3 = get_time();
			m.erase(++m.begin(), --m.end());
			time_t e3 = get_time();
			std::cout << "erase(range) time: " << e3 - s3 << "ms" << std::endl;
		}

		ft::map<char,int> mymap;
		ft::map<char,int>::iterator it;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;

		it=mymap.find('b');
		mymap.erase (it);

		mymap.erase ('c');

		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );

		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	std::cout << YELLOW << "swap()" << RESET << std::endl;
	{
		{
			ft::map<int,std::string> m;
			ft::map<int,std::string> m1;
			
			for (int i = 1; i <= 1e5; i++) m.insert(ft::make_pair(i,"TEst"));
			for (int i = -1e3; i <= 1e2; i++) m.insert(ft::make_pair(i,"TEst1"));

			time_t s1 = get_time();
			m.swap(m1);
			time_t e1 = get_time();
			std::cout << " time: " << e1 - s1 << "ms" << std::endl;
		}

		ft::map<char,int> foo,bar;

		foo['x']=100;
		foo['y']=200;

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;

		foo.swap(bar);

		std::cout << "foo contains:\n";
		for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "bar contains:\n";
		for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	std::cout << YELLOW << "clear()" << RESET << std::endl;
	{
		{
			ft::map<int,std::string> m;
			for (int i = 1; i <= 1e5; i++) m.insert(ft::make_pair(i,"TEst"));

			time_t s1 = get_time();
			m.clear();
			time_t e1 = get_time();
			std::cout << "time: " << e1 - s1 << "ms" << std::endl;
		}

		ft::map<char,int> mymap;

		mymap['x']=100;
		mymap['y']=200;
		mymap['z']=300;

		std::cout << "mymap contains:\n";
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		mymap.clear();
		mymap['a']=1101;
		mymap['b']=2202;

		std::cout << "mymap contains:\n";
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	std::cout << YELLOW << "key_compare()" << RESET << std::endl;
	{
		ft::map<char,int> mymap;

		ft::map<char,int>::key_compare mycomp = mymap.key_comp();

		mymap['a']=100;
		mymap['b']=200;
		mymap['c']=300;

		std::cout << "mymap contains:\n";

		char highest = mymap.rbegin()->first;

		ft::map<char,int>::iterator it = mymap.begin();
		do {
			std::cout << it->first << " => " << it->second << '\n';
		} while ( mycomp((*it++).first, highest) );
	}
	std::cout << YELLOW << "vlaue_compare()" << RESET << std::endl;
	{
		ft::map<char,int> mymap;

		mymap['x']=1001;
		mymap['y']=2002;
		mymap['z']=3003;

		std::cout << "mymap contains:\n";

		ft::pair<char,int> highest = *mymap.rbegin();

		ft::map<char,int>::iterator it = mymap.begin();
		do {
			std::cout << it->first << " => " << it->second << '\n';
		} while ( mymap.value_comp()(*it++, highest) );
	}
	std::cout << YELLOW << "find()" << RESET << std::endl;
	{
		{
			ft::map<int,std::string> m;
			for (int i = 1; i <= 1e5; i++) m.insert(ft::make_pair(i,"TEst"));

			time_t s1 = get_time();
			m.find(4);
			time_t e1 = get_time();
			std::cout << "time: " << e1 - s1 << "ms" << std::endl;
		}

		ft::map<char,int> mymap;
		ft::map<char,int>::iterator it;

		mymap['a']=50;
		mymap['b']=100;
		mymap['c']=150;
		mymap['d']=200;

		it = mymap.find('b');
		if (it != mymap.end())
			mymap.erase (it);

		// print content:
		std::cout << "elements in mymap:" << '\n';
		std::cout << "a => " << mymap.find('a')->second << '\n';
		std::cout << "c => " << mymap.find('c')->second << '\n';
		std::cout << "d => " << mymap.find('d')->second << '\n';
	}
	std::cout << YELLOW << "count()" << RESET << std::endl;
	{
		ft::map<char,int> mymap;
		char c;

		mymap ['a']=101;
		mymap ['c']=202;
		mymap ['f']=303;

		for (c='a'; c<'h'; c++)
		{
			std::cout << c;
			if (mymap.count(c)>0)
				std::cout << " is an element of mymap.\n";
			else
				std::cout << " is not an element of mymap.\n";
		}
	}
	std::cout << YELLOW << "lower_bound() and upper_bound()" << RESET << std::endl;
	{
		{
			ft::map<int,std::string> m;
			for (int i = 1; i <= 1e5; i++) m.insert(ft::make_pair(i,"TEst"));

			time_t s1 = get_time();
			m.lower_bound(1e4);
			time_t e1 = get_time();
			std::cout << "lower_bound() time: " << e1 - s1 << "ms" << std::endl;

			time_t s2 = get_time();
			m.upper_bound(1e4);
			time_t e2 = get_time();
			std::cout << "upper_bound() time: " << e2 - s2 << "ms" << std::endl;
		}

		ft::map<char,int> mymap;
		ft::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow=mymap.lower_bound ('b');
		itup=mymap.upper_bound ('d');

		mymap.erase(itlow,itup);

		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	std::cout << YELLOW << "equal_rang()" << RESET << std::endl;
	{
		{
			ft::map<int,std::string> m;
			for (int i = 1; i <= 1e5; i++) m.insert(ft::make_pair(i,"TEst"));

			time_t s1 = get_time();
			m.equal_range(1e4);
			time_t e1 = get_time();
			std::cout << "time: " << e1 - s1 << "ms" << std::endl;
		}

		ft::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
		ret = mymap.equal_range('b');

		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
	}
	std::cout << YELLOW << "relational operators()" << RESET << std::endl;
	{
		ft::map<int,std::string> m;
		ft::map<int,std::string> m1;

		for (int i = 1; i <= 1e5; i++) m.insert(ft::make_pair(i,"TEst"));
		for (int i = -1e3; i <= 1e2; i++) m.insert(ft::make_pair(i,"TEst1"));

		time_t s1 = get_time();
		std::cout << (m == m1) << ' ';
		time_t e1 = get_time();
		std::cout << "op ==() time: " << e1 - s1 << "ms" << std::endl;

		time_t s2 = get_time();
		std::cout << (m != m1) << ' ';
		time_t e2 = get_time();
		std::cout << "op !=() time: " << e2 - s2 << "ms" << std::endl;

		time_t s3 = get_time();
		std::cout << (m < m1) << ' ';
		time_t e3 = get_time();
		std::cout << "op <() time: " << e3 - s3 << "ms" << std::endl;

		time_t s4 = get_time();
		std::cout << (m <= m1) << ' ';
		time_t e4 = get_time();
		std::cout << "op <=() time: " << e4 - s4 << "ms" << std::endl;

		time_t s5 = get_time();
		std::cout << (m > m1) << ' ';
		time_t e5 = get_time();
		std::cout << "op >() time: " << e5 - s5 << "ms" << std::endl;

		time_t s6 = get_time();
		std::cout << (m >= m1) << ' ';
		time_t e6 = get_time();
		std::cout << "op >=() time: " << e6 - s6 << "ms" << std::endl;
	}
}

void stack_test()
{
	std::cout.width(40); std::cout << std::internal << GREEN << "TESTING STACK" << RESET << std::endl;
	std::cout << YELLOW << "Constructors" << RESET << std::endl;
	{
		std::deque<int> mydeque (3,100);
		ft::vector<int> myvector (2,200);

		ft::stack<int> first;
		ft::stack<int, ft::vector<int> > second (myvector);

		ft::stack<int,ft::vector<int> > third;
		ft::stack<int,std::deque<int> > fourth (mydeque);

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
	}
	std::cout << YELLOW << "empty()" << RESET << std::endl;
	{
		ft::stack<int> s;
		ft::stack<int> s1;
		s1.push(12);
		s1.push(454);
		s1.push(1337);

		if (s.empty()) std::cout << "s is empty\n";
		else std::cout << "s is not empty\n";
		if (s1.empty()) std::cout << "s1 is empty\n";
		else std::cout << "s1 is not empty\n";
	}
	std::cout << YELLOW << "size()" << RESET << std::endl;
	{
		ft::stack<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';
	}
	std::cout << YELLOW << "top()" << RESET << std::endl;
	{
		ft::stack<int> mystack;

		mystack.push(10);
		mystack.push(20);

		mystack.top() -= 5;

		std::cout << "mystack.top() is now " << mystack.top() << '\n';
	}
	std::cout << YELLOW << "push() and pop()" << RESET << std::endl;
	{
		ft::stack<int> mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';
	}
}
/*
void set_test()
{
	std::cout.width(40); std::cout << std::internal << GREEN << "TESTING SET" << RESET << std::endl;
	std::cout << YELLOW << "Constructors" << RESET << std::endl;
	{
		ft::set<char> first;

		first.insert('a');
		first.insert('b');
		first.insert('c');
		first.insert('d');

		time_t s1 = get_time();
		ft::set<char> second (first.begin(),first.end());
		time_t e1 = get_time();
		std::cout << "range const() time: " << e1 - s1 << "ms" << std::endl;

		time_t s2 = get_time();
		ft::set<char> third (second);
		time_t e2 = get_time();
		std::cout << "copy const() time: " << e2 - s2 << "ms" << std::endl;

		ft::set<char,classcomp> fourth;

		bool(*fn_pt)(char,char) = fncomp;
		ft::set<char,bool(*)(char,char)> fifth (fn_pt);
	}
	std::cout << YELLOW << "Operator =()" << RESET << std::endl;
	{
		{
			ft::set<int> m;
			ft::set<int> m1;

			for (int i = 1; i <= 1e4; i++)
				m.insert(i);

			time_t s1 = get_time();
			m1 = m;
			time_t e1 = get_time();
			std::cout << "time: " << e1 - s1 << "ms" << std::endl;
		}
		ft::set<char> first;
		ft::set<char> second;

		first.insert('x');
		first.insert('y');
		first.insert('z');

		second=first;
		first=ft::set<char>();

		std::cout << "Size of first: " << first.size() << '\n';
		std::cout << "Size of second: " << second.size() << '\n';
	}
	std::cout << YELLOW << "begin() and end()" << RESET << std::endl;
	{
		ft::set<char> myset;

		myset.insert('b');
		myset.insert('a');
		myset.insert('c');

		for (ft::set<char>::iterator it=myset.begin(); it!=myset.end(); ++it)
			std::cout << *it << '\n';
	}
	std::cout << YELLOW << "rbegin() and rend()" << RESET << std::endl;
	{
		ft::set<char> myset;

		myset.insert('b');
		myset.insert('a');
		myset.insert('c');

		for (ft::set<char>::reverse_iterator it=myset.rbegin(); it!=myset.rend(); ++it)
			std::cout << *it << '\n';
	}
	std::cout << YELLOW << "empty()" << RESET << std::endl;
	{
		ft::set<int> m;
		ft::set<char> m1;

		if (m.empty()) std::cout << "set is empty\n";

		m1.insert('a');
		m1.insert('b');
		m1.insert('c');

		while (!m1.empty())
		{
			std::cout << *m1.begin() << '\n';
			m1.erase(m1.begin());
		}
	}
	std::cout << YELLOW << "size() and max_size()" << RESET << std::endl;
	{
		ft::set<char> myset;
		myset.insert('a');
		myset.insert('b');
		myset.insert('c');

		std::cout << "myset.size() is " << myset.size() << '\n';
		std::cout << "myset.max_size() is " << myset.max_size() << '\n';
	}
	std::cout << YELLOW << "insert()" << RESET << std::endl;
	{
		{
			ft::set<int> m;
			ft::set<int> m1;

			for (int i = 1; i <= 1e5; i++)
			{
				m.insert(i);
				m1.insert(i);
			}

			time_t s1 = get_time();
			m.insert(1e4+5);
			time_t e1 = get_time();
			std::cout << "insert(single elem) time: " << e1 - s1 << "ms" << std::endl;

			time_t s2 = get_time();
			m1.insert(m.begin(), m.end());
			time_t e2 = get_time();
			std::cout << "insert(range) time: " << e2 - s2 << "ms" << std::endl;
		}
		ft::set<char> myset;

		// first insert function version (single parameter):
		myset.insert ( 'a' );
		myset.insert ( 'z' );

		ft::pair<ft::set<char>::iterator,bool> ret;
		ret = myset.insert ( 'z' );
		if (ret.second==false) {
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << *ret.first << '\n';
		}

		// second insert function version (with hint position):
		ft::set<char>::iterator it = myset.begin();
		myset.insert (it, 'b');
		myset.insert (it, 'c');

		// third insert function version (range insertion):
		ft::set<char> anotherset;
		anotherset.insert(myset.begin(),myset.find('c'));

		// showing contents:
		std::cout << "myset contains:\n";
		for (it=myset.begin(); it!=myset.end(); ++it)
			std::cout << *it << '\n';

		std::cout << "anotherset contains:\n";
		for (it=anotherset.begin(); it!=anotherset.end(); ++it)
			std::cout << *it << '\n';
	}
	std::cout << YELLOW << "erase()" << RESET << std::endl;
	{
		{
			ft::set<int> m;

			for (int i = 1; i <= 1e5; i++)
				m.insert(i);

			ft::set<int>::iterator it = m.find(1e3-2);
			time_t s1 = get_time();
			m.erase(it);
			time_t e1 = get_time();
			std::cout << "erase(it) time: " << e1 - s1 << "ms" << std::endl;

			time_t s2 = get_time();
			m.erase(40);
			time_t e2 = get_time();
			std::cout << "erase(key) time: " << e2 - s2 << "ms" << std::endl;

			time_t s3 = get_time();
			m.erase(++m.begin(), --m.end());
			time_t e3 = get_time();
			std::cout << "erase(range) time: " << e3 - s3 << "ms" << std::endl;
		}

		ft::set<char> myset;
		ft::set<char>::iterator it;

		myset.insert('a');
		myset.insert('b');
		myset.insert('c');
		myset.insert('d');
		myset.insert('e');
		myset.insert('f');

		it=myset.find('b');
		myset.erase (it);

		myset.erase ('c');

		it=myset.find ('e');
		myset.erase ( it, myset.end() );

		for (it=myset.begin(); it!=myset.end(); ++it)
			std::cout << *it << '\n';
	}
	std::cout << YELLOW << "swap()" << RESET << std::endl;
	{
		{
			ft::set<int> m;
			ft::set<int> m1;

			for (int i = 1; i <= 1e5; i++) m.insert(i);
			for (int i = -1e3; i <= 1e2; i++) m.insert(i);

			time_t s1 = get_time();
			m.swap(m1);
			time_t e1 = get_time();
			std::cout << " time: " << e1 - s1 << "ms" << std::endl;
		}

		ft::set<char> foo,bar;

		foo.insert('x');
		foo.insert('y');

		bar.insert('a');
		bar.insert('b');
		bar.insert('c');

		foo.swap(bar);

		std::cout << "foo contains:\n";
		for (ft::set<char>::iterator it=foo.begin(); it!=foo.end(); ++it)
			std::cout << *it << '\n';

		std::cout << "bar contains:\n";
		for (ft::set<char>::iterator it=bar.begin(); it!=bar.end(); ++it)
			std::cout << *it << '\n';
	}
	std::cout << YELLOW << "clear()" << RESET << std::endl;
	{
		{
			ft::set<int> m;
			for (int i = 1; i <= 1e5; i++) m.insert(i);

			time_t s1 = get_time();
			m.clear();
			time_t e1 = get_time();
			std::cout << "time: " << e1 - s1 << "ms" << std::endl;
		}

		ft::set<char> myset;

		myset.insert('x');
		myset.insert('y');
		myset.insert('z');

		std::cout << "myset contains:\n";
		for (ft::set<char>::iterator it=myset.begin(); it!=myset.end(); ++it)
			std::cout << *it << '\n';

		myset.clear();
		myset.insert('a');
		myset.insert('b');

		std::cout << "myset contains:\n";
		for (ft::set<char>::iterator it=myset.begin(); it!=myset.end(); ++it)
			std::cout << *it << '\n';
	}
	std::cout << YELLOW << "key_compare()" << RESET << std::endl;
	{
		ft::set<char> myset;

		ft::set<char>::key_compare mycomp = myset.key_comp();

		myset.insert('a');
		myset.insert('b');
		myset.insert('c');

		std::cout << "myset contains:\n";

		char highest = *myset.rbegin();

		ft::set<char>::iterator it = myset.begin();
		do {
			std::cout << *it << '\n';
		} while ( mycomp(*it++, highest) );
	}
	std::cout << YELLOW << "vlaue_compare()" << RESET << std::endl;
	{
		ft::set<char> myset;

		myset.insert('x');
		myset.insert('y');
		myset.insert('z');

		std::cout << "myset contains:\n";

		char highest = *myset.rbegin();

		ft::set<char>::iterator it = myset.begin();
		do {
			std::cout << *it << '\n';
		} while ( myset.value_comp()(*it++, highest) );
	}
	std::cout << YELLOW << "find()" << RESET << std::endl;
	{
		{
			ft::set<int> m;
			for (int i = 1; i <= 1e5; i++) m.insert(i);

			time_t s1 = get_time();
			m.find(4);
			time_t e1 = get_time();
			std::cout << "time: " << e1 - s1 << "ms" << std::endl;
		}

		ft::set<char> myset;
		ft::set<char>::iterator it;

		myset.insert('a');
		myset.insert('b');
		myset.insert('c');
		myset.insert('d');

		it = myset.find('b');
		if (it != myset.end())
			myset.erase (it);

		// print content:
		std::cout << "elements in myset:" << '\n';
		std::cout << "a => " << *myset.find('a') << '\n';
		std::cout << "c => " << *myset.find('c') << '\n';
		std::cout << "d => " << *myset.find('d') << '\n';
	}
	std::cout << YELLOW << "count()" << RESET << std::endl;
	{
		ft::set<char> myset;
		char c;

		myset.insert('a');
		myset.insert('c');
		myset.insert('f');

		for (c='a'; c<'h'; c++)
		{
			std::cout << c;
			if (myset.count(c)>0)
				std::cout << " is an element of myset.\n";
			else
				std::cout << " is not an element of myset.\n";
		}
	}
	std::cout << YELLOW << "lower_bound() and upper_bound()" << RESET << std::endl;
	{
		{
			ft::set<int> m;
			for (int i = 1; i <= 1e5; i++) m.insert(i);

			time_t s1 = get_time();
			m.lower_bound(1e4);
			time_t e1 = get_time();
			std::cout << "lower_bound() time: " << e1 - s1 << "ms" << std::endl;

			time_t s2 = get_time();
			m.upper_bound(1e4);
			time_t e2 = get_time();
			std::cout << "upper_bound() time: " << e2 - s2 << "ms" << std::endl;
		}

		ft::set<char> myset;
		ft::set<char>::iterator itlow,itup;

		myset.insert('a');
		myset.insert('b');
		myset.insert('c');
		myset.insert('d');
		myset.insert('e');

		itlow=myset.lower_bound ('b');
		itup=myset.upper_bound ('d');

		myset.erase(itlow,itup);

		for (ft::set<char>::iterator it=myset.begin(); it!=myset.end(); ++it)
			std::cout << *it << '\n';
	}
	std::cout << YELLOW << "equal_rang()" << RESET << std::endl;
	{
		{
			ft::set<int> m;
			for (int i = 1; i <= 1e5; i++) m.insert(i);

			time_t s1 = get_time();
			m.equal_range(1e4);
			time_t e1 = get_time();
			std::cout << "time: " << e1 - s1 << "ms" << std::endl;
		}

		ft::set<char> myset;

		myset.insert('a');
		myset.insert('b');
		myset.insert('c');

		ft::pair<ft::set<char>::iterator,ft::set<char>::iterator> ret;
		ret = myset.equal_range('b');

		std::cout << "lower bound points to: ";
		std::cout << *ret.first << '\n';

		std::cout << "upper bound points to: ";
		std::cout << *ret.second << '\n';
	}
	std::cout << YELLOW << "relational operators()" << RESET << std::endl;
	{
		ft::set<int> m;
		ft::set<int> m1;

		for (int i = 1; i <= 1e5; i++) m.insert(i);
		for (int i = -1e3; i <= 1e2; i++) m.insert(i);

		time_t s1 = get_time();
		std::cout << (m == m1) << ' ';
		time_t e1 = get_time();
		std::cout << "op ==() time: " << e1 - s1 << "ms" << std::endl;

		time_t s2 = get_time();
		std::cout << (m != m1) << ' ';
		time_t e2 = get_time();
		std::cout << "op !=() time: " << e2 - s2 << "ms" << std::endl;

		time_t s3 = get_time();
		std::cout << (m < m1) << ' ';
		time_t e3 = get_time();
		std::cout << "op <() time: " << e3 - s3 << "ms" << std::endl;

		time_t s4 = get_time();
		std::cout << (m <= m1) << ' ';
		time_t e4 = get_time();
		std::cout << "op <=() time: " << e4 - s4 << "ms" << std::endl;

		time_t s5 = get_time();
		std::cout << (m > m1) << ' ';
		time_t e5 = get_time();
		std::cout << "op >() time: " << e5 - s5 << "ms" << std::endl;

		time_t s6 = get_time();
		std::cout << (m >= m1) << ' ';
		time_t e6 = get_time();
		std::cout << "op >=() time: " << e6 - s6 << "ms" << std::endl;
	}
}
*/
int main()
{
	vector_test();
	map_test();
	stack_test();
	//set_test();
    system("leaks a.out");

}