#include <iostream>
#include <string>
using namespace std;

const int MAX_SPECIALIZATION = 20;
const int MAX_QUEUE = 5;

string names_list[MAX_SPECIALIZATION + 1][MAX_QUEUE];
int status_list[MAX_SPECIALIZATION + 1][MAX_QUEUE];
int queue_length[MAX_SPECIALIZATION + 1];

int menu()
{

    int choice = -1;
    while (choice == -1)
    {
        cout << "\n1. Add new patieant" << endl;
        cout << "2. Display all patients" << endl;
        cout << "3. Get the next patient" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice <= 0 && choice > 4)
        {
            cout << "Invalid choice" << endl;
            choice = -1;
        }
    }
    return choice;
}

void shift_left(int spec, string names_sp[], int status_sp[])
{
    int len = queue_length[spec];
    for (int i = 1; i < len; ++i)
    {
        names_sp[i - 1] = names_sp[i];
        status_sp[i - 1] = status_sp[i];
    }
    queue_length[spec]--;
}

void shift_right(int spec, string names_sp[], int status_sp[])
{
    int len = queue_length[spec];
    for (int i = len - 1; i >= 0; --i)
    {
        names_sp[i + 1] = names_sp[i];
        status_sp[i + 1] = status_sp[i];
    }
    queue_length[spec]++;
}

bool add_patient()
{
    int spec;
    string name;
    int st;

    cout << "\nEnter specialization, name, statis: ";
    cin >> spec >> name >> st;

    int pos = queue_length[spec];
    if (pos >= MAX_QUEUE)
    {
        cout << "Sorry we can't add more patients for this specialization\n";
        return false;
    }

    if (st == 0) // regular, add to end
    {
        names_list[spec][pos] = name;
        status_list[spec][pos] = st;
        queue_length[spec]++;
    }
    else
    {
        // urgent, add to begin. Shift, then add
        shift_right(spec, names_list[spec], status_list[spec]);
        names_list[spec][0] = name;
        status_list[spec][0] = st;
    }

    return true;
}

void print_patient(int spec, string names_sp[], int status_sp[])
{
    int len = queue_length[spec];
    if (len == 0)
        return;

    cout << "There are " << len << " patients in specialization " << spec << "\n";
    for (int i = 0; i < len; ++i)
    {
        cout << names_sp[i] << " ";
        if (status_sp[i])
            cout << "urgent\n";
        else
            cout << "regular\n";
    }
    cout << "\n";
}

void print_all_patients()
{
    for (int spec = 0; spec < MAX_SPECIALIZATION; ++spec)
    {
        print_patient(spec, names_list[spec], status_list[spec]);
    }
}

void get_next_patients()
{
    int spec;
    cout << "\nEnter specialization: ";
    cin >> spec;

    int len = queue_length[spec];

    if (len == 0)
    {
        cout << "No patients at the moment. Have rest, Dr\n";
        return;
    }

    cout << names_list[spec][0] << " please go with the Dr\n";

    shift_left(spec, names_list[spec], status_list[spec]);
}

void hospital_system()
{
    while (true)
    {
        int choice = menu();

        if (choice == 1)
        {
            add_patient();
            cout << "*****************************************" << endl;
        }
        else if (choice == 2)
        {
            print_all_patients();
            cout << "*****************************************" << endl;
        }
        else if (choice == 3)
        {
            get_next_patients();
            cout << "*****************************************" << endl;
        }
        else
            break;
    }
}

int main()
{
    hospital_system();
    return 0;
}
