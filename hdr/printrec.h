/*
 * printrec.h
 *
 *  Created on: 4 Nov 2019
 *      Author: greg
 */

#ifndef HDR_PRINTREC_H_
#define HDR_PRINTREC_H_

#include "dldrec.h"

enum indentation_sizes{FOUR_COLUMNS = 4};

void print_data_record(struct dld_rec_def *record, size_t *indents);
void print_header_record(struct dld_rec_def *record, size_t *indents);
void print_indentation_spaces(size_t number_of_indents, size_t chars_per_indent);
void print_record(char *record);
void print_record_header(struct dld_record_header_def *header, size_t *indents);
void print_trailer_record(struct dld_rec_def *record, size_t *indents);
void print_xml_oneliner(char *tag_name, unsigned char *content, size_t content_length, size_t *indents);

#endif /* HDR_PRINTREC_H_ */
