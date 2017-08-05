#include "Boss.h"
#include <iostream>

using namespace std;

Boss::Boss(int damageMultiplier)
{
    m_pDamageMultiplier = new int(damageMultiplier);
}
Boss::~Boss()
{
    cout << "Boss class's destructor called, begin. --------- BOSS -" << endl;
    cout << "Deleting m_pDamageMultiplier... ";
    delete m_pDamageMultiplier;
    m_pDamageMultiplier = nullptr;
    cout << "Done!" << endl;
    cout << "Boss class's destructor called, END. -----------" << endl;
}
void Boss::Attack() const
{
    cout << "Boss class's attack method dealt " << (*m_pDamage) * (*m_pDamageMultiplier) << " damage points." << endl;
}
