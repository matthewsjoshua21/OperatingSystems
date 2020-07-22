// Remember to add comments to your code
// ...

#pragma once

#include "PCB.h"

//i left the ones he created in here in comments to see what we are supposed to be passing to the functions

	// TODO: Implement the required functions. Add necessary member fields and functions
	// You may use different parameter signatures from the example below

	// add the PCB of a process into the ready queue.
	//void insertProc(PCB* pcbPtr);

	// remove and return the PCB with the highest priority from the queue
	// PCB* removeHighestProc();

class ReadyQueue
{
 private:

  PCB q1[20];   // array holding processes - only priority numbers are stored
  int count;   // how many processes are in the array-use in size function
  // jobs are in slots 0 through count-1

  // Utility functions
  void reheapify();  // reheapify after printing
  // - involves moving the last job to the front and trickling down
  int  getSmallerchild(int);  // return location of the smaller child
  //- compares L and R children of the given location
  void trickleup();    // trickling up after adding at the rear
  int getParent(int);  // return the parent location given the child loc
  bool even(int);      // is the number even?  Needed to find the parent

 public:
  ReadyQueue();
  ~ReadyQueue();
  void insertProc(PCB);  // insert the process id and priority
  void removeHighestProc();      // remove the process with the highest priority
  void displayQueue();    // display queue
  // size() to return the number of elements in the queue
  int size();
};
      
