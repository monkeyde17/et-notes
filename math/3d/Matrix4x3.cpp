/*************************************************************************
    > File Name: Matrix4x3.cpp
    > Author: etond
    > Mail: monkey_tv@126.com 
    > Created Time: 三 12/24 10:33:54 2014
 ************************************************************************/

#include <assert.h>
#include <math.h>

#include "Vector3.h"
#include "EulerAngles.h"
#include "Quaternion.h"
#include "RotationMatrix.h"

#include "Matrix4x3.h"
#include "MathUtil.h"

void Matrix4x3::identity()
{
    m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
    m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
    m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;
    tx = 0.0f; ty = 0.0f; tz = 1.0f;
}

void Matrix4x3::zeroTranslation()
{
    tx = ty = tz = 0.0f;
}

void Matrix4x3::setTranslation(const Vector3 &d)
{
    tx = d.x; ty = d.y; tz = d.z;
}

void Matrix4x3::setupTranslation(const Vector3 &d)
{
    m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
    m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
    m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;
    tx = d.x; ty = d.y; tz = d.z;
}

void Matrix4x3::setupLocalToParent(const Vector3 &pos, const EulerAngles &orient)
{
    RotationMatrix orientMatrix;
    orientMatrix.setup(orient);

    setupLocalToParent(pos, orientMatrix);
}

void Matrix4x3::setupLocalToParent(const Vector3 &pos, const RotationMatrix &orient)
{
    m11 = orient.m11; m12 = orient.m12; m13 = orient.m13;
    m21 = orient.m21; m22 = orient.m22; m23 = orient.m23;
    m31 = orient.m31; m32 = orient.m32; m33 = orient.m33;
    tx = pos.x; ty = pos.y; tz = pos.z;
}

void Matrix4x3::setupParentToLocal(const Vector3 &pos, const EulerAngles &orient)
{
    RotationMatrix orientMatrix;
    orientMatrix.setup(orient);

    setupParentToLocal(pos, orientMatrix);
}

void Matrix4x3::setupParentToLocal(const Vector3 &pos, const RotationMatrix &orient)
{
    m11 = orient.m11; m12 = orient.m12; m13 = orient.m13;
    m21 = orient.m21; m22 = orient.m22; m23 = orient.m23;
    m31 = orient.m31; m32 = orient.m32; m33 = orient.m33;

    tx = -(pos.x*m11 + pos.y*m21 + pos.z*m31);
    ty = -(pos.x*m12 + pos.y*m22 + pos.z*m32);
    tz = -(pos.x*m13 + pos.y*m23 + pos.z*m33);
}

void Matrix4x3::setupRotate(int axis, float theta)
{
    float s, c;
    sinCos(&s, &c, theta);

    switch (axis) {
        case 1:
            m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
            m21 = 0.0f; m22 = c; m23 = s;
            m31 = 0.0f; m32 = -s; m33 = c;
            break;

        case 2:
            m11 = c; m12 = 0.0f; m13 = -s;
            m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
            m31 = s; m32 = 0.0f; m33 = c;
            break;

        case 3:
            m11 = c; m12 = s; m13 = 0.0f;
            m21 = -s; m22 = c; m23 = 0.0f;
            m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;
            break;
        default:
            assert(false);
    }

    tx = ty = tz = 0.0f;
}

void Matrix4x3::setupRotate(const Vector3 &axis, float theta)
{
    assert(fabs(axis*axis - 1.0f) < 0.01f);

    float s, c;
    sinCos(&s, &c, theta);

    float a = 1.0f - c;
    float ax = a * axis.x;
    float ay = a * axis.y;
    float az = a * axis.z;

    m11 = ax*axis.x + c;
    m12 = ax*axis.y + axis.z*s;
    m13 = ax*axis.z - axis.y*s;

    m21 = ay*axis.x - axis.z*s;
    m22 = ay*axis.y + c;
    m23 = ay*axis.z + axis.x*s;

    m31 = az*axis.x + axis.y*s;
    m32 = az*axis.y - axis.x*s;
    m33 = az*axis.z + c;

    tx = ty = tz = 0.0f;
}

