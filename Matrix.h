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
    

public:
    template <typename... T,
    typename = typename enable_if<(sizeof...(T) == R
                                   && R < 5 && R > 0
                                   && are_same<Vector<C>, T...>::value) >::type>
    Matrix(T... rows): data_{rows...}, data(data_) {};
    
    Matrix(Vector<C>* vs, int n): data(data_) {
        for (int i=0; i<n; i++) {
            data_[i] = *(vs+i);
        }
    };
    
    Matrix<R,C>& operator*=(const float s) {
        for (auto& e: data_) {
            e *= s;
        }
        return *this;
    }
    
    template <size_t R1, size_t C1,
    typename = typename enable_if<C == R1>::type>
    
    Matrix<R,C> operator*(const Matrix<R1,C1>& m) {
        Vector<C1> tmp[R];
        
        for (int i=0; i<R; i++) {
            tmp[i] = data[i]*m;
        }
        
        return Matrix<R,C1>(tmp, R);
    }

    const Vector<C> (&data)[R];
    
private:
    Vector<C> data_[R];
};

#endif
