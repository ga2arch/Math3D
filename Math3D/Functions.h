//
//  Functions.h
//  Math
//
//  Created by Gabriele on 19/10/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#ifndef functions_h_
#define functions_h_

namespace Math3D { namespace functions {
    using namespace utils;
    
    using vector::Vector;
    using vector::Vec3;

    using matrix::Matrix;
    using quaternion::Quaternion;
    
    // Generic
    __m128 dot(const __m128& p, const __m128& q) {
    #ifndef __SSE4_1__
        const auto m = _mm_mul_ps(p, q);
        const auto sum = _mm_hadd_ps(m, m);
        return _mm_hadd_ps(sum, sum);
    #else
        // mask = 4-byte   4-byte
        //        x y z w  x y z w
        //        origin   destination
        //        1 = mul  0 = set 0
        // 0xFF = 1 1 1 1  1 1 1 1
        return _mm_dp_ps(p, q, 0x0FF);
    #endif
    }

    __m128 cross(const __m128& p, const __m128& q) {
        auto sh1 = _mm_shuffle_ps(p, p, _MM_SHUFFLE(0,3,1,2));
        auto sh2 = _mm_shuffle_ps(q, q, _MM_SHUFFLE(0,2,3,1));
        
        const auto mul1 = _mm_mul_ps(sh1, sh2);
        
        sh1 = _mm_shuffle_ps(q, q, _MM_SHUFFLE(0,3,1,2));
        sh2 = _mm_shuffle_ps(p, p, _MM_SHUFFLE(0,2,3,1));
        
        const auto mul2 = _mm_mul_ps(sh1, sh2);
        
        return _mm_sub_ps(mul1, mul2);
    }

    // Vector ====================================================

    template <size_t N>
    Vector<N> normalize(const Vector<N>& v) {
        const auto m = v.magnitude();
        const auto r = _mm_rcp_ps(m);
        return Vector<N>(_mm_mul_ps(r, v.data));
    }

    template <size_t N>
    __m128 dot(const Vector<N>& v1, const Vector<N>& v2) {
        return dot(v1.data, v2.data);
    }


    template <size_t N>
    __m128 cross(const Vector<N>& v1, const Vector<N>& v2) {
        return cross(v1.data, v2.data);
    }

    template <size_t N>
    inline __m128 abs_cross(const Vector<N>& v1, const Vector<N>& v2) {
        return _mm_abs_ps(cross(v1, v2));
    }

    template <size_t N>
    Vector<N> operator*(const float s, const Vector<N>& v) {
        const auto tmp = _mm_set_ps1(s);
        const auto data = _mm_mul_ps(tmp, v.data);
        return Vector<N>(data);
    }

    template <size_t N>
    Vector<N> operator*(const Vector<N>& v, const float s) {
        const auto tmp = _mm_set_ps1(s);
        const auto data = _mm_mul_ps(v.data, tmp);
        return Vector<N>(data);
    }

    template <size_t N>
    Vector<N> operator+(const Vector<N>& v1, const float s) {
        const auto tmp = _mm_set_ps1(s);
        const auto data = _mm_add_ps(v1.data, tmp);
        return Vector<N>(data);
    }

    template <size_t N>
    Vector<N> operator+(const Vector<N>& v1, const Vector<N>& v2) {
        const auto data = _mm_add_ps(v1.data, v2.data);
        return Vector<N>(data);
    }

    template <size_t N>
    Vector<N> operator-(const Vector<N>& v1, const float s) {
        const auto tmp = _mm_set_ps1(s);
        const auto data = _mm_sub_ps(v1.data, tmp);
        return Vector<N>(data);
    }

    template <size_t N>
    Vector<N> operator-(const Vector<N>& v1, const Vector<N>& v2) {
        const auto data = _mm_sub_ps(v1.data, v2.data);
        return Vector<N>(data);
    }

    template <size_t N>
    Vector<N> operator*(const Vector<N>& v1, const Vector<N>& v2) {
        const auto data = _mm_mul_ps(v1.data, v2.data);
        return Vector<N>(data);
    }

