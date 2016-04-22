
#include "sr_private_library/string_utils.h"
#include <string>
#include <sstream>

std::string doSomeAction(std::string value, int intValue)
{
  std::ostringstream stream;
  stream << value << intValue;
  return stream.str();
}