void Matrix4x3::fromQuaternion(const Quaternion &q)
{
    float ww = 2.0f * q.w;
    float xx = 2.0f * q.x;
    float yy = 2.0f * q.y;
    float zz = 2.0f * q.z;

    m11 = 1.0f - yy*q.y - zz*q.z;
    m12 = xx*q.y + ww*q.z;
    m13 = xx*q.z - ww*q.x;

    m21 = xx*q.y - ww*q.z;
    m22 = 1.0f - xx*q.x - zz*q.z;
    m23 = xx*q.z + ww*q.x;

    m31 = xx*q.z + ww*q.y;
    m32 = yy*q.y - ww*q.x;
    m33 = 1.0f - xx*q.x - yy*q.y;

    tx = ty = tz = 0.0f;
}

void Matrix4x3::setupScale(const Vector3 &s)
{
    m11 = s.x; m12 = 0.0f; m13 = 0.0f;
    m21 = 0.0f; m22 = s.y; m23 = 0.0f;
    m31 = 0.0f; m32 = 0.0f; m33 = s.z;

    tx = ty = tz = 0.0f;
}

void Matrix4x3::setupScaleAlongAxis(const Vector3 &axis, float k)
{
    assert(fabs(axis*axis - 1.0f) < 0.01f);

    float a = k - 1.0f;
    float ax = a * axis.x;
    float ay = a * axis.y;
    float az = a * axis.z;

    m11 = ax*axis.x + 1.0f;
    m22 = ay*axis.y + 1.0f;
    m33 = az*axis.z + 1.0f;

    m12 = m21 = ax*axis.y;
    m13 = m31 = ax*axis.z;
    m23 = m32 = ay*axis.z;

    tx = ty = tz = 0.0f;
}

void Matrix4x3::setupShear(int axis, float s, float t)
{
    switch (axis) {
        case 1:
            m11 = 1.0f; m12 =    s; m13 =    t;
            m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
            m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;
            break;

        case 2:
            m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
            m21 =    s; m22 = 1.0f; m23 =    t;
            m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;
            break;
            
        case 3:
            m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
            m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
            m31 =    s; m32 =    t; m33 = 1.0f;
            break;

        default:
            assert(false);
    }

    tx = ty = tz = 0.0f;
}

void Matrix4x3::setupProject(const Vector3 &n)
{
    assert(fabs(n*n - 1.0f) < 0.01f);

    m11 = 1.0f - n.x*n.x;
    m22 = 1.0f - n.y*n.y;
    m33 = 1.0f - n.z*n.z;

    m12 = m21 = -n.x*n.y;
    m13 = m31 = -n.x*n.z;
    m23 = m32 = -n.y*n.z;

    tx = ty = tz = 0.0f;
}

void Matrix4x3::setupReflect(int axis, float k)
{
    switch (axis) {
        case 1:
            m11 = -1.0f; m12 = 0.0f; m13 = 0.0f;
            m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
            m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;

            tx = 2.0f * k;
            ty = 0.0f;
            tz = 0.0f;
            break;
        case 2:
            m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
            m21 = 0.0f; m22 = -1.0f; m23 = 0.0f;
            m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;

            tx = 0.0f;
            ty = 2.0f * k;
            tz = 0.0f;
            break;
        case 3:
            m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
            m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
            m31 = 0.0f; m32 = 0.0f; m33 = -1.0f;

            tx = 0.0f;
            ty = 0.0f;
            tz = 2.0f * k;
            break;
        default:
            assert(false);
    }
}

void Matrix4x3::setupReflect(const Vector3 &n)
{
    assert(fabs(n*n - 1.0f) < 0.01f);

    float ax = -2.0f * n.x;
    float ay = -2.0f * n.y;
    float az = -2.0f * n.z;

    m11 = 1.0f + ax*n.x;
    m22 = 1.0f + ay*n.y;
    m33 = 1.0f + az*n.z;

    m12 = m21 = ax*n.y;
    m13 = m31 = ax*n.z;
    m23 = m32 = ay*n.z;

    tx = ty = tz = 0.0f;
}

