#include<iostream>
#include<vector>
using namespace std;
class Publication
{
protected:
    string name;
    int price;

public:
    Publication()
    {
        this->name = "NA";
        this-> price = 0;
    }

    virtual void getData()
    {
        cout << "\nEnter the name of the publication: ";
        // getline(cin, this->name);
        getline(cin, this->name);

        
        cout << "\nEnter the price of " << this->name << " :";
        int user_price;
        try
        {   
            cin >> user_price;
            if (user_price < 0)
            {
                throw user_price;
            }

            this->price = user_price;
        }

        catch(const int user_price)
        {
            cout << "\nPrice cannot be -ve." << endl;
            this->price = 0;
        }

        catch(...)
        {
            cout << "\nInvalid price entered!" << endl;
            this->price = 0;
        }
    }

    virtual void display()
    {
        cout << "\nName: " << this->name << endl;
        cout << "\nPrice: " << this->price << endl;
    }
};

class Book : public Publication
{
    int pages;

public:
    Book()
    {
        pages = 0;
    }

    virtual void getData()
    {
        cout << "\nEnter the name of the publication: ";
        getline(cin, this->name);
        getline(cin, this->name);

        
        cout << "\nEnter the price of " << this->name << " :";
        int user_price;
        try
        {   
            cin >> user_price;
            if (user_price < 0)
            {
                throw user_price;
            }

            this->price = user_price;
        }

        catch(const int user_price)
        {
            cout << "\nPrice cannot be -ve." << endl;
            this->price = 0;
        }

        catch(...)
        {
            cout << "\nInvalid price entered!" << endl;
            this->price = 0;
        }

        cout << "\nEnter the no.of pages: ";
        int user_pages;

        try
        {
            cin >> user_pages;
            if (pages < 0)
            {
                throw user_pages;
            }

            this->pages = user_pages;
        }
        catch(const int pages)
        {
            cout << "No of pages cannot be -ve";
            this->pages = 0;
        }

        catch(...)
        {
            cout << "Invalid no.of pages entered!" << endl;
            this->pages = 0;
        }
    }

    virtual void display()
    {
        cout << "\nName: " << this->name << endl;
        cout << "\nPrice: " << this->price << endl;
        cout << "\nPages: " << this->pages << endl;
    }
};
int main()
{
    Book *ptr;
    vector<Book*> vec_books;

    Book objB;
    ptr = &objB;
    ptr->getData();
    ptr->display();
    vec_books.push_back(ptr);

    return 0;
}