#include <employee.hpp>
#include <hrms.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <algorithm>

void hrms::write_again_salary()
{
    std::fstream file_salary;
    file_salary.open("salary.txt", std::ios::trunc);
    int i = all_workers.size();
    for(int j=0; j<i; j++)
    {
        file_salary << all_workers[j].id << std::endl;
        if(j==i-1)
        {
            file_salary << salary[all_workers[j].id];
        }
        else
        {
            file_salary << salary[all_workers[j].id] << std::endl;;
        }
    }
    file_salary.close();
}
void hrms::write_again_date()
{
    std::fstream file_date;
    file_date.open("date.txt", std::ios::trunc);
    int i = all_workers.size(); 
    for(int j=0; j<i; j++)
    {
        file_date << all_workers[j].id << std::endl;
        file_date << all_workers[j].name << std::endl;
        file_date << all_workers[j].surname << std::endl;
        file_date << all_workers[j].departmentId << std::endl;
        if(j==i-1)
        {
            file_date << all_workers[j].position;
        }
        else
        {
            file_date << all_workers[j].position << std::endl;;
        }
    }
    file_date.close();
}
std::string upper_case(std::string word)
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
class WrongOpenFile : public std::exception
{
    virtual const char *what() const throw()
    {
        return "Exeption1: Blad przy otwarciu pliku";
    }
};
void hrms::read_from_file()
{
    std::fstream file;
    file.open("date.txt");
    if(file.good())
    {
        while(!file.eof())
        {
            std::string name, id, surname, depertment, position;
            std::getline(file, id);
            std::getline(file, name);
            std::getline(file, surname);
            std::getline(file, depertment);
            std::getline(file, position);
            all_workers.push_back(employee{id, name, surname, depertment, position});
        }
    }
    else 
    {
        throw WrongOpenFile();
    }
    file.close();
}
void hrms::read_from_console(employee nowy)
{
    all_workers.push_back(nowy);
    
    //zapiszemy te dane na koniec pliku
    std::fstream file;
    file.open("date.txt", std::ios::app);;
    if(file.good())
    {
        file << std::endl;
        file << nowy.id << std::endl;
        file << nowy.name << std::endl;
        file << nowy.surname << std::endl;
        file << nowy.departmentId << std::endl;
        file << nowy.position << std::endl;
    }
    else throw WrongOpenFile();

    file.close();
}
void hrms::print_all_workers()
{
    int liczba_pracownikow = all_workers.size();
    std::cout << "Liczba wszystkich pracownikow:\t"<< liczba_pracownikow << std::endl;
    for(int i=0; i<liczba_pracownikow; i++)
    {
        all_workers[i].print();
        std::cout << std::endl;
    }
}
void hrms::create_connection_dep()
{
    int liczba_pracownikow = all_workers.size();
    for(int i=0; i<liczba_pracownikow; i++)
    {
        connection_dep[all_workers[i].departmentId].push_back(all_workers[i].id);
    }
}
void hrms::print_connection_dep()
{
    int ilosc = connection_dep.size();
    std::cout << "Ilosc departamentow:\t" << ilosc << std::endl;
    std::map<std::string, std::vector <std::string>>::iterator it = connection_dep.begin();
    for(int i=0; i<ilosc; i++)
    {
        int ilosc_w_dep = connection_dep[it->first].size();
        std::cout << "Ilosc w " << it->first << " to: \t" << ilosc_w_dep << std::endl;
        std::string dep = it->first;
        for(int j=0; j <ilosc_w_dep; j++)
        {
            std::cout << dep << "\t => \t" << connection_dep[dep][j] << '\n';
        }
        *it++;
    }   
}
void hrms::read_salary()
{
    std::fstream file;
    file.open("salary.txt");
    if(file.good())
    {
        while(!file.eof())
        {
           std::string id;
           double money;
           file >>id;
           file >> money;
           salary[id] = money;
        }
    }
    else 
    {
        throw WrongOpenFile();
    }
    file.close();
}
void hrms::print_salary()
{
    std::map<std::string, double>::iterator it = salary.begin();
    int ilosc = salary.size();
    int ilosc_pracownikow = all_workers.size();
    for(int i=0; i<ilosc; i++)
    {
        std::string obecna_osoba = it->first;
        int j;
        for(j=0; all_workers[j].id!=obecna_osoba; ++j);
        std::cout << "ID: " << it->first << "\tImie: " << all_workers[j].name << "\tNazwisko: " << all_workers[j].surname << "\tDepartment: " << all_workers[j].departmentId << "\tPosition: " << all_workers[j].position << "\tPensja: " << it->second << std::endl;
        *it++;
    }
}
void hrms::print_department(std::string departmentid)
{
    std::map<std::string, std::vector <std::string>>::iterator it = connection_dep.begin();
    int ilosc_w_dep = connection_dep[it->first].size();
    for(int i=0; i<ilosc_w_dep; i++)
    {
        std::cout << departmentid << "\t => \t" << connection_dep[departmentid][i] << '\n';
        *it++;
    }   
}
void hrms::add(employee employee, std::string departmentid, double sal)
{
    //dodanie do kontenerów
    all_workers.push_back(employee);
    int i = all_workers.size() - 1;
    connection_dep[all_workers[i].departmentId].push_back(all_workers[i].id);
    salary[departmentid] = sal;
    //zmiany w plikach
    write_again_date();
    write_again_salary();
}
void hrms::printSalariesSorted()
{
    //ze wzgledu ze uzylismy mapy do salary, aby posortowac wzgledem kluczy przeniesiemy ja do wektora
    std::vector <std::pair<std::string, double>> vec;
    std::map <std::string, double> ::iterator it2 = salary.begin();
    for (it2=salary.begin(); it2!=salary.end(); it2++) 
    {
        vec.push_back(make_pair(it2->first, it2->second));
    }

    std::sort(vec.begin(), vec.end(), [](auto &left, auto &right) { return left.second < right.second; });
    int ilosc = all_workers.size();
    for(int i=0; i<ilosc; i++)
    {
        std::string obecna_osoba = vec[i].first;
        int j;
        for(j=0; all_workers[j].id!=obecna_osoba; ++j);
        std::cout << "ID: " << obecna_osoba << "\tImie: " << all_workers[j].name << "\tNazwisko: " << all_workers[j].surname << "\tDepartment: " << all_workers[j].departmentId << "\tPosition: " << all_workers[j].position << "\tPensja: " << vec[i].second << std::endl;
    }
}
void hrms::change_salary(std::string employeeId, double sal)
{
    //usuniecie poprzedniego elementu
    std::map< std::string, double>::iterator szukaj;
    szukaj = salary.find(employeeId);
    salary.erase(szukaj);

    //dodanie nowego elementu
    salary[employeeId]=sal;

    //poprawki w pliku
    write_again_salary();
}