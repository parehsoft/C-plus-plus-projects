#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

bool IsNumber(char c)
{
    if ((c >= 48) && (c <= 57))
        return true;
    else
        return false;
}

int InputInteger()
{
    char c;
    string input;
    bool work = true;
    while (work == true)
    {
        getline(cin, input);
        if (input.empty() == true)
        {
            cout << "Please choose again: ";
            work = true;
        }
        else
        {
            if (IsNumber(input[0]) == true)
            {
                c = input[0];
                work = false;
            }
            else
                cout << "Wrong input, please provide number: ";
        }
    }
    return c - 48;
}

char InputChar()
{
    char c;
    string input;
    bool work = true;
    while (work == true)
    {
        getline(cin, input);
        if (input.empty() == true)
        {
            cout << "Please choose again: ";
            work = true;
        }
        else
        {
            c = input[0];
            work = false;
        }
    }
    return c;
}

char YOrN()
{
    char c;
    string input;
    bool work = true;
    while (work == true)
    {
        getline(cin, input);
        if (input.empty() == true)
        {
            cout << "Please choose again: ";
            work = true;
        }
        else
        {
            c = tolower(input[0]);
            if (c == 'y' || c == 'n')
            {
                work = false;
            }
            else
                cout << "Press 'y' for \"yes\" or 'n' for \"no\": ";
        }
    }
    return c;
}

int main()
{
    cout << "Welcome to Hangman utilizing C++!" << endl;
    cout << "Choose the difficulty. 1,2, or 3. 3 is the hardest: ";
    int difficulty;
    do
    {
        difficulty = InputInteger();
        if ((difficulty < 1 || difficulty > 3) == true)
        {
            cout << "Please provide a number form 1 to 3: ";
            difficulty = 9;
        }
    } while (difficulty == 9);

    int attempts = 15;
    switch (difficulty)
    {
        case 3:
            cout << "There is 5 attempts to guess the phrase." << endl;
            attempts = 5;
            break;
        case 2:
            cout << "There is 10 attempts to guess the phrase." << endl;
            attempts = 10;
            break;
        case 1:
            cout << "There is 15 attempts to guess the phrase." << endl;
            attempts = 15;
            break;
    }

    vector<string> vecWords;
    vecWords.push_back("Rio de Janeiro");
    vecWords.push_back("Variables and Constants");
    vecWords.push_back("Wild is always revealing");
    vecWords.push_back("Get out alive with Bear Grills");
    vecWords.push_back("Troodon");
    vecWords.push_back("Miroslav Erdelyi");

    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(vecWords.begin(), vecWords.end());
    const string theWord = *(vecWords.begin());
    string guessedWord = theWord;
    unsigned int lOfguessedWord = guessedWord.length();
    for (unsigned int i = 0; i < lOfguessedWord; i++)
    {
        guessedWord[i] = '-';
    }
    cout << "Word to guess consists of " << lOfguessedWord << " characters." << endl;

    char guess;
    char yOrN;
    bool play = true;
    for (unsigned int i = 0; i < lOfguessedWord; i++) // show spaces
    {
        if (theWord[i] == ' ')
            guessedWord[i] = ' ';
    }
    cout << guessedWord << endl;

    while (attempts != 0 && play == true)
    {

        cout << "There is " << attempts << " attempts remaining: ";
        guess = InputChar();
        for (unsigned int i = 0; i < lOfguessedWord; i++)
        {
            if (theWord[i] == guess)
                guessedWord[i] = guess;
        }
        cout << guessedWord << endl;
        if (attempts % 5 == 0 )
        {
            cout << "Do you want to guess whole phrase now? y/n: ";
            yOrN = YOrN();
            if (yOrN == 'y')
            {
                cout << "Please type in the phrase. Once done, press return." << endl;
                cout << "However, if you guess wrong, you will loose! Phrase is:" << endl;
                string proposedPhrase;
                getline(cin, proposedPhrase);
                if (proposedPhrase == theWord)
                {
                    cout << "Congratulations! You guessed it!" << endl;
                    break;
                }
                else
                {
                    cout << "No, that's not it! You lost! Try another time!" << endl;
                    break;
                }
            }
        }
        attempts --;
        if (guessedWord == theWord)
        {
            cout << "Congratulations! You guessed it!" << endl;
            break;
        }
        if (attempts <= 0)
        {
            cout << "Yor ran out of attempts. This is your last chance!" << endl;
            cout << "Do you want to guess whole phrase now? y/n: ";
            yOrN = YOrN();
            if (yOrN == 'y')
            {
                cout << "Please type in the phrase. Once done, press return." << endl;
                cout << "However, if you guess wrong, you will loose! Phrase is:" << endl;
                string proposedPhrase;
                getline(cin, proposedPhrase);
                if (proposedPhrase == theWord)
                {
                    cout << "Congratulations! You guessed it!" << endl;
                    break;
                }
                else
                {
                    cout << "No, that's not it! You lost!  Try another time!" << endl;
                    break;
                }
            }
        }

    }

    return 0;
}
