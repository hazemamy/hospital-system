#include <iostream>
#include <string>
using namespace std;

const int MAX_SPACIALZATION = 20;
const int MAX_QUEUE = 5;

int manu()
{

    string spac_list[MAX_SPACIALZATION + 1][MAX_QUEUE];
    int patient_status_list[MAX_SPACIALZATION + 1][MAX_QUEUE];
    int patient_wating_list[MAX_SPACIALZATION];

    int choice = -1;
    while (choice = -1)
    {
        cout << "\n----------------------------" << endl;
        cout << "1. Add new patieant" << endl;
        cout << "2. Get the next patient" << endl;
        cout << "3. Display all patients" << endl;
        cout << "4. Exit" << endl;
        cout << "----------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        // cout << "----------------------------"<<endl;

        if (choice <= 0 && choice > 4)
            cout << "Invalid choice" << endl;
        choice = -1;
    }
    return choice;
}

int main()
{
    manu();
}
