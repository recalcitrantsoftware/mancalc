#ifndef __property_t_hpp__
#define __property_t_hpp__

/**
 * @file
 * 
 * @copyright 2013 Recalcitrant Software, LLC.
 * @license Distributed under the Boost Software License,
 * Version 1.0. See included LICENSE.md or
 * http://www.boost.org/LICENSE_1_0.txt for the complete
 * license.
 */

#define make_property(type, name)\
public:\
type name() const\
{\
   return name ## _;\
}\
void name(type new_val)\
{\
   name ## _ = new_val;\
}\
private:\
type name ## _


#endif
