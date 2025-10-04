#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;


class database
{
    string name, dob, rollNo;

public:
    database()
    {
        this->name = "NA";
        this->dob = "NA";
        this->rollNo = "NA";
    }

    void getData()
    {
        cout << "Enter name: ";
        cin >> this->name;
        transform(this->name.begin(), this->name.end(), this->name.begin(), ::toupper);
        cout << "Enter DOB: ";
        cin >> this->dob;

        cout << "Enter roll.no: ";
        cin >> this->rollNo;
    }

    void display()
    {
        cout<<"\n" << this->name << "\t" << this->dob << "\t" << this->rollNo << endl;
    }

    friend bool operator==(const database &, const string &);
    friend bool compare(const database &obj1, const database &obj2);
};

bool operator==(const database &p,const string &name)
{
    return p.name == name;
}

bool compare(const database &obj1,const database &obj2)
{
    return obj1.name < obj2.name;
}

void sort(vector<database> &obj)
{
    sort(obj.begin(), obj.end(), compare);
    for (int i = 0; i < obj.size(); i++)
    {
        obj[i].display();
    }
}

int search(vector<database> &obj, string name)
{
    auto itr = find(obj.begin(), obj.end(), name);
    if (itr !=obj.end())
    {
        return distance(obj.begin(), itr);
    }

    return -1;
}

int main()
{
    vector<database> vec_database;
    database *ptr = new database;
    ptr->getData();
    vec_database.push_back(*ptr);
    ptr = new database;
    ptr->getData();
    vec_database.push_back(*ptr);
    ptr = new database;
    ptr->getData();
    vec_database.push_back(*ptr);
    sort(vec_database);
    int a =search(vec_database, "JACK");
    cout << a;
    return 0;
}