#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <vector>

#include "process.h"
#include "processor.h"

class System {
 public:
  System();
  Processor& Cpu();
  std::vector<Process>& Processes();
  float MemoryUtilization() const;
  long UpTime() const;
  int TotalProcesses() const;
  int RunningProcesses() const;
  const std::string& Kernel() const;
  const std::string& OperatingSystem() const;

 private:
  Processor cpu_{};
  std::string osName_;
  std::string kernel_;
  std::vector<Process> processes_;
};

#endif