/*************************************************************************
    > File Name: 11-1-MathUtil.h
    > Author: etond
    > Mail: monkey_tv@126.com 
    > Created Time: 二  9/ 2 21:29:02 2014
 ************************************************************************/
#ifndef __MATH_UTIL_H__
#define __MATH_UTIL_H__

#include <math.h>

const float kPi = 3.14159265f;
const float k2Pi = kPi * 2.0f;
const float kPiOver2 = kPi / 2.0f;
const float k1OverPi = 1.0f / kPi;
const float k1Over2Pi = 1.0f / k2Pi;

extern float warpPi(float theta);
extern float safeAcos(float x);

inline void sinCos(float *returnSin, float *returnCos, float theta)
{
	*returnSin = sin(theta);
	*returnCos = cos(theta);
}
#endif
