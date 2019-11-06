/*
 * getargs.c
 *
 *  Created on: 2 Nov 2019
 *      Author: greg
 */

#include <stdlib.h>

#include "hdr/usage.h"
#include "textconv.defs.h"

void get_arguments(int argc, char **argv, struct args_def *args)
{
	switch (argc) {

	case 1:
		print_usage(argv[0]);
		exit(EXIT_SUCCESS);
		break;

	case 2:
		args->in_file = argv[1];
		break;

	default:
		print_usage(argv[0]);
		exit(EXIT_FAILURE);
		break;

	}
}
