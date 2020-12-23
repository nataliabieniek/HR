#include <employee.hpp>
#include <hrms.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

std::string upper_case(std::string word)
{
    std::string wyraz = word;
     for(int i=0;i<=wyraz.length();i++)
     {
        if(wyraz[i]>=97 && wyraz[i]<=122)
        {
		    wyraz[i]=wyraz[i]-32;
        }
     }
    return wyraz;
}
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
    id = upper_case(id); 
    name =upper_case(name);
    surname = upper_case(surname);
    depertment = upper_case(depertment);
    position = upper_case(position);
    all_workers.push_back(employee{id, name, surname, depertment, position});
    
    //zapiszemy te dane na koniec pliku
    std::fstream file;
    file.open("date.txt", std::ios::app);;
    if(file.good())
    {
        file << std::endl;
        file << id << std::endl;
        file << name << std::endl;
        file << surname << std::endl;
        file << depertment << std::endl;
        file << position << std::endl;
    }
    else throw WrongOpenFile();

    file.close();
}
void hrms::print_all_workers()
{
    int liczba_pracownikow = all_workers.size();
    std::cout << " Liczba wszystkich pracownikow:\t"<< liczba_pracownikow << std::endl;
    for(int i=0; i<liczba_pracownikow; i++)
    {
        all_workers[i].print();
        std::cout << std::endl;
    }
}
void hrms::create_connection_dep()
{
    int liczba_pracownikow = all_workers.size();
    for(int i=1; i<liczba_pracownikow; i++)
    {
        std::string  dep_obecne;
        dep_obecne = all_workers[i].departmentId;
        connection_dep[dep_obecne].push_back(all_workers[i].id);
    }
}
void hrms::print_connection_dep()
{
    int ilosc = connection_dep.size();
    std::cout << "Ilosc departamentow:\t" << ilosc << std::endl;
}