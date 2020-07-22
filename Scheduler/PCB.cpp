#include "PCB.h"
#include <vector>
#include <iostream>
#include "random.h"
#include "event.h"
#include "scheduler.h"

PCB::PCB()
{
  id = 0;
  startTime = rand.ranInt(0, 300000);
  cpuDuration = rand.ranInt(1000, 60000);
  remCpuDuration = cpuDuration;
  avgCpuBurst = rand.ranInt(5, 100);
  nextCpuBurst = rand.CPUBurstRandom(avgCpuBurst);
  ioBurst = rand.ranInt(30, 100);
  priority = 0;
  state = ProcState::NEW;
}
//destructor
PCB::~PCB()
{}
PCB::PCB(int setId)
{
  id = setId;
  startTime = rand.ranInt(0, 300000);
  cpuDuration = rand.ranInt(1000, 60000);
  remCpuDuration = cpuDuration;
  avgCpuBurst = rand.ranInt(5, 100);
  nextCpuBurst = rand.CPUBurstRandom(avgCpuBurst);
  ioBurst = rand.ranInt(30, 100);
  priority = setId;
  state = ProcState::NEW;

}
//returns ID of PCB object
int PCB::getId()
{
  return id;
}
//returns start time
int PCB:: getStartTimes()
{
  return startTime;
}
//
int PCB::getCpuDur()
{
  return cpuDuration;
}
//
int PCB::getRemCpuDur()
{
  return remCpuDuration;
}
//
int PCB::getAvgCpuBurst()
{
  return avgCpuBurst;
}
//
int PCB::getNextCpuBurst()
{
  return nextCpuBurst;
}
//
int PCB::getIoBurst()
{
  return ioBurst;
}

/*set priority of a PCB object
void PCB:: setPriority(int setP)
{
  priority = setP;
  }*/
//returns priority of PCB object
int PCB::getPriority()
{
  return priority;
}
//set ProcState of PCB object
void PCB::setProcState(ProcState setState)
{
  state = setState;
}
//return PrcoState of PCB object
ProcState PCB::getProcState()
{
  return state;
}


//implementation of PCBTable
//default contructor
PCBTable::PCBTable()
{}
//destructor
PCBTable::~PCBTable()
{}
//creates a table of PCB objects
void PCBTable::makeDES(int num, EventQueue* p_event_queue)
{ EventQueue *event_queue = p_event_queue;
  //loop through num times and fill the table with PCB objects  
  for (int i = 0; i < num; i++)
    {
     PCB newPCB = PCB(i);
     pcbTable.push_back(newPCB);
      
     Event newEvent = Event(1, newPCB.startTime, i);
     event_queue->push(newEvent);
    }

}
//return a PCB object from the table
PCB PCBTable::getPCB(int id)
{
  return pcbTable.at(id);

}
