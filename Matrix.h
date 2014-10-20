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
    
    template <size_t T>
    Matrix<R,C>& operator*=(const Vector<T>& v) {
        const __m128 xxxx = _mm_replicate_x_ps(v.data);
        const __m128 yyyy = _mm_replicate_y_ps(v.data);
        const __m128 zzzz = _mm_replicate_z_ps(v.data);
        const __m128 wwww = _mm_replicate_w_ps(v.data);
        
        const __m128 m_row1 = _mm_mul_ps(xxxx, data[0]);
        const __m128 m_row2 = _mm_mul_ps(yyyy, data[1]);
        const __m128 m_row3 = _mm_mul_ps(zzzz, data[2]);
        const __m128 m_row4 = _mm_mul_ps(wwww, data[3]);
        
        auto result = _mm_add_ps(m_row1, m_row2);
        result = _mm_add_ps(result, m_row3);
        result = _mm_add_ps(result, m_row4);
                
        return Matrix {Vector<C>(result)};
    }


    const Vector<C>* data;
};

#endif
