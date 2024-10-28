#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <fstream>
using namespace std;

int writeFile(const string& filename){
    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    ofstream ofs(filename);
    if(!ofs){
        cerr << "Error opening file for writing" << endl;
        return 0;
    }

    for (int i=0;i<numEmployees;++i){
        int empID;
        char empName[50];
        char department[50];
        double salary;

        cout << "Enter Employee ID, Name, Department, and Salary: ";
        cin >> empID >> empName >> department >> salary;

        ofs << empID << " " << empName << " " << department << " " << salary << endl;
    }

    ofs.close();
    cout << "Employee records saved to " << filename << endl;

    return numEmployees;
}

int readFile(const string& filename){
    ifstream ifs(filename);
    if (!ifs){
        cerr << "File Open Error\n";
        return 0;
    }

    int numberOfEmployees;
    ifs >> numberOfEmployees;

    cout << "ID        Name        Department   Salary" << endl;

    for (int i=0; i<numberOfEmployees;++i){
        int empID;
        char empName[50];
        char department[50];
        double salary;

        ifs >> empID >> empName >> department >> salary;

        cout << empID << "   " << empName << "   " << department << "   " << salary << endl;
    }

    ifs.close();
    return numberOfEmployees;
}

#endif
