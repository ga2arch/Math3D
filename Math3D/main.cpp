//
//  main.cpp
//  Math
//
//  Created by Gabriele on 18/10/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#include <iostream>
#include <chrono>

#include "Math3D.h"

using namespace std;
using namespace std::chrono;

using namespace Math3D::functions;
using namespace Math3D::vector;

int main(int argc, const char * argv[]) {
    auto t1 = high_resolution_clock::now();
    
    //auto m = normalize(v3);
    //auto b = dot(v1, v1);
    
    Vec3 v1(8.0f, 9.0f, 3.0f);
    Vec3 v2(4.0f, 8.0f, 2.0f);
    
    Vec4 v3(7.0f, 4.0f, 3.0f, 1.0f);
    Vec4 v4(9.0f, 8.0f, 2.0f, 5.0f);
    
    Matrix<3,2> m0{Vec2(1.0f, 5.0f),Vec2(9.0f, 2.3f), Vec2(9.0f, 2.3f)};
    Matrix<3,3> m1{v1,v1,v1};
    
    float m1_n[3][3] = {{8.0f, 9.0f, 3.0f},{8.0f, 9.0f, 3.0f},{8.0f, 9.0f, 3.0f}};
    
    float v1_n[4] = {2.0f, 3.0f, 10.0f, 8.0f};
    float v2_n[4] = {2.0f, 3.0f, 10.0f, 8.0f};
    float v3_n[4] = {2.0f, 3.0f, 10.0f, 8.0f};

    auto r = m1 + m1;
    
    //auto id = Matrix<4,4>::identity();
    //auto _q = v3*v4;
    auto q  = Quaternion(v1, 10.0f);
    auto q1 = Quaternion(v1, 10.0f);
    q.matrix();
    auto c = dot(v1, v2);
    
//    debug(b);
    
    auto t2 = high_resolution_clock::now();
    
    m1 *= m0;

    auto duration1 = duration_cast<chrono::duration<double>>( t2 - t1 ).count();
    
    t2 = high_resolution_clock::now();
    
    for (int i=0; i < 3; i++) {
        for (int j=0; j < 3; j++) {
            m1_n[i][j] *= 2;
        }
    }
    
    auto duration2 = duration_cast<chrono::duration<double>>( t2 - t1 ).count();
    
    cout << duration1 << endl;

    cout << duration2 << endl;
    
//    for (auto& e: q.matrix().data)
//        debug(e.data);
    
}

