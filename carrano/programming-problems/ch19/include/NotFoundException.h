#ifndef NOT_FOUND_EXCEPTION_H
#define NOT_FOUND_EXCEPTION_H

#include "NotFoundException.h"
#include <stdexcept>
#include <string>
class NotFoundException: public std::runtime_error
{
   public :
   NotFoundException(const std::string& message = "")
                         : std::runtime_error("Target not found: " + message)
   {
   } 
}; 

#endif