#include <iostream>

using namespace std;

// -----------------
class Player
{
public:
    Player(const string& name = "Default Name");
    void DisplayName() const;
    Player* GetNext() const;
    void SetNext(Player* nextPlayer);

private:
    string m_Name;
    Player* m_pNextPlayer;
};
Player::Player(const string& name):
    m_Name(name),
    m_pNextPlayer(NULL)
{}
void Player::DisplayName() const
{
    cout << m_Name << endl;
}
Player* Player::GetNext() const
{
    return m_pNextPlayer;
}
void Player::SetNext(Player* nextPlayer)
{
    m_pNextPlayer = nextPlayer;
}

// -----------------
class Lobby
{
public:
    Lobby();
    ~Lobby();
    void DisplayLobby();
    void AddPlayer();
    void RemovePlayer();
    void Clear();

private:
    Player* m_pHead;
    Player* m_pTail;
};
Lobby::Lobby():
    m_pHead(NULL),
    m_pTail(NULL)
{}
Lobby::~Lobby()
{
    Clear();
}
void Lobby::DisplayLobby() /** DisplayLobby can be also managed my  overloading the << operator. **/
{
    cout << "\nLobby is:" << endl;
    if (m_pHead == NULL)
    {
        cout << "Lobby is empty." << endl;
    }
    else
    {
        Player* pTemp = m_pHead;
        while (pTemp != NULL)
        {
            pTemp->DisplayName();
            pTemp = pTemp->GetNext();
        }
    }
}
void Lobby::AddPlayer()
{
    cout << "Please add the name of the new player: ";
    string name;
    cin >> name;
    Player* pNewPlayer = new Player(name);
    /*Memory availability is not checked!*/

    if (m_pHead == NULL)
    {
        m_pHead = pNewPlayer;
        m_pTail = m_pHead;
    }
    else
    {
        m_pTail->SetNext(pNewPlayer);
        m_pTail = pNewPlayer;
    }
}
void Lobby::RemovePlayer()
{
    if (m_pHead != NULL)
    {
        Player* pTemp = m_pHead;
        m_pHead = m_pHead->GetNext();
        if (m_pHead == NULL) // if next element doesn't exist, clear the tail
        {
            m_pTail = NULL;
        }
        delete pTemp;
    }
    // else - do nothing, list is empty
}
void Lobby::Clear()
{
    while (m_pHead != NULL)
        RemovePlayer();
}


void DisplayHelp()
{
    cout << "WELCOME to the game lobby! Press:" << endl;
    cout << "0 - to exit program," << endl;
    cout << "1 - to add player," << endl;
    cout << "2 - to remove player," << endl;
    cout << "3 - to clear the lobby." << endl;
    cout << "4 - to display the lobby." << endl;
}

void HitReturnKey (void)
{
    cout << "\nHit return to continue...";
    string garbage;
    getline(cin, garbage);
}

int main()
{
    Lobby myLobby;
    /*Memory availability is not checked!*/

    int choice;
    DisplayHelp();
    do
    {
        cout << "Your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 0: cout << "Bye-bye!" << endl;
                break;
            case 1: myLobby.AddPlayer();
                myLobby.DisplayLobby();
                break;
            case 2: myLobby.RemovePlayer();
                myLobby.DisplayLobby();
                break;
            case 3: myLobby.Clear();
                myLobby.DisplayLobby();
                break;
            case 4: myLobby.DisplayLobby();
                break;
            default: cout << "Please enter the valid choice:" << endl;
                     DisplayHelp();
        }
    } while (choice != 0);

    HitReturnKey();
    HitReturnKey();
    return 0;
}
