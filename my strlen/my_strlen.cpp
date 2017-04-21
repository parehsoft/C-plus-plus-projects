#include <iostream>
#include <cstdio>

using namespace std;

int my_strlen (char* _array)
{
  int i = 0; // index
  while (_array[i] != '\0')
   i++;
  return i;
}

int main()
{
  char _array[101];
  fgets(_array, 101, stdin);
  cout << my_strlen(_array) << endl;
}
