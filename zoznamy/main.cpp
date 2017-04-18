/**
 **************************************************************************
 )   ___
(__/_____)                 ,     /)
  /       _____       __     _  (/  _/_
 /       (_) /_)_(_/_/ (__(_(_/_/ )_(__
(______)  .-/   .-/        .-/
         (_/   (_/        (_/
  ____ ____ ____ ____ ____ _________ ____ ____ ____ ____ ____ ____ ____ ____
||P |||a |||v |||o |||l |||       |||R |||e |||h |||o |||r |||č |||í |||k ||
||__|||__|||__|||__|||__|||_______|||__|||__|||__|||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|/_______\|/__\|/__\|/__\|/__\|/__\|/__\|/__\|/__\|

 **************************************************************************
**/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct TElement
{ // Structure to contain element of the list.
    int data; // Element's data.
    TElement *next; // Pointer to next element.
};

struct TList
{ // Structure to contain info about the list itself, where it begins and where it ends.
    TElement *first; // Where the list begins. Pints to the first list element.
    TElement *last; // where the list ends. Points to the last list element.
};

bool IsListEmpty (TList *mylist)
{ // Check if my list is empty. Returns true or false, empty or not empty.
    if (mylist->first == nullptr && mylist->last == nullptr) // Check list is empty. So start and the end of the list points nowhere.
        return true; // List is empty.
    else
        return false; // List is not empty.
}

TElement *CreateElement(void)
{ // Allocates new element on the heap. Returns pointer to the newly allocated list element.
    TElement *newElement = new TElement; // Allocates memory and store the address into the pointer.

    newElement->data = rand() % 100 + 1; // Fill the newest element with some random data.
    newElement->next = nullptr; // Newly constructed element will always point to NULL as the next element.

    return newElement; // And return the pointer tot he newly created element.
}

void PrintListElemnets (TList *mylist)
{ // Print the content of the list. Returns nothing.
    if (IsListEmpty(mylist) == true) // If the list is empty,
        cout << "List is empty!\n"; // display it's empty :-).
    else // It the list is not empty.
    {
        TElement *elementHelpingPointer; // Create helping pointer to list element.
        elementHelpingPointer = mylist->first; // Helping pointer will point to the same location where first element of the list is.
        do // Go through the list to the end.
        {
            cout << elementHelpingPointer->data << ", "; // Print element's data.
            elementHelpingPointer = elementHelpingPointer->next; // Put address of the next element to the helping pointer.
        } while (elementHelpingPointer != nullptr); // Repeat while the helping pointer is NULL. (The last list element point to NULL as next element, so this NULL will be stored in this helping pointer which indicates the end of the list.)
        cout << endl;
    }
}

bool AddFirstElement (TList *myList)
{ // Adds the first element. Returns true or false, whether the operations was successful or not.
    TElement *newElement = CreateElement(); // Create new element using my own function.
    if (newElement == nullptr) // If there is not enough memory, than return false, because the operation was unsuccessful.
        return false; // Returns false if the new element allocation failed.

    if (IsListEmpty(myList) == true)
    { // In case list was empty at the beginning, the first and the last list pointers from the TList structure will point to this new and the only element :-).
        myList->first = newElement;
        myList->last = newElement;
    }
    else
    {
        TElement *originalFirst = myList->first;
        myList->first = newElement;
        newElement->next = originalFirst;
    }
    return true;
}

bool AddLastElement (TList *myList)
{
    TElement *newElement = CreateElement();
    if (newElement == nullptr)
        return false;

    if (IsListEmpty(myList) == true)
    {
        myList->first = newElement;
        myList->last = newElement;
    }
    else
    {
        TElement *originalLast = myList->last;
        myList->last = newElement;
        originalLast->next = newElement;
    }
    return true;
}

void DeleteFisrt (TList *myList)
{
    if (IsListEmpty(myList) == true)
    {
        ;
    }
    else
    {
        if (myList->first == myList->last)
        { // If there is only one element left.
            TElement *storeFirst = myList->first;
            myList->first = nullptr;
            myList->last = nullptr;
            delete storeFirst;
        }
        else
        {
            TElement *originalFirst = myList->first;
            myList->first = originalFirst->next;
            delete originalFirst;
        }
    }
}

void DeleteTheEntireList (TList *myList)
{
    while (IsListEmpty(myList) != true)
    {
        DeleteFisrt(myList);
    }
}

int NumberOfElementsInTheList (TList *myList)
{
    if (IsListEmpty(myList) == true )
        return 0;

    int counter = 0;
    TElement *nextElement = myList->first;
    do
    {
        nextElement = nextElement->next;
        counter++;
    } while (nextElement != nullptr);

    return counter;
}

TElement *GetPointerToElementOnPosition (TList *myList, int requestedPosition)
{
    if (IsListEmpty(myList) == true)
        return nullptr;

    if (requestedPosition < 0)
        return nullptr;

    if (requestedPosition >= NumberOfElementsInTheList(myList))
        return nullptr;

    TElement *myFoundElemet = myList->first;
    for (int i = 0; i <= requestedPosition; i++)
    {
        if (i == requestedPosition)
            break; // I found it!
        else
            myFoundElemet = myFoundElemet->next;
    }
    return myFoundElemet;
}

