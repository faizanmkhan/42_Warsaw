/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:07:29 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/25 23:31:26 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    if(argc != 4)
    {
        std::cout << "Wrong number of arguments." << std::endl;
        return(1);
    }
    if(argv[2][0] == 0 || argv[3][0] == 0)
    {
        std::cout << "No search or replace string found." << std::endl;
        return(1);
    }
    std::string search = argv[2];
    std::string replace = argv[3];
    std::ifstream input_file(argv[1]);
    if(!input_file)
    {
        std::cout << argv[1] << " file not found or no permission to read." << std::endl;
        return (1);
    }
    std::string out_file_name(argv[1]);
    out_file_name += ".replace";
    std::ofstream output_file(out_file_name.c_str());
    if(!output_file)
    {
        std::cout << out_file_name << "Unable to create file." << std::endl;
        output_file.close();
        return (1);
    }
    std::string line_buf;
    std::size_t pos;
    while(std::getline(input_file, line_buf))
    {
        pos = 0;
        while((pos = line_buf.find(search, pos)) != std::string::npos)
        {
            line_buf.erase(pos, search.length());
            line_buf.insert(pos, replace);
            pos += replace.length();
        }
        output_file << line_buf;
        if(!input_file.eof())
            output_file << '\n';
    }
    if(output_file.bad())
    {
        std::cout << "Failed to write in output file." << std::endl;
        input_file.close();
        output_file.close();
        return (1);
    }
    input_file.close();
    output_file.close();
    return (0);
}