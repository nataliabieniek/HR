#include <employee.hpp>
#include <hrms.hpp>
#include <iostream>
#include <cstdlib>
#include <cstring>
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
    file.open("date.txt", std::ios::in);
    if(file.good())
    {
        while(!file.eof())
        {
            //tutaj dopisze wczytywanie danych do wektora
        }
    }
    else 
    {
        throw WrongOpenFile();
    }
    file.close();
}