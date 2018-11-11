#include<iostream>
#include "round_robin.h"

int main() {
 
  std::list< std::pair<int, std::pair<int, int> > > data;
  data.push_back(std::make_pair(1, std::make_pair(0, 3)));
  data.push_back(std::make_pair(2, std::make_pair(0, 4)));
  data.push_back(std::make_pair(3, std::make_pair(0, 3)));
  //data.push_back(std::make_pair(4, std::make_pair(0, 1)));
  //data.push_back(std::make_pair(1, std::make_pair(5, 5)));
  //data.push_back(std::make_pair(6, std::make_pair(6, 3)));
   
  RoundRobin scheduler(data, 1);

  scheduler.schedule_process();

  std::cout<<"Average TAT: "<<scheduler.average_tat()<<std::endl;
  std::cout<<"Average WT: "<<scheduler.average_wt()<<std::endl;
}
