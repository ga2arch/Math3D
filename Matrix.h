//
//  Matrix.h
//  Math
//
//  Created by Gabriele on 19/10/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#ifndef matrix_h_
#define matrix_h_

#include <iostream>
#include "Vector.h"
#include "Utils.h"

using namespace std;

template <size_t R, size_t C>
class Matrix {
    
private:
    Vector<C> data_[R];
    
public:
    template <typename... T,
    typename = typename enable_if<(sizeof...(T) == R
                                   && R < 5 && R > 0
                                   && are_same<Vector<C>, T...>::value) >::type>
    Matrix(T... rows): data_{rows...}, data(data_) {};
    
    Matrix<R,C>& operator*=(const float s) {
        for (auto& e: data_) {
            e *= s;
        }
        return *this;
    }
    
    template <size_t R1, size_t C1>
    Matrix<R,C> operator*(const Matrix<R1,C1>& m) {
        Vector<C1> tmp[R];
        
        for (int i=0; i<R; i++) {
            tmp[i] = data[i]*m;
        }
        
        return Matrix(tmp[0], tmp[1], tmp[2], tmp[3]);
    }

    const Vector<C>* data;
};

#endif
