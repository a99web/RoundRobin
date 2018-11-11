#include<queue>
#include<string>
#include<utility>
#include<list>
#include "process.h"

class RoundRobin {
  int current_time;
  int time_quanta;
  std::queue<Process *> rrq;
  std::list<Process *> completed_processes;
  // list of maps related to the process, the pair stores the arrival time and burst time respectively
  std::list< std::pair<int, std::pair<int, int> > > data;
  
  public:
    // constructor that reads the data required, this is the mapping
    RoundRobin(std::list< std::pair<int, std::pair<int, int> > >, int);

    void schedule_process();

    double average_tat();
    double average_wt();
    void add_process_to_queue(int, int, std::list< std::pair<int, std::pair<int, int> > >&);

};
