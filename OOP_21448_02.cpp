#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Student
{
private:
    string name, address, bloodGp, division, dob,rollNo, contactNo, LicenseNo;
    static int counter;
    friend class DataBase;

    Student()
    {
        this->name = "NA";
        this->dob = "00-00-0000";
        this->address = "NA";
        this->bloodGp = "NA";
        this->contactNo = "NA";
        this->rollNo = "NA";
        this->division = "NA";
        this->LicenseNo = "NA";
        counter++;
    }

    Student(Student &obj)
    {
        this->name = obj.name;
        this->dob = obj.dob;
        this->address = obj.address;
        this->bloodGp = obj.bloodGp;
        this->contactNo = obj.contactNo;
        this->rollNo = obj.rollNo;
        this->division = obj.division;
        this->LicenseNo = obj.LicenseNo;
        counter++;
    }

    void getData()
    {
        cout << "\nEnter the name of the student: ";
        cin >> this->name;

        cout <<"\nEnter the Date of birth of " << this->name<<": ";
        cin >> this->dob;

        cout << "\nEnter the address of " << this->name << ": ";
        cin >> this->address;

    }
public:
    void displayData()
    {
        cout << "Name: " << this->name << endl;
        cout << "Date of birth: " << this->dob << endl;
        cout << "Address: " << this->address << endl;

    }
    string getName()
    {
        return this->name;
    }
    static int countOut();

    ~Student()
    {
        cout << "\nStudent data has been successfully deleted!" << endl;
        counter--;
    }
};

class DataBase
{
    vector<Student*> database;
public:
    void create()
    {   
        cout << "\nData Type\tSymbol\nDefault\t\t'd'\nCopy\t\t'c'\nNew\t\t'n'\n'Delete'\t'd'" << endl;
        cout << "Enter operation symbol: ";
        char option;
        cin >> option;

        switch (option)
        {
        case 'd':
        {
            Student *ptr = new Student();
            database.push_back(ptr);
            break;
        }
            

        case 'c':
        {
            if (database.size() > 0)
            {
                this->displayNames();
                cout << "\nEnter the index of the Student whose data to be copied: ";

                int index;
                cin >> index;

                Student obj = *database[index];
                Student *ptr = new Student(obj);
                database.push_back(ptr);
            }

            else
            {
                cout << "\nNo Student found to copy data!" << endl;
            }
            
            break;
        }

        case 'n':
        {
            Student *ptr = new Student();
            ptr->getData();
            database.push_back(ptr);
            break;
        }
        default:
        {
            cout << "\nEnter valid symbol!" << endl;
            break;
        }
        }
    }
    
    void deleteData()
    {
        this->displayNames();
        cout << "\nEnter the index of the Student to display data: ";

        int index;
        cin >> index;
        Student *ptr = database[index];
        database.erase(database.begin()+index);
        delete ptr;
    }

    void displayNames()
    {   
        cout << "\nIndex\tName\n\n";
        for (int i = 0; i < Student::countOut(); i++)
        {   
            cout << i << "\t" << database.at(i)->getName()<< endl;;
        }
    }

    inline void displayData()
    {
        this->displayNames();
        cout << "\nEnter the index of the Student to display data: ";

        int index;
        cin >> index;

        database[index]->displayData();
    }
};


int Student::counter = 0;

int Student::countOut()
{
    return counter;
}

int main()
{
    DataBase *ptr = new DataBase();
    bool flag = true;
    while (flag)
    {
        cout << "Count: " << Student::countOut() << endl;
        cout << "\nOperation\tSymbol\nDisplay\t\t'd'\nCreate\t\t'c'\nDelete\t\t'~'\nExit\t\t'e'" << endl;

        cout << "Operation symbol: ";
        char option;
        cin >> option;

        switch (option)
        {
        case 'd':
        {
            ptr->displayData();
            break;
        }

        case 'c':
        {
            ptr->create();
            break;
        }

        case '~':
        {
            ptr->deleteData();
            break;
        }

        case 'e':
        {
            flag = false;
            cout << "\nExit operation executed successfully!" << endl;
            break;
        }

        default:
            cout << "\nEnter valid input!" << endl;
            break;
        }
    }

    return 0;
}