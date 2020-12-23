#include <employee.hpp>
#include <hrms.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

class WrongOpenFile : public std::exception
{
    virtual const char *what() const throw()
    {
        return "Exeption1: Blad przy otwarciu pliku";
    }
};
void hrms::read_from_file()
{
    std::fstream file;
    file.open("date.txt");
    if(file.good())
    {
        int number_of_workers=0;
        while(!file.eof())
        {
            //dziwnie drukuje
            std::string name, id, surname, depertment, position;
            std::getline(file, id);
            std::getline(file, name);
            std::getline(file, surname);
            std::getline(file, depertment);
            std::getline(file, position);
            all_workers.push_back(employee{id, name, surname, depertment, position});
            all_workers[number_of_workers].print();
            std::cout << std::endl;
            number_of_workers++;
        }
    }
    else 
    {
        throw WrongOpenFile();
    }
    file.close();
}