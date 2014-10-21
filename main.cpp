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

using namespace std;
using namespace std::chrono;

int main(int argc, const char * argv[]) {
    auto t1 = high_resolution_clock::now();
    
    //auto m = normalize(v3);
    //auto b = dot(v1, v1);
    //auto c = abs_cross(v2, v2);
    
    Vec3 v1(4.0f, 1.0f, 1.0f);
    Matrix<2,3> m0{v1,v1};
    Matrix<3,3> m1{v1,v1,v1};
    auto id = Matrix<3,4>::identity();
    
    auto result = m0*m1;
    
    
    auto t2 = high_resolution_clock::now();
    
    auto duration = duration_cast<chrono::duration<double>>( t2 - t1 ).count();
    
    cout << duration << endl;
    
    for (auto& e: id.data)
        debug(e.data);
    
}

