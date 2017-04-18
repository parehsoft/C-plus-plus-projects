#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> inventory;
    inventory.push_back("sword");
    inventory.push_back("battle axe");
    inventory.push_back("M107");

    vector<string>::iterator       iteNormal;
    vector<string>::const_iterator iteConst;

    for (iteConst = inventory.begin(); iteConst != inventory.end(); iteConst++)
    {
        cout << *iteConst << " and has " << iteConst->size() << " letters." << endl;
    }

    // change 0th element of the
    iteNormal  = inventory.begin();
    *iteNormal = "ka";
    cout << endl;

    for (iteConst = inventory.begin(); iteConst != inventory.end(); iteConst++)
    {
        cout << *iteConst << endl;
    }
    cout << endl;

    inventory.insert(inventory.begin(), "crossbow at  the beginning");
    inventory.insert(inventory.end(), "crossbow at  the end");
    for (iteConst = inventory.begin(); iteConst != inventory.end(); iteConst++)
    {
        cout << *iteConst << " and has " << iteConst->size() << " letters." << endl;
    }
    iteNormal  = inventory.begin() + 2;
    *iteNormal = "iterator points here";


    cout << endl;
    for (iteConst = inventory.begin(); iteConst != inventory.end(); iteConst++)
    {
        cout << *iteConst << endl;
    }

    inventory.erase(inventory.begin() + 2);
    *iteNormal = "iterator points here";
    cout << endl;
    for (iteConst = inventory.begin(); iteConst != inventory.end(); iteConst++)
    {
        cout << *iteConst << endl;
    }

    inventory.insert(inventory.begin(), "troodon");
    *iteNormal = "iterator points here";
    cout << endl;
    for (iteConst = inventory.begin(); iteConst != inventory.end(); iteConst++)
    {
        cout << *iteConst << endl;
    }

    return 0;
}
