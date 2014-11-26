//
//  Vector4Test.cpp
//  3DMath
//
//  Created by Gabriele Carrettoni on 19/11/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#include "Math3DTest.h"

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

TEST(Vector4Test, ToArray) {
    
    Vector<4> v(1.0f,3.0f,5.0f,9.0f);
    
    __declspec(align(16)) float t[4];
    float m[4] = { 1.0f,3.0f,5.0f,9.0f };
    
    v.to_array(t);
    
    for (int i=0; i < 4; i++) {
        ASSERT_EQ(t[i], m[i]);
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

TEST(Matrix, ToArray) {
    
    Matrix<4,4> m (Vector<4>(1.0f, 1.0f, 1.0f, 1.0f),
                   Vector<4>(1.0f, 1.0f, 1.0f, 1.0f),
                   Vector<4>(1.0f, 1.0f, 1.0f, 1.0f),
                   Vector<4>(1.0f, 1.0f, 1.0f, 1.0f));
    
    
    __declspec(align(16)) float t[4][4];
    m.to_array(t);
    
    for (int i=0; i < 4; i++) {
        for (int j=0; j < 4; j++) {
            ASSERT_FLOAT_EQ(t[i][j], 1.0f);
        }
    }
}

TEST(Matrix, SumByFloat) {
    Matrix<2,2> m1 (Vector<2>(2.0f, 4.0f),
                    Vector<2>(5.0f, 3.0f));
    
    float b = 10;
    
    auto m = m1 + b;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, m.data[0].data);
    
    ASSERT_FLOAT_EQ(t[0], 2.0f + b);
    ASSERT_FLOAT_EQ(t[1], 4.0f + b);
    
    _mm_storer_ps(t, m.data[1].data);
    
    ASSERT_FLOAT_EQ(t[0], 5.0f + b);
    ASSERT_FLOAT_EQ(t[1], 3.0f + b);
    
    m1 += b;
    
    _mm_storer_ps(t, m1.data[0].data);
    
    ASSERT_FLOAT_EQ(t[0], 2.0f + b);
    ASSERT_FLOAT_EQ(t[1], 4.0f + b);
    
    _mm_storer_ps(t, m1.data[1].data);
    
    ASSERT_FLOAT_EQ(t[0], 5.0f + b);
    ASSERT_FLOAT_EQ(t[1], 3.0f + b);
}

TEST(Matrix, SubByFloat) {
    Matrix<2,2> m1 (Vector<2>(2.0f, 4.0f),
                    Vector<2>(5.0f, 3.0f));
    
    float b = 10;
    
    auto m = m1 - b;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, m.data[0].data);
    
    ASSERT_FLOAT_EQ(t[0], 2.0f - b);
    ASSERT_FLOAT_EQ(t[1], 4.0f - b);
    
    _mm_storer_ps(t, m.data[1].data);
    
    ASSERT_FLOAT_EQ(t[0], 5.0f - b);
    ASSERT_FLOAT_EQ(t[1], 3.0f - b);
    
    m1 -= b;
    
    _mm_storer_ps(t, m1.data[0].data);
    
    ASSERT_FLOAT_EQ(t[0], 2.0f - b);
    ASSERT_FLOAT_EQ(t[1], 4.0f - b);
    
    _mm_storer_ps(t, m1.data[1].data);
    
    ASSERT_FLOAT_EQ(t[0], 5.0f - b);
    ASSERT_FLOAT_EQ(t[1], 3.0f - b);
}

TEST(Matrix, MulByFloat) {
    Matrix<2,2> m1 (Vector<2>(2.0f, 4.0f),
                    Vector<2>(5.0f, 3.0f));
    
    float b = 10;
    
    auto m = m1 * b;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, m.data[0].data);
    
    ASSERT_FLOAT_EQ(t[0], 2.0f * b);
    ASSERT_FLOAT_EQ(t[1], 4.0f * b);
    
    _mm_storer_ps(t, m.data[1].data);
    
    ASSERT_FLOAT_EQ(t[0], 5.0f * b);
    ASSERT_FLOAT_EQ(t[1], 3.0f * b);
    
    m1 *= b;
    
    _mm_storer_ps(t, m1.data[0].data);
    
    ASSERT_FLOAT_EQ(t[0], 2.0f * b);
    ASSERT_FLOAT_EQ(t[1], 4.0f * b);
    
    _mm_storer_ps(t, m1.data[1].data);
    
    ASSERT_FLOAT_EQ(t[0], 5.0f * b);
    ASSERT_FLOAT_EQ(t[1], 3.0f * b);
}

