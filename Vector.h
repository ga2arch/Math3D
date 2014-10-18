//
//  Vector.h
//  Math
//
//  Created by Gabriele on 18/10/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#include <iostream>
#include <xmmintrin.h>

// Curiously Recurring Template Pattern (CRTP)
// http://kaba.hilvi.org/pastel/techniques_specialization.htm

template <std::size_t N, typename Derived>
class BaseVector {
    
public:
    explicit BaseVector(const __m128& v): data(v) {}
    
    const __m128& operator()() const {
        return data;
    }
    
    Derived operator+(const Derived& d) const {
        return Derived(_mm_add_ps(data, d()));
    }
    
    Derived& operator+=(const Derived& d) {
        data = _mm_add_ps(data, d());
        return static_cast<Derived&>(*this);
    }
    
protected:
    __m128 data;
    
};

template <std::size_t N>
class Vector : public BaseVector<N, Vector<N>> {
  
private:
    typedef BaseVector<N, Vector<N>> Base;
    
public:
    explicit Vector(const __m128& v): Base(v) {}
    
};

template <>
class Vector<1> : public BaseVector<1, Vector<1>> {
    
private:
    typedef BaseVector<1, Vector<1>> Base;
    
public:
    explicit Vector<1>(const __m128& v): Base(v) {}
    explicit Vector<1>(float x);
    
};

template <>
class Vector<2> : public BaseVector<2, Vector<2>> {
    
private:
    typedef BaseVector<2, Vector<2>> Base;
    
public:
    explicit Vector<2>(const __m128& v): Base(v) {}
    explicit Vector<2>(float x, float y);
    
};

template <>
class Vector<3> : public BaseVector<3, Vector<3>> {
    
private:
    typedef BaseVector<3, Vector<3>> Base;
    
public:
    explicit Vector<3>(const __m128& v): Base(v) {}
    explicit Vector<3>(float x, float y, float z);
    
};

template <>
class Vector<4> : public BaseVector<4, Vector<4>> {
    
private:
    typedef BaseVector<4, Vector<4>> Base;
    
public:
    explicit Vector<4>(const __m128& v): Base(v) {}
    explicit Vector<4>(float x, float y, float z, float w);
    
};

typedef Vector<1> Vec1;
typedef Vector<2> Vec2;
typedef Vector<3> Vec3;
typedef Vector<4> Vec4;