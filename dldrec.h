/*
 * dldrec.h
 *
 *  Created on: 4 Nov 2019
 *      Author: greg
 */

#ifndef DLDREC_H_
#define DLDREC_H_

#include <stddef.h>

enum dldrec_sizeofs{DLDREC_LENGTH = 42};

struct dldrec {

	union {

		char bytes[DLDREC_LENGTH]; // unstructured bytes
		struct {

			// record header - 6 bytes
			struct {
				unsigned char rec_num[4];
				unsigned char rec_typ;
				char filler_01;
			} rec_header;

			// record body: up to 34 bytes
			union {
				struct { // 10 bytes
					unsigned char yyyy[4];
					unsigned char mm[2];
					unsigned char dd[2];
					unsigned char nn[2];
				} header_rec_body;

				struct { // 34 bytes
					unsigned char name[16];
					unsigned char colour[16];
					unsigned char age[2];
				} data_rec_body;

				struct { // 8 bytes
					unsigned char recs_count[8];
				} trailer_rec_body;
			} dld_rec_body;

			// non-data "array trailer" elements: 2 bytes
			char eol_byte; // in case disk record has a terminating EOL
			char zero_byte; // for fgets() to place terminating 0

		} data;

	} dld_rec;
};

#endif /* DLDREC_H_ */
