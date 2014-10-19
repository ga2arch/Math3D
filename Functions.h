//
//  Functions.h
//  Math
//
//  Created by Gabriele on 19/10/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#include "Vector.h"
#include "Utils.h"

template <size_t N>
inline Vector<N> normalize(const Vector<N>& v) {
    auto m = v.magnitude();
    auto r = _mm_rcp_ps(m);
    return Vector<N>(_mm_mul_ps(r, v.data));
}

template <size_t N>
inline __m128 dot(const Vector<N>& v1, const Vector<N>& v2) {
    auto m = _mm_mul_ps(v1.data, v2.data);
    auto sum = _mm_hadd_ps(m, m);
    return _mm_hadd_ps(sum, sum);
}

template <size_t N>
inline __m128 cross(const Vector<N>& v1, const Vector<N>& v2) {
    auto sh1 = _mm_shuffle_ps(v1.data, v1.data, _MM_SHUFFLE(0,3,1,2));
    auto sh2 = _mm_shuffle_ps(v2.data, v2.data, _MM_SHUFFLE(0,2,3,1));
    
    auto mul1 = _mm_mul_ps(sh1, sh2);
    
    sh1 = _mm_shuffle_ps(v2.data, v2.data, _MM_SHUFFLE(0,3,1,2));
    sh2 = _mm_shuffle_ps(v1.data, v1.data, _MM_SHUFFLE(0,2,3,1));
    
    auto mul2 = _mm_mul_ps(sh1, sh2);
    
    return _mm_sub_ps(mul1, mul2);
}

template <size_t N>
inline __m128 abs_cross(const Vector<N>& v1, const Vector<N>& v2) {
    return _mm_abs_ps(cross(v1, v2));
}

template <size_t N>
inline Vector<N> operator*(const float s, Vector<N>& v) {
    auto tmp = _mm_set_ps(s,s,s,s);
    auto data = _mm_mul_ps(tmp, v.data);
    return Vector<N>(data);
}

template <size_t N>
inline Vector<N> lerp(const Vector<N>& v1, const Vector<N>& v2, const float b) {
    return (1-b)*v1 + b*v2;
}





