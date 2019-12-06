#include <sstream>
#include <string>

#include "format.h"

using std::string;
using std::ostringstream;

string Format::ElapsedTime(const long seconds) {
  int h = seconds / 3600;
  int m = (seconds - 3600 * h) / 60;
  int s = seconds - 3600 * h - 60 * m;

  ostringstream ss;

  ss.width(2);
  ss.fill('0');
  ss << h << ":";

  ss.width(2);
  ss.fill('0');
  ss << m << ":";

  ss.width(2);
  ss.fill('0');
  ss << s;

  return ss.str();
}