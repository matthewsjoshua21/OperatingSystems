#pragma once
#include <vector>

using namespace std;
// Remember to add comments to your code
// ...

// enum class of process state
// A process (PCB) in ready queue should be in READY state
enum class ProcState {NEW, READY, RUNNING, WAITING, TERMINATED};

/* 
Process control block(PCB) is a data structure representing a process in the system.
A process should have at least an ID and a state(i.e.NEW, READY, RUNNING, WAITING or TERMINATED).
It may also have other attributes, such as scheduling information (e.g. priority)
*/
class PCB 
{
public:
	// TODO: Add the body of PCB class


	int id;
	int priority;
	ProcState state;
 
	PCB();
	~PCB();
	PCB(int setId, int setPriority, ProcState setState);
	int getId();
	void setPriority(int setP);
	int getPriority();
	void setProcState(ProcState setState);
	ProcState getProcState();
};

/*
A vector of all PCB elements in the system.
*/
class PCBTable 
{
 private:
  vector <PCB> pcbTable;
 public:
  PCBTable();
  ~PCBTable();
  void makeTable(int num);
  PCB getPCB(int id);

};
