#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include <time.h>  
#include <unistd.h>
#include <semaphore.h>

using namespace std;

const int BUFFER_SIZE = 5;
int buffer[BUFFER_SIZE]; 

//fuction prototypes
void *producerThread(void *param);
void *consumerThread(void *param);
void create(int, int);
bool insert_item(int item);
bool remove_item(int *item);


//global variables
sem_t semaphore;
sem_t mutex;
pthread_t producer;
pthread_t consumer;
int count = -1;
int jobs = 0;
int item;

int main(int argc, char *argv[]) 
{ 
  //Print basic information about the program
  std::cout << "=================================================================" << std::endl;
  std::cout << "CS 433 Programming assignment 4" << std::endl;
  std::cout << "Author: Joshua Matthews and Lauren Robbins" << std::endl;
  std::cout << "Date: 11/20/2019" << std::endl;
  std::cout << "Course: CS433 (Operating Systems)" << std::endl;
  std::cout << "Description : Producer and Consumer Problem" << std::endl;
  std::cout << "=================================================================\n" << std::endl;
  
  //variables to hold user input
  int sleepTime;
  int numProThreads;
  int numConThreads;

  /* 1. Get command line arguments argv[1],argv[2],argv[3] */
  cout << "Enter how long the main thread sleep before terminating..\n> ";
  cin >> sleepTime;
  cout << "Enter the number of producer threads.. \n> ";
  cin >> numProThreads;
  cout << "Enter the number of consumer threads.. \n> ";
  cin >> numConThreads;
 
  /* 3. Create producer thread(s) */ 
  /* 4. Create consumer thread(s) */ 
  create(numProThreads, numConThreads);
 
  /* 5. Sleep */ 
  cout << "Now the main() will sleep..." << endl;
  sleepTime = sleepTime * 5;
  sleep(sleepTime);

  /* 6. Exit */ 
  return 0;

}

void *producerThread(void *param) 
{ 
  //cout << "Producer Thread..." << endl;
  //buffer_item item; 
  // int item;
  int exit = 1;

  while (exit)
    {
      // sleep for a random period of time  
      int time = rand() % 10 + 1;      
      sleep((time/100));
      //  cout << "sleeping.." << endl;
      //generate a random number */ 
      item = rand() % 100 + 1;
      //semwait
      sem_wait(&semaphore); //empty
      sem_wait(&mutex);

      if (insert_item(item))
	{
	  cout << "producer produced " << item << ". ";
	  cout << "Buffer contents are [";
	  for (int i = 0; i < jobs; i++)
	    cout << buffer[i] << ", ";
	  cout << "]" << endl;
	  exit = 0;
	}
      else
	{
	  cout << "Buffer is full!" << endl;
	}
      
      sem_post(&mutex);
      
      sem_post(&semaphore);//full
    }
} 

void *consumerThread(void *param) 
{ 
  //  cout << "Consumer Thread..." << endl;
  // int item;
  int exit = 1;

  while (exit)
    {
      
      //sleep for a random period of time */ 
      int time = rand() % 10 + 1;
      sleep((time/100));
      
      sem_wait(&semaphore); 
      sem_wait(&mutex);
      
	if (remove_item(&item))
	  {
	    cout << "consumer consumed " << item << endl;
	    exit = 0;
	  }
	else
	  {
	    cout << "Buffer is empty!" << endl;
	  }
	sem_post(&mutex);
	sem_post(&semaphore);
	
    }
  
}

void create(int numProducer, int numConsumer)
{
  cout << "Initializing Threads..." << endl;

  sem_init(&mutex, 0, 1);
  sem_init(&semaphore, 0, BUFFER_SIZE);

  //create producer threads
  for (int i = 0; i < numProducer; i++)
    {
      pthread_create(&producer, NULL, producerThread, NULL);
    }
  //create consumer threads
  for (int j = 0; j < numConsumer; j++)
    {
      pthread_create(&consumer, NULL, consumerThread, NULL);
    }
  //
  // cout << "Finishing Threads..." << endl;
}

bool insert_item(int item) //used template from book
{
  // cout << "Inserting..." << endl;
  //checks if the buffer is full
  if (jobs < BUFFER_SIZE)
    {
      //puts the item into the buffer
      buffer[count + 1 % BUFFER_SIZE] = item; 

      //increments count 
      count++;
      jobs++;
      //if successful returns true
      return true;
    }
  else
    {
      //if not successful, returns false and error message
      return false; 
    }
}

bool remove_item(int *item) //used template from book 
{
  // cout << "Removing..." << endl;
  //checks if the buffer is empty
  if (jobs >= 0)
    {
      //take the item out of the buffer
      *item = buffer[count % BUFFER_SIZE];
      
      //decrement the counter
      count--;
      jobs--;
      //if successful, return true
      return true;
    }
  else
    {
      //if not successful, returns false and error message
      return false; 
    }
}
