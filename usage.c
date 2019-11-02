/*
 * usage.c
 *
 *  Created on: 2 Nov 2019
 *      Author: greg
 */

#include <libgen.h>
#include <stdio.h>

void print_usage(char *path){

	char *name = basename(path);
	printf("%s%s%s\n", "---- ", name, " ----");
	puts("Work in progress. Usage info will go here");
	return;

}
