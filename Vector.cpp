//
//  Vector.cpp
//  Math
//
//  Created by Gabriele on 18/10/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#include "Vector.h"

Vector<1>::Vector(float x) {
    __declspec(align(16)) float t[] = {x};
    data_ = _mm_load1_ps(t);
}

Vector<2>::Vector(float x, float y) {
    __declspec(align(16)) float t[] = {x, y, 0.0f, 0.0f};
    data_ = _mm_load_ps(t);
 }

Vector<3>::Vector(float x, float y, float z) {
    __declspec(align(16)) float t[] = {x, y, z, 0.0f};
    data_ = _mm_load_ps(t);
}

Vector<4>::Vector(float x, float y, float z, float w) {
    __declspec(align(16)) float t[] = {x, y, z, w};
    data_ = _mm_load_ps(t);
}
