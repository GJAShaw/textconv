/*
 * dldrec.h
 *
 *  Created on: 4 Nov 2019
 *      Author: greg
 */

#ifndef DLDREC_H_
#define DLDREC_H_

#include <stddef.h>

struct dld_record_header_def {
	unsigned char num[4];
	unsigned char typ;
	char filler_01;
};

struct dld_header_data_def {
	unsigned char yyyy[4];
	unsigned char mm[2];
	unsigned char dd[2];
	unsigned char nn[2];
};

struct dld_data_data_def {
	unsigned char name[16];
	unsigned char colour[16];
	unsigned char age[2];
};

struct dld_trailer_data_def {
	unsigned char recs_count[8];
};

struct dld_rec {

	struct dld_record_header_def header;
	union {
		struct dld_header_data_def header;
		struct dld_data_data_def data;
		struct dld_trailer_data_def trailer;
	} data_u;

};

#endif /* DLDREC_H_ */
