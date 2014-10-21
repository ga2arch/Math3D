//
//  Quaternion.h
//  Math
//
//  Created by Gabriele on 21/10/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#ifndef Math_Quaternion_h
#define Math_Quaternion_h

#include <mmintrin.h>
#include <xmmintrin.h>
#include <x86intrin.h>
#include "Vector.h"
#include "SSEMathFun.h"

class Quaternion {
    
public:
    Quaternion(): data(data_) {};
    Quaternion(Vec3 v, float angle): data(data_) {
        __declspec(align(16)) float t[4] = {0.0f,0.0f,0.0f,angle/2.0f};
        auto ___a = _mm_load_ps(t);
        
        auto aaaa = _mm_shuffle_ps(___a, ___a, _MM_SHUFFLE(0,0,0,0));
        aaaa = sin_ps(aaaa);
        ___a = cos_ps(___a);
        
        const auto r = _mm_mul_ps(v.data, aaaa);
        data_ = _mm_add_ps(r, ___a);
    };
    
    const __m128& data;
    
private:
    __m128 data_;
    
};


#endif
