#include "Enemy.h"

#ifndef BOSS_H
#define BOSS_H

class Boss : public Enemy
{
public:
    Boss(int damageMultiplier = 3);
    virtual ~Boss();
    void Attack() const;

private:
    int* m_pDamageMultiplier;
};

#endif // BOSS_H
