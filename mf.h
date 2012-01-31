/**
 * @file mf.h
 * wrapper for fast median filter based on OpenCV.
 *
 * @blackball
 */

#ifndef MEDIANFILTER_H
#define MEDIANFILTER_H

/* forward declaration */
typedef struct _IplImage IplImage;

/**
 * median filter with simplified interface
 *
 * @param src should be 'CHAR' depth, color image supported
 * @param dst same size and format with src, allocated outside
 * @param radius kernel radius, in fact, the kernel is squre
 * and the width and height is (2*radius + 1)
 */
void mf(IplImage *src, IplImage *dst, int radius);

#endif 
