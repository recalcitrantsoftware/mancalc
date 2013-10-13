#ifndef __bin_printer_t_hpp__
#define __bin_printer_t_hpp__

/**
 * @file
 * 
 * @copyright 2013 Recalcitrant Software, LLC.
 * @license Distributed under the Boost Software License,
 * Version 1.0. See included LICENSE.md or
 * http://www.boost.org/LICENSE_1_0.txt for the complete
 * license.
 */

#include <string>
#include <unordered_map>
#include "num_t.hpp"
#include "base_printer_t.hpp"

struct bin_printer_t : base_printer_t
{
   std::string convert(const num_t& n)
   {
      std::string result = base_printer_t::convert
      (
         n,
         digits,
         "0b"
      );
      return result;
   }
private:
   std::unordered_map<int, char> digits =
   {
      {0, '0'}, {1, '1'}
   };
};

#endif
