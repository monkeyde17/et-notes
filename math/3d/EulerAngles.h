/*************************************************************************
    > File Name: EulerAngles.h
    > Author: etond
    > Mail: monkey_tv@126.com 
    > Created Time: 二 12/23 13:39:28 2014
 ************************************************************************/

#ifndef __EULERANGLES_H__
#define __EULERANGLES_H__

class Quaternion;
class Matrix4x3;
class RotationMatrix;

class EulerAngles 
{
public:
    float heading;
    float pitch;
    float bank;

    EulerAngles() {}

    EulerAngles(float h, float p, float b)
        : heading(h), pitch(p), bank(b) {}

    void identity() { pitch = heading = bank = 0.0f }

    void canonize();

    void fromObjectToIntertialQuaternion(const Quaternion &q);
    void fromIntertialToObjectQuaternion(const Quaternion &q);

    void fromObjectToWorldMatrix(const Matrix4x3 &m);
    void fromWorldToMatrixObject(const Matrix4x3 &m);

    void fromRotationMatrix(const RotationMatrix &m);
};

extern const EulerAngles kEulerAnglesIdentity;

#endif


