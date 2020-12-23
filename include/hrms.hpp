#ifndef hrms_hpp
#define hrms_hpp

#include <iostream>
#include <vector>
#include <employee.hpp>

class hrms{
    public:
    void read_from_file(); //do sll_workers wpisuje dane z pliku
    void read_from_console(); //z konsoli wpisuje dane do all_workers
    void print_all_workers();
    private:
    std::vector<employee> all_workers;
};

#endif