#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid) : pid_(pid){};

int Process::Pid() { return pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() {
  long totalTime = LinuxParser::ActiveJiffies(pid_);
  long startTime = LinuxParser::UpTime(pid_);
  long upTime = LinuxParser::UpTime();

  long seconds = upTime - (startTime / sysconf(_SC_CLK_TCK));

  return (totalTime / sysconf(_SC_CLK_TCK)) / seconds;
}

string Process::Command() { return LinuxParser::Command(pid_); }

string Process::Ram() { return LinuxParser::Ram(pid_); }

long int Process::UpTime() { return LinuxParser::UpTime(pid_); }

string Process::User() { return LinuxParser::User(pid_); }

bool Process::operator<(Process const& process) const {
  return stoi(LinuxParser::Ram(process.pid_)) <
         stoi(LinuxParser::Ram(this->pid_));
}