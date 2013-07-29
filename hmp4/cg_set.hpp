/*
** File Name:	cg_set.hpp
** Author:	Aditya Ramesh
** Date:	07/28/2013
** Contact:	_@adityaramesh.com
*/

#ifndef Z3FC1AC17_63A6_4BA4_9FA3_A2C3AC210790
#define Z3FC1AC17_63A6_4BA4_9FA3_A2C3AC210790

#include <hmp4/hash.hpp>
#include <hmp4/join.hpp>

#define HMP4_CG_SET(...) \
	HMP4_CG_SET_IMPL_1(__VA_ARGS__)

#define HMP4_CG_SET_IMPL_1(...) \
	HMP4_CG_SET_IMPL_2(hmpp HMP4_PREPEND_HASH(define) HMP4_JOIN(__VA_ARGS__))

#define HMP4_CG_SET_IMPL_2(a) \
	HMP4_CG_SET_IMPL_3(a)

#define HMP4_CG_SET_IMPL_3(a) \
	_Pragma(#a)

#endif
