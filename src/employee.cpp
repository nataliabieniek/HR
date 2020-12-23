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