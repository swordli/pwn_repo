/* Test llrint.
   Copyright (C) 1997-2017 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#include "libm-test-driver.c"

static const struct test_f_L_data llrint_test_data[] =
  {
    /* Bug 6798: errno setting may be missing.  */
    TEST_f_L (llrint, plus_infty, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_f_L (llrint, minus_infty, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_f_L (llrint, qnan_value, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_f_L (llrint, -qnan_value, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_f_L (llrint, snan_value, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_f_L (llrint, -snan_value, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_f_L (llrint, max_value, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_f_L (llrint, -max_value, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_f_L (llrint, 0x1p31, 0x80000000LL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 0x1p32, 0x100000000LL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 0x1p33, 0x200000000LL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 0x1p63, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_f_L (llrint, 0x1p64, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_f_L (llrint, 0x1p65, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_f_L (llrint, -0x1p31, -0x80000000LL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -0x1p32, -0x100000000LL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -0x1p33, -0x200000000LL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -0x1p63, LLONG_MIN, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -0x1p64, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_f_L (llrint, -0x1p65, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_f_L (llrint, 0x7fffff80p0, 0x7fffff80LL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
#if !TEST_COND_binary32
    TEST_f_L (llrint, 0x7fffffffp0, 0x7fffffffLL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 0x7fffffff.4p0, 0x7fffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0x7fffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0x7fffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 0x7fffffff.7ffffcp0, 0x7fffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0x7fffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0x7fffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 0x7fffffff.8p0, 0x7fffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0x7fffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 0x7fffffff.cp0, 0x7fffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0x7fffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
#endif
#if MANT_DIG >= 64
    TEST_f_L (llrint, 0x7fffffff.7fffffff8p0L, 0x7fffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0x7fffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0x7fffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
#endif
#if MANT_DIG >= 106
    TEST_f_L (llrint, 0x7fffffff.7fffffffffffffffffep0L, 0x7fffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0x7fffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0x7fffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
#endif
#if MANT_DIG >= 113
    TEST_f_L (llrint, 0x7fffffff.7fffffffffffffffffffcp0L, 0x7fffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0x7fffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0x7fffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
#endif
#if !TEST_COND_binary32
    TEST_f_L (llrint, -0x80000000.4p0, -0x80000001LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -0x80000000.7ffff8p0, -0x80000001LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -0x80000000.8p0, -0x80000001LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -0x80000000.cp0, -0x80000001LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -0x80000001LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -0x80000001p0, -0x80000001LL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
#endif
    TEST_f_L (llrint, -0x80000100p0, -0x80000100LL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
#if MANT_DIG >= 64
    TEST_f_L (llrint, -0x80000000.7fffffffp0L, -0x80000001LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
#endif
#if MANT_DIG >= 106
    TEST_f_L (llrint, -0x80000000.7fffffffffffffffffcp0L, -0x80000001LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
#endif
#if MANT_DIG >= 113
    TEST_f_L (llrint, -0x80000000.7fffffffffffffffffff8p0L, -0x80000001LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -0x80000000LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
#endif
    TEST_f_L (llrint, 0x7fffff8000000000p0, 0x7fffff8000000000LL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
#if !TEST_COND_binary32
    TEST_f_L (llrint, 0x7ffffffffffffc00p0, 0x7ffffffffffffc00LL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
#endif
#if MANT_DIG >= 64
    TEST_f_L (llrint, 0x7fffffffffffffffp0L, 0x7fffffffffffffffLL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 0x7fffffffffffffff.8p0L, 0x7fffffffffffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION, 0x7fffffffffffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
# if MANT_DIG > 64
    TEST_f_L (llrint, 0x7fffffffffffffff.4p0L, 0x7fffffffffffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0x7fffffffffffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0x7fffffffffffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_f_L (llrint, 0x7fffffffffffffff.cp0L, 0x7fffffffffffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION, 0x7fffffffffffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
# endif
# if MANT_DIG >= 106
    TEST_f_L (llrint, 0x7fffffffffffffff.7fffffffffep0L, 0x7fffffffffffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0x7fffffffffffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0x7fffffffffffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
# endif
# if MANT_DIG >= 113
    TEST_f_L (llrint, 0x7fffffffffffffff.7fffffffffffcp0L, 0x7fffffffffffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0x7fffffffffffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0x7fffffffffffffffLL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
# endif
#endif
#if MANT_DIG >= 64
    TEST_f_L (llrint, -0x8000000000000001p0L, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
#endif
#if MANT_DIG >= 106
    TEST_f_L (llrint, -0x8000000000000000.4p0L, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION, LLONG_MIN, INEXACT_EXCEPTION|ERRNO_UNCHANGED, LLONG_MIN, INEXACT_EXCEPTION|ERRNO_UNCHANGED, LLONG_MIN, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -0x8000000000000000.7fffffffffcp0L, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION, LLONG_MIN, INEXACT_EXCEPTION|ERRNO_UNCHANGED, LLONG_MIN, INEXACT_EXCEPTION|ERRNO_UNCHANGED, LLONG_MIN, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -0x8000000000000000.8p0L, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION, LLONG_MIN, INEXACT_EXCEPTION|ERRNO_UNCHANGED, LLONG_MIN, INEXACT_EXCEPTION|ERRNO_UNCHANGED, LLONG_MIN, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -0x8000000000000000.cp0L, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION, LLONG_MIN, INEXACT_EXCEPTION|ERRNO_UNCHANGED, LLONG_MIN, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
#endif
    TEST_f_L (llrint, -0x8000010000000000p0, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
#if !TEST_COND_binary32
    TEST_f_L (llrint, -0x8000000000000800p0, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
#endif
#if MANT_DIG >= 113
    TEST_f_L (llrint, -0x8000000000000000.7fffffffffff8p0L, IGNORE, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION, LLONG_MIN, INEXACT_EXCEPTION|ERRNO_UNCHANGED, LLONG_MIN, INEXACT_EXCEPTION|ERRNO_UNCHANGED, LLONG_MIN, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
#endif
    TEST_f_L (llrint, 0.0, 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, minus_zero, 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, min_value, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 1, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -min_value, -1, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, min_subnorm_value, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 1, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -min_subnorm_value, -1, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 0.2L, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 1, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -0.2L, -1, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 0.5L, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 1, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -0.5L, -1, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 0.8L, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 1, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 1, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -0.8L, -1, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -1, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 0, INEXACT_EXCEPTION|ERRNO_UNCHANGED),

    TEST_f_L (llrint, 1.4L, 1, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 1, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 1, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 2, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -1.4L, -2, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -1, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -1, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -1, INEXACT_EXCEPTION|ERRNO_UNCHANGED),

    TEST_f_L (llrint, 8388600.3L, 8388600, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 8388600, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 8388600, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 8388601, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -8388600.3L, -8388601, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -8388600, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -8388600, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -8388600, INEXACT_EXCEPTION|ERRNO_UNCHANGED),

#if !TEST_COND_binary32
    TEST_f_L (llrint, 1071930.0008, 1071930, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 1071930, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 1071930, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 1071931, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 1073741824.01, 1073741824, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 1073741824, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 1073741824, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 1073741825, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
# if MANT_DIG >= 64
    TEST_f_L (llrint, 281474976710656.025L, 281474976710656, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 281474976710656, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 281474976710656, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 281474976710657, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
# endif
#endif

    /* Test boundary conditions.  */
    /* 0x1FFFFF */
    TEST_f_L (llrint, 2097151.0, 2097151LL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    /* 0x800000 */
    TEST_f_L (llrint, 8388608.0, 8388608LL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    /* 0x1000000 */
    TEST_f_L (llrint, 16777216.0, 16777216LL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    /* 0x20000000000 */
    TEST_f_L (llrint, 2199023255552.0, 2199023255552LL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    /* 0x40000000000 */
    TEST_f_L (llrint, 4398046511104.0, 4398046511104LL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    /* 0x1000000000000 */
    TEST_f_L (llrint, 281474976710656.0, 281474976710656LL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    /* 0x10000000000000 */
    TEST_f_L (llrint, 4503599627370496.0, 4503599627370496LL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    /* 0x10000080000000 */
    TEST_f_L (llrint, 4503601774854144.0, 4503601774854144LL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    /* 0x20000000000000 */
    TEST_f_L (llrint, 9007199254740992.0, 9007199254740992LL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    /* 0x80000000000000 */
    TEST_f_L (llrint, 36028797018963968.0, 36028797018963968LL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    /* 0x100000000000000 */
    TEST_f_L (llrint, 72057594037927936.0, 72057594037927936LL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
#if MANT_DIG >= 64
    /* The input can only be represented in long double.  */
    TEST_f_L (llrint, 4503599627370495.5L, 4503599627370495LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370495LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 4503599627370496.25L, 4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370497LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 4503599627370496.5L, 4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370497LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 4503599627370496.75L, 4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370497LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370497LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 4503599627370497.5L, 4503599627370497LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370498LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370497LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370498LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),

    TEST_f_L (llrint, -4503599627370495.5L, -4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370495LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370495LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -4503599627370496.25L, -4503599627370497LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -4503599627370496.5L, -4503599627370497LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -4503599627370496.75L, -4503599627370497LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370497LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -4503599627370497.5L, -4503599627370498LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370498LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370497LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370497LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),

# if MANT_DIG > 100
    TEST_f_L (llrint, 4503599627370495.4999999999999L, 4503599627370495LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370495LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370495LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 4503599627370496.4999999999999L, 4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370497LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 4503599627370497.4999999999999L, 4503599627370497LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370497LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370497LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370498LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 4503599627370494.5000000000001L, 4503599627370494LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370495LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370494LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370495LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 4503599627370495.5000000000001L, 4503599627370495LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370495LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 4503599627370496.5000000000001L, 4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370497LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 4503599627370497LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),

    TEST_f_L (llrint, -4503599627370495.4999999999999L, -4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370495LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370495LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370495LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -4503599627370496.4999999999999L, -4503599627370497LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -4503599627370497.4999999999999L, -4503599627370498LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370497LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370497LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370497LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -4503599627370494.5000000000001L, -4503599627370495LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370495LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370494LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370494LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -4503599627370495.5000000000001L, -4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370495LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370495LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -4503599627370496.5000000000001L, -4503599627370497LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370497LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -4503599627370496LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
# endif

    TEST_f_L (llrint, 9007199254740991.5L, 9007199254740991LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740991LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 9007199254740992.25L, 9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 9007199254740992.5L, 9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 9007199254740992.75L, 9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 9007199254740993.5L, 9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740994LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740994LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),

    TEST_f_L (llrint, -9007199254740991.5L, -9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740991LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740991LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -9007199254740992.25L, -9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -9007199254740992.5L, -9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -9007199254740992.75L, -9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -9007199254740993.5L, -9007199254740994LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740994LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),

# if MANT_DIG > 100
    TEST_f_L (llrint, 9007199254740991.4999999999999L, 9007199254740991LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740991LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740991LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 9007199254740992.4999999999999L, 9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 9007199254740993.4999999999999L, 9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740994LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 9007199254740991.5000000000001L, 9007199254740991LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740991LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 9007199254740992.5000000000001L, 9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 9007199254740993.5000000000001L, 9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740994LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9007199254740994LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),

    TEST_f_L (llrint, -9007199254740991.4999999999999L, -9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740991LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740991LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740991LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -9007199254740992.4999999999999L, -9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -9007199254740993.4999999999999L, -9007199254740994LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -9007199254740991.5000000000001L, -9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740991LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740991LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -9007199254740992.5000000000001L, -9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740992LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -9007199254740993.5000000000001L, -9007199254740994LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740994LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9007199254740993LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
# endif

    TEST_f_L (llrint, 72057594037927935.5L, 72057594037927935LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 72057594037927936LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 72057594037927935LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 72057594037927936LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 72057594037927936.25L, 72057594037927936LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 72057594037927936LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 72057594037927936LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 72057594037927937LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 72057594037927936.5L, 72057594037927936LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 72057594037927936LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 72057594037927936LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 72057594037927937LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 72057594037927936.75L, 72057594037927936LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 72057594037927937LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 72057594037927936LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 72057594037927937LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 72057594037927937.5L, 72057594037927937LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 72057594037927938LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 72057594037927937LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 72057594037927938LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),

    TEST_f_L (llrint, -72057594037927935.5L, -72057594037927936LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -72057594037927936LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -72057594037927935LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -72057594037927935LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -72057594037927936.25L, -72057594037927937LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -72057594037927936LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -72057594037927936LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -72057594037927936LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -72057594037927936.5L, -72057594037927937LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -72057594037927936LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -72057594037927936LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -72057594037927936LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -72057594037927936.75L, -72057594037927937LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -72057594037927937LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -72057594037927936LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -72057594037927936LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -72057594037927937.5L, -72057594037927938LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -72057594037927938LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -72057594037927937LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -72057594037927937LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),

# if MANT_DIG > 100
    TEST_f_L (llrint, 9223372036854775805.5L, 9223372036854775805LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9223372036854775806LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9223372036854775805LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9223372036854775806LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -9223372036854775805.5L, -9223372036854775806LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9223372036854775806LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9223372036854775805LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9223372036854775805LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 9223372036854775806.0L, 9223372036854775806LL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -9223372036854775806.0L, -9223372036854775806LL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 9223372036854775806.25L, 9223372036854775806LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9223372036854775806LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9223372036854775806LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9223372036854775807LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -9223372036854775806.25L, -9223372036854775807LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9223372036854775806LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9223372036854775806LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9223372036854775806LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 9223372036854775806.5L, 9223372036854775806L, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9223372036854775806L, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9223372036854775806L, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9223372036854775807L, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -9223372036854775806.5L, -9223372036854775807LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9223372036854775806LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9223372036854775806LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9223372036854775806LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 9223372036854775806.75L, 9223372036854775806LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9223372036854775807LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9223372036854775806LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, 9223372036854775807LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -9223372036854775806.75L, -9223372036854775807LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9223372036854775807LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9223372036854775806LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED, -9223372036854775806LL, INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, 9223372036854775807.0L, 9223372036854775807LL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_f_L (llrint, -9223372036854775807.0L, -9223372036854775807LL, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
# endif
#endif
  };

static void
llrint_test (void)
{
  ALL_RM_TEST (llrint, 1, llrint_test_data, RUN_TEST_LOOP_f_L, END);
}

static void
do_test (void)
{
  llrint_test ();
}

/*
 * Local Variables:
 * mode:c
 * End:
 */