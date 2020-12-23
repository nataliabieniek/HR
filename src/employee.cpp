#include <employee.hpp>
#include <iostream>
#include <cstdlib>
#include <cstring>

std::string uppercase(std::string word)
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
employee::employee(std::string ID, std::string NAME, std::string SURNAME, std::string DEPARTMENT, std::string POSITION )
{
    id = uppercase(ID);
    name = uppercase(NAME);
    surname = uppercase(SURNAME);
    departmentId = uppercase(DEPARTMENT);
    position = uppercase(POSITION);
}
void employee::print()
{
    std::cout << "ID:\t\t" << id << std::endl; 
    std::cout << "Name:\t\t" << name << std::endl;
    std::cout << "Surname:\t" << surname << std::endl;
    std::cout << "Department ID:\t" << departmentId << std::endl;
    std::cout << "Position:\t" << position << std::endl;
}