void PrinElementOnPosition (TList *myList, int requestedPosition)
{
    TElement *elementToBePrinted = GetPointerToElementOnPosition(myList, requestedPosition);
    if (elementToBePrinted == nullptr)
        cout << "Such element does not exist!\n";
    else
        cout << "Element on position " << requestedPosition << " is: " << elementToBePrinted->data << " .\n";
}

void MergeThem (int left[], int nL, int right[], int nR, int field[], int nF)
{
    int i = 0, j = 0, k = 0;
    while (i < nL && j < nR)
    {
        if   (left[i] <= right[j])
            { field[k] = left[i];  i++; }
        else
            { field[k] = right[j]; j++; }
        k++;
    }
    while (i < nL)
        { field[k] =  left[i]; i++; k++; }
    while (j < nR)
        { field[k] = right[j]; j++; k++; }
}

void mergeSort(int field[], int length)
{
    if (length < 2)
        return;

    int mid = length / 2;
    int left[mid];
    int lengthMinusMid = length - mid;
    int right[lengthMinusMid];

    for (int i = 0; i < mid; i++)
        left[i] = field[i];
    for (int i = mid; i < length; i++)
        right[i - mid] = field[i];

    mergeSort(left,  mid);
    mergeSort(right, lengthMinusMid);

    MergeThem(left, mid/*side of left*/, right, lengthMinusMid/*size of right*/, field, length /*size of field*/);
}

void SortTheEntireList(TList *myList)
{
    int numberOfElementsInTheList = NumberOfElementsInTheList(myList);
    int shadowField[numberOfElementsInTheList];
    for (int i = 0; i < numberOfElementsInTheList; i++)
    {
        shadowField[i] = (GetPointerToElementOnPosition(myList, i))->data;
    }

    mergeSort(shadowField, numberOfElementsInTheList);

    for (int i = 0; i < numberOfElementsInTheList; i++)
    {
        (GetPointerToElementOnPosition(myList, i))->data = shadowField[i];
    }
}

void DisplayHelp (void)
{
    cout << endl;
    cout << "****************************" << endl;
    cout << "How to control:" << endl;
    cout << "press 'x' to exit," << endl;
    cout << "press 'h' to display this help, \n" << endl;

    cout << "press 'd' to delete the entire list." << endl;
    cout << "press 'f' to add First element into the list," << endl;
    cout << "press 'g' to delete the (G)first element." << endl;
    cout << "press 'l' to add Last element into the list," << endl;
    cout << "press 'o' to sOrt the entire list, " << endl;
    cout << "press 'p' to print specific element." << endl;
    cout << "press 's' show the elements of the list." << endl;
}

int main()
{
    // Empty list initialization.
    TList TList_mylist;
    TList_mylist.first = nullptr;
    TList_mylist.last  = nullptr;

    DisplayHelp();

    string s = "";
    while (1)
    {
        getline(cin, s);
        if (s.empty())
        {
            cout << "Please specify input according to help:\n";
            s[0]='h';
        }

        char c = tolower(s[0]);
        switch (c)
        {
            case 'h':
                DisplayHelp();
                break;
            case 'f':
                cout << "Adding new first element...";
                if (AddFirstElement(&TList_mylist) == true)
                    cout << " Done!\n";
                else
                    cout << " FAILED! New element can't be added due to memory failure!\n";
                PrintListElemnets(&TList_mylist);
                cout << "Number of elements is: " << NumberOfElementsInTheList(&TList_mylist) << " ." << endl;
                break;
            case 'l':
                cout << "Adding new last element...";
                if (AddLastElement(&TList_mylist) == true)
                    cout << " Done!\n";
                else
                    cout << " FAILED! New element can't be added due to memory failure!\n";
                PrintListElemnets(&TList_mylist);
                cout << "Number of elements is: " << NumberOfElementsInTheList(&TList_mylist) << " ." << endl;
                break;
            case 's':
                cout << "Printing list elements:\n";
                PrintListElemnets(&TList_mylist);
                cout << "Number of elements is: " << NumberOfElementsInTheList(&TList_mylist) << " ." << endl;
                break;
            case 'g':
                cout << "First element deleted.\n";
                DeleteFisrt(&TList_mylist);
                PrintListElemnets(&TList_mylist);
                cout << "Number of elements is: " << NumberOfElementsInTheList(&TList_mylist) << " ." << endl;
                break;
            case 'd':
                DeleteTheEntireList(&TList_mylist);
                cout << "Entire list was deleted.\n";
                PrintListElemnets(&TList_mylist);
                cout << "Number of elements is: " << NumberOfElementsInTheList(&TList_mylist) << " ." << endl;
                break;
            case 'p':
                cout << "Caution! List is indexed same as the arrays are!\n0th, 1st, 2nd, 3rd, 4th... So your position is: 4th!\n";
                PrinElementOnPosition(&TList_mylist, 4);
                break;
            case 'x':
                cout << "OK, I will exit now... ";
                break;
            case 'o':
                cout << "Sorted list is:\n";
                SortTheEntireList(&TList_mylist);
                PrintListElemnets(&TList_mylist);
                break;
            default:
                cout << "Please use proper input:";
                DisplayHelp();
                break;
        }
        if (c == 'x')
        {
            if (IsListEmpty(&TList_mylist) == false) // If the list is not empty, clean up the mess before you exit.
                DeleteTheEntireList(&TList_mylist);

            cout << "Done!";
            break;
        }
    }
    return 0;
}
