#include <iostream>
#include <string>
#include <list>
#include <limits>

using namespace std;

class Employee {
public:
    Employee(int id, const string& name, int age, const string& department, const string& position)
        : id(id), name(name), age(age), department(department), position(position) {}

    void displayDetails() const {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
    }

    int getId() const {
        return id;
    }

private:
    int id;
    string name;
    int age;
    string department;
    string position;
};

class EmployeeManagement {
public:
    void addEmployee() {
        int id;
        string name, department, position;
        int age;

        cout << "Enter Employee ID: ";
        cin >> id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Employee Name: ";
        getline(cin, name);

        cout << "Enter Employee Age: ";
        cin >> age;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Employee Department: ";
        getline(cin, department);

        cout << "Enter Employee Position: ";
        getline(cin, position);

        Employee newEmployee(id, name, age, department, position);
        employees.push_back(newEmployee);

        cout << "Employee added successfully!" << endl;
    }

    void deleteEmployee() {
        int id;
        cout << "Enter Employee ID to delete: ";
        cin >> id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        auto it = employees.begin();
        while (it != employees.end()) {
            if (it->getId() == id) {
                it = employees.erase(it);
                cout << "Employee deleted successfully!" << endl;
                return;
            }
            else {
                ++it;
            }
        }

        cout << "Employee not found!" << endl;
    }

    void displayEmployees() const {
        if (employees.empty()) {
            cout << "No employees to display." << endl;
        }
        else {
            cout << "ID\tName\tAge\tDepartment\tPosition" << endl;
            for (const auto& employee : employees) {
                cout << employee.getId() << "\t";
                employee.displayDetails();
            }
        }
    }

private:
    list<Employee> employees;
};

class Main {
public:
    void run() {
        EmployeeManagement employeeManagement;

        while (true) {
            int choice;
            cout << "Menu of options:" << endl;
            cout << "1. Add Employee" << endl;
            cout << "2. Delete Employee" << endl;
            cout << "3. Display Employees" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                employeeManagement.addEmployee();
                break;
            case 2:
                employeeManagement.deleteEmployee();
                break;
            case 3:
                employeeManagement.displayEmployees();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return;
            default:
                cout << "Invalid choice!" << endl;
                break;
            }
        }
    }
};

int main() {
    Main app;
    app.run();

    return 0;
}