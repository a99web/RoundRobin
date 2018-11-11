#include "process.h"

Process::Process(int pid, int at, int bt): pid(pid), arrival_time(at), burst_time(bt), remaining_burst_time(bt) {}

bool Process::finished_execution() {
  return remaining_burst_time == 0;
}

void Process::set_completion_time(int time) {
   completion_time = time;
}

int Process::get_completion_time() { return completion_time; }

int Process::get_arrival_time() { return arrival_time; }

int Process::get_burst_time() { return burst_time; }

int Process::get_remaining_burst_time() { return remaining_burst_time; }

int Process::get_pid() { return pid; }

void Process::set_remaining_burst_time(int bt) { 
 if(bt <= 0) remaining_burst_time = 0; 
 else remaining_burst_time = bt;
}
