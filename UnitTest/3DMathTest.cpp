//
//  Vector4Test.cpp
//  3DMath
//
//  Created by Gabriele Carrettoni on 19/11/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#include "3DMathTest.h"

// ================ VECTORS ================

// VECTOR<4>

TEST(Vector4Test, Creation) {
    
    Vector<4> v(1.0f,1.0f,1.0f,1.0f);
    
    __declspec(align(16)) float t[4];
    _mm_store_ps(t, v.data);
    
    for (int i=0; i < 4; i++) {
        ASSERT_FLOAT_EQ(t[i], 1.0f);
    }
}

TEST(Vector4Test, SumByFloat) {
    
    Vector<4> v1(1.0f,2.0f,5.0f,6.0f);
    
    auto v3 = v1 + 3.0f;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, v3.data);
    
    ASSERT_FLOAT_EQ(t[0], 1.0f + 3.0f);
    ASSERT_FLOAT_EQ(t[1], 2.0f + 3.0f);
    ASSERT_FLOAT_EQ(t[2], 5.0f + 3.0f);
    ASSERT_FLOAT_EQ(t[3], 6.0f + 3.0f);
    
     v1 += 3.0f;
    
    __declspec(align(16)) float t1[4];
    _mm_storer_ps(t1, v1.data);
    
    ASSERT_FLOAT_EQ(t1[0], 1.0f + 3.0f);
    ASSERT_FLOAT_EQ(t1[1], 2.0f + 3.0f);
    ASSERT_FLOAT_EQ(t1[2], 5.0f + 3.0f);
    ASSERT_FLOAT_EQ(t1[3], 6.0f + 3.0f);
}

TEST(Vector4Test, SubByFloat) {
    
    Vector<4> v1(1.0f,2.0f,5.0f,6.0f);
    
    auto v3 = v1 - 3.0f;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, v3.data);
    
    ASSERT_FLOAT_EQ(t[0], 1.0f - 3.0f);
    ASSERT_FLOAT_EQ(t[1], 2.0f - 3.0f);
    ASSERT_FLOAT_EQ(t[2], 5.0f - 3.0f);
    ASSERT_FLOAT_EQ(t[3], 6.0f - 3.0f);
    
    v1 -= 3.0f;
    
    __declspec(align(16)) float t1[4];
    _mm_storer_ps(t1, v1.data);
    
    ASSERT_FLOAT_EQ(t1[0], 1.0f - 3.0f);
    ASSERT_FLOAT_EQ(t1[1], 2.0f - 3.0f);
    ASSERT_FLOAT_EQ(t1[2], 5.0f - 3.0f);
    ASSERT_FLOAT_EQ(t1[3], 6.0f - 3.0f);

}

TEST(Vector4Test, MulByFloat) {
    
    Vector<4> v1(1.0f,2.0f,5.0f,6.0f);
    
    auto v3 = v1 * 3.0f;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, v3.data);
    
    ASSERT_FLOAT_EQ(t[0], 1.0f * 3.0f);
    ASSERT_FLOAT_EQ(t[1], 2.0f * 3.0f);
    ASSERT_FLOAT_EQ(t[2], 5.0f * 3.0f);
    ASSERT_FLOAT_EQ(t[3], 6.0f * 3.0f);
    
    v1 *= 3.0f;
    
    __declspec(align(16)) float t1[4];
    _mm_storer_ps(t1, v1.data);
    
    ASSERT_FLOAT_EQ(t1[0], 1.0f * 3.0f);
    ASSERT_FLOAT_EQ(t1[1], 2.0f * 3.0f);
    ASSERT_FLOAT_EQ(t1[2], 5.0f * 3.0f);
    ASSERT_FLOAT_EQ(t1[3], 6.0f * 3.0f);

}

