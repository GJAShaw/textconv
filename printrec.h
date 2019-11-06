/*
 * printrec.h
 *
 *  Created on: 4 Nov 2019
 *      Author: greg
 */

#ifndef PRINTREC_H_
#define PRINTREC_H_

#include "dldrec.h"

enum indentation_sizes{FOUR_COLUMNS = 4};

void print_record(char *record);
void print_header_record(struct dld_rec_def *record, size_t *indents);
void print_data_record(struct dld_rec_def *record, size_t *indents);
void print_trailer_record(struct dld_rec_def *record, size_t *indents);
void print_record_header(struct dld_record_header_def *header, size_t *indents);
void print_xml_oneliner(char *tag_name, unsigned char *content, size_t content_length, size_t *indents);

#endif /* PRINTREC_H_ */
