/*
 * main.c
 *
 *  Created on: 2 Nov 2019
 *      Author: greg
 */

#include <stdio.h>
#include <stdlib.h>

#include "textconv.defs.h"
#include "getargs.h"

int main(int argc, char **argv)
{
	struct args_def args;
	FILE *in_file = NULL;

	get_arguments(argc, argv, &args);

	in_file = fopen(args.in_file, "r");
	if (in_file == NULL) {
		perror("Failed to open in-file");
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}