TEST(Vector4Test, DivByFloat) {
    
    Vector<4> v1(1.0f,2.0f,5.0f,6.0f);
    
    auto v3 = v1 / 3.0f;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, v3.data);
    
    ASSERT_FLOAT_EQ(t[0], 1.0f / 3.0f);
    ASSERT_FLOAT_EQ(t[1], 2.0f / 3.0f);
    ASSERT_FLOAT_EQ(t[2], 5.0f / 3.0f);
    ASSERT_FLOAT_EQ(t[3], 6.0f / 3.0f);
    
    v1 /= 3.0f;
    
    __declspec(align(16)) float t1[4];
    _mm_storer_ps(t1, v1.data);
    
    ASSERT_FLOAT_EQ(t1[0], 1.0f / 3.0f);
    ASSERT_FLOAT_EQ(t1[1], 2.0f / 3.0f);
    ASSERT_FLOAT_EQ(t1[2], 5.0f / 3.0f);
    ASSERT_FLOAT_EQ(t1[3], 6.0f / 3.0f);

}


TEST(Vector4Test, Sum) {
    
    Vector<4> v1(1.0f,2.0f,5.0f,6.0f);
    Vector<4> v2(2.0f,3.0f,4.0f,7.0f);
    
    auto v3 = v1 + v2;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, v3.data);
    
    ASSERT_FLOAT_EQ(t[0], 1.0f + 2.0f);
    ASSERT_FLOAT_EQ(t[1], 2.0f + 3.0f);
    ASSERT_FLOAT_EQ(t[2], 5.0f + 4.0f);
    ASSERT_FLOAT_EQ(t[3], 6.0f + 7.0f);
    
    v1 += v2;
    
    __declspec(align(16)) float t1[4];
    _mm_storer_ps(t1, v1.data);
    
    ASSERT_FLOAT_EQ(t1[0], 1.0f + 2.0f);
    ASSERT_FLOAT_EQ(t1[1], 2.0f + 3.0f);
    ASSERT_FLOAT_EQ(t1[2], 5.0f + 4.0f);
    ASSERT_FLOAT_EQ(t1[3], 6.0f + 7.0f);

}

TEST(Vector4Test, Sub) {
    
    Vector<4> v1(1.0f,2.0f,5.0f,6.0f);
    Vector<4> v2(2.0f,3.0f,4.0f,7.0f);
    
    auto v3 = v1 - v2;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, v3.data);
    
    ASSERT_FLOAT_EQ(t[0], 1.0f - 2.0f);
    ASSERT_FLOAT_EQ(t[1], 2.0f - 3.0f);
    ASSERT_FLOAT_EQ(t[2], 5.0f - 4.0f);
    ASSERT_FLOAT_EQ(t[3], 6.0f - 7.0f);
    
    v1 -= v2;
    
    __declspec(align(16)) float t1[4];
    _mm_storer_ps(t1, v1.data);
    
    ASSERT_FLOAT_EQ(t1[0], 1.0f - 2.0f);
    ASSERT_FLOAT_EQ(t1[1], 2.0f - 3.0f);
    ASSERT_FLOAT_EQ(t1[2], 5.0f - 4.0f);
    ASSERT_FLOAT_EQ(t1[3], 6.0f - 7.0f);
}

TEST(Vector4Test, Mul) {
    
    Vector<4> v1(1.0f,2.0f,5.0f,6.0f);
    Vector<4> v2(2.0f,3.0f,4.0f,7.0f);
    
    auto v3 = v1 * v2;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, v3.data);
    
    ASSERT_FLOAT_EQ(t[0], 2.0f);
    ASSERT_FLOAT_EQ(t[1], 6.0f);
    ASSERT_FLOAT_EQ(t[2], 20.0f);
    ASSERT_FLOAT_EQ(t[3], 42.0f);
    
    v1 *= v2;
    
    __declspec(align(16)) float t1[4];
    _mm_storer_ps(t1, v1.data);
    
    ASSERT_FLOAT_EQ(t1[0], 1.0f * 2.0f);
    ASSERT_FLOAT_EQ(t1[1], 2.0f * 3.0f);
    ASSERT_FLOAT_EQ(t1[2], 5.0f * 4.0f);
    ASSERT_FLOAT_EQ(t1[3], 6.0f * 7.0f);
}

