#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class PersonalData
{
    string name;
    string DoB;
    string cell_no;

public:
    PersonalData()
    {
        this->name = "N/A";
        this->DoB = "00 / 00 / 0000 ";
        this->cell_no = "0000000000";
    }

    PersonalData(string name, string DoB, string cell_no)
    {
        this->name = name;
        this->DoB = DoB;
        this->cell_no = cell_no;
    }

    void getData()
    {
        cout << "Enter the name: ";
        cin.ignore(); // Ignore any previous newline character in the input buffer
        getline(cin, this->name);
        transform(this->name.begin(), this->name.end(), this->name.begin(), ::toupper);

        cout << "Enter the Date of Birth of " << this->name << " : ";
        getline(cin, this->DoB);

        cout << "Enter the Cell Phone No of " << this->name << " : ";
        cin >> this->cell_no;
    }

    void displayData()
    {
        cout << "\n\t\t\t\t\t|\t" << this->name << "\t\t" << this->DoB << "\t\t" << this->cell_no << "\t|" << endl;
    }

    friend bool operator==(const PersonalData &, const string &);
    friend bool compareNames(const PersonalData &, const PersonalData &);
};

bool operator==(const PersonalData &p, const string &name_check)
{
    return p.name == name_check;
}

bool compareNames(const PersonalData &p1, const PersonalData &p2)
{
    return p1.name < p2.name;
}

int search(vector<PersonalData> &records, string name)
{
    auto it = find(records.begin(), records.end(), name);
    if (it != records.end())
    {
        return distance(records.begin(), it);
    }
    else
    {
        return -1;
    }
}

void sortData(vector<PersonalData> &ref)
{
    cout << "\t\t\t\t\t_________________________________________________________________" << endl;
    cout << "\t\t\t\t\t|\tName\t\tDate of Birth\t\tCell Phone No\t|" << endl;

    sort(ref.begin(), ref.end(), compareNames);
    for (int i = 0; i < ref.size(); i++)
    {
        ref[i].displayData();
    }
    cout << "\n\t\t\t\t\t|_______________________________________________________________|" << endl;
}

int main()
{
    vector<PersonalData> data_base;
    bool flag = true;

    while (flag)
    {
        char option;
        cout << "\n\t\t\t\t\t_____________________________________________" << endl;
        cout << "\t\t\t\t\t|\t    OPERATION\t\tSYMBOL      |\n\t\t\t\t\t|___________________________________________|\n\t\t\t\t\t|\t   Append Data\t\t  'a'       |\n\t\t\t\t\t|\t  Display Data\t\t  'd'       |\n\t\t\t\t\t|\t   Find Person\t\t  'f'       |\n\t\t\t\t\t|\t    Sort Data\t\t  's'       |\n\t\t\t\t\t|\t      Exit\t\t  'e'       |" << endl;
        cout << "\t\t\t\t\t|___________________________________________|" << endl;

        cout << "\nEnter the symbol of operation:";
        cin >> option;

        switch (option)
        {
        case 'a':
        {
            PersonalData a;
            a.getData();
            data_base.push_back(a);
            break;
        }

        case 'd':
        {
            cout << "\t\t\t\t\t_________________________________________________________________" << endl;
            cout << "\t\t\t\t\t|\tName\t\tDate of Birth\t\tCell Phone No\t|" << endl;

            for (int i = 0; i < data_base.size(); i++)
            {
                data_base[i].displayData();
            }

            cout << "\n\t\t\t\t\t|_______________________________________________________________|" << endl;
            break;
        }

        case 'f':
        {
            string search_name = "";
            cout << "Enter name of the person to search: ";
            cin >> search_name;
            transform(search_name.begin(), search_name.end(), search_name.begin(), ::toupper);

            int index = search(data_base, search_name);
            if (index != -1)
            {
                cout << search_name << "'s data found in database at index " << index << "!" << endl;
            }
            else
            {
                cout << search_name << "'s data not found in database!" << endl;
            }
            break;
        }

        case 's':
        {
            sortData(data_base);
            break;
        }

        case 'e':
        {
            flag = false;
            cout << "Exit operation executed successfully! " << endl;
            break;
        }

        default:
        {
            cout << "Enter valid input! " << endl;
            break;
        }
        }
    }

    return 0;
}
