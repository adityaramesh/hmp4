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
#include <hmp4/count.hpp>

#define HMP4_TUPLE_CAT(...) \
	BOOST_PP_CAT(HMP4_TUPLE_CAT_IMPL_, HMP4_COUNT(__VA_ARGS__))(__VA_ARGS__)

#define HMP4_TUPLE_CAT_IMPL_2(a, b) \
	(BOOST_PP_TUPLE_REM()a, BOOST_PP_TUPLE_REM()b)

#define HMP4_TUPLE_CAT_IMPL_3(_1, _2, _3) \
	HMP4_TUPLE_CAT_IMPL_2(HMP4_TUPLE_CAT_IMPL_2(_1, _2), _3)

#define HMP4_TUPLE_CAT_IMPL_4(_1, _2, _3, _4) \
	HMP4_TUPLE_CAT_IMPL_2(HMP4_TUPLE_CAT_IMPL_3(_1, _2, _3), _4)

#define HMP4_TUPLE_CAT_IMPL_5(_1, _2, _3, _4, _5) \
	HMP4_TUPLE_CAT_IMPL_2(HMP4_TUPLE_CAT_IMPL_4(_1, _2, _3, _4), _5)

#define HMP4_TUPLE_CAT_IMPL_6(_1, _2, _3, _4, _5, _6) \
	HMP4_TUPLE_CAT_IMPL_2(HMP4_TUPLE_CAT_IMPL_5(_1, _2, _3, _4, _5), _6)

#define HMP4_TUPLE_CAT_IMPL_7(_1, _2, _3, _4, _5, _6, _7) \
	HMP4_TUPLE_CAT_IMPL_2(HMP4_TUPLE_CAT_IMPL_6(_1, _2, _3, _4, _5, _6), _7)

#define HMP4_TUPLE_CAT_IMPL_8(_1, _2, _3, _4, _5, _6, _7, _8) \
	HMP4_TUPLE_CAT_IMPL_2(HMP4_TUPLE_CAT_IMPL_7(_1, _2, _3, _4, _5, _6, _7), _8)

#define HMP4_TUPLE_CAT_IMPL_9(_1, _2, _3, _4, _5, _6, _7, _8, _9) \
	HMP4_TUPLE_CAT_IMPL_2(HMP4_TUPLE_CAT_IMPL_8(_1, _2, _3, _4, _5, _6, _7, _8), _9)

#define HMP4_TUPLE_CAT_IMPL_10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10) \
	HMP4_TUPLE_CAT_IMPL_2(HMP4_TUPLE_CAT_IMPL_9(_1, _2, _3, _4, _5, _6, _7, _8, _9), _10)

#endif
