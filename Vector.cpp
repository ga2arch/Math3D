//
//  Vector.cpp
//  Math
//
//  Created by Gabriele on 18/10/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#include "Vector.h"

Vector<1>::Vector(float x)                           : Base(_mm_set1_ps(x))            {}
Vector<2>::Vector(float x, float y)                  : Base(_mm_set_ps(x,y,0.0f,0.0f)) {}
Vector<3>::Vector(float x, float y, float z)         : Base(_mm_set_ps(x,y,z,0.0f))    {}
Vector<4>::Vector(float x, float y, float z, float w): Base(_mm_set_ps(x,y,z,w))       {}
