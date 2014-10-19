//
//  Matrix.h
//  Math
//
//  Created by Gabriele on 19/10/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#ifndef matrix_h
#define matrix_h

#include <iostream>
#include "Vector.h"

using namespace std;

template <typename ...T>
struct are_same;

template <typename A, typename B, typename ...T>
struct are_same<A, B, T...> {
    static const bool value = std::is_same<A, B>::value && are_same<B, T...>::value;
};

template <typename A>
struct are_same<A> {
    static const bool value = true;
};

template <size_t R, size_t C>
class Matrix {
    
private:
    Vector<C> data_[R];
    
public:
    template <typename... T,
    typename = typename enable_if<(sizeof...(T) == R && are_same<Vector<C>, T...>::value) >::type>
    Matrix(T... rows): data_{rows...}, data(data_) {};

    const Vector<C>* data;
};

#endif
