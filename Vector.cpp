//
//  Vector.cpp
//  Math
//
//  Created by Gabriele on 18/10/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#include "Vector.h"

Vector<4>::Vector(float x, float y, float z, float w): Base(_mm_set_ps(x,y,z,w)) {}