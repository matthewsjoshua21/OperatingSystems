// Remember to add comments to your code

#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include "ReadyQueue.h"

int main(int argc, char* argv[]) {
	//Print basic information about the program
	std::cout << "CS 433 Programming assignment 1" << std::endl;
	std::cout << "Author: Joshua Matthews and Lauren Robbins" << std::endl;
	std::cout << "Date: 09/16/2016" << std::endl;
	std::cout << "Course: CS433 (Operating Systems)" << std::endl;
	std::cout << "Description : Program to implement a priority ready queue of processes" << std::endl;
	std::cout << "=================================" << std::endl;


	// Test 1
	std::cout << "\n\nPerforming Test 1" << std::endl;

	ReadyQueue Procs;
	PCBTable table;
	table.makeTable(20);



	Procs.insertProc(table.getPCB(5));
	Procs.insertProc(table.getPCB(1));
	Procs.insertProc(table.getPCB(8));
	Procs.insertProc(table.getPCB(11));

	Procs.displayQueue();
	Procs.removeHighestProc();
	Procs.displayQueue();
	Procs.removeHighestProc();
	Procs.displayQueue();


	Procs.insertProc(table.getPCB(3));
	Procs.insertProc(table.getPCB(7));
	Procs.insertProc(table.getPCB(2));
	Procs.insertProc(table.getPCB(12));
	Procs.insertProc(table.getPCB(9));

	Procs.displayQueue();
	Procs.removeHighestProc();
	Procs.displayQueue();
	Procs.removeHighestProc();
	Procs.displayQueue();
	Procs.removeHighestProc();
	Procs.displayQueue();
	Procs.removeHighestProc();
	Procs.displayQueue();
	Procs.removeHighestProc();
	Procs.displayQueue();
	Procs.removeHighestProc();
	Procs.displayQueue();
	Procs.removeHighestProc();

	// Test 2
	std::cout << "\n\nPerforming Test 2" << std::endl;

	srand(time(0));
	//randomly select 10 processes from the PCB table and put them into q1
	//each process gets a random priority from 1 to 50 
	for(int i = 0; i < 10; i++)
	  { PCB temp;
	    int randomPriority = rand()%50+1;//random number between 1 and 50 for the priority
	    int randomProcess = rand()%20;//random number from the pcb table 
	    
	    temp = table.getPCB(randomProcess);
	    temp.setPriority(randomPriority);
	    Procs.insertProc(temp);
	    /*
	    Procs.insertProc(table.getPCB(randomProcess));
	    table.setPriority(randomPriority);
	    */
	    //	    cout << "i did a thing" << endl;
	  }
	      //start clock here 
	clock_t start = clock();

	      for(int i = 0; i < 1000000; i++)//going through loop 1000000 times
		{
		  int probability = rand()%2;//setting a 50/50 probability 

		  if(probability == 1)
		    {
		      PCB temp;
		      int randomProcess2 = rand()%20;
		      int randomPriority2 = rand()%50+1;

		      temp = table.getPCB(randomProcess2);
		      temp.setPriority(randomPriority2);
		      Procs.insertProc(temp);
		      // Procs.insertProc(table.getPCB(randomProcess2));

		    }

		  if(probability == 2)
		    {

		      Procs.removeHighestProc();
		    }
		}
	      clock_t end = clock();
	      double result = end-start;
	      cout << "\n\nTest 2 time = " <<( result/CLOCKS_PER_SEC) << "  seconds\n\n" << endl;
	      Procs.displayQueue();

	 







	

}
