//
//  Functions.h
//  Math
//
//  Created by Gabriele on 19/10/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#include "Vector.h"

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
inline Vector<N> operator*(const float s, Vector<N>& v) {
    auto tmp = _mm_set_ps(s,s,s,s);
    auto data = _mm_mul_ps(tmp, v());
    return Vector<N>(data);
}



