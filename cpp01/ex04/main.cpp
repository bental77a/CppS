/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohben-t <mohben-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 01:49:47 by mohben-t          #+#    #+#             */
/*   Updated: 2025/11/12 19:44:12 by mohben-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

std::string search_and_replace(std::string line, const std::string &s1, const std::string &s2)
{
    std::string res;
    size_t start = 0;
    size_t pos;

    if (s1.empty())
        return (line);

    while ((pos = line.find(s1,start)) != std::string::npos)
    {
        res.append(line.substr(start, pos - start));
        res.append(s2);
        start = pos + s1.length();
    }
    res.append(line.substr(start));
    return (res);
}


int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::string a = "asdasd";
        std::cout << " <usag : ./programe <file_name> <s1>  <s2>"<< std::endl;
        return(1);
    }
    
    std::ifstream in(av[1]);
    std::string line,b;
    while(getline(in, line, '\n'))
    {
        b.append(search_and_replace(line,av[2], av[3]));
        b.append("\n");
    }
    std::string out_name = std::string(av[1]) + ".replace";
    std::ofstream out(out_name.c_str());
    out << b;
    in.close();
    out.close();
}

