#ifndef employee_hpp
#define employee_hpp

#include <iostream>
#include <cstdlib>
#include <cstring>

class employee
{
    private:
    std::string id;
    std::string name;
    std::string surname;
    std::string departmentId;
    std::string position;

    public:
    void set(std::string id, std::string name, std::string surname, std::string depertment, std::string position );
};

#endif