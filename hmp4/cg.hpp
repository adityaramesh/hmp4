/*
** File Name:	cg_set.hpp
** Author:	Aditya Ramesh
** Date:	07/28/2013
** Contact:	_@adityaramesh.com
*/

#ifndef Z3FC1AC17_63A6_4BA4_9FA3_A2C3AC210790
#define Z3FC1AC17_63A6_4BA4_9FA3_A2C3AC210790

#include <boost/preprocessor/facilities/expand.hpp>
#include <hmp4/hash.hpp>
#include <hmp4/join.hpp>

#define HMP4_CG_DEFINE(...) \
	HMP4_CG_HELPER_1(hmpp HMP4_PREPEND_HASH(define), __VA_ARGS__)

#define HMP4_CG_PERMUTE(...) \
	HMP4_CG_HELPER_1(hmpp permute, __VA_ARGS__)

#define HMP4_CG_GRID_BLOCKSIZE(a, b) \
	HMP4_CG_HELPER_1(hmpp grid blocksize, HMP4_MAKE_DIMENSIONS(a, b))

#define HMP4_MAKE_DIMENSIONS(a, b) \
	HMP4_MAKE_DIMENSIONS_IMPL_1(a, b) \

#define HMP4_MAKE_DIMENSIONS_IMPL_1(a, b) \
	HMP4_MAKE_DIMENSIONS_IMPL_2(a ## x ## b) \

#define HMP4_MAKE_DIMENSIONS_IMPL_2(a) \
	#a

#define HMP4_CG_HELPER_1(a, ...) \
	HMP4_CG_HELPER_2(a HMP4_JOIN(__VA_ARGS__))

#define HMP4_CG_HELPER_2(a) \
	HMP4_CG_HELPER_3(a)

#define HMP4_CG_HELPER_3(a) \
	_Pragma(#a)

#endif
