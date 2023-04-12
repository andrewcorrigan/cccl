//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// WARNING: This test was generated by generate_feature_test_macro_components.py
// and should not be edited manually.

// <memory>

// Test the feature test macros defined by <memory>

/*  Constant                                      Value
    __cpp_lib_addressof_constexpr                 201603L [C++17]
    __cpp_lib_allocator_traits_is_always_equal    201411L [C++17]
    __cpp_lib_constexpr_dynamic_alloc             201907L [C++20]
    __cpp_lib_enable_shared_from_this             201603L [C++17]
    __cpp_lib_make_unique                         201304L [C++14]
    __cpp_lib_ranges                              201811L [C++2a]
    __cpp_lib_raw_memory_algorithms               201606L [C++17]
    __cpp_lib_shared_ptr_arrays                   201611L [C++17]
    __cpp_lib_shared_ptr_weak_type                201606L [C++17]
*/

#include <memory>
#include "test_macros.h"

#if TEST_STD_VER < 14

# ifdef __cpp_lib_addressof_constexpr
#   error "__cpp_lib_addressof_constexpr should not be defined before c++17"
# endif

# ifdef __cpp_lib_allocator_traits_is_always_equal
#   error "__cpp_lib_allocator_traits_is_always_equal should not be defined before c++17"
# endif

# ifdef __cpp_lib_constexpr_dynamic_alloc
#   error "__cpp_lib_constexpr_dynamic_alloc should not be defined before c++20"
# endif

# ifdef __cpp_lib_enable_shared_from_this
#   error "__cpp_lib_enable_shared_from_this should not be defined before c++17"
# endif

# ifdef __cpp_lib_make_unique
#   error "__cpp_lib_make_unique should not be defined before c++14"
# endif

# ifdef __cpp_lib_ranges
#   error "__cpp_lib_ranges should not be defined before c++2a"
# endif

# ifdef __cpp_lib_raw_memory_algorithms
#   error "__cpp_lib_raw_memory_algorithms should not be defined before c++17"
# endif

# ifdef __cpp_lib_shared_ptr_arrays
#   error "__cpp_lib_shared_ptr_arrays should not be defined before c++17"
# endif

# ifdef __cpp_lib_shared_ptr_weak_type
#   error "__cpp_lib_shared_ptr_weak_type should not be defined before c++17"
# endif

#elif TEST_STD_VER == 14

# ifdef __cpp_lib_addressof_constexpr
#   error "__cpp_lib_addressof_constexpr should not be defined before c++17"
# endif

# ifdef __cpp_lib_allocator_traits_is_always_equal
#   error "__cpp_lib_allocator_traits_is_always_equal should not be defined before c++17"
# endif

# ifdef __cpp_lib_constexpr_dynamic_alloc
#   error "__cpp_lib_constexpr_dynamic_alloc should not be defined before c++20"
# endif

# ifdef __cpp_lib_enable_shared_from_this
#   error "__cpp_lib_enable_shared_from_this should not be defined before c++17"
# endif

# ifndef __cpp_lib_make_unique
#   error "__cpp_lib_make_unique should be defined in c++14"
# endif
# if __cpp_lib_make_unique != 201304L
#   error "__cpp_lib_make_unique should have the value 201304L in c++14"
# endif

# ifdef __cpp_lib_ranges
#   error "__cpp_lib_ranges should not be defined before c++2a"
# endif

# ifdef __cpp_lib_raw_memory_algorithms
#   error "__cpp_lib_raw_memory_algorithms should not be defined before c++17"
# endif

# ifdef __cpp_lib_shared_ptr_arrays
#   error "__cpp_lib_shared_ptr_arrays should not be defined before c++17"
# endif

# ifdef __cpp_lib_shared_ptr_weak_type
#   error "__cpp_lib_shared_ptr_weak_type should not be defined before c++17"
# endif

#elif TEST_STD_VER == 17

# if TEST_HAS_BUILTIN(__builtin_addressof) || TEST_GCC_VER >= 700
#   ifndef __cpp_lib_addressof_constexpr
#     error "__cpp_lib_addressof_constexpr should be defined in c++17"
#   endif
#   if __cpp_lib_addressof_constexpr != 201603L
#     error "__cpp_lib_addressof_constexpr should have the value 201603L in c++17"
#   endif
# else
#   ifdef __cpp_lib_addressof_constexpr
#     error "__cpp_lib_addressof_constexpr should not be defined when TEST_HAS_BUILTIN(__builtin_addressof) || TEST_GCC_VER >= 700 is not defined!"
#   endif
# endif

# ifndef __cpp_lib_allocator_traits_is_always_equal
#   error "__cpp_lib_allocator_traits_is_always_equal should be defined in c++17"
# endif
# if __cpp_lib_allocator_traits_is_always_equal != 201411L
#   error "__cpp_lib_allocator_traits_is_always_equal should have the value 201411L in c++17"
# endif

# ifdef __cpp_lib_constexpr_dynamic_alloc
#   error "__cpp_lib_constexpr_dynamic_alloc should not be defined before c++20"
# endif

# ifndef __cpp_lib_enable_shared_from_this
#   error "__cpp_lib_enable_shared_from_this should be defined in c++17"
# endif
# if __cpp_lib_enable_shared_from_this != 201603L
#   error "__cpp_lib_enable_shared_from_this should have the value 201603L in c++17"
# endif

