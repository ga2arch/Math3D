//
//  VectorTest.cpp
//  3DMath
//
//  Created by Gabriele Carrettoni on 19/11/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#include "VectorTest.h"

TEST(VectorTest, Creation) {
    
    Vector<4> v(1.0f,1.0f,1.0f,1.0f);
    
    __declspec(align(16)) float t[4];
    _mm_store_ps(t, v.data);
    
    for (int i=0; i < 4; i++) {
        ASSERT_EQ(t[i], 1.0f);
    }
}

TEST(VectorTest, Sum) {
    
    Vector<4> v1(1.0f,2.0f,5.0f,6.0f);
    Vector<4> v2(2.0f,3.0f,4.0f,7.0f);
    
    auto v3 = v1 + v2;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, v3.data);
    
    ASSERT_EQ(t[0], 1.0f + 2.0f);
    ASSERT_EQ(t[1], 2.0f + 3.0f);
    ASSERT_EQ(t[2], 5.0f + 4.0f);
    ASSERT_EQ(t[3], 6.0f + 7.0f);
}

TEST(VectorTest, Sub) {
    
    Vector<4> v1(1.0f,2.0f,5.0f,6.0f);
    Vector<4> v2(2.0f,3.0f,4.0f,7.0f);
    
    auto v3 = v1 - v2;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, v3.data);
    
    ASSERT_EQ(t[0], 1.0f - 2.0f);
    ASSERT_EQ(t[1], 2.0f - 3.0f);
    ASSERT_EQ(t[2], 5.0f - 4.0f);
    ASSERT_EQ(t[3], 6.0f - 7.0f);
}

TEST(VectorTest, Mul) {
    
    Vector<4> v1(1.0f,2.0f,5.0f,6.0f);
    Vector<4> v2(2.0f,3.0f,4.0f,7.0f);
    
    auto v3 = v1 * v2;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, v3.data);
    
    ASSERT_EQ(t[0], 2.0f);
    ASSERT_EQ(t[1], 6.0f);
    ASSERT_EQ(t[2], 20.0f);
    ASSERT_EQ(t[3], 42.0f);
}

TEST(VectorTest, Div) {
    
    Vector<4> v1(1.0f,2.0f,5.0f,6.0f);
    Vector<4> v2(2.0f,3.0f,4.0f,7.0f);
    
    auto v3 = v1 / v2;
    
    __declspec(align(16)) float t[4];
    _mm_storer_ps(t, v3.data);
    
    ASSERT_EQ(t[0], 1.0f/2.0f);
    ASSERT_EQ(t[1], 2.0f/3.0f);
    ASSERT_EQ(t[2], 5.0f/4.0f);
    ASSERT_EQ(t[3], 6.0f/7.0f);
}