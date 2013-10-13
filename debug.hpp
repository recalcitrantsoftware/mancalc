#ifndef __debug_hpp__
#define __debug_hpp__

/**
 * @file
 * 
 * @copyright 2013 Recalcitrant Software, LLC.
 * @license Distributed under the Boost Software License,
 * Version 1.0. See included LICENSE.md or
 * http://www.boost.org/LICENSE_1_0.txt for the complete
 * license.
 */

#include "log_t.hpp"

#define ensure(pred)\
   do\
   {\
      if (!(pred))\
      {\
         throw #pred;\
      }\
   } while (0)

#define show(x)\
   ooo(iii)\
      << #x\
      << " = "\
      << x

#define hex(x)\
   ooo(iii)\
      << #x\
      << " = 0x"\
      << std::hex\
      << x

#endif
