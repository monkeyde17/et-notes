/*************************************************************************
    > File Name: RotationMatrix.h
    > Author: etond
    > Mail: monkey_tv@126.com 
    > Created Time: 二 12/23 15:12:43 2014
 ************************************************************************/

#ifndef __ROTATIONMATRIX_H__
#define __ROTATIONMATRIX_H__

class Vector3;
class EulerAngles;
class Quaternion;

class RotationMatrix 
{
public:
    float m11, m12, m13;
    float m21, m22, m23;
    float m31, m32, m33;

    void identity();

    void setup(const EulerAngles &orientation);

    void fromIntertialToObjectQuaternion(const Quaternion &q);
    void fromObjectToIntertialQuaternion(const Quaternion &q);

    Vector3 inertialToObject(const Vector3 &v) const;
    Vector3 objectToInertial(const Vector3 &v) const;
};

#endif
