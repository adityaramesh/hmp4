<!--
  ** File Name:	README.md
  ** Author:	Aditya Ramesh
  ** Date:	07/28/2013
  ** Contact:	_@adityaramesh.com
-->

# Introduction

`p5` is a tool intended to allow for the automatic insertion configuration
pragma directives through the use of higher-order preprocessor directives. This
tool makes it easy, for example, to change the loop configuration parameters in
your HMPP kernels without manually changing the preprocessor directives in your
code. If you are performing auto-tuning on C or C++ code using pragma-based
utilities like HMPP, OpenACC, or OpenMP, then you probably need this library.

# Installation

This is a header-only library that contains only macro definitions. To download
the library, click the "Download ZIP" button at the right-hand side of your
screen. The headers are contained in the `p5` directory. Note that this
library requires a C99 compiler and depends on the Boost.Preprocessor library.

# Usage

## Getting Started

We will modify the following listing to use the macros defined by `p5`.

	#pragma hmppcg grid blocksize "32x8"
	#pragma hmppcg parallel
	for (i = 0; i < NI; i++)
	{
		#pragma hmppcg parallel
		for (j = 0; j < NJ; j++)
		{
			e[i][j] = 0;

			#pragma hmppcg unroll 8, guarded
			#pragma hmppcg noParallel
			for (k = 0; k < NK; ++k)
			{
				e[i][j] += a[i][k] * b[k][j];
			}
		}
	}

The `p5` library requires a data structure that contains the contents of the
HMPP directives associated with each loop. This data structure is supplied as
the argument to the `P5_ANNOTATE_LOOP` macro, which is invoked before each
loop associated with HMPP directives. This macro reads the contents of the HMPP
directive associated with each loop from the data structure, and pastes the
contents into a series of pragma statements. The tuple associated with the code
listing above is given below.

	#define LOOP_PARAMETERS                                            \
		(                                                          \
			("hmppcg grid blocksize 32x8", "hmppcg parallel"), \
			("hmppcg parallel"),                               \
			("hmppcg unroll 8, guarded", "hmppcg noParallel")  \
		)

Using the `P5_ANNOTATE_LOOP` macro, the new code listing given below will
expand to the original code listing.

	P5_ANNOTATE_LOOP(LOOP_PARAMETERS)
	for (i = 0; i < NI; i++)
	{
		P5_ANNOTATE_LOOP(LOOP_PARAMETERS)
		for (j = 0; j < NJ; j++)
		{
			e[i][j] = 0;

			P5_ANNOTATE_LOOP(LOOP_PARAMETERS)
			for (k = 0; k < NK; ++k)
			{
				e[i][j] += a[i][k] * b[k][j];
			}
		}
	}

## Multiple Functions

It is imperative that the same loop parameter tuple be used in the
`P5_ANNOTATE_LOOP` macros throughout the entire file. However, in order to
maintain legibility, it is convenient to define separate loop parameter tuples
for each function in your source file. The `P5_TUPLE_CAT` macro is useful in
this regard; its use is demonstrated below.

	#define LOOP_A_PARAMETERS                                          \
		(                                                          \
			("hmppcg grid blocksize 32x8", "hmppcg parallel"), \
			("hmppcg parallel"),                               \
			("hmppcg unroll 8, guarded", "hmppcg noParallel")  \
		)

	#define LOOP_B_PARAMETERS                                          \
		(                                                          \
			("hmppcg grid blocksize 32x8", "hmppcg parallel"), \
			("hmppcg parallel"),                               \
			("hmppcg unroll 8, guarded", "hmppcg noParallel")  \
		)

	#define LOOP_C_PARAMETERS                                          \
		(                                                          \
			("hmppcg grid blocksize 32x8", "hmppcg parallel"), \
			("hmppcg parallel"),                               \
			("hmppcg unroll 8, guarded", "hmppcg noParallel")  \
		)

	#define LOOP_PARAMETERS \
		P5_TUPLE_CAT(LOOP_A_PARAMETERS, LOOP_B_PARAMETERS, LOOP_C_PARAMETERS)
