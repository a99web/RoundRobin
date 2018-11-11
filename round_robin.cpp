#include<iostream>
#include "round_robin.h"



RoundRobin::RoundRobin(std::list< std::pair<int, std::pair<int, int> > > d, int tq) : current_time(0), data(d), time_quanta(tq) 
{
}  

int RoundRobin::average_tat() {
  // add logic
}

int RoundRobin::average_wt() {
  // add logic
}

void RoundRobin::schedule_process() {
  // schedule any process
  std::list< std::pair<int, std::pair<int, int> > >::iterator iter = data.begin();
  // get the PID of the process
  int pid = iter->first;
  // get the arrival time
  int at = iter->second.first;
  // get the burst time
  int bt = iter->second.second;

  current_time = at;
  Process *p = new Process(pid, at, bt);

  rrq.push(p);
  int last_index = 0;
  std::list< std::pair<int, std::pair<int, int> > > temp_data = data;

  // to ignore the first process data
  temp_data.pop_front();
  while(!rrq.empty()) {
    Process *p = rrq.front();
    // if the process has burst time less than the time_quata
    int updated_tq = time_quanta;
    if(p->get_burst_time() < time_quanta) updated_tq = p->get_burst_time();
    // add all the process that came during this time to queue
    add_process_to_queue(current_time, current_time + updated_tq, temp_data);
    current_time += time_quanta;
    
    std::cout<<"Executing process: "<<p->get_pid()<<std::endl;
    rrq.pop();
    p->set_burst_time(p->get_burst_time() - updated_tq);
    if(!p->finished_execution()) rrq.push(p);
    else delete p;
  }
}

void RoundRobin::add_process_to_queue(int start, int end, std::list< std::pair<int, std::pair<int, int> > >& td) {
   std::list< std::pair<int, std::pair<int, int> > >::const_iterator iter = td.begin();
   while(!td.empty() && iter->second.first >= start && iter->second.first <= end) {

     rrq.push(new Process(iter->first, iter->second.first, iter->second.second));
     td.pop_front();
     iter = td.begin(); 
      
   }
 
}




