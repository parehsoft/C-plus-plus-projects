#include <iostream>
#include <limits.h>

using namespace std;

void fill_array_ (int* array_, int lenght)
{
  cout << endl;
  for (int i = 0; i < lenght; i++)
    cin >> array_[i];
}

void print_array_ (int* array_, int length)
{
  cout << endl;
  for (int i = 0; i < length; i++)
    cout << array_[i] << " ";
}

 /** requires pointer to field to msort, start INDEX of the field and end INDEX of the field **/
void merge_sort (int* array_, int start, int lenght)
{
  if (lenght == start + 1) //finit sate of recursion (field contains 2 elements)
    return;

  int middle = (start + lenght) / 2;
  merge_sort(array_, start, middle); // sort lower half of sub arrays
  merge_sort(array_, middle, lenght); // sort upper half of sub arrays

  int i = start; // index variables for each of sub-fields
  int j = middle;
  int temp[lenght]; // end index + 1 is capacity of the field
  int temp_index = start;

  /** merging loop **/
  for (/*i and j are already initialized*/; (i < middle) || (j < lenght); /*we will increase i and j inside of for*/)
  {
    if (i < middle && j < lenght) //when we have something to compare
    {
      if (array_[i] > array_[j])
      {
        temp[temp_index] = array_[i];
        i++;
      }
      else
      {
        temp[temp_index] = array_[j];
        j++;
      }
    }
    else // when we don't to compare any more, than move the rest of the array_ which left to temporary array_
    {
      if (i < middle) // finish i-indexed field
      {
        temp[temp_index] = array_[i];
        i++;
      }
      else // finish j-indexed field
      {
        temp[temp_index] = array_[j];
        j++;
      }
    }

    temp_index++; // when anything is done, increase index in temporary array_ to put there another element
  }

  /** copy temp to field wchich needs to be sorted **/
  for (i = start; i < lenght; i++)
    array_[i] = temp[i];
}

int my_binary_search (int* array_, int start, int length, int element)
{
  if (length == start + 1) // only 1 element in the field (if (1 == 0 + 1)) or (if (6 == 5 + 1))
  {
    if (array_[start] == element) // is element the searched element ?
      return start; // yes return it's position
    else
      return -1; // no, than return error
  }

  int middle = (start + length) / 2;
  if (array_[middle] == element)
    return middle;
  else
  {
    if (array_[middle] < element)
      my_binary_search(array_, start, middle, element);
    else
      my_binary_search(array_, middle, length, element);
  }
}

int main()
{
  int my_array[10];
  int element;
  cout << "Enter searched number: ";
  cin >> element;

  cout << "Enter 10 elements for the array: ";
  fill_array_(my_array, 10);
  print_array_(my_array, 10);

  int start = 0;
  int lenght = 10;
  merge_sort(my_array, start, lenght);
  print_array_(my_array, 10);
  cout << "\n";

  int position = my_binary_search(my_array, start, lenght, element);
  if (position == -1)
  {
    cerr << "This is not the array, that you are looking for... (requred element is not present).\n";
    return -1;
  }
  cout << "Searched element is in position number: " << position << ".\n";

  return 0;
}
