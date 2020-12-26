#ifndef hrms_hpp
#define hrms_hpp

#include <iostream>
#include <vector>
#include <map>
#include <employee.hpp>

class hrms{
    public:
    void read_from_file(); //do sll_workers wpisuje dane z pliku
    void read_from_console(); //z konsoli wpisuje dane do all_workers
    void print_all_workers();
    void create_connection_dep();
    void print_connection_dep();
    void read_salary();
    void print_salary();
    void printSalariesSorted();
    void print_department(std::string departmentid); //dodaj sprawdzenie czy jest taki department
    void add(employee employee, std::string departmentid, double salary); //sprawdz czy dano dobre salary
    void write_again_date();
    void write_again_salary();
    private:
    std::vector<employee> all_workers;
    std::map < std::string, std::vector <std::string>> connection_dep;
    std::map < std::string, double> salary;

};

#endif