#include <iostream>

using namespace std;

class Critter
{
public:
    Critter(string name = "Default Name", int age = 0);
    ~Critter();
    Critter(const Critter& incommingCritter); // copy constructor
    Critter& operator=(const Critter& passedCritter);
    void Greet() const;

private:
    string* m_pName;
    int m_age;
};

Critter::Critter(string name, int age)
{
    cout << "Constructor called!" << endl;
    m_pName = new string(name);
    m_age = age;
    cout << "Im " << *m_pName << " and Im " << m_age << " years old." << endl;
    cout << "m_pName points to: " << cout << m_pName << endl;
}

Critter::~Critter()
{
    cout << "DEstructor called!" << endl;
    delete m_pName;
}

/**
Sometimes an object is copied automatically for you. This occurs when an object
is:
- Passed by value to a function.
- Returned from a function.
- Initialized to another object through an initializer.
- Provided as a single argument to the object’s constructor.
*/
Critter::Critter(const Critter& incommingCritter) // copy constructor to provide deep copy
{
    cout << "Copy constructor called.";
    m_pName = new string(*(incommingCritter.m_pName));
    m_age = incommingCritter.m_age;
}

Critter& Critter::operator=(const Critter& passedCritter) // deep copy by overloaded operator=
{
    cout << "Overloaded operator= function called." << endl;
    if (this != &passedCritter) // Check whether I'm not assigning an object to itself. Potential problems can arise.
    {
        delete m_pName; // Left value (crit1)'s heap memory will be returned to the heap.
        m_pName = new string(*(passedCritter.m_pName));
        m_age = passedCritter.m_age;
    }
    return *this;
}

void Critter::Greet() const
{
    cout << "Im " << *m_pName << " and Im " << m_age << " years old." << endl;
    cout << "m_pName points to: " << cout << m_pName << endl;
}

void TestCopyConstructor(Critter coppiedCrit)
{
    cout << endl << "Inside of the TestCopyConstructor function, called with crit1:" << endl;
    coppiedCrit.Greet();
}

void HitReturnKey (void)
{
    cout << "\nHit return to continue...";
    string garbage;
    getline(cin, garbage);
}

int main()
{
    Critter crit1;
    Critter crit2("Poochie", 5);

    cout << endl;
    crit1.Greet();
    TestCopyConstructor(crit1);

    cout << endl << "crit1 = crit2;" << endl;
    crit1 = crit2;
    crit1.Greet();
    crit2.Greet();

    HitReturnKey();
    return 0;
}
