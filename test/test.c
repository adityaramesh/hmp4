/*
** File Name:	test.c
** Author:	Aditya Ramesh
** Date:	07/28/2013
** Contact:	_@adityaramesh.com
*/

#include <p5/annotate.hpp>
#include <p5/tuple.hpp>

//P5_PP_DEFINE(a,b,c)
//P5_CG_GRID_BLOCKSIZE(3, 3)
//P5_CG_NATIVE(CUDA, poop)
//P5_CG_NO_PARALLEL

#define LOOP_A_PARAMETERS                                          \
	(                                                          \
		("hmppcg grid blocksize 32x8", "hmppcg parallel"), \
		("hmppcg parallel"),                               \
		("hmppcg unroll 8, guarded", "hmppcg noParallel")  \
	)

P5_ANNOTATE_LOOP(LOOP_A_PARAMETERS)
