
#include "sr_public_library/private_class.h"
#include "sr_private_library/string_utils.h"

int MyPrivateCLass::getValue()
{
  return this->value;
}

void MyPrivateCLass::setValue(int newValue)
{
  this->value = newValue;
}

std::string MyPrivateCLass::getSomeValue()
{
  return doSomeAction("My value is ", this->value);
}
