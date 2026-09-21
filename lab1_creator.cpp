#include <iostream>
#include <fstream>
#include <cstdlib>
#include "emp_data.h"
#include <windows.h>

using namespace std;

int main(int argc, char* argv[]) {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    if (argc != 3) {
        return 1;
    }

    char* file_name = argv[1];
    int records_count = atoi(argv[2]);

    ofstream fout(file_name, ios::binary);

    if (!fout.is_open()) {
        return 1;
    }

    for (int i = 0; i < records_count; ++i) {
        employee emp;

        cout << "Введите номер сотрудника, имя, отработанные часы: ";
        cin >> emp.num >> emp.name >> emp.hours;

        fout.write((char*)&emp, sizeof(employee));
    }

    fout.close();
    return 0;
}