TEST(Vector4Test, Div) {
    
    Vector<4> v1(1.0f,2.0f,5.0f,6.0f);
    Vector<4> v2(2.0f,3.0f,4.0f,7.0f);
    
    auto v3 = v1 / v2;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, v3.data);
    
    ASSERT_FLOAT_EQ(t[0], 1.0f/2.0f);
    ASSERT_FLOAT_EQ(t[1], 2.0f/3.0f);
    ASSERT_FLOAT_EQ(t[2], 5.0f/4.0f);
    ASSERT_FLOAT_EQ(t[3], 6.0f/7.0f);
    
    v1 /= v2;
    
    __declspec(align(16)) float t1[4];
    _mm_storer_ps(t1, v1.data);
    
    ASSERT_FLOAT_EQ(t1[0], 1.0f / 2.0f);
    ASSERT_FLOAT_EQ(t1[1], 2.0f / 3.0f);
    ASSERT_FLOAT_EQ(t1[2], 5.0f / 4.0f);
    ASSERT_FLOAT_EQ(t1[3], 6.0f / 7.0f);
}

// VECTOR<3>

TEST(Vector3Test, Creation) {
    
    Vector<3> v(1.0f,1.0f,1.0f);
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, v.data);
    
    for (int i=0; i < 3; i++) {
        ASSERT_FLOAT_EQ(t[i], 1.0f);
    }
    
    ASSERT_FLOAT_EQ(t[3], 0.0f);
}

TEST(Vector3Test, SumByFloat) {
    
    Vector<3> v1(1.0f,2.0f,5.0f);
    
    auto v3 = v1 + 3.0f;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, v3.data);
    
    ASSERT_FLOAT_EQ(t[0], 1.0f + 3.0f);
    ASSERT_FLOAT_EQ(t[1], 2.0f + 3.0f);
    ASSERT_FLOAT_EQ(t[2], 5.0f + 3.0f);
    ASSERT_FLOAT_EQ(t[3], 3.0f);
    
    v1 += 3.0f;
    
    __declspec(align(16)) float t1[4];
    _mm_storer_ps(t1, v1.data);
    
    ASSERT_FLOAT_EQ(t1[0], 1.0f + 3.0f);
    ASSERT_FLOAT_EQ(t1[1], 2.0f + 3.0f);
    ASSERT_FLOAT_EQ(t1[2], 5.0f + 3.0f);
    ASSERT_FLOAT_EQ(t1[3], 3.0f);
}

TEST(Vector3Test, SubByFloat) {
    
    Vector<3> v1(1.0f,2.0f,5.0f);
    
    auto v3 = v1 - 3.0f;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, v3.data);
    
    ASSERT_FLOAT_EQ(t[0], 1.0f - 3.0f);
    ASSERT_FLOAT_EQ(t[1], 2.0f - 3.0f);
    ASSERT_FLOAT_EQ(t[2], 5.0f - 3.0f);
    ASSERT_FLOAT_EQ(t[3], -3.0f);
    
    v1 -= 3.0f;
    
    __declspec(align(16)) float t1[4];
    _mm_storer_ps(t1, v1.data);
    
    ASSERT_FLOAT_EQ(t1[0], 1.0f - 3.0f);
    ASSERT_FLOAT_EQ(t1[1], 2.0f - 3.0f);
    ASSERT_FLOAT_EQ(t1[2], 5.0f - 3.0f);
    ASSERT_FLOAT_EQ(t1[3], -3.0f);
}

