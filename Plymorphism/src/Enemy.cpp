#include "Enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy(int damage)
{
    m_pDamage = new int(damage);
}
Enemy::~Enemy()
{
    cout << "Enemy class's destructor called, begin. --------- ENEMY -" << endl;
    cout << "Deleting m_pDamage... ";
    delete m_pDamage;
    m_pDamage = nullptr;
    cout << "Done!" << endl;
    cout << "Enemy class's destructor called, END. -----------" << endl;
}
void Enemy::Attack() const
{
    cout << "Enemy class's attack method dealt " << *m_pDamage << " damage points." << endl;
}
