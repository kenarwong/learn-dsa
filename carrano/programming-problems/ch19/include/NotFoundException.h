#ifndef NOT_FOUND_EXCEPTION_
#define NOT_FOUND_EXCEPTION_

//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include "NotFoundException.h"
#include <stdexcept>
#include <string>
class NotFoundException: public std::runtime_error
{
   public :
   NotFoundException(const std::string& message = "")
                         : std::runtime_error("Target not found: " + message)
   {
   } // end constructor
}; // end NotFoundException

#endif