/**
    Polymorphism
    Demonstrates calling member functions dynamically.
*/
#include <iostream>
#include "Enemy.h"
#include "Boss.h"

using namespace std;

void HitReturnKey (void)
{
    cout << "Hit return to continue...\n";
    string garbage;
    getline(cin, garbage);
}

int main()
{
    Enemy* pBoss0 = new Boss(8); // Polymorphism - one method Attack() defined in Enemy and the same in Boss, but Boss reacts with it.
    Boss* pBoss1 = new Boss(8);  // NOT polymorphism
    /**
     The difference between those 2 is, in Enemy class there is defined interface with
     virtual methods. If Boss had a new own another method defined inside, I can't
     access it through Enemy type pointer. I can access only in Boss the interface defined in Enemy.

     When polymorphism is used, derived class is pointed to by base class's pointer, virtual
     methods and destructor need to be defined in base class. Otherwise, when called like this,
     base class's method will be called and only base class's destructor will be called for the object
     and thus derived class's object will not clean after itself and chunks of memory allocated in derived
     class will not be deallocated!
    */

    Enemy* pBoss2 = new Enemy(1);

    pBoss0->Attack();
    pBoss1->Attack();
    pBoss2->Attack();

    delete pBoss0; pBoss0 = nullptr;
    delete pBoss1; pBoss1 = nullptr;
    delete pBoss2; pBoss2 = nullptr;
    cout << "\nProgram ended: ";
    HitReturnKey();;
    return 0;
}





















