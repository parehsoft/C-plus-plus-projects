#include <iostream>
#include <limits.h>

using namespace std;

void fill_array (int* pole, int lenght)
{
  cout << endl;
  for (int i = 0; i < lenght; i++)
    cin >> pole[i];
}

void print_array (int* pole, int length)
{
  cout << endl;
  for (int i = 0; i < length; i++)
    cout << pole[i] << " ";
}

void selection_sort (int* pole, int lenght)
{
  int index_biggest;
  int biggest;
  int temporary;
  for (int j = 0; j < lenght - 1; j++) // increasing the j variable as index where the rest part of array starts
  {
    biggest = pole[j];
    for (int i = j + 1; i < lenght; i++) // find maximum of remaining array
    {
      if (pole[i] > biggest)
      {
        biggest = pole[i];
        index_biggest = i;
      }
    }
    temporary = pole[j];
    pole[j] = pole[index_biggest];
    pole[index_biggest] = temporary;
  }
}

int main()
{
  int my_array[10];
  fill_array(my_array, 10);
  print_array(my_array, 10);
  selection_sort (my_array, 10);
  print_array(my_array, 10);
  cout << "\n";
  return 0;
}
