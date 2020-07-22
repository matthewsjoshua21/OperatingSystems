#include "PCB.h"
#include <vector>
#include <iostream>
// TODO: Add your implementation her
//default constructor for PCB object
PCB::PCB()
{
  id = 0;
  priority = 0;
  state = ProcState::NEW;
}
//destructor
PCB::~PCB()
{}
//overloaded constructor  
PCB::PCB(int setId, int setPriority, ProcState setState)
{
  //  cout << "i am the PCB constructor" << endl;
  id = setId;
  priority = setPriority;
  state = setState;
}
//returns ID of PCB object
int PCB::getId()
{
  return id;
}
//set priority of a PCB object
void PCB:: setPriority(int setP)
{
  priority = setP;
}
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
void PCBTable::makeTable(int num)
{
  //loop through num times and fill the table with PCB objects  
  for (int i = 0; i < num; i++)
    {
      //  cout << "PCB " << i << " entering table" << endl;
      PCB newPCB = PCB(i, i, ProcState::NEW);
      pcbTable.push_back(newPCB);
    }

}
//return a PCB object from the table
PCB PCBTable::getPCB(int id)
{
  return pcbTable.at(id);

}
