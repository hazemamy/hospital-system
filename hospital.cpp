#include <iostream>
#include <string>
using namespace std;

const int MAX_SPACIALZATION = 20;
const int MAX_QUEUE = 5;

string names_list[MAX_SPACIALZATION + 1][MAX_QUEUE];
int status_list[MAX_SPACIALZATION + 1][MAX_QUEUE];
int queue_length[MAX_SPACIALZATION + 1];

int manu()
{

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

    cout << "Enter specialization, name, statis: ";
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

int main()
{
}