TEST(Matrix, DivByFloat) {
    Matrix<2,2> m1 (Vector<2>(2.0f, 4.0f),
                    Vector<2>(5.0f, 3.0f));
    
    float b = 10;
    
    auto m = m1 / b;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, m.data[0].data);
    
    ASSERT_FLOAT_EQ(t[0], 2.0f / b);
    ASSERT_FLOAT_EQ(t[1], 4.0f / b);
    
    _mm_storer_ps(t, m.data[1].data);
    
    ASSERT_FLOAT_EQ(t[0], 5.0f / b);
    ASSERT_FLOAT_EQ(t[1], 3.0f / b);
    
    m1 /= b;
    
    _mm_storer_ps(t, m1.data[0].data);
    
    ASSERT_FLOAT_EQ(t[0], 2.0f / b);
    ASSERT_FLOAT_EQ(t[1], 4.0f / b);
    
    _mm_storer_ps(t, m1.data[1].data);
    
    ASSERT_FLOAT_EQ(t[0], 5.0f / b);
    ASSERT_FLOAT_EQ(t[1], 3.0f / b);
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
    
    ASSERT_FLOAT_EQ(t[0], 18.0f);
    ASSERT_FLOAT_EQ(t[1], 14.0f);

    _mm_storer_ps(t, m.data[1].data);
    
    ASSERT_FLOAT_EQ(t[0], 31.0f);
    ASSERT_FLOAT_EQ(t[1], 14.0f);
    
    m1 *= m2;
    
    _mm_storer_ps(t, m.data[0].data);
    
    ASSERT_FLOAT_EQ(t[0], 18.0f);
    ASSERT_FLOAT_EQ(t[1], 14.0f);
    
    _mm_storer_ps(t, m.data[1].data);
    
    ASSERT_FLOAT_EQ(t[0], 31.0f);
    ASSERT_FLOAT_EQ(t[1], 14.0f);
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

TEST(Matrix, Transpose4x4) {
    Matrix<4,4> m1 (Vector<4>(2.0f, 4.0f, 5.0f, 7.0f),
                   Vector<4>(5.0f, 3.0f, 9.0f, 8.0f),
                   Vector<4>(7.0f, 3.0f, 1.0f, 3.0f),
                   Vector<4>(7.0f, 3.0f, 5.0f, 3.0f));
    
    auto m = m1.transpose();
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, m.data[0].data);
    
    ASSERT_FLOAT_EQ(t[0], 2.0f);
    ASSERT_FLOAT_EQ(t[1], 5.0f);
    ASSERT_FLOAT_EQ(t[2], 7.0f);
    ASSERT_FLOAT_EQ(t[3], 7.0f);

    _mm_storer_ps(t, m.data[1].data);
    
    ASSERT_FLOAT_EQ(t[0], 4.0f);
    ASSERT_FLOAT_EQ(t[1], 3.0f);
    ASSERT_FLOAT_EQ(t[2], 3.0f);
    ASSERT_FLOAT_EQ(t[3], 3.0f);
    
    _mm_storer_ps(t, m.data[2].data);
    
    ASSERT_FLOAT_EQ(t[0], 5.0f);
    ASSERT_FLOAT_EQ(t[1], 9.0f);
    ASSERT_FLOAT_EQ(t[2], 1.0f);
    ASSERT_FLOAT_EQ(t[3], 5.0f);
    
    _mm_storer_ps(t, m.data[3].data);
    
    ASSERT_FLOAT_EQ(t[0], 7.0f);
    ASSERT_FLOAT_EQ(t[1], 8.0f);
    ASSERT_FLOAT_EQ(t[2], 3.0f);
    ASSERT_FLOAT_EQ(t[3], 3.0f);
}

TEST(Matrix, Transpose3x3) {
    Matrix<3,3> m1 (Vector<3>(2.0f, 4.0f, 5.0f),
                    Vector<3>(5.0f, 3.0f, 9.0f),
                    Vector<3>(7.0f, 3.0f, 1.0f));
    
    auto m = m1.transpose();
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, m.data[0].data);
    
    ASSERT_FLOAT_EQ(t[0], 2.0f);
    ASSERT_FLOAT_EQ(t[1], 5.0f);
    ASSERT_FLOAT_EQ(t[2], 7.0f);
    
    _mm_storer_ps(t, m.data[1].data);
    
    ASSERT_FLOAT_EQ(t[0], 4.0f);
    ASSERT_FLOAT_EQ(t[1], 3.0f);
    ASSERT_FLOAT_EQ(t[2], 3.0f);
    
    _mm_storer_ps(t, m.data[2].data);
    
    ASSERT_FLOAT_EQ(t[0], 5.0f);
    ASSERT_FLOAT_EQ(t[1], 9.0f);
    ASSERT_FLOAT_EQ(t[2], 1.0f);

}

