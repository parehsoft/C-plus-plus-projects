#include <iostream>
#include <limits.h>

using namespace std;

int fillarray (int *myarray, int s_ize)
{
  cout << "Now provide numbers within int limit for each element of the array: ";
  for (int i = 0; i < s_ize; i++)
  {
    cin >> myarray[i]; // read number to the cell
    if (myarray[i] <= INT_MIN || myarray[i] >= INT_MAX) // test it for limit
    {
      for (int j = 0; j < 3; j++) // read aditional 2 times if the imput was incorrect
      {
        if (j >= 2) // terminate if reading for 3rd time
        {
          cout << "You have failed provide valid number too many times now, termination command received.\n";
          return -1;
        }
        cout << "Please provide valid number: ";
        cin >> myarray[i];
        if (myarray[i] <=INT_MIN || myarray[i] >= INT_MAX)// Check again, if correct break the for iteration
          cout << "Wrong number.\n";
        else
          break;
      } // ending for reading for value
    } // ending check
  } // ending reading elements for array
  return 0;
}

int numberOfOccurences (int *myarray, int s_ize, int value)
{
  int occurences = 0;
  for (int i = 0; i < s_ize; i++)
    if (myarray[i] == value)
      occurences++;

  return occurences;
}

void occurencePositions (int *myarray, int s_ize, int *positions, int value)
{
  int indexInPositions = -1;
  for (int i = 0; i < s_ize; i++)
  {
    if (myarray[i] == value)
    {
      ++indexInPositions;
      positions[indexInPositions] = i;
    }
  }
}

int main()
{
  cout << "\n" << INT_MIN << "  " << INT_MAX << "\n";
  cout << "Provide a size for array from 1 to 19: ";
  int n;
  cin >> n;
  if (n < 1 || n > 19)
  {
    for (int i = 0; i < 4; i++)
    {
      if (i == 3)
      {
        cout << "You have failed provide valid number too many times now, termination command received.\n";
        return -1;
      }
      cout << "Provide valid number again: ";
      cin >> n;
      if (n >= 1 && n <= 19)
        break;
    }
  }

  int myarray[n];
  if (fillarray(myarray, n) == -1) // fill the array
    return -1;

  cout << "\n";
  for (int i = 0; i < n; i++)
    cout << myarray[i] << " ";

  int value;
  cout << "\n Enter number you would like to find in the array: ";
  cin >> value;

  int occurences = numberOfOccurences(myarray, n, value);
  if (occurences == 0)
  {
    cout << "There were 0 occurences.\n";
    return -1;
  }

  int positions[occurences];
  occurencePositions(myarray, n, positions, value);

  cout << "Value " << value << " is present in possitions:\n";
  for (int i = 0; i < occurences; i++)
  {
      cout << positions[i] << " ";
  }
  cout << "\n";

  return 0;
}
