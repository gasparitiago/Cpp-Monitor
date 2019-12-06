#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {

 public:
  float Utilization();

 private:
  long totalJiffiesStart = 0;
  long activeJiffiesStart = 0;
  long totalJiffiesEnd = 0;
  long activeJiffiesEnd = 0;

};

#endif