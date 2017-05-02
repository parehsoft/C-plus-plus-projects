#include <iostream>

using namespace std;

/** CLASS CRITTER **/
class Critter
{
public:
    Critter(int hunger = 4, int boredom = 4);
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);

private:
    int m_Hunger;
    int m_Boredom;

    void PassTime(int time = 1);
    inline int GetMood() const;
};

Critter::Critter(int hunger, int boredom):
        m_Hunger(hunger),
        m_Boredom(boredom)
{}

void Critter::PassTime(int time)
{
    m_Hunger  += time;
    m_Boredom += time;
}

inline int Critter::GetMood() const
{
    return m_Hunger + m_Boredom;
}

void Critter::Talk()
{
    cout << "I'm a critter and I feel: ";
    int mood = GetMood();
    if (mood > 15)
        cout << "mad!" << endl;
    else if (mood > 10)
        cout << "frustrated!" << endl;
    else if (mood > 5)
        cout << "ok!" << endl;
    else if (mood)
        cout << "happy!" << endl;

    PassTime();
}

void Critter::Eat(int food)
{
    cout << "Brupp..." << endl;
    m_Hunger -= food;
    if (m_Hunger < 0)
        m_Hunger = 0;
    if (m_Hunger > 10)
        m_Hunger = 10;

    PassTime();
}

void Critter::Play(int fun)
{
    cout << "Wheee!!" << endl;
    m_Boredom -= fun;
    if (m_Boredom < 0)
        m_Boredom = 0;
    if (m_Boredom > 10)
        m_Boredom = 10;

    PassTime();
}
/** END CLASS CRITTER**/

void HitReturnKey (void)
{
    cout << "\nHit return to continue...";
    string garbage;
    getline(cin, garbage);
    getline(cin, garbage);
}

int main()
{
    Critter myCritter;
    myCritter.Talk();
    int choice;
    do
    {
        cout << endl << "Critter Caretaker" << endl;
        cout << "0 - Quit" << endl;
        cout << "1 - Listen to your critter" << endl;
        cout << "2 - Feed your critter" << endl;
        cout << "3 - Play with your critter" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 0:
            cout << "Goodbye!" << endl;
                break;
            case 1:
            myCritter.Talk();
                break;
            case 2:
            myCritter.Eat();
                break;
            case 3:
            myCritter.Play();
                break;
            default:
            cout << "Sorry, but " << choice << " isn’t a valid choice." << endl;
        }
    } while (choice != 0);

    HitReturnKey();
    return 0;
}
