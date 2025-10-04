#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileManger
{
    string file_name;
    fstream reader;
    fstream writer;

public:
    FileManger()
    {
        cout << "Enter the file name: ";
        cin >> this->file_name;
    }

    void newData()
    {
        string user_name, user_dob;
        writer.open(file_name, ios::out | ios::trunc);
        cout << "\nEnter the name of the student: ";
        cin >> user_name;

        cout << "\nEnter the Date of birth of " << user_name << ":";
        cin >> user_dob;

        writer << "Name: " << user_name << endl;
        writer << "Date of Birth: " << user_dob << endl;
        writer.close();
    }

    void appendData()
    {
        string user_name, user_dob;
        writer.open(file_name, ios::out | ios::app);
        cout << "\nEnter the name of the student: ";
        cin >> user_name;

        cout << "\nEnter the Date of birth of " << user_name << ":";
        cin >> user_dob;

        writer << "Name: " << user_name;
        writer << "Date of Birth: " << user_dob << "\n";
        writer.close();
    }

    void readData()
    {
        string read;
        reader.open(file_name, ios::in);
        reader.seekg(0, ios::beg);
        while (!reader.eof())
        {
            getline(reader, read);
            // getline(reader, read);
            cout << read << endl;
        }
        reader.close();
    }
};

int main()
{
    FileManger obj;
    obj.newData();
    // obj.appendData();
    // obj.appendData();
    obj.readData();
    // obj.newData();
    // obj.readData();
    return 0;
}