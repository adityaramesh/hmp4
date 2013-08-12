/*
** File Name:	tuple.hpp
** Author:	Aditya Ramesh
** Date:	07/29/2013
** Contact:	_@adityaramesh.com
*/

#ifndef Z85F675B6_207F_414C_8EF9_46920B38B7D6
#define Z85F675B6_207F_414C_8EF9_46920B38B7D6

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/tuple/rem.hpp>
#include <p5/variadic_size.hpp>

#define P5_TUPLE_CAT(...) \
	BOOST_PP_CAT(P5_TUPLE_CAT_IMPL_, P5_VARIADIC_SIZE(__VA_ARGS__))(__VA_ARGS__)

#define P5_TUPLE_CAT_IMPL_2(a, b) \
	(BOOST_PP_TUPLE_REM()a, BOOST_PP_TUPLE_REM()b)

#define P5_TUPLE_CAT_IMPL_3(_1, _2, _3) \
	P5_TUPLE_CAT_IMPL_2(P5_TUPLE_CAT_IMPL_2(_1, _2), _3)

#define P5_TUPLE_CAT_IMPL_4(_1, _2, _3, _4) \
	P5_TUPLE_CAT_IMPL_2(P5_TUPLE_CAT_IMPL_3(_1, _2, _3), _4)

#define P5_TUPLE_CAT_IMPL_5(_1, _2, _3, _4, _5) \
	P5_TUPLE_CAT_IMPL_2(P5_TUPLE_CAT_IMPL_4(_1, _2, _3, _4), _5)

#define P5_TUPLE_CAT_IMPL_6(_1, _2, _3, _4, _5, _6) \
	P5_TUPLE_CAT_IMPL_2(P5_TUPLE_CAT_IMPL_5(_1, _2, _3, _4, _5), _6)

#define P5_TUPLE_CAT_IMPL_7(_1, _2, _3, _4, _5, _6, _7) \
	P5_TUPLE_CAT_IMPL_2(P5_TUPLE_CAT_IMPL_6(_1, _2, _3, _4, _5, _6), _7)

#define P5_TUPLE_CAT_IMPL_8(_1, _2, _3, _4, _5, _6, _7, _8) \
	P5_TUPLE_CAT_IMPL_2(P5_TUPLE_CAT_IMPL_7(_1, _2, _3, _4, _5, _6, _7), _8)

#define P5_TUPLE_CAT_IMPL_9(_1, _2, _3, _4, _5, _6, _7, _8, _9) \
	P5_TUPLE_CAT_IMPL_2(P5_TUPLE_CAT_IMPL_8(_1, _2, _3, _4, _5, _6, _7, _8), _9)

#define P5_TUPLE_CAT_IMPL_10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10) \
	P5_TUPLE_CAT_IMPL_2(P5_TUPLE_CAT_IMPL_9(_1, _2, _3, _4, _5, _6, _7, _8, _9), _10)

#endif
