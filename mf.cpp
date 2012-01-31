/**
 * @file mf.cpp
 * fast median filter wrapper based on OpenCV
 *
 * @blackball
 */

#include "mf.h"
#include "ctmf.h"

#include <cv.h>
#include <highgui.h>
#include <assert.h>

#define _CHKFMT(src, dst)                       \
  (                                             \
      src->width == dst->width &&               \
      src->height == dst->height &&             \
      src->depth == dst->depth &&               \
      src->nChannels == dst->nChannels          \
  )

/**
 * src and dst should be "char" format
 * dst was allocated outside, and src must
 * be the same size with dst.
 */
void mf(IplImage *src, IplImage *dst, int radius)
{
  assert(src && dst && radius > 0 && _CHKFMT(src, dst));
  
  ctmf((unsigned char*)(src->imageData),
       (unsigned char*)(dst->imageData),
       src->width, src->height,
       src->widthStep, dst->widthStep,
       radius, /* radius of kernel, 2 * radius + 1 */
       src->nChannels,
       256 * 1024 /* L2 cache size is a proper option */
       );
}

#undef _CHKFMT
