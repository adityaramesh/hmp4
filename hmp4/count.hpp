/*
** File Name:	count.hpp
** Author:	Aditya Ramesh
** Date:	07/28/2013
** Contact:	_@adityaramesh.com
*/

#ifndef Z03BE52C2_8635_41BE_84BD_1348AE5FBE39
#define Z03BE52C2_8635_41BE_84BD_1348AE5FBE39

#define HMP4_COUNT(...) \
	HMP4_COUNT_IMPL(__VA_ARGS__, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, \
		8, 7, 6, 5, 4, 3, 2, 1)

#define HMP4_COUNT_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, \
	_15, _16, _17, _18, _19, _20, N, ...) N

#endif
