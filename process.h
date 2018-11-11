class Process {
  int pid;
  int arrival_time;
  int completion_time;
  int burst_time;
  int remaining_burst_time;

  public:
    Process(int, int, int);

    int get_completion_time();
    int get_pid();
    void set_completion_time(int);
    int get_arrival_time();
    int get_burst_time();
    int get_remaining_burst_time();
    void set_remaining_burst_time(int);
    bool finished_execution();
};
