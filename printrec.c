/*
 * printrec.c
 *
 *  Created on: 4 Nov 2019
 *      Author: greg
 */

#include <stdio.h>

#include "textconv.defs.h"
#include "dldrec.h"
#include "printrec.h"

void print_record(char *record)
{
	struct dld_rec_def *dld = (struct dld_rec_def *)record;

	puts("<dld_rec>");

	if (dld->header.typ == 'H') {
		print_header_record(dld);
	} else if (dld->header.typ == 'D') {
		print_data_record(dld);
	} else if (dld->header.typ == 'T') {
		print_trailer_record(dld);
	} else {
		puts("unknown record type");
	}

	puts("</dld_rec>");

	return;
}

void print_header_record(struct dld_rec_def *record)
{
	print_record_header(&(record->header));
	printf(" ");
	puts("header record");
}

void print_data_record(struct dld_rec_def *record)
{
	print_record_header(&(record->header));
	printf(" ");
	puts("data record");
}

void print_trailer_record(struct dld_rec_def *record)
{
	print_record_header(&(record->header));

	puts("\t<trailer_body>");

	printf("\t\t%s", "<recs_count>");
	fwrite(
			(const void *)&(record->data_u.trailer.recs_count),
			sizeof(record->data_u.trailer.recs_count),
			ONE_ELEMENT,
			stdout
	);
	printf("%s\n", "</recs_count>");

	puts("\t</trailer_body>");


}

void print_record_header(struct dld_record_header_def *header)
{
	size_t offset = 0; // running total of bytes read from header

	puts("\t<record_header>");

	printf("\t\t%s", "<num>");
	fwrite((const void *)header, sizeof(header->num), ONE_ELEMENT, stdout);
	printf("%s\n", "</num>");
	offset += sizeof(header->num);

	printf("\t\t%s", "<type>");
	fwrite((const void *)header + offset, sizeof(header->typ), ONE_ELEMENT, stdout);
	printf("%s\n", "</type>");

	puts("\t</record_header>");

}
