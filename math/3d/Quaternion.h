/*************************************************************************
    > File Name: Quaternion.h
    > Author: etond
    > Mail: monkey_tv@126.com 
    > Created Time: 二 12/23 14:27:35 2014
 ************************************************************************/

#ifndef __QUATERNION_H__
#define __QUATERNION_H__

class Vector3
class EulerAngles;

class Quaternion
{
public:
    float w, x, y, z;

    void identity() { w = 1.0f; x = y = z = 0.0f; }

    void setToRotateAboutX(float theta);
    void setToRotateAboutY(float theta);
    void setToRotateAboutZ(float theta);
    void setToRotateAboutAxis(const Vector3 ^axis, float theta);

    void setToRotateObjectToInertial(const EulerAngles &orientation);
    void setToRotateInertialToObject(const EulerAngles &orientation);

    Quaternion operator * (const Quaternion &a) const;
    Quaternion &operator *= (const Quaternion &a);

    void normalize();
    float getRotationAngle() const;
    Vector3 getRotationAxis() const;
};

extern const Quaternion kQuaternionIdentity;

extern float dotProduct(const Quaternion &a, const Quaternion &b);

extern Quaternion slerp(const Quaternion &p, const Quaternion &q, float t);

extern Quaternion conjugate(const Quaternion &q);

extern Quaternion pow(const Quaternion &q, float exponent);

#endif
