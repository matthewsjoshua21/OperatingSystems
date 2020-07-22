#include <iostream>
#include "ReadyQueue.h"

// TODO: Add your implementation of ReadyQueue here

using namespace std;

// constructor
ReadyQueue::ReadyQueue()
{  count = 0;  // no jobs yet
}

// destructor does nothing
ReadyQueue::~ReadyQueue() {}

// Purpose: to add a process to a right place in the ReadyQueue
// Argument: j is the process  priority number-this will change when pulling the number from PCB
void ReadyQueue::insertProc(PCB process)
{
  // ** add the process j at the rear (update count)
  q1[count] = process;
  q1[count].setProcState(ProcState::READY);
  count++;
  trickleup(); // moves the process to the right place
}


void ReadyQueue::removeHighestProc()  //this removes the highest priority
{
  //cout << "printing: " << Q[0] <<endl;
  reheapify();
}

//return the number of elements in the queue q1--NEW
int ReadyQueue:: size()
{
  return count;
}

// Purpose: to display all processes
void ReadyQueue::displayQueue()
{ cout << "Display Processes in Ready Queue: " << endl;
  // ** loop to display processes from slot 0 to slot count-1 horizontally. No need to show a tree format.
  for (int i = 0; i <= count-1; i++)
    cout << "Proc ID = " << q1[i].getId() << ", " << "priority = " << q1[i].getPriority() << endl;
  //cout << endl;
}

// Utility functions follow: ------------------


// Purpose: to make the very last process trickle up to the right location
void ReadyQueue::trickleup()
{
  int x = count-1;  // the very last process location
  int p; // variable to hold parent of x
  // ** while x is > 0
  // compare Q[x] with the parent and if the parent is bigger swap & update x to be the parent . Otherwise stop.
  //  You can call getParent to get the location of the parent
  while (x > 0)
    {
      p = getParent(x);
      if ( q1[x].getPriority() < q1[p].getPriority())
        {
	  PCB temp;
	  temp = q1[x];
	  q1[x] = q1[p];
	  q1[p] = temp;
	  x = p;
        }
      else
	return;

    }
}

// Purpose: find the location of the parent
// The child location is given.  Need to call even.
int ReadyQueue::getParent(int child)
{  // ** return the parent location based on the child loc
  int parent; // declare a variahble to hold position of parent
  if (even(child)) // check if even or odd case
    parent = ((child - 2)/2);
  else
    parent = ((child - 1)/2);
  return parent;

}

// Purpose: is location i even? Important in finding its parent location
bool ReadyQueue::even(int i)
{
  if ((i % 2) ==  0) return true; else return false; }


// Purpose: to reheapify the ReadyQueue after printing
void ReadyQueue::reheapify()
{
  q1[0].setProcState(ProcState::RUNNING);
  q1[0] = q1[count-1];  // move the last process to the front
  int x = 0;
  count--;
  // ** start X at the root and repeat the following:
  // Find the location of the smaller child if the child is
  // not off the tree yet
  // If the smaller child is smaller than the parent, swap
  //     and X becomes the smaller child
  // else stop to loop
  while (x < count-1)
    {
      int c = getSmallerchild(x);
      if (q1[x].getPriority() > q1[c].getPriority())
        {
	  PCB temp = q1[x];
	  q1[x] = q1[c];
	  q1[c] = temp;
	  x = c;

        }
      else
	return;
    }
}

// Purpose: to find the location of the smaller child
// where children at locations 2*i+1 and 2*i+2
int ReadyQueue::getSmallerchild(int i)
{
  int childL,childR, smallest; // variables to hold the smallest values
  // ** return the location of the smaller child
  if ((2*i)+2 <= count-1) //check if there are enough elements
    {
      childL = (2 * i)+1;
      childR = (2 * i)+2;
    }
  else if ((2*i)+1 <= count-1) //check if only left child exists
    {
      smallest = (2*i)+1;
      return smallest;
    }
  else // if position is already at smallest
    {
      smallest = i;
      return smallest;
    }
  if (q1[childL].getPriority() > q1[childR].getPriority())
    smallest = childR;
  else
    smallest = childL;
  return smallest;

}


