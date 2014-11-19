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