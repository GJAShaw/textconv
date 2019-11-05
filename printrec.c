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

	puts("\t<header_body>");

	printf("\t\t%s", "<yyyy>");
	fwrite(
			(const void *)&(record->data_u.header.yyyy),
			sizeof(record->data_u.header.yyyy),
			ONE_ELEMENT,
			stdout
	);
	printf("%s\n", "</yyyy>");

	printf("\t\t%s", "<mm>");
	fwrite(
			(const void *)&(record->data_u.header.mm),
			sizeof(record->data_u.header.mm),
			ONE_ELEMENT,
			stdout
	);
	printf("%s\n", "</mm>");

	printf("\t\t%s", "<dd>");
	fwrite(
			(const void *)&(record->data_u.header.dd),
			sizeof(record->data_u.header.dd),
			ONE_ELEMENT,
			stdout
	);
	printf("%s\n", "</dd>");

	printf("\t\t%s", "<nn>");
	fwrite(
			(const void *)&(record->data_u.header.nn),
			sizeof(record->data_u.header.nn),
			ONE_ELEMENT,
			stdout
	);
	printf("%s\n", "</nn>");

	puts("\t</header_body>");

}

void print_data_record(struct dld_rec_def *record)
{
	puts("\t<data_body>");

	printf("\t\t%s", "<name>");
	fwrite(
			(const void *)&(record->data_u.data.name),
			sizeof(record->data_u.data.name),
			ONE_ELEMENT,
			stdout
	);
	printf("%s\n", "</name>");

	printf("\t\t%s", "<colour>");
	fwrite(
			(const void *)&(record->data_u.data.colour),
			sizeof(record->data_u.data.colour),
			ONE_ELEMENT,
			stdout
	);
	printf("%s\n", "</colour>");

	printf("\t\t%s", "<age>");
	fwrite(
			(const void *)&(record->data_u.data.age),
			sizeof(record->data_u.data.age),
			ONE_ELEMENT,
			stdout
	);
	printf("%s\n", "</age>");

	puts("\t</data_body>");
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
	size_t offset = 0; // running total of bytes read from record

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
