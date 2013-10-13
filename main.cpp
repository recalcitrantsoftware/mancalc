#include <iostream>
#include "postfix_t.hpp"
#include "log_t.hpp"
#include "infix_t.hpp"

/**
 * @file
 * 
 * @copyright 2013 Recalcitrant Software, LLC.
 * @license Distributed under the Boost Software License,
 * Version 1.0. See included LICENSE.md or
 * http://www.boost.org/LICENSE_1_0.txt for the complete
 * license.
 *
 * This is a basic command line shell for running the man
 * calc engine.
 */

int main()
{
   std::string buf;
   std::string last_expression;
   postfix_t p;
   infix_t infix(p);
   while (true)
   {
      std::cout
         << "["
         << p
         << "]>";

      std::getline(std::cin, buf);
      if (std::cin.eof())
      {
         return 0;
      }

      if (buf.size() == 0)
      {
         buf = last_expression;
      }
      last_expression = buf;

      bool push_failed = false;
      try
      {
         p.push(buf);
      }
      catch (const char* e)
      {
         push_failed = true;
      }

      if (push_failed)
      {
         auto t = infix.parse(buf);
         auto i = std::get<0>(t);
         auto msg = std::get<1>(t);
         auto end = buf.cend();
         if (i != end)
         {
            int diff = end - i;
            ooo(eee)
               << msg
               << ": diff = "
               << diff;
         }
      }
   }
}
