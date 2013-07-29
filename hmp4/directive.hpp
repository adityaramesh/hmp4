/*
** File Name:	directive.hpp
** Author:	Aditya Ramesh
** Date:	07/28/2013
** Contact:	_@adityaramesh.com
*/

#ifndef Z3FC1AC17_63A6_4BA4_9FA3_A2C3AC210790
#define Z3FC1AC17_63A6_4BA4_9FA3_A2C3AC210790

#include <boost/preprocessor/facilities/expand.hpp>
#include <hmp4/hash.hpp>
#include <hmp4/join.hpp>

/*
** Low-level directive functions.
*/

#define HMP4_MAKE_DIMENSIONS(a, b) \
	HMP4_MAKE_DIMENSIONS_IMPL_1(a, b) \

#define HMP4_MAKE_DIMENSIONS_IMPL_1(a, b) \
	HMP4_MAKE_DIMENSIONS_IMPL_2(a ## x ## b) \

#define HMP4_MAKE_DIMENSIONS_IMPL_2(a) \
	#a

#define HMP4_DIRECTIVE(a, ...) \
	HMP4_DIRECTIVE_IMPL_1(a HMP4_JOIN(__VA_ARGS__))

#define HMP4_DIRECTIVE_IMPL_1(a) \
	HMP4_DIRECTIVE_IMPL_2(a)

#define HMP4_DIRECTIVE_IMPL_2(a) \
	_Pragma(#a)

/*
** Loop properties.
*/

#define HMP4_CG_GRID_BLOCKSIZE(a, b) \
	HMP4_DIRECTIVE(hmppcg grid blocksize, HMP4_MAKE_DIMENSIONS(a, b))

/*
** Loop transformations.
*/

#define HMP4_CG_DISTRIBUTE(...) \
	HMP4_DIRECTIVE(hmppcg distribute, __VA_ARGS__)

#define HMP4_CG_CUT(...) \
	HMP4_DIRECTIVE(hmppcg cut, __VA_ARGS__)

#define HMP4_CG_FUSE(...) \
	HMP4_DIRECTIVE(hmppcg fuse, __VA_ARGS__)

#define HMP4_CG_PERMUTE(...) \
	HMP4_DIRECTIVE(hmppcg permute, __VA_ARGS__)

#define HMP4_CG_UNROLL(...) \
	HMP4_DIRECTIVE(hmppcg unroll, __VA_ARGS__)

#define HMP4_CG_FULLUNROLL(...) \
	HMP4_DIRECTIVE(hmppcg fullunroll, __VA_ARGS__)

#define HMP4_CG_TILE(...) \
	HMP4_DIRECTIVE(hmppcg tile, __VA_ARGS__)

#define HMP4_CG_NATIVE(...) \
	HMP4_DIRECTIVE(hmppcg native, __VA_ARGS__)

/*
** Preprocessor directives.
*/

#define HMP4_PP_ECHO(...) \
	HMP4_DIRECTIVE(hmpp HMP4_PREPEND_HASH(echo), __VA_ARGS__)

#define HMP4_PP_ERROR(...) \
	HMP4_DIRECTIVE(hmpp HMP4_PREPEND_HASH(error), __VA_ARGS__)

#define HMP4_PP_WARNING(...) \
	HMP4_DIRECTIVE(hmpp HMP4_PREPEND_HASH(warning), __VA_ARGS__)

#define HMP4_PP_PRINT(...) \
	HMP4_DIRECTIVE(hmpp HMP4_PREPEND_HASH(print), __VA_ARGS__)

#define HMP4_PP_DEFINE(...) \
	HMP4_DIRECTIVE(hmpp HMP4_PREPEND_HASH(define), __VA_ARGS__)

#define HMP4_PP_BLOCK(...) \
	HMP4_DIRECTIVE(hmpp HMP4_PREPEND_HASH(block), __VA_ARGS__)

#define HMP4_PP_ENDBLOCK(...) \
	HMP4_DIRECTIVE(hmpp HMP4_PREPEND_HASH(endblock), __VA_ARGS__)

#define HMP4_PP_INSERT(...) \
	HMP4_DIRECTIVE(hmpp HMP4_PREPEND_HASH(insert), __VA_ARGS__)

#endif
