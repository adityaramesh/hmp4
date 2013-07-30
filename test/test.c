/*
** File Name:	test.c
** Author:	Aditya Ramesh
** Date:	07/28/2013
** Contact:	_@adityaramesh.com
*/

#include <hmp4/annotate.hpp>
#include <hmp4/tuple.hpp>

//HMP4_PP_DEFINE(a,b,c)
//HMP4_CG_GRID_BLOCKSIZE(3, 3)
//HMP4_CG_NATIVE(CUDA, poop)
//HMP4_CG_NO_PARALLEL

#define LOOP_A_PARAMETERS                                          \
	(                                                          \
		("hmppcg grid blocksize 32x8", "hmppcg parallel"), \
		("hmppcg parallel"),                               \
		("hmppcg unroll 8, guarded", "hmppcg noParallel")  \
	)

HMP4_ANNOTATE_LOOP(LOOP_A_PARAMETERS)