TEST(Vector3Test, MulByFloat) {
    
    Vector<3> v1(1.0f,2.0f,5.0f);
    
    auto v3 = v1 * 3.0f;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, v3.data);
    
    ASSERT_FLOAT_EQ(t[0], 1.0f * 3.0f);
    ASSERT_FLOAT_EQ(t[1], 2.0f * 3.0f);
    ASSERT_FLOAT_EQ(t[2], 5.0f * 3.0f);
    ASSERT_FLOAT_EQ(t[3], 0.0f);
    
    v1 *= 3.0f;
    
    __declspec(align(16)) float t1[4];
    _mm_storer_ps(t1, v1.data);
    
    ASSERT_FLOAT_EQ(t1[0], 1.0f * 3.0f);
    ASSERT_FLOAT_EQ(t1[1], 2.0f * 3.0f);
    ASSERT_FLOAT_EQ(t1[2], 5.0f * 3.0f);
    ASSERT_FLOAT_EQ(t1[3], 0.0f);
}

TEST(Vector3Test, DivByFloat) {
    
    Vector<3> v1(1.0f,2.0f,5.0f);
    
    auto v3 = v1 / 3.0f;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, v3.data);
    
    ASSERT_FLOAT_EQ(t[0], 1.0f / 3.0f);
    ASSERT_FLOAT_EQ(t[1], 2.0f / 3.0f);
    ASSERT_FLOAT_EQ(t[2], 5.0f / 3.0f);
    ASSERT_FLOAT_EQ(t[3], 0.0f);
    
    v1 /= 3.0f;
    
    __declspec(align(16)) float t1[4];
    _mm_storer_ps(t1, v1.data);
    
    ASSERT_FLOAT_EQ(t1[0], 1.0f / 3.0f);
    ASSERT_FLOAT_EQ(t1[1], 2.0f / 3.0f);
    ASSERT_FLOAT_EQ(t1[2], 5.0f / 3.0f);
    ASSERT_FLOAT_EQ(t1[3], 0.0f);
}

TEST(Vector3Test, Sum) {
    
    Vector<3> v1(1.0f,2.0f,5.0f);
    Vector<3> v2(2.0f,3.0f,4.0f);
    
    auto v3 = v1 + v2;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, v3.data);
    
    ASSERT_FLOAT_EQ(t[0], 1.0f + 2.0f);
    ASSERT_FLOAT_EQ(t[1], 2.0f + 3.0f);
    ASSERT_FLOAT_EQ(t[2], 5.0f + 4.0f);
    ASSERT_FLOAT_EQ(t[3], 0.0f);
    
    v1 += v2;
    
    __declspec(align(16)) float t1[4];
    _mm_storer_ps(t1, v1.data);
    
    ASSERT_FLOAT_EQ(t1[0], 1.0f + 2.0f);
    ASSERT_FLOAT_EQ(t1[1], 2.0f + 3.0f);
    ASSERT_FLOAT_EQ(t1[2], 5.0f + 4.0f);
    ASSERT_FLOAT_EQ(t1[3], 0.0f);
    
}

TEST(Vector3Test, Sub) {
    
    Vector<3> v1(1.0f,2.0f,5.0f);
    Vector<3> v2(2.0f,3.0f,4.0f);
    
    auto v3 = v1 - v2;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, v3.data);
    
    ASSERT_FLOAT_EQ(t[0], 1.0f - 2.0f);
    ASSERT_FLOAT_EQ(t[1], 2.0f - 3.0f);
    ASSERT_FLOAT_EQ(t[2], 5.0f - 4.0f);
    ASSERT_FLOAT_EQ(t[3], 0.0f);
    
    v1 -= v2;
    
    __declspec(align(16)) float t1[4];
    _mm_storer_ps(t1, v1.data);
    
    ASSERT_FLOAT_EQ(t1[0], 1.0f - 2.0f);
    ASSERT_FLOAT_EQ(t1[1], 2.0f - 3.0f);
    ASSERT_FLOAT_EQ(t1[2], 5.0f - 4.0f);
    ASSERT_FLOAT_EQ(t1[3], 0.0f);
    
}

