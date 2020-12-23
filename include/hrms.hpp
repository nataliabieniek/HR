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
    private:
    std::vector<employee> all_workers;
    std::map < std::string, std::vector <std::string>> connection_dep ;

};

#endif