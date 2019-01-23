///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Functors Library
// Copyright (C) 2019 Michael Heilmann
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the
// use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "primordialmachine/functors/include.hpp"
#include "gtest/gtest.h"

TEST(functors_tests, concat_seq_test)
{
  using namespace primordialmachine;
  using u = index_sequence<0, 1, 2, 0, 1, 2, 3>;
  using v = decltype(concat_seq(make_index_sequence<3>(),
                                make_index_sequence<4>{}));
  static_assert(is_same_v<u, v>);
}

TEST(functors_tests, reverse_seq_test)
{
  using namespace primordialmachine;
  using u = index_sequence<3, 2, 1, 0>;
  using v = decltype(reverse_seq(make_index_sequence<4>{}));
  static_assert(is_same_v<u, v>);
}

TEST(functors_tests, even_seq_test)
{
  using namespace primordialmachine;
  using u = index_sequence<0, 2>;
  using v = decltype(even_seq(make_index_sequence<4>{}));
  static_assert(is_same_v<u, v>);
}

TEST(functors_tests, odd_seq_test)
{
  using namespace primordialmachine;
  using u = index_sequence<1, 3>;
  using v = decltype(odd_seq(make_index_sequence<4>{}));
  static_assert(is_same_v<u, v>);
}

TEST(functors_tests, filter_seq_test)
{
  using namespace primordialmachine;
  using u = index_sequence<1, 3>;
  struct predicate
  {
    constexpr bool operator()(size_t x) const { return x % 2 != 0; }
  };
  using v =
    decltype(filter_seq(make_index_sequence<4>{}, predicate{}));
  static_assert(is_same_v<u, v>);
}
