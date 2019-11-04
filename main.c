/*
 * main.c
 *
 *  Created on: 2 Nov 2019
 *      Author: greg
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "dldrec.h"
#include "textconv.defs.h"
#include "getargs.h"

int main(int argc, char **argv)
{
	struct args_def args;
	char record_read[DLDREC_LENGTH];
	FILE *in_file = NULL;
	bool finished = false;

	get_arguments(argc, argv, &args);

	in_file = fopen(args.in_file, "r");
	if (in_file == NULL) {
		perror("Failed to open in-file");
		exit(EXIT_FAILURE);
	}

	while (!finished) {
		if (fgets(record_read, DLDREC_LENGTH, in_file) != NULL ) {
			printf("%s", record_read);
		} else {
			finished = true;
		} // TODO - make this stub into a proper record-processor

	}

	return EXIT_SUCCESS;
}
