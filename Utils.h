//
//  Utils.h
//  Math
//
//  Created by Gabriele on 19/10/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

// Single precision float have sign bit at 31° bit
// applying a mask of 0x7fffffff (31° bit is 0) allows
// to keep all the bits and setting the 31° to 0
// effectively abs-ing the number

#ifndef utils_h_
#define utils_h_

__declspec(align(16)) static const int absmask[] = {
    0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff
};

#define _mm_abs_ps(x) _mm_and_ps((x), *(const __m128*)absmask)

__m128 debug(__m128 a, int pos) {
    __declspec(align(16)) float A[4];
    _mm_store_ps(&A[0], a);
    
    std::cout << A[pos] << std::endl;
    return a;
}

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

#endif