/*
 * printrec.c
 *
 *  Created on: 4 Nov 2019
 *      Author: greg
 */

#include <stdio.h>

#include "dldrec.h"

void print_record(char *record)
{
	struct dld_rec *dld = (struct dld_rec *)record;

	if (dld->header.typ == 'H') {
		puts("header");
	} else if (dld->header.typ == 'D') {
		puts("data");
	} else if (dld->header.typ == 'T') {
		puts("trailer");
	} else {
		puts("unknown record type");
	}

	return;
}
