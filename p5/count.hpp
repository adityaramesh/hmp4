/*
** File Name:	count.hpp
** Author:	Aditya Ramesh
** Date:	07/28/2013
** Contact:	_@adityaramesh.com
**
** Support for empty-argument detection was adapted from the approach given in
** this [blog post][empty_macro].
**
** [empty_macro]:
** http://gustedt.wordpress.com/2010/06/08/detect-empty-macro-arguments/ "Detect
** Empty Macro Arguments"
*/

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/control/if.hpp>

#ifndef Z03BE52C2_8635_41BE_84BD_1348AE5FBE39
#define Z03BE52C2_8635_41BE_84BD_1348AE5FBE39

#define P5_LAST_ARGUMENT(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, \
	_13, _14, _15, _16, _17, _18, _19, _20, ...) _20

#define P5_HAS_COMMA(...)                                                    \
	P5_LAST_ARGUMENT(__VA_ARGS__, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
	1, 1, 1, 1, 1, 0)

#define P5_TRIGGER_PARENTHESIS(...) ,

#define P5_IS_EMPTY(...)                                              \
	P5_IS_EMPTY_IMPL(                                             \
		P5_HAS_COMMA(__VA_ARGS__),                            \
		P5_HAS_COMMA(P5_TRIGGER_PARENTHESIS __VA_ARGS__),   \
		P5_HAS_COMMA(__VA_ARGS__ ()),                         \
		P5_HAS_COMMA(P5_TRIGGER_PARENTHESIS __VA_ARGS__ ()) \
	)

#define P5_IS_EMPTY_IMPL(_1, _2, _3, _4) \
	P5_HAS_COMMA(P5_PASTE_5(P5_IS_EMPTY_CASE_, _1, _2, _3, _4))

#define P5_IS_EMPTY_CASE_0001 ,

#define P5_PASTE_5(_1, _2, _3, _4, _5) \
	_1 ## _2 ## _3 ## _4 ## _5

#define P5_COUNT(...)                                                        \
	BOOST_PP_IF(                                                           \
		BOOST_PP_EQUAL(P5_IS_EMPTY(__VA_ARGS__), 1), 0,              \
		P5_COUNT_IMPL(__VA_ARGS__, 20, 19, 18, 17, 16, 15, 14, 13,   \
		12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)                         \
	)

#define P5_COUNT_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, \
	_13, _14, _15, _16, _17, _18, _19, _20, N, ...) N

#endif
