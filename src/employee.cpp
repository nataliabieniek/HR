#include <employee.hpp>
#include <iostream>
#include <cstdlib>
#include <cstring>

void employee::set(std::string ID, std::string NAME, std::string SURNAME, std::string DEPARTMENT, std::string POSITION )
{
    id = ID;
    name = NAME;
    surname = SURNAME;
    departmentId = DEPARTMENT;
    position = POSITION;
}
void employee::print()
{
    std::cout << "ID:\t" << id << std::endl; 
    std::cout << "Name:\t" << name << std::endl;
    std::cout << "Surname::\t" << surname << std::endl;
    std::cout << "Department ID:\t" << departmentId << std::endl;
    std::cout << "Position:\t" << position << std::endl;
}