# ifndef __cpp_lib_make_unique
#   error "__cpp_lib_make_unique should be defined in c++17"
# endif
# if __cpp_lib_make_unique != 201304L
#   error "__cpp_lib_make_unique should have the value 201304L in c++17"
# endif

# ifdef __cpp_lib_ranges
#   error "__cpp_lib_ranges should not be defined before c++2a"
# endif

# ifndef __cpp_lib_raw_memory_algorithms
#   error "__cpp_lib_raw_memory_algorithms should be defined in c++17"
# endif
# if __cpp_lib_raw_memory_algorithms != 201606L
#   error "__cpp_lib_raw_memory_algorithms should have the value 201606L in c++17"
# endif

# if !defined(_LIBCUDACXX_VERSION)
#   ifndef __cpp_lib_shared_ptr_arrays
#     error "__cpp_lib_shared_ptr_arrays should be defined in c++17"
#   endif
#   if __cpp_lib_shared_ptr_arrays != 201611L
#     error "__cpp_lib_shared_ptr_arrays should have the value 201611L in c++17"
#   endif
# else // _LIBCUDACXX_VERSION
#   ifdef __cpp_lib_shared_ptr_arrays
#     error "__cpp_lib_shared_ptr_arrays should not be defined because it is unimplemented in libc++!"
#   endif
# endif

# ifndef __cpp_lib_shared_ptr_weak_type
#   error "__cpp_lib_shared_ptr_weak_type should be defined in c++17"
# endif
# if __cpp_lib_shared_ptr_weak_type != 201606L
#   error "__cpp_lib_shared_ptr_weak_type should have the value 201606L in c++17"
# endif

#elif TEST_STD_VER > 17

# if TEST_HAS_BUILTIN(__builtin_addressof) || TEST_GCC_VER >= 700
#   ifndef __cpp_lib_addressof_constexpr
#     error "__cpp_lib_addressof_constexpr should be defined in c++2a"
#   endif
#   if __cpp_lib_addressof_constexpr != 201603L
#     error "__cpp_lib_addressof_constexpr should have the value 201603L in c++2a"
#   endif
# else
#   ifdef __cpp_lib_addressof_constexpr
#     error "__cpp_lib_addressof_constexpr should not be defined when TEST_HAS_BUILTIN(__builtin_addressof) || TEST_GCC_VER >= 700 is not defined!"
#   endif
# endif

# ifndef __cpp_lib_allocator_traits_is_always_equal
#   error "__cpp_lib_allocator_traits_is_always_equal should be defined in c++2a"
# endif
# if __cpp_lib_allocator_traits_is_always_equal != 201411L
#   error "__cpp_lib_allocator_traits_is_always_equal should have the value 201411L in c++2a"
# endif

# ifndef __cpp_lib_constexpr_dynamic_alloc
#   error "__cpp_lib_constexpr_dynamic_alloc should be defined in c++2a"
# endif
# if __cpp_lib_constexpr_dynamic_alloc != 201907L
#   error "__cpp_lib_constexpr_dynamic_alloc should have the value 201907L in c++2a"
# endif

# ifndef __cpp_lib_enable_shared_from_this
#   error "__cpp_lib_enable_shared_from_this should be defined in c++2a"
# endif
# if __cpp_lib_enable_shared_from_this != 201603L
#   error "__cpp_lib_enable_shared_from_this should have the value 201603L in c++2a"
# endif

# ifndef __cpp_lib_make_unique
#   error "__cpp_lib_make_unique should be defined in c++2a"
# endif
# if __cpp_lib_make_unique != 201304L
#   error "__cpp_lib_make_unique should have the value 201304L in c++2a"
# endif

# if !defined(_LIBCUDACXX_VERSION)
#   ifndef __cpp_lib_ranges
#     error "__cpp_lib_ranges should be defined in c++2a"
#   endif
#   if __cpp_lib_ranges != 201811L
#     error "__cpp_lib_ranges should have the value 201811L in c++2a"
#   endif
# else // _LIBCUDACXX_VERSION
#   ifdef __cpp_lib_ranges
#     error "__cpp_lib_ranges should not be defined because it is unimplemented in libc++!"
#   endif
# endif

# ifndef __cpp_lib_raw_memory_algorithms
#   error "__cpp_lib_raw_memory_algorithms should be defined in c++2a"
# endif
# if __cpp_lib_raw_memory_algorithms != 201606L
#   error "__cpp_lib_raw_memory_algorithms should have the value 201606L in c++2a"
# endif

# if !defined(_LIBCUDACXX_VERSION)
#   ifndef __cpp_lib_shared_ptr_arrays
#     error "__cpp_lib_shared_ptr_arrays should be defined in c++2a"
#   endif
#   if __cpp_lib_shared_ptr_arrays != 201611L
#     error "__cpp_lib_shared_ptr_arrays should have the value 201611L in c++2a"
#   endif
# else // _LIBCUDACXX_VERSION
#   ifdef __cpp_lib_shared_ptr_arrays
#     error "__cpp_lib_shared_ptr_arrays should not be defined because it is unimplemented in libc++!"
#   endif
# endif

# ifndef __cpp_lib_shared_ptr_weak_type
#   error "__cpp_lib_shared_ptr_weak_type should be defined in c++2a"
# endif
# if __cpp_lib_shared_ptr_weak_type != 201606L
#   error "__cpp_lib_shared_ptr_weak_type should have the value 201606L in c++2a"
# endif

#endif // TEST_STD_VER > 17

int main(int, char**) { return 0; }
