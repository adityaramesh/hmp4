/*
** File Name:	directive.hpp
** Author:	Aditya Ramesh
** Date:	07/28/2013
** Contact:	_@adityaramesh.com
*/

#ifndef Z3FC1AC17_63A6_4BA4_9FA3_A2C3AC210790
#define Z3FC1AC17_63A6_4BA4_9FA3_A2C3AC210790

#include <boost/preprocessor/facilities/expand.hpp>
#include <p5/hash.hpp>
#include <p5/join.hpp>
#include <p5/pragma.hpp>

/*
** Low-level directive functions.
*/

#define P5_MAKE_DIMENSIONS(a, b) \
	P5_MAKE_DIMENSIONS_IMPL_1(a, b) \

#define P5_MAKE_DIMENSIONS_IMPL_1(a, b) \
	P5_MAKE_DIMENSIONS_IMPL_2(a ## x ## b) \

#define P5_MAKE_DIMENSIONS_IMPL_2(a) \
	#a

#define P5_DIRECTIVE(a, ...) \
	P5_DIRECTIVE_IMPL_1(a P5_JOIN(__VA_ARGS__))

#define P5_DIRECTIVE_IMPL_1(a) \
	P5_DIRECTIVE_IMPL_2(a)

#define P5_DIRECTIVE_IMPL_2(a) \
	P5_PRAGMA(#a)

/*
** Loop properties.
*/

#define P5_CG_GRIDIFY(...) \
	P5_DIRECTIVE(hmppcg gridify, __VA_ARGS__)

#define P5_CG_PARALLEL(...) \
	P5_DIRECTIVE(hmppcg parallel, __VA_ARGS__)

#define P5_CG_NO_PARALLEL \
	P5_DIRECTIVE(hmppcg noParallel)

#define P5_CG_GRID_BLOCKSIZE(a, b) \
	P5_DIRECTIVE(hmppcg grid blocksize, P5_MAKE_DIMENSIONS(a, b))

#define P5_CG_SET(...) \
	P5_DIRECTIVE(hmppcg set, P5_MAKE_DIMENSIONS(__VA_ARGS__))

/*
** Loop transformations.
*/

#define P5_CG_DISTRIBUTE(...) \
	P5_DIRECTIVE(hmppcg distribute, __VA_ARGS__)

#define P5_CG_CUT(...) \
	P5_DIRECTIVE(hmppcg cut, __VA_ARGS__)

#define P5_CG_FUSE(...) \
	P5_DIRECTIVE(hmppcg fuse, __VA_ARGS__)

#define P5_CG_PERMUTE(...) \
	P5_DIRECTIVE(hmppcg permute, __VA_ARGS__)

#define P5_CG_UNROLL(...) \
	P5_DIRECTIVE(hmppcg unroll, __VA_ARGS__)

#define P5_CG_FULLUNROLL(...) \
	P5_DIRECTIVE(hmppcg fullunroll, __VA_ARGS__)

#define P5_CG_TILE(...) \
	P5_DIRECTIVE(hmppcg tile, __VA_ARGS__)

/*
** Native functions.
*/

#define P5_CG_NATIVE(target, function) \
	P5_DIRECTIVE(hmppcg native(target) function,)

#define P5_CG_INCLUDE(file) \
	P5_DIRECTIVE(hmppcg include(file))

/*
** Preprocessor directives.
*/

#define P5_PP_ECHO(...) \
	P5_DIRECTIVE(hmpp P5_PREPEND_HASH(echo), __VA_ARGS__)

#define P5_PP_ERROR(...) \
	P5_DIRECTIVE(hmpp P5_PREPEND_HASH(error), __VA_ARGS__)

#define P5_PP_WARNING(...) \
	P5_DIRECTIVE(hmpp P5_PREPEND_HASH(warning), __VA_ARGS__)

#define P5_PP_PRINT(...) \
	P5_DIRECTIVE(hmpp P5_PREPEND_HASH(print), __VA_ARGS__)

#define P5_PP_DEFINE(...) \
	P5_DIRECTIVE(hmpp P5_PREPEND_HASH(define), __VA_ARGS__)

#define P5_PP_BLOCK(...) \
	P5_DIRECTIVE(hmpp P5_PREPEND_HASH(block), __VA_ARGS__)

#define P5_PP_ENDBLOCK(...) \
	P5_DIRECTIVE(hmpp P5_PREPEND_HASH(endblock), __VA_ARGS__)

#define P5_PP_INSERT(...) \
	P5_DIRECTIVE(hmpp P5_PREPEND_HASH(insert), __VA_ARGS__)

#endif
