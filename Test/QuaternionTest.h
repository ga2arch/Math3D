//
//  QuaternionTest.h
//  3DMath
//
//  Created by Gabriele Carrettoni on 28/10/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#ifndef _DMath_QuaternionTest_h
#define _DMath_QuaternionTest_h

SCENARIO( "Quaterions", "[quaterion]" ) {
    
    GIVEN( "Quaternion" ) {
        Vec3 v(1.0f,2.0f,3.0f);
        Quaternion q(v, 10);
        
        WHEN( "The content is checked" ) {
            __declspec(align(16)) float t[4];
            _mm_storer_ps(t, q.data);
            
            REQUIRE ( t[0] == (float)1.0f*sin(10/2) );
        }
    }
}


#endif
