#include <employee.hpp>
#include <iostream>
#include <cstdlib>
#include <cstring>

int main()
{
    std::cout << "System dla HR" << std::endl;
    employee pracownik;
    pracownik.employee::set("10b", "Natalia", "Bieniek", "IT", "Software engineer");
    pracownik.print();
    return 0;
}