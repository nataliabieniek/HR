#ifndef employee_hpp
#define employee_hpp

#include <iostream>
#include <cstdlib>
#include <cstring>

class employee
{
    public:
    std::string id;
    std::string name;
    std::string surname;
    std::string departmentId;
    std::string position;
    employee();
    employee(std::string id, std::string name, std::string surname, std::string depertment, std::string position);
    void print();
};

#endif