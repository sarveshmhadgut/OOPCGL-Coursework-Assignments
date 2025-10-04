#include<iostream>
#include<map>
#include<cstdlib>
using namespace std;

class Population
{
    map<string, int> population;

public:
    void addData()
    {
        string user_state;
        int user_population;

        cout << "Enter the name of the state: ";
        cin >> user_state;
        transform(user_state.begin(), user_state.begin()+1, user_state.begin(), ::toupper);

        cout << "Enter the population of '" << user_state << "' : ";
        cin >> user_population;

        population[user_state] = user_population;
    }

    void search()
    {
        string user_state;
        cout << "Enter the name of the state to search: ";

        cin >> user_state;
        transform(user_state.begin(), user_state.begin()+1, user_state.begin(), ::toupper);

        try
        {
            int ret_population = 0;
            ret_population = population[user_state];
            if (ret_population == 0)
            {
                throw ret_population;
            }

            cout << "Population of '" << user_state << "' is " << ret_population << endl;
        }
        catch(int ret_population)
        {
            cout <<user_state <<"'s population not found in database!" << endl;
        }

    }
};

int main() {
    Population *ptr = new Population;

    ptr->addData();

    ptr->search();
    ptr->search();

    return 0;
}