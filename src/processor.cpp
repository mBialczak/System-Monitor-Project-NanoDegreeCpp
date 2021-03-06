#include "processor.h"

#include <chrono>
#include <thread>

#include "linux_parser.h"

using namespace std::literals::chrono_literals;

double Processor::Utilization() const {
  // Read CPU stats in a time interval
  std::vector<std::string> prevCpuStats = LinuxParser::CpuUtilization();
  std::this_thread::sleep_for(interval);
  std::vector<std::string> cpuStats = LinuxParser::CpuUtilization();
  // extract stats for first read
  long prevTotal = LinuxParser::Jiffies(prevCpuStats);
  long prevIdle = LinuxParser::IdleJiffies(prevCpuStats);
  // extract stats for second read
  long total = LinuxParser::Jiffies(cpuStats);
  long idle = LinuxParser::IdleJiffies(cpuStats);
  // calc  the differences in reads
  double totalDelta = static_cast<double>(total - prevTotal);
  double idleDelta = static_cast<double>(idle - prevIdle);
  // calc the final CPU percentage
  return (totalDelta - idleDelta) / (totalDelta);
}