#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "emp_data.h"

using namespace std;

void print_bin_file(string filename) {
    ifstream fin(filename, ios::binary);
    employee emp;

    while (fin.read((char*)&emp, sizeof(employee))) {
        cout << emp.num << " " << emp.name << " " << emp.hours << "\n";
    }

    fin.close();
}

void print_report(string filename) {
    ifstream fin(filename);
    string line;

    while (getline(fin, line)) {
        cout << line << "\n";
    }

    fin.close();
}

void run_program(string cmd) {
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    CreateProcessA(NULL, &cmd[0], NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    string bin_name;
    int records;

    cout << "Введи имя бинарного файла: ";
    cin >> bin_name;

    cout << "Введи кол-во записей: ";
    cin >> records;

    string cmd_creator = "Creator.exe " + bin_name + " " + to_string(records);
    run_program(cmd_creator);

    cout << "\n** Содержимое бинарного файла **\n";
    print_bin_file(bin_name);

    string report_name;
    double wage;

    cout << "\nВведи имя файла отчета: ";
    cin >> report_name;

    cout << "Введи оплату за час работы: ";
    cin >> wage;

    string cmd_reporter = "Reporter.exe " + bin_name + " " + report_name + " " + to_string(wage);
    run_program(cmd_reporter);

    cout << "\n** Отчет **\n";
    print_report(report_name);

    system("pause");
    return 0;
}