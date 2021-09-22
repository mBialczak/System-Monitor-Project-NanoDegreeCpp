#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <vector>

#include "process.h"
#include "processor.h"

class System {
 public:
  System();  // DEBUG: maybe not needed
  Processor& Cpu();
  std::vector<Process>& Processes();  // TODO: See src/system.cpp
  float MemoryUtilization() const;
  long UpTime() const;
  int TotalProcesses() const;
  int RunningProcesses() const;
  std::string Kernel() const;
  std::string OperatingSystem() const;

  // TODO: Define any necessary private members
 private:
  Processor cpu_{};
  std::string osName_;
  std::string kernel_;
  std::vector<int> pids_;
  std::vector<Process> processes_;
};

#endif