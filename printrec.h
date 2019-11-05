/*
 * printrec.h
 *
 *  Created on: 4 Nov 2019
 *      Author: greg
 */

#ifndef PRINTREC_H_
#define PRINTREC_H_

#include "dldrec.h"

void print_record(char *record);
void print_header_record(struct dld_rec_def *record);
void print_data_record(struct dld_rec_def *record);
void print_trailer_record(struct dld_rec_def *record);
void print_record_header(struct dld_record_header_def *header);

#endif /* PRINTREC_H_ */
