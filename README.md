<!--
  ** File Name:	README.md
  ** Author:	Aditya Ramesh
  ** Date:	07/28/2013
  ** Contact:	_@adityaramesh.com
-->

# Introduction

`hmp4` is short for `HMPPPP` --- a tool intended to allow for the configuration
of HMPP codelet generation preprocessor directives through the use of
higher-order preprocessor directives. This tool makes it easy to change the loop
configuration parameters in your HMPP kernels without manually changing the
preprocessor directives in your code. If you are performing auto-tuning on C
code using HMPP, then you probably need this library.

# Installation

This is a header-only library that contains only macro definitions. To download
the library, click the "Download ZIP" button at the right-hand side of your
screen. The headers are contained in the `hmp4` directory. Note that this
library requires a C99 compiler and depends on the Boost.Preprocessor library.

# Usage

## Getting Started

We will modify the following listing to use the macros defined by `hmp4`.

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

The `hmp4` library requires a data structure that defines the HMPP directives to
be invoked before each loop. This data structure is supplied as the argument to
the `HMP4_ANNOTATE_LOOP` macro, which is invoked before each loop that is
associated with HMPP directives. The macro reads from the data structure the
names and the parameters of the HMPP directives associated with each loop, and
declares the HMPP directives for you.

These names and parameters of these directives are provided in a tuple of tuple
of tuple of loop parameters. The data structure is triply nested because there
can be multiple loops in a program, and multiple HMPP directives corresponding
to each loop. The tuple corresponding to the previous code listing is given
below:

	#define LOOP_PARAMETERS                        \
	(                                              \
		((grid blocksize, 32, 8), (parallel)), \
		((parallel)),                          \
		((unroll, 8, guarded), (noParallel))   \
	)

Using the `HMP4_ANNOTATE_LOOP` macro, the new code listing given below will
expand to the original code listing.

	HMP4_ANNOTATE_LOOP(LOOP_PARAMETERS)
	for (i = 0; i < NI; i++)
	{
		HMP4_ANNOTATE_LOOP(LOOP_PARAMETERS)
		for (j = 0; j < NJ; j++)
		{
			e[i][j] = 0;

			HMP4_ANNOTATE_LOOP(LOOP_PARAMETERS)
			for (k = 0; k < NK; ++k)
			{
				e[i][j] += a[i][k] * b[k][j];
			}
		}
	}

## Multiple Functions

It is imperative that the same loop parameter tuple be used in the
`HMP4_ANNOTATE_LOOP` macros throughout the entire file. However, in order to
maintain legibility, it is convenient to define separate loop parameter tuples
for each function in your source file. The `HMP4_TUPLE_CAT` macro is useful in
this regard; its use is demonstrated below.

	#define LOOP_A_PARAMETERS                              \
		(                                              \
			((grid blocksize, 32, 8), (parallel)), \
			((parallel)),                          \
			((unroll, 8, guarded), (noParallel))   \
		)

	#define LOOP_B_PARAMETERS                              \
		(                                              \
			((grid blocksize, 32, 8), (parallel)), \
			((parallel)),                          \
			((unroll, 8, guarded), (noParallel))   \
		)

	#define LOOP_C_PARAMETERS                              \
		(                                              \
			((grid blocksize, 32, 8), (parallel)), \
			((parallel)),                          \
			((unroll, 8, guarded), (noParallel))   \
		)

	#define LOOP_PARAMETERS \
		HMP4_TUPLE_CAT(LOOP_A_PARAMETERS, LOOP_B_PARAMETERS, LOOP_C_PARAMETERS)
