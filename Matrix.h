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
    
    

    const Vector<C>* data;
};

#endif
