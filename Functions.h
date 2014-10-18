//
//  Functions.h
//  Math
//
//  Created by Gabriele on 19/10/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#include <xmmintrin.h>
#include <x86intrin.h>

template <typename T>
inline T normalize(const T& v) {
    auto m = v.magnitude();
    auto r = _mm_rcp_ps(m);
    return T(_mm_mul_ps(r, v.data));
}