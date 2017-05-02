#include <iostream>

using namespace std;

class Critter
{
private:
    int m_Hunger;  // object quality (data member)
    static int s_Total; // Static variable is accessible through the all instances of the same class. It's accessible in all class.

public:
    Critter(int hunger = 0); // constructor prototype with default value assignment.
    int GetHunger() const;
    void SetHunger(int hunger);
    static int GetTotal();
};

int Critter::s_Total = 0; // Initialize the static member variable.

Critter::Critter(int hunger): // Scope resolved function definition, careful about default value of int hunger in constructor prototype.
    m_Hunger(hunger) // <-              ^ member initializers
{
    cout << "New critter was born!" << endl;
    s_Total++;
}

int Critter::GetTotal()
{
    return s_Total;
}

int Critter::GetHunger() const
{
    return m_Hunger;
}

void Critter::SetHunger(int hunger)
{
    if (hunger < 0)
        cout << "You can't set negative number as hunger level." << endl;
    else
        m_Hunger = hunger;
}

void HitReturnKey (void)
{
    cout << "\nHit return to continue...";
    string garbage;
    getline(cin, garbage);
}

int main()
{
    cout << "Number of critters: " << Critter::GetTotal() << endl;

    Critter crit1;
    Critter crit2(7);

    cout << "Number of critters: " << Critter::GetTotal() << endl << endl;

    cout << "Calling critter 1's GetHunger(): " << crit1.GetHunger() << "." << endl;
    cout << "Calling critter 2's GetHunger(): " << crit2.GetHunger() << "." << endl;

    cout << "Calling critter 1's SetHunger() with -1:" << endl;
    crit1.SetHunger(-1);

    cout << "Calling critter 1's SetHunger() with 9:" << endl;
    crit1.SetHunger(9);

    cout << "Calling critter 1's GetHunger(): " << crit1.GetHunger() << "." << endl;

    HitReturnKey();
    return 0;
}
