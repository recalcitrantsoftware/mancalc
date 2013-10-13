/**
 * @file
 * 
 * @copyright 2013 Recalcitrant Software, LLC.
 * @license Distributed under the Boost Software License,
 * Version 1.0. See included LICENSE.md or
 * http://www.boost.org/LICENSE_1_0.txt for the complete
 * license.
 *
 * This file exists to make sure libtestables.a has
 * something in it in the event all library code is
 * header-only. The alternative would be to create
 * libtestables.a only if there were some .cpp library
 * files. It's easier to unconditionally create the library
 * with a useless symbol which is elided from the link
 * anyway.
 */

void foo() {}
