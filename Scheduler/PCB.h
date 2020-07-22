#pragma once
#include <vector>
#include "event.h"
#include "random.h"

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
	int startTime;
	int cpuDuration;
	int remCpuDuration;
	int avgCpuBurst;
	int nextCpuBurst;
	int ioBurst;
	int priority;
	ProcState state;
	
	PCB();
	~PCB();
	PCB(int id);
	int getId();
	int getStartTimes();
	int getCpuDur();
	int getRemCpuDur();
	int getAvgCpuBurst();
	int getNextCpuBurst();
	int getIoBurst();
	int getPriority();
	void setProcState(ProcState setState);
	ProcState getProcState();
	RandomNumGen rand;
	EventQueue event_queue;
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
  void makeDES(int num, EventQueue* p_event_queue);
  PCB getPCB(int id);

};
