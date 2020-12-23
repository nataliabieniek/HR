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
#endif