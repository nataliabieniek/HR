#include <employee.hpp>
#include <hrms.hpp>
#include <iostream>
#include <cstdlib>
#include <cstring>


int main()
{
    std::cout << "System dla HR" << std::endl;
    hrms przyklad;
    //wczytannie danych
    przyklad.read_from_file();
    przyklad.read_salary();
    przyklad.create_connection_dep();

    //menu
    int wybor=0;
    bool dzialanie=true;
    while(dzialanie)
    {
        std::cout << "Wybierz jeden z następujących numerów:" << std::endl;
        std::cout << "1\t-Wydrukuj wszystkich pracownikow" << std::endl;
        std::cout << "2\t-Wydrukuj ile osob jest w wszystkich departamentach, wraz z id osob tam pracujacych" << std::endl;
        std::cout << "3\t-Wydruj pracownikow danego departamentu" << std::endl;
        std::cout << "4\t-Wydrukuj zarobki wszystkich pracownikow" << std::endl;
        std::cout << "5\t-Wydrukuj posortowane zarobki wszystkich pracownikow" << std::endl;
        std::cout << "6\t-Dodaj nowego pracownika, wraz z jego zarobkami" << std::endl;
        std::cout << "100\t-Wyjdz z programu" << std::endl;
        std::cin  >> wybor;
        std::cout << std::endl;

        switch(wybor)
        {
            case 100:
            {
                dzialanie=false;
            }
            case 1:
            {
                przyklad.print_all_workers();
            }
            case 2:
            {
                przyklad.print_connection_dep();
            }
            case 3:
            {
                std::string dzial;
                std::cout << "Podaj z jakiego dzialu chcesz znalezc pracownikow" << std::endl;
                std::cin >> dzial;
                przyklad.print_department(dzial);
            }
            case 4:
            {
                przyklad.print_salary();
            }
            case 5:
            {
                przyklad.printSalariesSorted();
            }
            case 6:
            {
                double sal;
                std::string id, name, surname, dep, pos;
                std::cout << "\nPodaj id:" << std::endl;
                std::cin >> id;
                std::cout << "Podaj imie:" << std::endl;
                std::cin >> name;
                std::cout << "Podaj nazwisko" << std::endl;
                std::cin >> surname;
                std::cout << "Podaj ID departamentu" << std::endl;
                std::cin >> dep;
                std::cout << "Podaj pozycje" << std::endl;
                std::cin >> pos;
                std::cout << "Podaj pensje" << std::endl;
                employee nowy(id, name, surname, dep, pos);
                przyklad.read_from_console(nowy);
                przyklad.add(nowy, dep, sal);
            }
            default:
            {
                std::cout << "Zle wybrales!" << std::endl;
            }
        }
    }
    
   
    return 0;
}