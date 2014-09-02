/*************************************************************************
    > File Name: 11-1-MathUtil.cpp
    > Author: etond
    > Mail: monkey_tv@126.com 
    > Created Time: 二  9/ 2 21:33:23 2014
 ************************************************************************/

#include "11-1-MathUtil.h"
#include "6-1-Vector3.h"

const Vector3 kZeroVecotr(0.0f, 0.0f, 0.0f);

float warpPi(float theta)
{
	theta += kPi;
	theta -= floor(theta * k1Over2Pi) * k2Pi;
	theta -= kPi;

	return theta;
}

float safeAcos(float x)
{
	if (x <= -1.0f)
	{
		return kPi;
	}

	if (x >= 1.0f)
	{
		return 0.0f;
	}

	return acos(x);
}
