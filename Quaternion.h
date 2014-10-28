//
//  Quaternion.h
//  Math
//
//  Created by Gabriele on 21/10/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#ifndef Math_Quaternion_h
#define Math_Quaternion_h

class Quaternion {
    
public:
    Quaternion(): data(data_) {};
    Quaternion(__m128& m): data_(m), data(data_) {};
    Quaternion(const Vec3& v, float angle): data(data_) {
        __declspec(align(16)) float t[4] = {angle/2.0f};
        
        auto aaaa = _mm_replicate_w_ps(_mm_load_ps(t));
        auto ssss = sin_ps(aaaa);
        auto cccc = cos_ps(aaaa);
        
        const auto r = _mm_mul_ps(v.data, ssss);
        data_ = _mm_move_ss(r, cccc);
    };
    
    Quaternion(const Vec3& v, const __m128& angle): data(data_) {
        data_ = _mm_move_ss(v.data, angle);
    }

    Matrix<3,3> matrix() {
        return matrix(true);
    }
    
    Matrix<3,3> matrix(const bool reset) {
        
        auto const s1 = _mm_add_ps(data, data); // 2x 2y 2z 2w
        
        //First Row
        
        auto t1 = _mm_shuffle_ps(s1, s1, _MM_SHUFFLE(2,3,3,0)); // 2y 2x 2x w
        auto t2 = _mm_shuffle_ps(data, data, _MM_SHUFFLE(2,2,1,0)); // y y z w
        if (reset) t2 = _mm_reset_ps(t2, 0); // y y z 0
        
        auto t3 = _mm_mul_ps(t1, t2);
        t3 = _mm_mul_ps(t3, _mm_set_ps(-1.0f,1.0f,1.0f,1.0f)); // -2y^2 2xy 2xz 0
        
        auto t4 = _mm_shuffle_ps(s1, s1, _MM_SHUFFLE(1,1,2,0)); // 2z 2z 2y w
        auto t5 = _mm_shuffle_ps(data, data, _MM_SHUFFLE(1,0,0,0)); // z w w w
        if (reset) t5 = _mm_reset_ps(t5, 0); // z z w 0
        
        auto t6 = _mm_mul_ps(t4, t5);
        t6 = _mm_mul_ps(t6, _mm_set_ps(-1.0f,1.0f,-1.0f,1.0f)); // -2x^2 + 2zw - 2yw
        
        auto v1 = _mm_add_ps(_mm_set_ps(1.0f,0.0f,0.0f,0.0f), t3);
        v1 = _mm_add_ps(v1, t6);
        
        // Second Row

        t1 = _mm_shuffle_ps(s1, s1, _MM_SHUFFLE(3,3,2,0)); // 2x 2x 2y w
        
        t2 = _mm_shuffle_ps(data, data, _MM_SHUFFLE(2,3,1,0)); // y x z w
        if (reset) t2 = _mm_reset_ps(t2, 0); // y x z 0
        
        t3 = _mm_mul_ps(t1, t2);
        t3 = _mm_mul_ps(t3, _mm_set_ps(1.0f,-1.0f,1.0f,1.0f)); // 2xy 2x^2 2yz 0
        
        t4 = _mm_shuffle_ps(s1, s1, _MM_SHUFFLE(1,1,3,0)); // 2z 2z 2x w
        
        t5 = _mm_shuffle_ps(data, data, _MM_SHUFFLE(0,1,0,0)); // w z w w
        if (reset) t5 = _mm_reset_ps(t5, 0); // w z w 0
        
        t6 = _mm_mul_ps(t4, t5);
        t6 = _mm_mul_ps(t6, _mm_set_ps(-1.0f,-1.0f,1.0f,1.0f)); // -2xw - 2z^2 + 2xw
        
        auto v2 = _mm_add_ps(_mm_set_ps(0.0f,1.0f,0.0f,0.0f), t3);
        v2 = _mm_add_ps(v2, t6);
        
        //Third Row
        
        t1 = _mm_shuffle_ps(s1, s1, _MM_SHUFFLE(3,2,3,0)); // 2x 2y 2x w
        
        t2 = _mm_shuffle_ps(data, data, _MM_SHUFFLE(1,1,3,0)); // z z x w
        if (reset) t2 = _mm_reset_ps(t2, 0); // z z x 0
        
        t3 = _mm_mul_ps(t1, t2);
        t3 = _mm_mul_ps(t3, _mm_set_ps(1.0f,1.0f,-1.0f,-1.0f)); // 2xz 2yz -2x^2 0
        
        t4 = _mm_shuffle_ps(s1, s1, _MM_SHUFFLE(2,3,2,0)); // 2y 2x 2y w
        
        t5 = _mm_shuffle_ps(data, data, _MM_SHUFFLE(0,0,2,0)); // w w y w
        if (reset) t5 = _mm_reset_ps(t5, 0); // w w y 0
        
        t6 = _mm_mul_ps(t4, t5);
        t6 = _mm_mul_ps(t6, _mm_set_ps(1.0f,-1.0f,-1.0f,1.0f)); // 2yw - 2xw - 2y^2
        
        auto v3 = _mm_add_ps(_mm_set_ps(0.0f,0.0f,1.0f,0.0f), t3);
        v3 = _mm_add_ps(v3, t6);
        
        return Matrix<3,3>(Vec3(v1),Vec3(v2),Vec3(v3));
    }

    const __m128& data;
    
private:
    __m128 data_;
    
};

#endif
