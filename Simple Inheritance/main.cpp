/*Not inherited by derived class:
- constructors,
- destructors,
- copy constructors,
- overloaded assignment operators,
versions of these have to be written for derived class manually.*/
#include <iostream>

using namespace std;

class Enemy
{
public:
    Enemy();
    void DisplayDamage() const;

protected:
    int m_Damage;
};
/** - Constructor */
Enemy::Enemy():
        m_Damage(10)
{}
/** - Member Funcs */
void Enemy::DisplayDamage() const
{
    cout << "Damage is: " << m_Damage << endl;
}
/** ----------- END ----------- */

class Boss : public Enemy
{
public:
    Boss();
    void SpecialDamage() const;

private:
    int m_DamageMultiplier;
};
/** - Constructor */
Boss::Boss():
    m_DamageMultiplier(3)
{}
/** - Member Funcs */
void Boss::SpecialDamage() const
{
    cout << "Boss's special damage is: " << m_DamageMultiplier * m_Damage << endl;
}

void HitReturnKey (void)
{
    cout << "\nHit return to continue...";
    string garbage;
    getline(cin, garbage);
}

int main()
{
    cout << "Creating enemy:" << endl;
    Enemy enemy0;
    enemy0.DisplayDamage();

    cout << "Creating the boss." << endl;
    Boss boss0;
    boss0.DisplayDamage();
    /**
    After this line of code, I have a Boss object with an m_Damage data member equal
to 10 and an m_DamageMultiplier data member equal to 3 . How did this happen?
Although constructors and destructors are not inherited from a base class, they
are called when an instance is created or destroyed. In fact, a base class
constructor is called before the derived class constructor to create its part of
the final object.
In this case, when a Boss object is instantiated, the default Enemy constructor is
automatically called and the object gets an m_Damage data member with a value of
10 (just like any Enemy object would). Then, the Boss constructor is called and
finishes off the object by giving it an m_DamageMultiplier data member with a
value of 3 . The reverse happens when a Boss object is destroyed at the end of the
program. First, the Boss class destructor is called for the object, and then the
336 Chapter 10
n
Inheritance and Polymorphism: Blackjack
Enemy class destructor is called. Because I didn’t define destructors in this
program, nothing special happens before the Boss object ceases to exist.
    */
    boss0.SpecialDamage();

    HitReturnKey();

    return 0;
}




















