#include <iostream>

using namespace std;

/**
Friend functions have complete access to any member of a class.
*/
class Critter
{
    friend void FriendGetName(const Critter& crit);
    friend ostream& operator<<(ostream& os, const Critter crit);
public:
    Critter(const string& name = "Default Name");
    void GetName() const;
private:
    string m_Name;
};
Critter::Critter(const string& name):
    m_Name(name)
{}

void FriendGetName(const Critter& crit)
{
    cout << "Friend function FriendGetName was called." << endl;
    cout << crit.m_Name << endl;
}

ostream& operator<<(ostream& os, const Critter crit)
{
    cout << "Overloaded operator << was called." << endl;
    cout << crit.m_Name << endl;
}

void Critter::GetName() const
{
    cout << "Member function GetName was called." << endl;
    cout << "I'm a critter " << m_Name << "." << endl;
}

void HitReturnKey (void)
{
    cout << "\nHit return to continue...";
    string garbage;
    getline(cin, garbage);
}

int main()
{
    Critter crit("Poochie");
    crit.GetName();
    FriendGetName(crit);
    cout << crit;
    HitReturnKey();
    return 0;
}
