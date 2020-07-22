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


const int BUFFER_SIZE = 25;
int buffer[BUFFER_SIZE]; 

//fuction prototypes
void *producer(void *param);
void *consumer(void *param);
void create(int, int);

//global variables
sem_t semaphore;
sem_t mutex;
pthread_t producer;
pthread_t consumer;


int main(int argc, char *argv[]) 
{ 
  //Print basic information about the program
  std::cout << "=================================================================" << std::endl;
  std::cout << "CS 433 Programming assignment 4" << std::endl;
  std::cout << "Author: Joshua Matthews and Lauren Robbins" << std::endl;
  std::cout << "Date: 11/xx/2019" << std::endl;
  std::cout << "Course: CS433 (Operating Systems)" << std::endl;
  std::cout << "Description : " << std::endl;
  std::cout << "=================================================================\n" << std::endl;
  
  //variables to hold user input
  int sleepTime;
  int numProThreads;
  int numConThreads;

  //initilize semaphores
  sem_init(&mutex, 0, 1);
  sem_init(&semaphore, 0, BUFFER_SIZE);
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
  sleep(sleepTime);

  /* 6. Exit */ 
  return 0;
}

void *producer(void *param) 
{ 
  //buffer_item item; 

while (true) 
{ 
  /* sleep for a random period of time  
  sleep(...); 
  /* generate a random number */ 
  item = rand();
  if (insert_item(item)) //change to insert item into buffer 
    fprintf("report error condition");
  else 
    printf("producer produced %d\n",item); 
} 

void *consumer(void *param) 
{ 
  //  buffer_item item; 
  while (true) 
    { 
      /* sleep for a random period of time */ 
      // sleep(...); 
      if (remove_item(&item)) //change to pull item from buffer
	fprintf("report error condition"); 
      else 
	printf("consumer consumed %d\n",item); 
}

void create(int numProducer, int numConsumer)
{
  //create producer threads
  for (int i = 1; i < numProducer; i++)
    {
      pthread_create(&producer, NULL, producer, NULL);
    }
  //create consumer threads
  for (int j = 1; j < numConsumer; j++)
    {
      pthread_create(&consumer, NULL, consumer, NULL);
    }
}
