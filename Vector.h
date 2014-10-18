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
class Vector<4> : public BaseVector<4, Vector<4>> {
    
private:
    typedef BaseVector<4, Vector<4>> Base;
    
public:
    explicit Vector<4>(const __m128& v): Base(v) {}
    explicit Vector<4>(float x, float y, float z, float w);
    
};

typedef Vector<4> Vec4;