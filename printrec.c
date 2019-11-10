/*
 * printrec.c
 *
 *  Created on: 4 Nov 2019
 *      Author: greg
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hdr/dldrec.h"
#include "hdr/printrec.h"
#include "hdr/textconv_defs.h"

void print_record(char *record)
{
	size_t indents = 0;
	struct dld_rec_def *dld = (struct dld_rec_def *)record;
	static bool xml_declaration_written = false;

	if (!xml_declaration_written){
		puts("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
		xml_declaration_written = true;
	}

	puts("<dld_rec>");
	++indents;

	if (dld->header.typ == 'H') {
		print_header_record(dld, &indents);
	} else if (dld->header.typ == 'D') {
		print_data_record(dld, &indents);
	} else if (dld->header.typ == 'T') {
		print_trailer_record(dld, &indents);
	} else {
		puts("unknown record type");
	}

	--indents;
	puts("</dld_rec>");

	return;
}

void print_header_record(struct dld_rec_def *record, size_t *indents)
{
	print_record_header(&(record->header), indents);

	print_indentation_spaces(*indents, FOUR_COLUMNS);
	puts("<header_body>");

	++(*indents);

	print_xml_oneliner(
		"yyyy", record->data_u.header.yyyy, sizeof(record->data_u.header.yyyy), indents
	);
	print_xml_oneliner(
		"mm", record->data_u.header.mm, sizeof(record->data_u.header.mm), indents
	);
	print_xml_oneliner(
		"dd", record->data_u.header.dd, sizeof(record->data_u.header.dd), indents
	);
	print_xml_oneliner(
		"nn", record->data_u.header.nn, sizeof(record->data_u.header.nn), indents
	);

	--(*indents);

	print_indentation_spaces(*indents, FOUR_COLUMNS);
	puts("</header_body>");

}

void print_data_record(struct dld_rec_def *record, size_t *indents)
{
	print_record_header(&(record->header), indents);

	print_indentation_spaces(*indents, FOUR_COLUMNS);
	puts("<data_body>");

	++(*indents);

	print_xml_oneliner(
		"name", record->data_u.data.name, sizeof(record->data_u.data.name), indents
	);
	print_xml_oneliner(
		"colour", record->data_u.data.colour, sizeof(record->data_u.data.colour), indents
	);
	print_xml_oneliner(
		"age", record->data_u.data.age, sizeof(record->data_u.data.age), indents
	);

	--(*indents);

	print_indentation_spaces(*indents, FOUR_COLUMNS);
	puts("</data_body>");

}

void print_trailer_record(struct dld_rec_def *record, size_t *indents)
{
	print_record_header(&(record->header), indents);

	print_indentation_spaces(*indents, FOUR_COLUMNS);
	puts("<trailer_body>");

	++(*indents);

	print_xml_oneliner(
		"recs_count",
		record->data_u.trailer.recs_count,
		sizeof(record->data_u.trailer.recs_count),
		indents
	);

	--(*indents);

	print_indentation_spaces(*indents, FOUR_COLUMNS);
	puts("</trailer_body>");

}

void print_record_header(struct dld_record_header_def *header, size_t *indents)
{
	print_indentation_spaces(*indents, FOUR_COLUMNS);
	puts("<record_header>");

	++(*indents);

	print_xml_oneliner("num", header->num, sizeof(header->num), indents);
	print_xml_oneliner("typ", &(header->typ), sizeof(header->typ), indents);

	--(*indents);

	print_indentation_spaces(*indents, FOUR_COLUMNS);
	puts("</record_header>");

}

void print_xml_oneliner(char *tag_name, unsigned char* content, size_t content_length, size_t *indents)
{
	size_t l = 0; // text length
	char tag_delimiters[] = "<></>"; // to help clarify calculation of l
	char *text = NULL;
	char *ptr = NULL;

	l = strlen(tag_delimiters) + (2 * strlen(tag_name)) + content_length;
	text = malloc(l);
	if (text == NULL) {
		perror("print_xml_oneliner malloc() failure");
		exit(EXIT_FAILURE);
	}

	ptr = text;
	memcpy((void *)ptr, (void *)"<", 1);
	ptr += 1;
	memcpy((void *)ptr, (void *)tag_name, strlen(tag_name));
	ptr += strlen(tag_name);
	memcpy((void *)ptr, (void *)">", 1);
	ptr += 1;
	memcpy((void *)ptr, (void *)content, content_length);
	ptr += content_length;
	memcpy((void *)ptr, (void *)"</", 2);
	ptr += 2;
	memcpy((void *)ptr, (void *)tag_name, strlen(tag_name));
	ptr += strlen(tag_name);
	memcpy((void *)ptr, (void *)">", 1);

	print_indentation_spaces(*indents, FOUR_COLUMNS);
	fwrite((const void *)text, l, ONE_ELEMENT, stdout);
	puts("");

	free(text);
	// It's safe not to make ptr and text NULL, as they're about to disappear

	return;

}

inline void print_indentation_spaces(size_t number_of_indents, size_t chars_per_indent)
{
	size_t n = number_of_indents * chars_per_indent;
	for (size_t i = 0; i < n; ++i)
		putc(' ', stdout);

}
