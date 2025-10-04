#include <iostream>
#include <map>
using namespace std;

int main()
{

    map<string, int> states;
    states["Uttar Pradesh"] = 199812341;
    states["Maharashtra"] = 112372972;
    states["Bihar"] = 103804637;
    states["West Bengal"] = 91347736;
    states["Madhya Pradesh"] = 72597565;
    states["Tamil Nadu"] = 72138958;
    states["Rajasthan"] = 68621012;
    states["Karnataka"] = 61130704;
    states["Gujarat"] = 60383628;
    states["Andhra_Pradesh"] = 49386799;
    try
    {
        string stateName;
        cout << "\nEnter name of the state:";
        getline(cin, stateName);
        int population = states[stateName];
        if (population == 0)
        {
            throw stateName;
        }
        else
        {
            cout << "Population is " << population << "\n";
        }
    }
    catch (string badName)
    {
        cout << "State " << badName << " does not exist." << endl;
    }
    return 0;
}