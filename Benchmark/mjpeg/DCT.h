#ifndef MJPEG_DCT_H
#define MJPEG_DCT_H

#include "mjpeg_func.h"

#define ONE ((int)1)
#define RIGHT_SHIFT(x,shft)	((x) >> (shft))
#define DESCALE(x,n)  RIGHT_SHIFT((x) + (ONE << ((n)-1)), n)
#define MULTIPLY(var,const)  ((var) * (const))

#define CONST_BITS  13
#define PASS1_BITS  2

#define FIX_0_298631336  ((int)  2446)	/* FIX(0.298631336) */
#define FIX_0_390180644  ((int)  3196)	/* FIX(0.390180644) */
#define FIX_0_541196100  ((int)  4433)	/* FIX(0.541196100) */
#define FIX_0_765366865  ((int)  6270)	/* FIX(0.765366865) */
#define FIX_0_899976223  ((int)  7373)	/* FIX(0.899976223) */
#define FIX_1_175875602  ((int)  9633)	/* FIX(1.175875602) */
#define FIX_1_501321110  ((int)  12299)	/* FIX(1.501321110) */
#define FIX_1_847759065  ((int)  15137)	/* FIX(1.847759065) */
#define FIX_1_961570560  ((int)  16069)	/* FIX(1.961570560) */
#define FIX_2_053119869  ((int)  16819)	/* FIX(2.053119869) */
#define FIX_2_562915447  ((int)  20995)	/* FIX(2.562915447) */
#define FIX_3_072711026  ((int)  25172)	/* FIX(3.072711026) */

#define DCTSIZE 8

    void ReferenceDct(int *matrix, int *newmatrix);
    void PreshiftDctMatrix(int *matrix, int shift);
    void BoundDctMatrix(int *matrix, int Bount);
    void DoubleReferenceDct1D(double *ivec, double *ovec);
    void DoubleTransposeMatrix(double *matrix, double *newmatrix);
    void IntArithDct (int *data, int *outdata);

    static char DataPrecision = 0;

    static long c[][8] = {  { 5931641, 5931641, 5931641, 5931641, 5931641, 5931641, 5931641, 5931641 },
                                  { 8227423, 6974872, 4660460, 1636536, -1636536, -4660460, -6974872, -8227423 },
				  { 7750063, 3210181, -3210181, -7750063, -7750063, -3210181, 3210181, 7750063 },
				  { 6974872, -1636536, -8227423, -4660460, 4660460, 8227423, 1636536, -6974872 },
				  { 5931641, -5931641, -5931641, 5931641, 5931641, -5931641, -5931641, 5931641 },
				  { 4660460, -8227423, 1636536, 6974872, -6974872, -1636536, 8227423, -4660460 },
				  { 3210181, -7750063, 7750063, -3210181, -3210181, 7750063, -7750063, 3210181 },
				  { 1636536, -4660460, 6974872, -8227423, 8227423, -6974872, 4660460, -1636536 }
				};


static double DctMatrix[] = {
  0.3535533905932737,
  0.3535533905932737,
  0.3535533905932737,
  0.3535533905932737,
  0.3535533905932737,
  0.3535533905932737,
  0.3535533905932737,
  0.3535533905932737,
  0.4903926402016152,
  0.4157348061512727,
  0.2777851165098011,
  0.0975451610080642,
 -0.0975451610080641,
 -0.2777851165098010,
 -0.4157348061512727,
 -0.4903926402016152,
  0.4619397662556434,
  0.1913417161825449,
 -0.1913417161825449,
 -0.4619397662556434,
 -0.4619397662556434,
 -0.1913417161825452,
  0.1913417161825450,
  0.4619397662556432,
  0.4157348061512727,
 -0.0975451610080641,
 -0.4903926402016152,
 -0.2777851165098011,
  0.2777851165098009,
  0.4903926402016153,
  0.0975451610080640,
 -0.4157348061512721,
  0.3535533905932738,
 -0.3535533905932737,
 -0.3535533905932738,
  0.3535533905932737,
  0.3535533905932738,
 -0.3535533905932733,
 -0.3535533905932736,
  0.3535533905932733,
  0.2777851165098011,
 -0.4903926402016152,
  0.0975451610080641,
  0.4157348061512728,
 -0.4157348061512726,
 -0.0975451610080649,
  0.4903926402016152,
 -0.2777851165098008,
  0.1913417161825449,
 -0.4619397662556434,
  0.4619397662556432,
 -0.1913417161825449,
 -0.1913417161825453,
  0.4619397662556437,
 -0.4619397662556435,
  0.1913417161825431,
  0.0975451610080642,
 -0.2777851165098011,
  0.4157348061512728,
 -0.4903926402016153,
  0.4903926402016152,
 -0.4157348061512720,
  0.2777851165098022,
 -0.0975451610080625};

static int transpose_index[] =          // Is a transpose map for a 8x8 matrix
{0,  8, 16, 24, 32, 40, 48, 56,
 1,  9, 17, 25, 33, 41, 49, 57,
 2, 10, 18, 26, 34, 42, 50, 58,
 3, 11, 19, 27, 35, 43, 51, 59,
 4, 12, 20, 28, 36, 44, 52, 60,
 5, 13, 21, 29, 37, 45, 53, 61,
 6, 14, 22, 30, 38, 46, 54, 62,
 7, 15, 23, 31, 39, 47, 55, 63};

#endif
