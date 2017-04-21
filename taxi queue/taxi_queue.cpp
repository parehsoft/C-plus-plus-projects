#include <iostream>

using namespace std;

struct Taxi
{ // element structure (info about taxi)
  int id;
  Taxi* next;
};

typedef struct
{ // queue structure
  Taxi* first;
  Taxi* last;
  int qsize;
} taxiqueue;

/**
Initialize the queue.
*/
void queue_init (taxiqueue* q)
{
  q->first = NULL;
  q->last = NULL;
  q->qsize = 0;
}

bool is_empty_ (taxiqueue *q)
{ // check if taxiqueue is empty
  if ((q->first == NULL) && (q->last == NULL))
    return true; // return tru if is
  else
    return false; // return false if is not
}

/**
New elements into the queue.
*/
void new_element (taxiqueue *q)
{
  if (is_empty_(q) == true)
  { // the very own first taxi
    q->first = new Taxi; // alocate new Taxi on the heap
    if(q->first == NULL) // check if allocation went well
      {cerr << "Memory allocation error!\n"; return;}
    q->qsize ++; // increment q size
    q->last = q->first; // set the last pointer
    q->first->next = q->last; // set the Taxi's next pointer
    cout << "Enter integer id for the first taxi: ";
    cin >> q->first->id;
  }
  else
  { // another taxies
    if(q->qsize >= 10) // check first if que is full
      {cerr << "Queue is already full!\n"; return;}
    q->last->next = new Taxi; // than create new Taxi and check if there is memory error
    if(q->last->next == NULL)
     {cerr << "Memory allocation error!\n"; return;}
    q->last = q->last->next; // update the last pointer
    q->qsize ++; // update the q size
    q->last->next = q->last;
    cout << "Enter integer id for the new taxi: ";
    cin >> q->last->id;
  }
  return;
}

/**
Dequeue the first element.
*/
void dequeue (taxiqueue* q)
{
  if (is_empty_(q) == true) // check if it is empty
    {cout << "There's no taxi waiting! Queue is empty.\n"; return;}
  else // if it is not empty
  {
    Taxi* free_the_first; // temporary variable to remember which element will be destroyed
    if (q->first == q->last)
    { // Check first if there is only one element in the queue (q->first == q->last). Th pointers points to the same location, to the only element.
      free_the_first = q->first; // store what to delete
      queue_init(q); // put queue to empty state
      cout << "Taxi, id: " << free_the_first->id << " was dispatched.\n";
      delete(free_the_first); // and delete the element
    }
    else
    { // if there is more than one element
      free_the_first = q->first; // store what to delete
      q->first = q->first->next; // set the first to following element
      cout << "Taxi, id: " << free_the_first->id << " was dispatched.\n";
      delete(free_the_first); // and delete the former first element, because it was dispatched
      q->qsize --; // decrement the queue size meter
    }
  }
  return; //end
}

/**
Disband the queue on exit.
*/
void disband (taxiqueue* q)
{
  if (is_empty_(q) == true) // check if it is empty
    return;
  else // if the queue is not empty
  {
    Taxi* p_temp_first; // temporpary pointer
    while (true) // disband the queue
    {
      p_temp_first = q->first; // store the first into temporary
      q->first = q->first->next; // update first to next element
      if(q->first == q->last) // check if we are on last element
      {
        delete(q->first); // deltete it
        break; // finished as queue is empty
      }
      delete(p_temp_first); // if deleted element is not last, delete it
    }
  }
  return;
}

/**
Show the queue.
*/
void show_q (taxiqueue* q)
{
  if (is_empty_(q) == true)
    {cout << "Queue is empty.\n"; return;}
  else
  {
    Taxi* temp_next; // temporary variable s
    temp_next = q->first; // store pointer to first element into temporary variable
    cout << "Queue size is: " << q->qsize << endl; // print the queue size
    while (true)
    {
      cout << "Id: " << temp_next->id << endl; // show the id of taxis in the queues
      if (temp_next == q->last)
        break; // if the end is reached, iteration is terminated
      temp_next = temp_next->next; // store pointer to next element into the temp variable
    }
  }
  return;
}

int main (void)
{
  cout << "Press d to dispatch taxi.\n";
  cout << "Press n to create new taxi in the queue\n";
  cout << "Press s to show queue of taxis.\n";
  cout << "Press x to destoy all of them!\n";

  taxiqueue q; // queue initialization
  queue_init(&q);

  char command;
  short int exitflag = 0;
  while (1)
  {
    cin >> command;
    switch (command)
    {
      case 'd': cout << "D was pressed.\n"; // dequeue first, dispatch the taxi
                //disband(&q);
                dequeue(&q);
               break;
      case 'n': cout << "N was pressed.\n"; // enqueue an element, new taxi arrived
                new_element(&q);
               break;
      case 's': cout << "S was pressed.\n"; // show the elements in the queue, show parkingplot
                show_q(&q);
               break;
      case 'x': cout << "X was pressed, disbanding the queue...\n"; // exit the program, delete the allocated memory first and exit
                exitflag = 1;
                disband(&q);
                cout << "and exiting.\n";
               break;

      default: cout << "Anything else pressed.\n";
              break;

    } // SWITCH end

    if (exitflag == 1)
      break;
  }

  return 0;
}
