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
        while(!file.eof())
        {
            std::string name, id, surname, depertment, position;
            std::getline(file, id);
            std::getline(file, name);
            std::getline(file, surname);
            std::getline(file, depertment);
            std::getline(file, position);
            all_workers.push_back(employee{id, name, surname, depertment, position});
            std::cout << std::endl;
        }
    }
    else 
    {
        throw WrongOpenFile();
    }
    file.close();
}
void hrms::read_from_console()
{
    std::string name, id, surname, depertment, position;
    std::cout << "Podaj id pracownika:" << std::endl;
    std::cin >> id;
    std::cout << "Podaj imie pracownika:" << std::endl;
    std::cin >> name;
    std::cout << "Podaj nazwisko pracownika:" << std::endl;
    std::cin >> surname;
    std::cout << "Podaj id departamentu pracownika:" << std::endl;
    std::cin >> depertment;
    std::cout << "Podaj pozycje pracownika:" << std::endl;
    std::cin >> position;
    //na duze litery
    uppercase(id); 
    uppercase(name);
    uppercase(surname);
    uppercase(depertment);
    uppercase(position);
    all_workers.push_back(employee{id, name, surname, depertment, position});
    
    //zapiszemy te dane na koniec pliku
    std::fstream file;
    file.open("date.txt", std::ios::app);
    if(file.good())
    {
        file << id << std::endl;
        file << name << std::endl;
        file << surname << std::endl;
        file << depertment << std::endl;
        file << position << std::endl;
    }
    else throw WrongOpenFile();

    file.close();
}