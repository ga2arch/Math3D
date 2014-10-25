//
//  Vector.h
//  Math
//
//  Created by Gabriele on 18/10/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#ifndef vector_h_
#define vector_h_

using namespace std;

template <std::size_t N>
class Vector {
    
public:
    
    template <typename... T,
    typename = typename enable_if<(sizeof...(T) == N
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
    Vector(const __m128& d): data_(d), data(data_) {};

    Vector& operator=(const Vector<N>& v) {
        data_ = v.data;
        return *this;
    }
    
    Vector operator+(const Vector& d) const {
        return Vector(_mm_add_ps(data, d()));
    }
    
    Vector& operator+=(const Vector& d) {
        data_ = _mm_add_ps(data, d.data);
        return *this;
    }
    
    Vector operator*(const float s) {
        auto tmp = _mm_set_ps1(s);
        return Vector(_mm_mul_ps(data, tmp));
    }
    
    Vector& operator*=(const float s) {
        auto tmp = _mm_set_ps1(s);
        data_ = _mm_mul_ps(tmp, data);
        return *this;
    }
    
    __m128 magnitude() const {
        // (1,2,3,4) * (1,2,3,4) = (1,4,9,16)
        auto exp = _mm_mul_ps(data, data);
        
        // (1+4, 9+16, 1+4, 9+16) = (5, 15, 5, 15)
        auto sum = _mm_hadd_ps(exp, exp);
        
        // sqrt(5+15, 5+15, 5+15, 5+15) = sqrt(20, 20, 20, 20)
        return _mm_sqrt_ps(_mm_hadd_ps(sum, sum));
    }
    
    __m128 squared_magnitude() const {
        auto exp = _mm_mul_ps(data, data);
        auto sum = _mm_hadd_ps(exp, exp);
        return _mm_hadd_ps(sum, sum);
    }
    
    const __m128& data;
    
protected:
    __m128 data_;

};

typedef Vector<1> Vec1;
typedef Vector<2> Vec2;
typedef Vector<3> Vec3;
typedef Vector<4> Vec4;

#endif