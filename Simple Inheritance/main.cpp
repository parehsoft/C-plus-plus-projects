/**Not inherited by derived class:
- constructors,
- destructors,
- copy constructors,
- overloaded assignment operators,
versions of these have to be written for derived class manually.*/
#include <iostream>

using namespace std;

class Enemy //-----------------------------------------------------------
{
public:
    Enemy(int damage = 10);
    void virtual DisplayDamage() const;
    void virtual LaughAtPlayer () const; // Member function to be inherited and overridden is declared as virtual.

protected:
    int m_Damage;
};
Enemy::Enemy(int damage):
        m_Damage(damage)
{}
void Enemy::DisplayDamage() const
{
    cout << "Enemy class's calling: Damage is: " << m_Damage << endl;
}
void Enemy::LaughAtPlayer() const // Virtual keyword is used only in declaration.
{
    cout << "The enemy class laughs at player." << endl;
}

class Boss : public Enemy  //--------------------------------------------
{
public:
    Boss(int damage = 20, int damageMultiplier = 3);
    void SpecialDamage() const;
    void virtual DisplayDamage() const;
    void virtual LaughAtPlayer() const; // In derived calls virtual method will be virtual as well, it is not required to put virtual keyword here, but it is good practice, as it reminds me that this derived method is indeed virtual in base class.

private:
    int m_DamageMultiplier;
};
Boss::Boss(int damage, int damageMultiplier):
    Enemy(damage), // I called Enemy class's constructor to fill the damage with derived class Boss's default value.
    m_DamageMultiplier(damageMultiplier)
{}
void Boss::SpecialDamage() const
{
    cout << "Boss's special damage is: " << m_DamageMultiplier * m_Damage << endl;
}
void Boss::DisplayDamage() const
{
    cout << "Boss invoked this method and calls Enemy's DisplayDamage ----- " << endl;
    Enemy::DisplayDamage(); // I call I call the original part enemy class's member member function here, in this overridden method in boss class. So I have original part + overridden part is some text wrapping.
    cout << "And the boss laughs afterwards!!! (This was boss calling.)" << endl;
}
void Boss::LaughAtPlayer() const
{
    cout << "The derived boss class's overridden function laugh at player!" << endl;
}

void HitReturnKey (void)
{
    cout << "\nHit return to continue...";
    string garbage;
    getline(cin, garbage);
}

int main()
{
    cout << "Enemy:" << endl;
    Enemy enemy0;
    enemy0.LaughAtPlayer();
    enemy0.DisplayDamage();

    cout << "Boss:" << endl;
    Boss boss0;
    boss0.LaughAtPlayer();
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
Enemy class destructor is called. Because I didn’t define destructors in this
program, nothing special happens before the Boss object ceases to exist.
    */
    boss0.SpecialDamage();

    HitReturnKey();

    return 0;
}
