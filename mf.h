/**
 * @file mf.h
 * wrapper for fast median filter based on OpenCV.
 *
 * @blackball
 */

#ifndef MEDIANFILTER_H
#define MEDIANFILTER_H

typedef struct _IplImage IplImage;

/* median filter wrapper */
void mf(IplImage *src, IplImage *dst, int radius);

#endif 
