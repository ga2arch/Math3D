//
//  main.cpp
//  Math
//
//  Created by Gabriele on 18/10/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#include <iostream>
#include <chrono>

#include "Vector.h"
#include "Matrix.h"
#include "Functions.h"
#include "Utils.h"
#include "Quaternion.h"
#include "SSEMathFun.h"

using namespace std;
using namespace std::chrono;

int main(int argc, const char * argv[]) {
    auto t1 = high_resolution_clock::now();
    
    //auto m = normalize(v3);
    //auto b = dot(v1, v1);
    
    Vec3 v1(4.0f, 1.0f, 1.0f);
    Matrix<2,3> m0{v1,v1};
    Matrix<3,3> m1{v1,v1,v1};
    //auto id = Matrix<4,4>::identity();
    
    auto q  = Quaternion(v1, 10.0f);
    auto q1 = Quaternion(v1, 10.0f);
    auto c = cross(v1, v1);

    
    auto t2 = high_resolution_clock::now();
    auto result = q*q1;

    auto duration = duration_cast<chrono::duration<double>>( t2 - t1 ).count();
    
    cout << duration << endl;
    
    //for (auto& e: q.data.data)
        debug(result.data);
    
}