TEST(Vector3Test, Mul) {
    
    Vector<3> v1(1.0f,2.0f,5.0f);
    Vector<3> v2(2.0f,3.0f,4.0f);
    
    auto v3 = v1 * v2;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, v3.data);
    
    ASSERT_FLOAT_EQ(t[0], 1.0f * 2.0f);
    ASSERT_FLOAT_EQ(t[1], 2.0f * 3.0f);
    ASSERT_FLOAT_EQ(t[2], 5.0f * 4.0f);
    ASSERT_FLOAT_EQ(t[3], 0.0f);
    
    v1 *= v2;
    
    __declspec(align(16)) float t1[4];
    _mm_storer_ps(t1, v1.data);
    
    ASSERT_FLOAT_EQ(t1[0], 1.0f * 2.0f);
    ASSERT_FLOAT_EQ(t1[1], 2.0f * 3.0f);
    ASSERT_FLOAT_EQ(t1[2], 5.0f * 4.0f);
    ASSERT_FLOAT_EQ(t1[3], 0.0f);
    
}

TEST(Vector3Test, Div) {
    
    Vector<3> v1(1.0f,2.0f,5.0f);
    Vector<3> v2(2.0f,3.0f,4.0f);
    
    auto v3 = v1 / v2;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, v3.data);
    
    ASSERT_FLOAT_EQ(t[0], 1.0f / 2.0f);
    ASSERT_FLOAT_EQ(t[1], 2.0f / 3.0f);
    ASSERT_FLOAT_EQ(t[2], 5.0f / 4.0f);
    
    v1 /= v2;
    
    __declspec(align(16)) float t1[4];
    _mm_storer_ps(t1, v1.data);
    
    ASSERT_FLOAT_EQ(t1[0], 1.0f / 2.0f);
    ASSERT_FLOAT_EQ(t1[1], 2.0f / 3.0f);
    ASSERT_FLOAT_EQ(t1[2], 5.0f / 4.0f);
}

TEST(Vector4Test, Magnitude) {
    Vector<4> v(2.0f,3.0f,4.0f,6.0f);
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, v.magnitude());
    
    float m = sqrt(4 + 9 + 16 + 36); // dot product
    
    for (int i=0; i<4; i++) {
        ASSERT_FLOAT_EQ(t[i], m);
    }
}

TEST(Vector3Test, Magnitude) {
    Vector<3> v(2.0f,3.0f,4.0f);
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, v.magnitude());
    
    float m = sqrt(4 + 9 + 16);
    
    for (int i=0; i<4; i++) {
        ASSERT_FLOAT_EQ(t[i], m);
    }
}

// ================ MATRIX ================

TEST(Matrix, Creation) {
    
    Matrix<4,4> m (Vector<4>(1.0f, 1.0f, 1.0f, 1.0f),
                   Vector<4>(1.0f, 1.0f, 1.0f, 1.0f),
                   Vector<4>(1.0f, 1.0f, 1.0f, 1.0f),
                   Vector<4>(1.0f, 1.0f, 1.0f, 1.0f));
    
    
    for (int i=0; i < 4; i++) {
        __declspec(align(16)) float t[4];
        _mm_storer_ps(t, m.data[i].data);

        for (int j=0; j < 4; j++) {

            ASSERT_FLOAT_EQ(t[j], 1.0f);
        }
    }
}