    template <size_t N>
    Vector<N> operator/(const Vector<N>& v, const float s) {
        const auto tmp = _mm_set_ps1(s);
        const auto data = _mm_div_ps(v.data, tmp);
        return Vector<N>(data);
    }

    template <size_t N>
    Vector<N> operator/(const Vector<N>& v1, const Vector<N>& v2) {
        const auto data = _mm_div_ps(v1.data, v2.data);
        return Vector<N>(data);
    }

    template <size_t N>
    inline Vector<N> lerp(const Vector<N>& v1,
                          const Vector<N>& v2,
                          const float b) {
        return (1-b)*v1 + b*v2;
    }
    
    template <size_t C>
    Vector<C> operator*(const Vector<4>& v, const Matrix<4,C>& m) {
        const auto xxxx = _mm_replicate_x_ps(v.data);
        const auto yyyy = _mm_replicate_y_ps(v.data);
        const auto zzzz = _mm_replicate_z_ps(v.data);
        const auto wwww = _mm_replicate_w_ps(v.data);
        
        const auto m_row1 = _mm_mul_ps(xxxx, m.data[0].data);
        const auto m_row2 = _mm_mul_ps(yyyy, m.data[1].data);
        const auto m_row3 = _mm_mul_ps(zzzz, m.data[2].data);
        const auto m_row4 = _mm_mul_ps(wwww, m.data[3].data);
        
        auto result = _mm_add_ps(m_row1, m_row2);
        result = _mm_add_ps(result, m_row3);
        result = _mm_add_ps(result, m_row4);
        
        return Vector<C>(result);
    }

    template <size_t C>
    Vector<C> operator*(const Vector<3>& v, const Matrix<3,C>& m) {
        const auto xxxx = _mm_replicate_x_ps(v.data);
        const auto yyyy = _mm_replicate_y_ps(v.data);
        const auto zzzz = _mm_replicate_z_ps(v.data);
        
        const auto m_row1 = _mm_mul_ps(xxxx, m.data[0].data);
        const auto m_row2 = _mm_mul_ps(yyyy, m.data[1].data);
        const auto m_row3 = _mm_mul_ps(zzzz, m.data[2].data);
        
        auto result = _mm_add_ps(m_row1, m_row2);
        result = _mm_add_ps(result, m_row3);
        
        return Vector<C>(result);
    }

    template <size_t C>
    Vector<C> operator*(const Vector<2>& v, const Matrix<2,C>& m) {
        const auto xxxx = _mm_replicate_x_ps(v.data);
        const auto yyyy = _mm_replicate_y_ps(v.data);
        
        const auto m_row1 = _mm_mul_ps(xxxx, m.data[0].data);
        const auto m_row2 = _mm_mul_ps(yyyy, m.data[1].data);
        
        auto result = _mm_add_ps(m_row1, m_row2);
        
        return Vector<C>(result);
    }

    // Quaternions ====================================================

    Quaternion operator*(const Quaternion& p, const Quaternion& q) {
        const auto ps = _mm_replicate_w_ps(p.data);
        const auto qs = _mm_replicate_w_ps(q.data);
        
        const auto s1 = _mm_mul_ps(ps, q.data);
        const auto s2 = _mm_mul_ps(qs, p.data);
        
        const auto pvXqv = cross(p.data, q.data);
        
        const auto psqs = _mm_mul_ps(ps, qs);
        const auto pvqv = dot(p.data, q.data);
        
        auto r = _mm_add_ps(s1, s2);
        r = _mm_add_ps(r, pvXqv);
        
        auto a = _mm_sub_ps(psqs, pvqv);
        return Quaternion(Vec3(r), a);
    };

    Quaternion conjugate(const Quaternion& q) {
        __declspec(align(16)) float t[4] = {
            1, -1, -1, -1
        };
        auto a = _mm_load_ps(t);
        auto r = _mm_mul_ps(a, q.data);
        
        return Quaternion(r);
    }

