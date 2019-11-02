/*
 * main.c
 *
 *  Created on: 2 Nov 2019
 *      Author: greg
 */

#include <stdlib.h>

#include "textconv.defs.h"
#include "getargs.h"

int main(int argc, char **argv)
{
	struct args_def args;
	get_arguments(argc, argv, &args);
	return EXIT_SUCCESS;
}
