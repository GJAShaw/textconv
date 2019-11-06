/*
 * textconv.defs.h
 *
 *  Created on: 2 Nov 2019
 *      Author: greg
 */

#ifndef HDR_TEXTCONV_DEFS_H_
#define HDR_TEXTCONV_DEFS_H_


/* array size - need to do this better */
enum sizes {ARRAY_SIZE = 100};

/**/
enum counts {ONE_ELEMENT = 1};

/* args_def */
struct args_def {
	char *in_file;
};

#endif /* HDR_TEXTCONV_DEFS_H_ */
