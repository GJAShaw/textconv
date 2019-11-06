/*
 * main.c
 *
 *  Created on: 2 Nov 2019
 *      Author: greg
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "textconv.defs.h"
#include "dldrec.h"
#include "getargs.h"
#include "printrec.h"

int main(int argc, char **argv)
{
	struct args_def args;
	char record_read[ARRAY_SIZE];
	FILE *in_file = NULL;
	bool finished = false;

	get_arguments(argc, argv, &args);

	in_file = fopen(args.in_file, "r");
	if (in_file == NULL) {
		perror("Failed to open in-file");
		exit(EXIT_FAILURE);
	}

	while (!finished) {
		if (fgets(record_read, ARRAY_SIZE, in_file) != NULL ) {
			print_record(record_read);
		} else {
			finished = true;
			if (ferror(in_file))
				exit(EXIT_FAILURE);
		}

	}

	return EXIT_SUCCESS;
}
