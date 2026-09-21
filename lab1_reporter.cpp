#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "emp_data.h"
#include <windows.h>

using namespace std;

int main(int argc, char* argv[]) {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    if (argc != 4) {
        return 1;
    }

    char* bin_file = argv[1];
    char* report_file = argv[2];
    double pay_per_hour = atof(argv[3]);

    ifstream fin(bin_file, ios::binary);
    ofstream fout(report_file);

    if (!fin.is_open() || !fout.is_open()) {
        return 1;
    }

    fout << "Отчет по файлу \"" << bin_file << "\"\n";
    fout << "Номер сотрудника, имя сотрудника, часы, зарплата\n";

    employee emp;

    while (fin.read((char*)&emp, sizeof(employee))) {
        double salary = emp.hours * pay_per_hour;

        fout << emp.num << ", "
            << emp.name << ", "
            << emp.hours << ", "
            << salary << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}