Vector3 operator* (const Vector3 &p, const Matrix4x3 &m)
{
    return Vector3(
            p.x*m.m11 + p.y*m.m21 + p.z*m.m31 + m.tx,
            p.x*m.m12 + p.y*m.m22 + p.z*m.m32 + m.ty,
            p.x*m.m13 + p.y*m.m23 + p.z*m.m33 + m.tz
            );
}

Vector3 &operator *= (const Vector3 &p, const Matrix4x3 &m)
{
    p = p * m;
    return p;
}

Matrix4x3 operator*(const Matrix4x3 &a, const Matrix4x3 &b)
{
    Matrix4x3 r;

    r.m11 = a.m11*b.m11 + a.m12*b.m21 + a.m13*b.m31;
    r.m12 = a.m11*b.m12 + a.m12*b.m22 + a.m13*b.m32;
    r.m13 = a.m11*b.m13 + a.m12*b.m23 + a.m13*b.m33;

    r.m21 = a.m21*b.m21 + a.m22*b.m21 + a.m23*b.m31;
    r.m22 = a.m21*b.m22 + a.m22*b.m22 + a.m23*b.m32;
    r.m23 = a.m21*b.m23 + a.m22*b.m23 + a.m23*b.m33;

    r.m31 = a.m31*b.m31 + a.m32*b.m21 + a.m33*b.m31;
    r.m32 = a.m31*b.m32 + a.m32*b.m22 + a.m33*b.m32;
    r.m33 = a.m31*b.m33 + a.m32*b.m23 + a.m33*b.m33;

    r.tx = a.tx*b.m11 + a.ty*b.m21 + a.tz*b.m31;
    r.ty = a.tx*b.m12 + a.ty*b.m22 + a.tz*b.m32;
    r.tz = a.tx*b.m13 + a.ty*b.m23 + a.tz*b.m33;

    return r;
}

Matrix4x3 &operator *= (Matrix4x3 &a, const Matrix4x3 &b)
{
    a = a * b;
    return a;
}

float determinant(const Matrix4x3 &m)
{
    return m.m11 * (m.m22*m.m33 - m.m23*m.m32)
        + m.m12 * (m.m23*m.m31 - m.m21*m.m33)
        + m.m13 * (m.m21*m.m32 - m.m22*m.m31);
}

Matrix4x3 inverse(const Matrix4x3 &m)
{
    float det = determinant(m);

    assert(fabs(det) > 0.000001f);

    float oneOverDet = 1.0f / det;

    Matrix4x3 r;

    r.m11 = (m.m22*m.m33 - m.m23*m.m32) * oneOverDet;
    r.m12 = (m.m13*m.m32 - m.m12*m.m33) * oneOverDet;
    r.m13 = (m.m12*m.m23 - m.m13*m.m22) * oneOverDet;

    r.m21 = (m.m22*m.m31 - m.m21*m.m33) * oneOverDet;
    r.m22 = (m.m11*m.m33 - m.m13*m.m31) * oneOverDet;
    r.m23 = (m.m13*m.m21 - m.m11*m.m23) * oneOverDet;

    r.m31 = (m.m21*m.m32 - m.m22*m.m31) * oneOverDet;
    r.m32 = (m.m12*m.m31 - m.m11*m.m32) * oneOverDet;
    r.m33 = (m.m11*m.m22 - m.m12*m.m21) * oneOverDet;

    r.tx = -(m.tx*r.m11 + m.ty*r.m21 + m.tz*r.m31);
    r.ty = -(m.tx*r.m12 + m.ty*r.m22 + m.tz*r.m32);
    r.tz = -(m.tx*r.m13 + m.ty*r.m23 + m.tz*r.m33);

    return r;
}

void Vector3 getTranslation(const Matrix4x3 &m)
{
    return Vector3(m.tx, m.ty, m.tz);
}

Vector3 getPositionFromLocalToParentMatrix(const Matrix4x3 &m)
{
    return Vector3(
            -(m.tx*m.m11 + m.ty*m.m12 + m.tz*m.m13),
            -(m.tx*m.m21 + m.ty*m.m22 + m.tz*m.m23),
            -(m.tx*m.m31 + m.ty*m.m32 + m.tz*m.m33)
            );
}

Vector3 getPositionFromLocalToParentMatrix(const Matrix4x3 &m)
{
    return Vector3(m.tx, m.ty, m.tz);
}




