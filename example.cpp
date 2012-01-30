/* test fast median filter based on OpenCV */

#include "mf.h"
#include <cv.h>
#include <highgui.h>

int main(int argc, char *argv[])
{

  IplImage *src = cvLoadImage("foo.jpg", 1);
  IplImage *dst = cvCreateImage(cvGetSize(src),
                                src->depth,
                                src->nChannels);
  int radius = 3;
  mf(src, dst, radius);

  /* fucking ugly code block ;( */
  cvNamedWindow("src", 1);
  cvNamedWindow("dst", 1);
  cvShowImage("src", src);
  cvShowImage("dst", dst);
  cvWaitKey(0);
  cvDestroyWindow("src");
  cvDestroyWindow("dst");
  cvReleaseImage(&src);
  cvReleaseImage(&dst);
  
  return 0;
}
