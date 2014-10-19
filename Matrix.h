//
//  Matrix.h
//  Math
//
//  Created by Gabriele on 19/10/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#ifndef matrix_h
#define matrix_h

#include <iostream>
#include "Vector.h"

using namespace std;

template <size_t R, size_t C>
class Matrix {
    
private:
    Vector<C> data_[R];
    
public:
    template <typename... T>
    Matrix(T... rows): data_{rows...}, data(data_) {};
 
    const Vector<C>* data;
};

#endif