TEST(Matrix, Sum) {
    Matrix<2,2> m1 (Vector<2>(2.0f, 4.0f),
                    Vector<2>(5.0f, 3.0f));
    
    Matrix<2,2> m2 (Vector<2>(5.0f, 1.0f),
                    Vector<2>(2.0f, 3.0f));
    
    auto m = m1 + m2;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, m.data[0].data);
    
    ASSERT_FLOAT_EQ(t[0], 2.0f + 5.0f);
    ASSERT_FLOAT_EQ(t[1], 4.0f + 1.0f);
    
    _mm_storer_ps(t, m.data[1].data);
    
    ASSERT_FLOAT_EQ(t[0], 5.0f + 2.0f);
    ASSERT_FLOAT_EQ(t[1], 3.0f + 3.0f);
    
    m1 += m2;
    
    _mm_storer_ps(t, m1.data[0].data);
    
    ASSERT_FLOAT_EQ(t[0], 2.0f + 5.0f);
    ASSERT_FLOAT_EQ(t[1], 4.0f + 1.0f);
    
    _mm_storer_ps(t, m1.data[1].data);
    
    ASSERT_FLOAT_EQ(t[0], 5.0f + 2.0f);
    ASSERT_FLOAT_EQ(t[1], 3.0f + 3.0f);
}

TEST(Matrix, Sub) {
    Matrix<2,2> m1 (Vector<2>(2.0f, 4.0f),
                    Vector<2>(5.0f, 3.0f));
    
    Matrix<2,2> m2 (Vector<2>(5.0f, 1.0f),
                    Vector<2>(2.0f, 3.0f));
    
    auto m = m1 - m2;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, m.data[0].data);
    
    ASSERT_FLOAT_EQ(t[0], 2.0f - 5.0f);
    ASSERT_FLOAT_EQ(t[1], 4.0f - 1.0f);
    
    _mm_storer_ps(t, m.data[1].data);
    
    ASSERT_FLOAT_EQ(t[0], 5.0f - 2.0f);
    ASSERT_FLOAT_EQ(t[1], 3.0f - 3.0f);
    
    m1 -= m2;
    
    _mm_storer_ps(t, m1.data[0].data);
    
    ASSERT_FLOAT_EQ(t[0], 2.0f - 5.0f);
    ASSERT_FLOAT_EQ(t[1], 4.0f - 1.0f);
    
    _mm_storer_ps(t, m1.data[1].data);
    
    ASSERT_FLOAT_EQ(t[0], 5.0f - 2.0f);
    ASSERT_FLOAT_EQ(t[1], 3.0f - 3.0f);
}

TEST(Matrix, Mul) {
    Matrix<2,2> m1 (Vector<2>(2.0f, 4.0f),
                    Vector<2>(5.0f, 3.0f));
    
    Matrix<2,2> m2 (Vector<2>(5.0f, 1.0f),
                    Vector<2>(2.0f, 3.0f));
    
    auto m = m1 * m2;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, m.data[0].data);
    
    ASSERT_FLOAT_EQ(t[0], 2.0f * 5.0f);
    ASSERT_FLOAT_EQ(t[1], 4.0f * 1.0f);

    _mm_storer_ps(t, m.data[1].data);
    
    ASSERT_FLOAT_EQ(t[0], 5.0f * 2.0f);
    ASSERT_FLOAT_EQ(t[1], 3.0f * 3.0f);
    
    m1 *= m2;
    
    _mm_storer_ps(t, m1.data[0].data);
    
    ASSERT_FLOAT_EQ(t[0], 2.0f * 5.0f);
    ASSERT_FLOAT_EQ(t[1], 4.0f * 1.0f);
    
    _mm_storer_ps(t, m1.data[1].data);
    
    ASSERT_FLOAT_EQ(t[0], 5.0f * 2.0f);
    ASSERT_FLOAT_EQ(t[1], 3.0f * 3.0f);
}

