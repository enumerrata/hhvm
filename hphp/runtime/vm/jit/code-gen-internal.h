/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-present Facebook, Inc. (http://www.facebook.com)  |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#ifndef incl_HPHP_VM_CODE_GEN_INTERNAL_H_
#define incl_HPHP_VM_CODE_GEN_INTERNAL_H_

#include "hphp/runtime/vm/member-operations.h"

#include "hphp/runtime/vm/jit/type.h"

namespace HPHP { namespace jit {

///////////////////////////////////////////////////////////////////////////////

/*
 * Information about an array key.
 *
 * This represents however much we know about whether the key is going to
 * behave like an integer or a string.
 */
struct ArrayKeyInfo {
  int64_t convertedInt{0};
  KeyType type{KeyType::Any};

  // If true, the string could dynamically contain an integer-like string,
  // which needs to be checked.
  bool checkForInt{false};

  // If true, useKey is an integer constant we've materialized, by converting a
  // string `key' that was strictly an integer.
  bool converted{false};
};

ArrayKeyInfo checkStrictlyInteger(Type arr, Type key);

///////////////////////////////////////////////////////////////////////////////

}}

#endif
