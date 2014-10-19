//
//  Functions.h
//  Math
//
//  Created by Gabriele on 19/10/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#include "Vector.h"

// Single precision float have sign bit at 31° bit
// applying a mask of 0x7fffffff (31* bit is 0) allows to
// to keep all the bits and setting the 31° to 0
// effectively abs-ing the number

__declspec(align(16)) static const int absmask[] = {
    0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff
};

#define _mm_abs_ps(x) _mm_and_ps((x), *(const __m128*)absmask)

template <size_t N>
inline Vector<N> normalize(const Vector<N>& v) {
    auto m = v.magnitude();
    auto r = _mm_rcp_ps(m);
    return Vector<N>(_mm_mul_ps(r, v()));
}

template <size_t N>
inline __m128 dot(const Vector<N>& v1, const Vector<N>& v2) {
    auto m = _mm_mul_ps(v1(), v2());
    auto sum = _mm_hadd_ps(m, m);
    return _mm_hadd_ps(sum, sum);
}

template <size_t N>
inline __m128 cross(const Vector<N>& v1, const Vector<N>& v2) {
    auto sh1 = _mm_shuffle_ps(v1(), v1(), _MM_SHUFFLE(0,3,1,2));
    auto sh2 = _mm_shuffle_ps(v2(), v2(), _MM_SHUFFLE(0,2,3,1));
    
    auto mul1 = _mm_mul_ps(sh1, sh2);
    
    sh1 = _mm_shuffle_ps(v2(), v2(), _MM_SHUFFLE(0,3,1,2));
    sh2 = _mm_shuffle_ps(v1(), v1(), _MM_SHUFFLE(0,2,3,1));
    
    auto mul2 = _mm_mul_ps(sh1, sh2);
    
    return _mm_sub_ps(mul1, mul2);
    //__declspec(align(16)) float A[4];
    //_mm_store_ps(&A[0], sub);
    
    //std::cout << A[0] << std::endl;
    //return v1();
}

template <size_t N>
inline __m128 abs_cross(const Vector<N>& v1, const Vector<N>& v2) {
    return _mm_abs_ps(cross(v1, v2));
}

template <size_t N>
inline Vector<N> operator*(const float s, Vector<N>& v) {
    auto tmp = _mm_set_ps(s,s,s,s);
    auto data = _mm_mul_ps(tmp, v());
    return Vector<N>(data);
}



