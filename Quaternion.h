//
//  Quaternion.h
//  Math
//
//  Created by Gabriele on 21/10/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#ifndef Math_Quaternion_h
#define Math_Quaternion_h

#include <immintrin.h>
#include <smmintrin.h>

#include "Functions.h"
#include "Vector.h"
#include "SSEFun.h"

class Quaternion {
    
public:
    Quaternion(): data(data_) {};
    Quaternion(__m128& m): data_(m), data(data_) {};
    Quaternion(Vec3 v, float angle): data(data_) {
        __declspec(align(16)) float t[4] = {
            angle/2.0f, angle/2.0f, angle/2.0f, angle/2.0f
        };
        auto aaaa = _mm_load_ps(t);
        aaaa = sin_ps(aaaa);
        
        auto ___a = _mm_keep_w_ps(cos_ps(aaaa));
        
        const auto r = _mm_mul_ps(v.data, aaaa);
        data_ = _mm_add_ps(r, ___a);
    };
    
    Quaternion(Vec3 v, __m128 angle): data(data_) {
        const auto ___a = _mm_keep_w_ps(v.data);
        data_ = _mm_add_ps(v.data, ___a);
    }

    const __m128& data;
    
private:
    __m128 data_;
    
};

#endif
