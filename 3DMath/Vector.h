//
//  Vector.h
//  Math
//
//  Created by Gabriele on 18/10/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#ifndef vector_h_
#define vector_h_

namespace Math3D { namespace vector {

    using namespace utils;
        
    template <size_t N>
    class Vector {

    public:
        
        template <typename... T,
        typename = typename std::enable_if<(sizeof...(T) == N
                                            && N < 5 && N > 0
                                            && are_same<float, T...>::value) >::type>
        Vector(T... cps): data(data_) {
            __declspec(align(16)) float t[4] = {cps...};
            data_ = _mm_loadr_ps(t);
        };
        
        Vector(const float (&vs)[4]) : data(data_) {
            data_ = _mm_loadr_ps(vs);
        }

        Vector(): data(data_) {};
        Vector(const Vector<N>& v): data_(v.data), data(data_) {};
        Vector(Vector<N>&& v): data_(std::move(v.data)), data(data_) {};
        Vector(const __m128& d): data_(d), data(data_) {};

        Vector& operator=(const Vector<N>& v) {
            data_ = v.data;
            return *this;
        }
        
        Vector& operator=(Vector<N>&& v) {
            data_ = std::move(v.data);
            return *this;
        }
        
        // By Vector
        
        Vector& operator+=(const Vector& d) {
            data_ = _mm_add_ps(data, d.data);
            return *this;
        }
        
        Vector& operator-=(const Vector& d) {
            data_ = _mm_sub_ps(data, d.data);
            return *this;
        }
        
        Vector& operator*=(const Vector& d) {
            data_ = _mm_mul_ps(data, d.data);
            return *this;
        }
        
        Vector& operator/=(const Vector& d) {
            data_ = _mm_div_ps(data, d.data);
            return *this;
        }
        
        // By Scalar
        
        Vector& operator+=(const float s) {
            auto tmp = _mm_set_ps1(s);
            data_ = _mm_add_ps(data, tmp);
            return *this;
        }
        
        Vector& operator-=(const float s) {
            auto tmp = _mm_set_ps1(s);
            data_ = _mm_sub_ps(data, tmp);
            return *this;
        }
        
        Vector& operator*=(const float s) {
            auto tmp = _mm_set_ps1(s);
            data_ = _mm_mul_ps(tmp, data);
            return *this;
        }

        Vector& operator/=(const float s) {
            auto tmp = _mm_set_ps1(s);
            data_ = _mm_div_ps(data, tmp);
            return *this;
        }
        
        __m128 squared_magnitude() const {
            // (1,2,3,4) * (1,2,3,4) = (1,4,9,16)
            auto exp = _mm_mul_ps(data, data);
            
            // (1+4, 9+16, 1+4, 9+16) = (5, 15, 5, 15)
            auto sum = _mm_hadd_ps(exp, exp);
            
            // (5+15, 5+15, 5+15, 5+15) = (20, 20, 20, 20)
            return _mm_hadd_ps(sum, sum);
        }
        
        __m128 magnitude() const {
            return _mm_sqrt_ps(squared_magnitude());
        }
        
        const __m128& data;
        
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

}}
    
#endif
