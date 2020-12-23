#include <employee.hpp>
#include <hrms.hpp>
#include <iostream>
#include <cstdlib>
#include <cstring>


int main()
{
    std::cout << "System dla HR" << std::endl;
    hrms przyklad;
    przyklad.read_from_file();
    return 0;
}