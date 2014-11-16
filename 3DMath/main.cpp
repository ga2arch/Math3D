//
//  main.cpp
//  Math
//
//  Created by Gabriele on 18/10/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#include <iostream>
#include <chrono>

#include "3DMath.h"

using namespace std;
using namespace std::chrono;

int main(int argc, const char * argv[]) {
    auto t1 = high_resolution_clock::now();
    
    //auto m = normalize(v3);
    //auto b = dot(v1, v1);
    
    Vec3 v1(8.0f, 9.0f, 3.0f);
    Vec3 v2(4.0f, 8.0f, 2.0f);
    
    Vec4 v3(7.0f, 4.0f, 3.0f, 1.0f);
    Vec4 v4(9.0f, 8.0f, 2.0f, 5.0f);
    
    Matrix<2,3> m0{v1,v1};
    Matrix<3,3> m1{v1,v1,v1};
    
    
    
    //auto id = Matrix<4,4>::identity();
    //auto _q = v3*v4;
    auto q  = Quaternion(v1, 10.0f);
    auto q1 = Quaternion(v1, 10.0f);
    q.matrix();
    auto c = dot(v1, v2);
    
//    debug(b);
    
    auto t2 = high_resolution_clock::now();
    auto result = q*q1;

    auto duration = duration_cast<chrono::duration<double>>( t2 - t1 ).count();
    
    //cout << duration << endl;
    
    for (auto& e: q.matrix().data)
        debug(e.data);
    
}

