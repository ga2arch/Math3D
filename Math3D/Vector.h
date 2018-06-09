//
//  Vector.h
//  Math
//
//  Created by Gabriele on 18/10/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#ifndef vector_h_
#define vector_h_
#include <array>

namespace Math3D { namespace matrix {
    template <size_t R, size_t C>
    class Matrix;
}}

namespace Math3D { namespace vector {
    
    using namespace utils;
        
    template <size_t N>
    class Vector {

        template <size_t R, size_t C> friend class Math3D::matrix::Matrix;

    public:
        
        template <typename... Args,
        typename = typename std::enable_if<(sizeof...(Args) == N
                                            && N < 5 && N > 0
                                            && are_same<float, Args...>::value) >::type>
        Vector(Args... args) {
            __declspec(align(16)) float t[4] = {std::forward<Args>(args)...};
            data_ = _mm_loadr_ps(t);
        };
        
        Vector(const float (&vs)[4]) {
            data_ = _mm_loadr_ps(vs);
        }
        
        template <typename... Args>
        Vector(Vector<N-1>&& v, Args... args) {
            data_ = std::move(v.data);
            __declspec(align(16)) float t[4] = {std::forward<Args>(args)...};
            auto temp = _mm_load_ps(t);
            
            data_ = _mm_add_ps(data_, temp);
        }

        Vector() {};
        Vector(const Vector<N>& v): data_(v.data) {};
        Vector(Vector<N>&& v): data_(std::move(v.data)) {};
        Vector(const __m128& d): data_(d) {};

        Vector<N>& operator=(const Vector<N>& v) {
            data_ = v.data;
            return *this;
        }
        
        Vector<N>& operator=(Vector<N>&& v) {
            data_ = std::move(v.data);
            return *this;
        }
        
        // By Vector
        
        Vector<N>& operator+=(const Vector<N>& d) {
            data_ = _mm_add_ps(data, d.data);
            return *this;
        }
        
        Vector<N>& operator-=(const Vector<N>& d) {
            data_ = _mm_sub_ps(data, d.data);
            return *this;
        }
        
        Vector<N>& operator*=(const Vector<N>& d) {
            data_ = _mm_mul_ps(data, d.data);
            return *this;
        }
        
        Vector<N>& operator/=(const Vector<N>& d) {
            data_ = _mm_div_ps(data, d.data);
            return *this;
        }
        
        // By Scalar
        
        Vector<N>& operator+=(const float s) {
            auto tmp = _mm_set_ps1(s);
            data_ = _mm_add_ps(data, tmp);
            return *this;
        }
        
        Vector<N>& operator-=(const float s) {
            auto tmp = _mm_set_ps1(s);
            data_ = _mm_sub_ps(data, tmp);
            return *this;
        }
        
        Vector<N>& operator*=(const float s) {
            auto tmp = _mm_set_ps1(s);
            data_ = _mm_mul_ps(tmp, data);
            return *this;
        }

        Vector<N>& operator/=(const float s) {
            auto tmp = _mm_set_ps1(s);
            data_ = _mm_div_ps(data, tmp);
            return *this;
        }
        
        //
        __m128 squared_magnitude() const {
            // (1,2,3,4) * (1,2,3,4) = (1,4,9,16)
            auto exp = _mm_mul_ps(data, data);
            
            // (1+4, 9+16, 1+4, 9+16) = (5, 25, 5, 25)
            auto sum = _mm_hadd_ps(exp, exp);
            
            // (5+25, 5+25, 5+25, 5+25) = (30, 30, 30, 30)
            return _mm_hadd_ps(sum, sum);
        }
        
        __m128 magnitude() const {
            return _mm_sqrt_ps(squared_magnitude());
        }
        
        Vector<N>& normalize() {
            data_ = _mm_div_ps(data_, magnitude());
            return *this;
        }
        
        void to_array(float (&a)[4]) {
            _mm_storer_ps(a, data_);
        }
        
        const __m128& data = data_;
        
    protected:
        __m128 data_;
    };

    template<>
    __m128 Vector<4>::squared_magnitude() const {
    #ifndef __SSE4_1__
        const auto m = _mm_mul_ps(data_, data_);
        const auto sum = _mm_hadd_ps(m, m);
        return _mm_hadd_ps(sum, sum);
    #else
        return _mm_dp_ps(data_, data_, 0x0FF);
    #endif
    }

    using Vec1 = Vector<1>;
    using Vec2 = Vector<2>;
    using Vec3 = Vector<3>;
    using Vec4 = Vector<4>;
    
    using Point = Vec3;

}}
    
#endif
