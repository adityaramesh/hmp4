/*
** File Name:	hash.hpp
** Author:	Aditya Ramesh
** Date:	07/28/2013
** Contact:	_@adityaramesh.com
*/

#ifndef Z12569416_23E5_434B_82E1_2548BC5902D6
#define Z12569416_23E5_434B_82E1_2548BC5902D6

#include <boost/preprocessor/facilities/expand.hpp>

#define P5_HASH #
#define P5_PREPEND_HASH(a) BOOST_PP_EXPAND(P5_HASH)a

#endif
