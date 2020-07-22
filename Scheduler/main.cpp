// Remember to add comments to your code

#include <iostream>
#include <cstdlib>
#include "event.h"
#include "scheduler.h"

using namespace std;

//void run(EventQueue &event_queue);

int main(int argc, char* argv[]) {
	//Print basic information about the program
	std::cout << "=================================================================" << std::endl;
	std::cout << "CS 433 Programming assignment 3" << std::endl;
	std::cout << "Author: Joshua Matthews and Lauren Robbins" << std::endl;
	std::cout << "Date: 10/31/2019" << std::endl;
	std::cout << "Course: CS433 (Operating Systems)" << std::endl;
	std::cout << "Description : Program to simulate CPU scheduling algorithms" << std::endl;
	std::cout << "=================================================================\n" << std::endl;

	
	int nproc = 1;
	int choice;
	// Create a event queue 
	EventQueue event_que;
	
	
	const int QUIT_TIME = 300000;	// 300,000 ms = 5 minutes 

	Scheduler *p_scheduler;

	cout << "How many processes would you like to simulate?\n";
	cin >> nproc;
	std::cout << "**********************(OPTION 0)***********************************" << std::endl;
	std::cout << "****************Simulate FCFS scheduler****************************" << std::endl;
	std::cout << "**********************(OPTION 1)***********************************" << std::endl;
	std::cout << "****************Simulate SJF scheduler****************************" << std::endl;
	std::cout << "Please select a simulation:\n";
	cin >> choice;
	
	p_scheduler = new Scheduler(nproc, choice, &event_que);
	
	int current_time = 0;
	// Main loop of the simulation
	while(!event_que.empty() && current_time < QUIT_TIME)
	  {
	    Event e = event_que.top();              // get the next event
	    event_que.pop();                        // remove the next event from queue
	    // Handle the event
	    p_scheduler -> handle_the_event(e);
	  }

	delete p_scheduler;

}
/*
void run(EventQueue &event_que)
{
  int current_time = 0;
  // Main loop of the simulation
  while(!event_que.empty() && current_time < QUIT_TIME) 
    {
      Event e = event_que.top();              // get the next event
      event_que.pop();                        // remove the next event from queue
      // Handle the event
      p_scheduler -> handle_the_event(e);
    }
  
    delete p_scheduler;


    }*/