TEST(Matrix, Traslation) {
    auto m = Matrix<4,4>::translation(2.0f, 3.0f, 7.0f);
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, m.data[0].data);
    
    ASSERT_FLOAT_EQ(t[0], 1.0f);
    ASSERT_FLOAT_EQ(t[1], 0.0f);
    ASSERT_FLOAT_EQ(t[2], 0.0f);
    ASSERT_FLOAT_EQ(t[3], 0.0f);

    _mm_storer_ps(t, m.data[1].data);
    
    ASSERT_FLOAT_EQ(t[0], 0.0f);
    ASSERT_FLOAT_EQ(t[1], 1.0f);
    ASSERT_FLOAT_EQ(t[2], 0.0f);
    ASSERT_FLOAT_EQ(t[3], 0.0f);
    
    _mm_storer_ps(t, m.data[2].data);
    
    ASSERT_FLOAT_EQ(t[0], 0.0f);
    ASSERT_FLOAT_EQ(t[1], 0.0f);
    ASSERT_FLOAT_EQ(t[2], 1.0f);
    ASSERT_FLOAT_EQ(t[3], 0.0f);

    _mm_storer_ps(t, m.data[3].data);
    
    ASSERT_FLOAT_EQ(t[0], 2.0f);
    ASSERT_FLOAT_EQ(t[1], 3.0f);
    ASSERT_FLOAT_EQ(t[2], 7.0f);
    ASSERT_FLOAT_EQ(t[3], 1.0f);
    
    m = Matrix<4,4>::translation(Vector<3>(2.0f, 3.0f, 7.0f));
    
    _mm_storer_ps(t, m.data[0].data);
    
    ASSERT_FLOAT_EQ(t[0], 1.0f);
    ASSERT_FLOAT_EQ(t[1], 0.0f);
    ASSERT_FLOAT_EQ(t[2], 0.0f);
    ASSERT_FLOAT_EQ(t[3], 0.0f);
    
    _mm_storer_ps(t, m.data[1].data);
    
    ASSERT_FLOAT_EQ(t[0], 0.0f);
    ASSERT_FLOAT_EQ(t[1], 1.0f);
    ASSERT_FLOAT_EQ(t[2], 0.0f);
    ASSERT_FLOAT_EQ(t[3], 0.0f);
    
    _mm_storer_ps(t, m.data[2].data);
    
    ASSERT_FLOAT_EQ(t[0], 0.0f);
    ASSERT_FLOAT_EQ(t[1], 0.0f);
    ASSERT_FLOAT_EQ(t[2], 1.0f);
    ASSERT_FLOAT_EQ(t[3], 0.0f);
    
    _mm_storer_ps(t, m.data[3].data);
    
    ASSERT_FLOAT_EQ(t[0], 2.0f);
    ASSERT_FLOAT_EQ(t[1], 3.0f);
    ASSERT_FLOAT_EQ(t[2], 7.0f);
    ASSERT_FLOAT_EQ(t[3], 1.0f);
}

TEST(Matrix, LookAt) {
    auto m = Matrix<4,4>::look_at(Vec3(2.0f, 3.0f, 2.0f),
                                  Vec3(3.0f, 4.0f, 2.0f),
                                  Vec3(1.0f, 7.0f, 9.0f));

    float dir[3]    {0.70703125, 0.70703125, 0};
    float left[3]   {-0.63960844, 0.63960844, -0.42640561};
    float new_up[3] {-0.30148208, 0.30148208, 0.9044463};
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, m.data[0].data);
    
    ASSERT_FLOAT_EQ(t[0], left[0]);
    ASSERT_FLOAT_EQ(t[1], left[1]);
    ASSERT_FLOAT_EQ(t[2], left[2]);
    ASSERT_FLOAT_EQ(t[3], 0.0f);
    
    _mm_storer_ps(t, m.data[1].data);
    
    ASSERT_FLOAT_EQ(t[0], new_up[0]);
    ASSERT_FLOAT_EQ(t[1], new_up[1]);
    ASSERT_FLOAT_EQ(t[2], new_up[2]);
    ASSERT_FLOAT_EQ(t[3], 0.0f);
    
    _mm_storer_ps(t, m.data[2].data);
    
    ASSERT_FLOAT_EQ(t[0], dir[0]);
    ASSERT_FLOAT_EQ(t[1], dir[1]);
    ASSERT_FLOAT_EQ(t[2], dir[2]);
    ASSERT_FLOAT_EQ(t[3], 0.0f);
    
    _mm_storer_ps(t, m.data[3].data);
    
    ASSERT_FLOAT_EQ(t[0], 2.0f);
    ASSERT_FLOAT_EQ(t[1], 3.0f);
    ASSERT_FLOAT_EQ(t[2], 2.0f);
    ASSERT_FLOAT_EQ(t[3], 1.0f);
}



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

// Functions

TEST(Functions, Cross) {
    Vector<3> v1{4.0f,  3.0f, 4.0f};
    Vector<3> v2{10.0f, 3.0f, 4.0f};

    auto r = cross(v1, v2);
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, r.data);
    
    ASSERT_FLOAT_EQ(t[0], 0.0f);
    ASSERT_FLOAT_EQ(t[1], 24.f);
    ASSERT_FLOAT_EQ(t[2], -18.0f);
}
