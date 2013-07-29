/*
** File Name:	annotate.hpp
** Author:	Aditya Ramesh
** Date:	07/28/2013
** Contact:	_@adityaramesh.com
*/

#ifndef ZE3B0ECBA_48D8_4AEF_998D_99E5B32DE98E
#define ZE3B0ECBA_48D8_4AEF_998D_99E5B32DE98E

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/arithmetic/dec.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/comparison/not_equal.hpp>
#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/repetition/for.hpp>
#include <boost/preprocessor/seq/enum.hpp>
#include <boost/preprocessor/seq/pop_front.hpp>
#include <boost/preprocessor/tuple/eat.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/tuple/rem.hpp>
#include <boost/preprocessor/tuple/size.hpp>
#include <boost/preprocessor/tuple/to_seq.hpp>
#include <hmp4/directive.hpp>

#define HMP4_ANNOTATE_LOOP(tuple) \
	HMP4_ANNOTATE_LOOP_IMPL_1(__COUNTER__, tuple)

#define HMP4_ANNOTATE_LOOP_IMPL_1(n, tuple)                               \
	HMP4_ANNOTATE_LOOP_IMPL_2(                                        \
		BOOST_PP_TUPLE_ELEM(BOOST_PP_TUPLE_SIZE(tuple), n, tuple) \
	)

#define HMP4_PRED(r, state)                       \
	BOOST_PP_NOT_EQUAL(                       \
		BOOST_PP_TUPLE_ELEM(3, 0, state), \
		BOOST_PP_TUPLE_ELEM(3, 1, state)  \
	)

#define HMP4_OP(r, state)                                       \
	(                                                       \
		BOOST_PP_INC(BOOST_PP_TUPLE_ELEM(3, 0, state)), \
	  	BOOST_PP_TUPLE_ELEM(3, 1, state),               \
	  	BOOST_PP_TUPLE_ELEM(3, 2, state)                \
	)

#define HMP4_MACRO(r, state)                                     \
	HMP4_MACRO_IMPL_1(                                       \
		BOOST_PP_TUPLE_ELEM(                             \
			BOOST_PP_TUPLE_SIZE(                     \
				BOOST_PP_TUPLE_ELEM(3, 2, state) \
			),                                       \
			BOOST_PP_TUPLE_ELEM(3, 0, state),        \
			BOOST_PP_TUPLE_ELEM(3, 2, state)         \
		)                                                \
	)

#ifndef BOOST_PP_SEQ_ENUM_0
	#define BOOST_PP_SEQ_ENUM_0
#endif

#define HMP4_MACRO_IMPL_1(tuple)                                             \
	HMP4_DIRECTIVE(                                                      \
		BOOST_PP_TUPLE_ELEM(                                         \
			BOOST_PP_TUPLE_SIZE(tuple),                          \
			0,                                                   \
			tuple                                                \
		),                                                           \
		BOOST_PP_SEQ_ENUM(                                           \
			BOOST_PP_SEQ_POP_FRONT(BOOST_PP_TUPLE_TO_SEQ(tuple)) \
		)                                                            \
	)

#define HMP4_ANNOTATE_LOOP_IMPL_2(tuple)                \
	BOOST_PP_FOR(                                   \
		(0, BOOST_PP_TUPLE_SIZE(tuple), tuple), \
		HMP4_PRED, HMP4_OP, HMP4_MACRO          \
	)

#endif