    // The inverse is equal to the conjugate because
    // |q| is always 1 because they rappresent
    // 3D rotations

    Quaternion inverse(const Quaternion& q) {
        return conjugate(q);
    }

    template <size_t N>
    Vector<N> rotate(const Vector<N>& v, const Quaternion& q) {
        auto vd  = v.data;
        auto qd  = q.data;
        auto qid = inverse(q).data;
        
        auto r = _mm_mul_ps(qd, vd);
        r = _mm_mul_ps(r, qid);
        
        return Vector<N>(r);
    }

    template <size_t N, typename... T>
    Vector<N> rotate(const Vector<N>& v, T... tqs) {
        Quaternion qs[]{tqs...};
        auto q  = qs[sizeof...(T)-1];
        auto iq = inverse(qs[0]);
        
        int j = 1;
        for (int i=sizeof...(T)-2; i!=0; i--) {
            q = q * qs[i];
            iq = iq * inverse(qs[i]);
            j++;
        }

        auto r = _mm_mul_ps(q.data, v.data);
        r = _mm_mul_ps(r, iq.data);
        
        return Vector<N>(r);
    }

    // Matrix ======================================================

    template <size_t R, size_t C>
    Matrix<R,C> operator+(const Matrix<R,C>& m1, const float s) {
        Vector<C> tmp[R];
        
        for (int i=0; i < R; i++) {
            tmp[i] = m1.data[i] + s;
        }
        
        return Matrix<R,C>(tmp);
    }

    template <size_t R, size_t C>
    Matrix<R,C> operator+(const Matrix<R,C>& m1, const Matrix<R,C>& m2) {
        Vector<C> tmp[R];
        
        for (int i=0; i < R; i++) {
            tmp[i] = m1.data[i] + m2.data[i];
        }
        
        return Matrix<R,C>(tmp);
    }

    template <size_t R, size_t C>
    Matrix<R,C> operator-(const Matrix<R,C>& m1, const float s) {
        Vector<C> tmp[R];
        
        for (int i=0; i < R; i++) {
            tmp[i] = m1.data[i] - s;
        }
        
        return Matrix<R,C>(tmp);
    }

    template <size_t R, size_t C>
    Matrix<R,C> operator-(const Matrix<R,C>& m1, const Matrix<R,C>& m2) {
        Vector<C> tmp[R];
        
        for (int i=0; i < R; i++) {
            tmp[i] = m1.data[i] - m2.data[i];
        }
        
        return Matrix<R,C>(tmp);
    }

    template <size_t R, size_t C>
    Matrix<R,C> operator*(const Matrix<R,C>& m1, const float s) {
        Vector<C> tmp[R];
        
        for (int i=0; i < R; i++) {
            tmp[i] = m1.data[i] * s;
        }
        
        return Matrix<R,C>(tmp);
    }

    template <size_t R, size_t C>
    Matrix<R,C> operator*(const Matrix<R,C>& m1, const Matrix<R,C>& m2) {
        Vector<C> tmp[R];
        
        for (int i=0; i < R; i++) {
            tmp[i] = m1.data[i] * m2;
        }
        
        return Matrix<R,C>(tmp);
    }

    template <size_t R, size_t C>
    Matrix<R,C> operator/(const Matrix<R,C>& m1, const float s) {
        Vector<C> tmp[R];
        
        for (int i=0; i < R; i++) {
            tmp[i] = m1.data[i] / s;
        }
        
        return Matrix<R,C>(tmp);
    }

//    template <size_t R, size_t C>
//    Matrix<R,C> operator/(const Matrix<R,C>& m1, const Matrix<R,C>& m2) {
//        Vector<C> tmp[R];
//        
//        for (int i=0; i < R; i++) {
//            tmp[i] = m1.data[i] / m2.data[i];
//        }
//        
//        return Matrix<R,C>(tmp);
//    }

}}

#endif