TEST(Matrix, Div) {
    Matrix<2,2> m1 (Vector<2>(2.0f, 4.0f),
                    Vector<2>(5.0f, 3.0f));
    
    Matrix<2,2> m2 (Vector<2>(5.0f, 1.0f),
                    Vector<2>(2.0f, 3.0f));
    
    auto m = m1 / m2;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, m.data[0].data);
    
    ASSERT_FLOAT_EQ(t[0], 2.0f / 5.0f);
    ASSERT_FLOAT_EQ(t[1], 4.0f / 1.0f);
    
    _mm_storer_ps(t, m.data[1].data);
    
    ASSERT_FLOAT_EQ(t[0], 5.0f / 2.0f);
    ASSERT_FLOAT_EQ(t[1], 3.0f / 3.0f);
    
    m1 /= m2;
    
    _mm_storer_ps(t, m1.data[0].data);
    
    ASSERT_FLOAT_EQ(t[0], 2.0f / 5.0f);
    ASSERT_FLOAT_EQ(t[1], 4.0f / 1.0f);
    
    _mm_storer_ps(t, m1.data[1].data);
    
    ASSERT_FLOAT_EQ(t[0], 5.0f / 2.0f);
    ASSERT_FLOAT_EQ(t[1], 3.0f / 3.0f);
}

TEST(Matrix, Identity) {
    auto m = Matrix<4, 4>::identity();

    for (int i=0; i < 4; i++) {
        __declspec(align(16)) float t[4];
        _mm_storer_ps(t, m.data[i].data);
        
        for (int j=0; j < 4; j++) {
            if (j == i) ASSERT_FLOAT_EQ(t[j], 1.0f);
            else ASSERT_FLOAT_EQ(t[j], 0.0f);
        }
    }
}

TEST(Matrix, MulByVector) {
    Matrix<2,2> m1 (Vector<2>(2.0f, 4.0f),
                    Vector<2>(5.0f, 3.0f));
    
    Vector<2> v1(5.0f, 1.0f);
    
    auto m = v1 * m1;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, m.data);
    
    ASSERT_FLOAT_EQ(t[0], 15.0f);
    ASSERT_FLOAT_EQ(t[1], 23.0f);

}

// TODO add more

// ================ QUATERNION ================

TEST(Quaternion, Creation) {
    Vector<3> v(1.0f, 3.0f, 4.0f);
    float angle = 10.0f;
    
    Quaternion q(v, angle);
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, q.data);
    
    ASSERT_FLOAT_EQ(t[0], 1.0f * sin(angle/2));
    ASSERT_FLOAT_EQ(t[1], 3.0f * sin(angle/2));
    ASSERT_FLOAT_EQ(t[2], 4.0f * sin(angle/2));
    ASSERT_FLOAT_EQ(t[3], cos(angle/2));
}

TEST(Quaternion, ToMatrix) {
    Vector<3> v(1.0f, 3.0f, 4.0f);
    float angle = 10.0f;
    
    Quaternion q(v, angle);
    auto m = q.matrix();
    
    auto x = 1.0f * sin(angle/2);
    auto y = 3.0f * sin(angle/2);
    auto z = 4.0f * sin(angle/2);
    auto w = cos(angle/2);
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, m.data[0].data);
    
    ASSERT_FLOAT_EQ(t[0], 1 - 2*y*y - 2*z*z);
    ASSERT_FLOAT_EQ(t[1], 2*x*y + 2*z*w);
    ASSERT_FLOAT_EQ(t[2], 2*x*z - 2*y*w);
    
    _mm_storer_ps(t, m.data[1].data);
    
    ASSERT_FLOAT_EQ(t[0], 2*x*y - 2*z*w);
    ASSERT_FLOAT_EQ(t[1], 1 - 2*x*x - 2*z*z);
    ASSERT_FLOAT_EQ(t[2], 2*y*z + 2*x*w);
    
    _mm_storer_ps(t, m.data[2].data);
    
    ASSERT_FLOAT_EQ(t[0], 2*x*z + 2*y*w);
    ASSERT_FLOAT_EQ(t[1], 2*y*z - 2*x*w);
    ASSERT_FLOAT_EQ(t[2], 1 - 2*x*x - 2*y*y);
}
