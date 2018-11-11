#include<iostream>
#include "round_robin.h"

int main() {
 
  std::list< std::pair<int, std::pair<int, int> > > data;
  data.push_back(std::make_pair(4, std::make_pair(1, 9)));
  data.push_back(std::make_pair(5, std::make_pair(2, 2)));
  data.push_back(std::make_pair(3, std::make_pair(3, 7)));
  data.push_back(std::make_pair(2, std::make_pair(4, 6)));
  data.push_back(std::make_pair(1, std::make_pair(5, 5)));
  data.push_back(std::make_pair(6, std::make_pair(6, 3)));
   
  RoundRobin scheduler(data, 3);

  scheduler.schedule_process();

}
