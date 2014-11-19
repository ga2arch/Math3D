//
//  Matrix.h
//  Math
//
//  Created by Gabriele on 19/10/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#ifndef matrix_h_
#define matrix_h_

class Quaternion;

using namespace std;

template <size_t R, size_t C>
class Matrix {
    
public:
    template <typename... T,
    typename = typename enable_if<(sizeof...(T) == R
                                   && R < 5 && R > 0
                                   && are_same<Vector<C>, T...>::value) >::type>
    Matrix(T... rows): data_{rows...}, data(data_) {};
    
    Matrix(Vector<C> (&vs)[R]): data(data_) {
        for (int i=0; i<R; i++) {
            data_[i] = vs[i];
        }
    };
    
    Matrix<R,C>& operator=(const Matrix<R,C>& m) {
        std::memset(data_, 0, R);
        std::memcpy(data_, m.data_, R);
        
        return *this;
    }
    
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
        
        return Matrix<R,C1>(tmp);
    }
    
    template <size_t R1, size_t C1,
    typename = typename enable_if<C == R1>::type>
    
    Matrix<R,C>& operator*=(const Matrix<R1,C1>& m) {
        Vector<C1> tmp[R];
        
        for (auto& e: data) {
            e *= m;
        }
        
        return Matrix<R,C1>(tmp);
    }
    
    template <size_t R1 = R, size_t C1 = C,
    typename = typename enable_if<R1 == C1>::type>
    
    static Matrix<R,R> identity() {
        Vector<R> tmp[R];
        for (int i=0; i<R; i++) {
            __declspec(align(16)) float t[4] = {0.0f,0.0f,0.0f,0.0f};
            t[i] = 1.0f;
            tmp[i] = Vector<R>(t);
        }
        
        return Matrix<R,R>(tmp);
    }
    
    Quaternion quaternion();
    
    const Vector<C> (&data)[R];
    
private:
    Vector<C> data_[R];
};

#include "Quaternion.h"

template<>
Quaternion Matrix<3,3>::quaternion() {
    
    return Quaternion(Vec3(1.0f,1.0f,1.0f), 20);
}

#endif
