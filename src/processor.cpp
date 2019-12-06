#include "processor.h"

#include <unistd.h> // for usleep

#include "linux_parser.h"

float Processor::Utilization() {

  totalJiffiesStart = LinuxParser::Jiffies();
  activeJiffiesStart = LinuxParser::ActiveJiffies();
  
  usleep(100000);
  
  totalJiffiesEnd = LinuxParser::Jiffies();
  activeJiffiesEnd = LinuxParser::ActiveJiffies();
  
  long totalDelta = totalJiffiesEnd - totalJiffiesStart;
  long activeDelta = activeJiffiesEnd - activeJiffiesStart;
  
  if (totalDelta == 0) {
    return 0.0;
  }
  
  return float(activeDelta) / float(totalDelta); 

}