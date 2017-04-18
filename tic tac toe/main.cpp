#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

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
            c = tolower(input[0]);
            work = false;
        }
    }
    return c;
}

char YOrN()
{
    char c;
    do
    {
        c = InputChar();
        if( c != 'y' && c != 'n')
            cout << "Please provide 'y' or 'n': ";
    } while(c != 'y' && c != 'n');

    return c;
}

int InputNumber(int rangeMin = 0, int rangeMax = 8)
{
    int number;
    do
    {
        cin >> number;
    } while (number < rangeMin || number > rangeMax);
    return number;
}

void Instructions()
{
    cout << "TIC TAC TOE with simple AI by Pavol Rehorèík." << endl;
    cout << "Make your move known by entering a number, 0 - 8. The number" << endl;
    cout << "corresponds to the desired board position, as illustrated:" << endl << endl;
    cout << " 0 | 1 | 2" << endl;
    cout << " --------- " << endl;
    cout << " 3 | 4 | 5" << endl;
    cout << " --------- " << endl;
    cout << " 6 | 7 | 8" << endl << endl;
}

void PrintBoard(const vector<char> &crBoard)
{
    int i = 1;
    for (vector<char>::const_iterator constIte = crBoard.begin(); constIte != crBoard.end(); constIte++)
    {
        cout << *constIte;
        if (i%3 != 0)
            cout << "|";
        else
            cout << endl;
        if (i%3 == 0)
            cout << "-----" << endl;
        i++;
    }
}

bool IsLegal (const vector<char> &crBoard, int number)
{
    const char EMPTY = ' ';
    return (crBoard[number] == EMPTY ? true : false);
}

char IsWinner (const vector<char> &crBoard)
{
    const char EMPTY = ' ';


    const int WINNING_ROWS[8][3] = { {0, 1, 2},
                                     {3, 4, 5},
                                     {6, 7, 8},
                                     {0, 3, 6},
                                     {1, 4, 7},
                                     {2, 5, 8},
                                     {0, 4, 8},
                                     {2, 4, 6} };

    const int TOTAL_ROWS = 8;
    // if any winning row has three values that are the same (and not EMPTY),
    // then we have a winner
    for(int row = 0; row < TOTAL_ROWS; ++row)
    {
        if ( (crBoard[WINNING_ROWS[row][0]] != EMPTY) && (crBoard[WINNING_ROWS[row][0]] == crBoard[WINNING_ROWS[row][1]]) && (crBoard[WINNING_ROWS[row][1]] == crBoard[WINNING_ROWS[row][2]]) )
        {
            return crBoard[WINNING_ROWS[row][0]];
        }
    }

    // since nobody has won, check for a tie (no empty squares left)
    if (count(crBoard.begin(), crBoard.end(), EMPTY) == 0)
        return 'T';

    // since nobody has won and it isn’t a tie, the game ain’t over
    return 'N';

}

void MovesHuman (vector<char> &rBoard, const char sign)
{
    cout << "Enter position where to place your: " << sign << ", number between 0 - 8 included: ";
    int number = InputNumber();
    while (IsLegal(rBoard, number) == false)
    {
        cout << "That square is already occupied! Try again: " << endl;
        number = InputNumber();
    }
    cout << "Good, GOOD!" << endl;
    rBoard[number] =  sign;
}

void MovesComputer (vector<char> &rBoard, const char sign)
{
    vector<char> board = rBoard;
    unsigned int cMove = 0;
    bool found = false;
    const char EMPTY = ' ';
    //if computer can win on next move, that’s the move to make
    while (!found && cMove < board.size())
    {
        if (IsLegal(board, cMove))
        {
            board[cMove] = sign;
            found = IsWinner(board) == sign;
            board[cMove] = EMPTY;
        }
        if (!found)
        {
            cMove++;
        }
    }
    //otherwise, if human can win on next move, that’s the move to make
    if (!found)
    {
        cMove = 0;
        char human = 'O';
        while (!found && cMove < board.size())
        {
            if (IsLegal(board, cMove))
            {
                board[cMove] = human;
                found = IsWinner(board) == human;
                board[cMove] = EMPTY;
            }
            if (!found)
            {
                cMove++;
            }
        }
    }
    //otherwise, moving to the best open square is the move to make
    if (!found)
    {
        cMove = 0;
        unsigned int i = 0;
        const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
        //pick best open square
        while (!found && i < board.size())
        {
            cMove = BEST_MOVES[i];
            if (IsLegal(board, cMove))
            {
                found = true;
            }
            i++;
        }
    }
    cout << "I shall take square number " << cMove << endl;
    rBoard[cMove] = sign;
}

void PressAnyKey (void)
{
    cout << "Press any key to continue...";
    string garbage;
    getline(cin, garbage);
    getline(cin, garbage);
}

int main()
{
    Instructions();

    const char     X = 'X';
    const char     O = 'O';
    const char EMPTY = ' ';
    const int NUM_OF_SQUARES = 9;

    char answer;
    char human = O;
    char computer = X; // Computer starts unless player decides otherwise. X Always starts.

    vector<char> board(NUM_OF_SQUARES, EMPTY);
    PrintBoard(board);
    cout << "Do you want to start, human? (y/n): ";
    answer = YOrN();
    if (answer == 'y')
    {
        human = X; // So human can go first.
        computer = O;
    }

    bool gameGoesOn = true;
    char result;

    while (gameGoesOn == true)
    {
        result = IsWinner(board);
        cout << result << endl << endl;
        if (result == 'T' || result == 'O' || result == 'X')
        {
                gameGoesOn = false;
                break;
        }

        if (human == X)
        {
            MovesHuman(board, human);


            MovesComputer(board, computer);
            PrintBoard(board);
            result = IsWinner(board);
            cout << "----- Winner is: " << result << endl << endl;
            if (result == 'T' || result == 'O' || result == 'X')
            {
                gameGoesOn = false;
                break;
            }
        }
        else
        {
            MovesComputer(board, computer);
            PrintBoard(board);
            result = IsWinner(board);
            cout << "----- Winner is: " << result << endl << endl;
            if (result == 'T' || result == 'O' || result == 'X')
            {
                gameGoesOn = false;
                break;
            }
            MovesHuman(board, human);
        }
    }

    PressAnyKey();
    return 0;
}
