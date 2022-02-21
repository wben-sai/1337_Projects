/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:46:48 by wben-sai          #+#    #+#             */
/*   Updated: 2021/09/22 16:57:48 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

std::string replace(std::string buf, std::string s1, std::string s2)
{
    size_t found;
    std::string str = "";
    while((found = buf.find(s1)) != std::string::npos)
    {
        str += buf.substr(0, found);
        str += s2;
        buf = buf.substr(found + s1.length());
    }
    str += buf;
    return (str);
}

int main(int ac, char **av)
{
    std::string s1, s2, filename, buf, str;
    int i = 0;

    if(ac != 4)
    {
        std::cout << "Error args" << std::endl;
        return (0);
    }
    filename = av[1];
    s1 = av[2];
    s2 = av[3];
    if(s1 == "" || s2 == "")
    {
        std::cout << "S1 or S2 is empty" << std::endl;
        return(0);
    }
    std::ifstream file(filename);
    if(file == 0)
    {
        std::cout << "file inco" << std::endl;
        return(0);
    }

    while (std::getline (file, buf))
    {
        if (i++ != 0)
            str += "\n";
        str += replace(buf, s1, s2);
    }
    file.close();

    std::ofstream ofs(filename + ".replace");
    ofs << str;
    ofs.close();
    
    return (0);
}