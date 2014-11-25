//
//  Matrix.h
//  Math
//
//  Created by Gabriele on 19/10/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#ifndef matrix_h_
#define matrix_h_

namespace Math3D { namespace quaternion {
    class Quaternion;
}}

namespace Math3D { namespace matrix {
    using namespace utils;

    using vector::Vector;
    using quaternion::Quaternion;
    
    template <size_t R, size_t C>
    class Matrix {

    public:
        template <typename... T,
        typename = typename std::enable_if<(sizeof...(T) == R
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
        
        // By Scalar
        
        Matrix<R,C>& operator+=(const float s) {
            for (auto& e: data_) {
                e += s;
            }
            return *this;
        }
        
        Matrix<R,C>& operator-=(const float s) {
            for (auto& e: data_) {
                e -= s;
            }
            return *this;
        }
        
        Matrix<R,C>& operator*=(const float s) {
            for (auto& e: data_) {
                e *= s;
            }
            return *this;
        }
        
        Matrix<R,C>& operator/=(const float s) {
            for (auto& e: data_) {
                e /= s;
            }
            return *this;
        }
        
        // By Matrix
        
        Matrix<R,C>& operator+=(const Matrix<R,C>& m) {
            for (int i=0; i < R; i++) {
                data_[i] += m.data[i];
            }
            
            return *this;
        }
        
        Matrix<R,C>& operator-=(const Matrix<R,C>& m) {
            for (int i=0; i < R; i++) {
                data_[i] -= m.data[i];
            }
            
            return *this;
        }

        Matrix<R,C>& operator*=(const Matrix<R,C>& m);
       
        template <size_t R1 = R, size_t C1 = C,
        typename = typename std::enable_if<R1==C1>::type>
        
        static Matrix<R,R> identity() {
            Vector<R> tmp[R];
            for (int i=0; i<R; i++) {
                __declspec(align(16)) float t[4] = {0.0f,0.0f,0.0f,0.0f};
                t[i] = 1.0f;
                tmp[i] = Vector<R>(t);
            }
            
            return Matrix<R,R>(tmp);
        }
        
        static Matrix<4,4> translation(float x, float y, float z) {
            auto m = Matrix<4,4>::identity();
            m.data_[3] = Vector<4>(x, y, z, 1.0f);
            return m;
        }
        
        static Matrix<4,4> translation(const Vector<3>& v) {
            auto m = Matrix<4,4>::identity();
            auto d = _mm_move_ss(v.data_, _mm_set1_ps(1.0f));
            m.data_[3] = Vector<4>(d);
            return m;
        }
        
        Matrix<R,R>& transpose() {
            if (R == 4) {
                _MM_TRANSPOSE4_PS(data_[3].data_,
                                  data_[2].data_,
                                  data_[1].data_,
                                  data_[0].data_);
                return *this;
            } else {
                __m128* temp[4];
                __m128  zeros[3] = {_mm_setzero_ps(),
                                    _mm_setzero_ps(),
                                    _mm_setzero_ps()};
                auto i = 0;
                
                for (i=0; i < R; i++) {
                    temp[i] = &data_[i].data_;
                }
                
                for (auto j=0; i <= 4; i++) {
                    temp[i] = &zeros[j];
                    j++;
                }
                
                _MM_TRANSPOSE4_PS(*temp[3],
                                  *temp[2],
                                  *temp[1],
                                  *temp[0]);
                return *this;
            }
        }
        
        Quaternion quaternion();
        
        const Vector<C> (&data)[R];
        
    private:
        Vector<C> data_[R];
    };
    
}}

#include "Quaternion.h"
using Math3D::matrix::Matrix;
using Math3D::quaternion::Quaternion;

template <size_t R, size_t C>
Quaternion Matrix<R,C>::quaternion() {
    // TODO
    return Quaternion(Vector<3>(1.0f,1.0f,1.0f), 20);
}

#include "Functions.h"
using Math3D::functions::operator*;

template <size_t R, size_t C>
Matrix<R,C>& Matrix<R,C>::operator*=(const Matrix<R,C>& m) {
    for (int i=0; i < R; i++) {
        data_[i] = data_[i] * m;
    }
    
    return *this;
}

#endif
