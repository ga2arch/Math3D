//
//  main.cpp
//  Math
//
//  Created by Gabriele on 18/10/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#include <iostream>
#include "Vector.h"

using namespace std;

#define SHUFFLE_PARAM(x, y, z, w) ((x) | ((y) << 2) | ((z) << 4) | ((w) << 6))

int main(int argc, const char * argv[]) {
//    
//    __m128 v1 = _mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f);
//    __m128 v2 = _mm_set_ps(5.0f, 6.0f, 7.0f, 8.0f);
//    
//    __m128 result = _mm_shuffle_ps((v1), (v1), SHUFFLE_PARAM(0,0,0,0));
//    
//    __declspec(align(16)) float A[4];
//    
//    _mm_store_ps(&A[0], result);
//    
//    printf("%g %g %g %g\n", A[0], A[1], A[2], A[3]);
    
    Vec4 v1(1.0f, 2.0f, 3.0f, 4.0f);
    
    Vec3 v2(1.0f, 2.0f, 3.0f);
    Vec3 v3(1.0f, 2.0f, 3.0f);

    //auto v3 = v1 + v2;
    v2 += v3;
    
//    Vector v2(1.0f, 1.0f, 1.0f, 1.2f);
//    
//    auto v3 = v1 + v2;
//    
    __declspec(align(16)) float A[4];
//    
   _mm_store_ps(&A[0], v2());
//    
    printf("%g %g %g %g\n", A[3], A[2], A[1], A[0]);

    
}

