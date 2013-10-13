#ifndef __num_t_hpp__
#define __num_t_hpp__

/**
 * @file
 * 
 * @copyright 2013 Recalcitrant Software, LLC.
 * @license Distributed under the Boost Software License,
 * Version 1.0. See included LICENSE.md or
 * http://www.boost.org/LICENSE_1_0.txt for the complete
 * license.
 */

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

using int_t = boost::multiprecision::number
<
   boost::multiprecision::cpp_int_backend<>,
   boost::multiprecision::expression_template_option::et_off
>;

using num_t = boost::multiprecision::number
<
   boost::multiprecision::cpp_dec_float<1024>,
   boost::multiprecision::expression_template_option::et_off
>;

#endif
