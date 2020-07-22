#include <cstdlib>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <vector>
#include <sys/wait.h>

#define MAX_LINE 80/* The maximum length command */

using namespace std;

// Function prototypes
void argHistory();
void parser(char buffer[], char * args[]);
void execCommand(char * arg[]);

//Global arrays
char buffer[MAX_LINE];
char save[MAX_LINE];
//Global vector
vector<string> history;
//Global variables
bool ampersand = false;
string command;

int main(void)
{
  cout << "*******************************************" << endl;
  cout << "Homework 2: Unix Shell and History Feature.\nAuthors: Lauren Robbins & Joshua Matthews." << endl;
  cout << "*******************************************" << endl;

  char *args[MAX_LINE/2 + 1]; /* command line arguments */

  int should_run = 1; /* flag to determine when to exit program */
  while(should_run)
    {
      printf("osh>");
      fflush(stdout);
      //  After reading user input, the steps are: *
      //  (1) fork a child process using fork() *
      //  (2) the child process will invoke execvp() *
      //  (3) parent will invoke wait() unless command included &
      //accept string from user and save
      cin.getline(buffer, MAX_LINE);
      //strcpy functions copies from buffer to save
      strcpy(save, buffer);

      // pass command to parser
      parser(buffer, args);
      // pass user comand to command
      command = args[0];
      // check to see if command is exception case
      if (command == "exit" || command == "EXIT" || command == "history" || command == "History" || command[0] == '!')
	{
	  if (command == "exit" || command == "EXIT")
        {
	  should_run = 0;
      	}
      	else if (command == "history" || command == "History")
        {
	  argHistory();
      	}

	else if (command[0] == '!')
	  { //variable for history execution
	    int num;

	    if (command == "!!")
	      {

		if (history.empty())
		  {
		    cout << "History is empty!" << endl;
		    break;
		  }

		size = history.size();
	      }

	    //
	    else
	      { //temp variable for holding num of command
		string temp;
		temp = command[1];
		// atoi converts string to an interger
		// .c_str() converts temp to string objects value
		num = atoi(temp.c_str());

		//error if history is empty
		if (num > history.size())
		  {
		    cout << "ERROR: command does not exist!" << endl;
		    break;
		  }
	      }
	    //
	    cout << history[size - 1] << endl;
	    //convert string to be accepted by C array
	    strcpy(buffer, history[num - 1].c_str());
	    //save buffer in history
	    history.push_back(buffer);
	    parser(buffer, args);
	    execCommand(args);
	  }
      }
      //
      else
	{
	  //push save into history vector
	  history.push_back(save);
	  execCommand(args);

	}


    }
  return 0;

}

//parser to seperate command into tokens
void parser(char buffer[], char * args[])
{
  int i = 0;

  // strtok parses command based of empty space delimeter
  char * temp = strtok(buffer, " ");
  //until delimeter is reached store in args[i]
  while (temp != NULL)
    {
      args[i] = temp;
      temp = strtok(NULL, " ");
      i++;
    }

  //check if last element of command is &; set flag true
  if (strcmp(args[i - 1], "&") == 0)
    {
      args[i - 1] = NULL;
      ampersand = true;
    }

  else
    {
      // terminated argument list with null
      args[i] = NULL;
      ampersand = false;
    }

}

// executes follwing steps
//  After reading user input, the steps are: *
//  (1) fork a child process using fork() *
//  (2) the child process will invoke execvp() *
//  (3) parent will invoke wait() unless command included &

void execCommand(char * args[])
{ //create pid and fork()
  pid_t pid;
  pid = fork();

  //call execvp() function
  if (pid == 0)
    {
      execvp(args[0], args);	//

      cout << "ERROR: command does not exist!" << endl;
      exit(1);
    }

  //call wait() to activate semaphore
  else if (pid > 0)
    {
      if (ampersand == false)
	  wait(NULL);
    }
  // fork process fails
  else
    {
      cout << "ERROR: fork process failed" << endl;
      exit(1);
    }
}

//function to display history from vector
void argHistory()
{
  // check if history is empty
  if (history.empty())
    {
      cout << "ERROR: no commands entered!\nPlease enter a command." << endl;
    }

  // determine size of history and display
  else
    {
      int i;
      if (history.size() < 10)
	i = 0;
      else
	i = history.size() - 10;

      for(i; i < history.size(); i++)//messed with this
	{
	  cout << "  " << i + 1 << "  " << history[i] << endl;//messed with this
	}

    }
}
