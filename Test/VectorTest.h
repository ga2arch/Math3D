//
//  VectorTest.h
//  3DMath
//
//  Created by Gabriele on 24/10/14.
//  Copyright (c) 2014 Ga2 & co. All rights reserved.
//

#ifndef _DMath_VectorTest_h
#define _DMath_VectorTest_h

SCENARIO( "Vectors", "[vector]" ) {
    
    GIVEN( "Vec1" ) {
        __declspec(align(16)) float v1data[4];
        __declspec(align(16)) float t[4] = {1.0f};
        
        Vec1 v1(1.0f);
        _mm_storer_ps(v1data, v1.data);
        
        WHEN( "The content is checked" ) {
            for (int i=0; i < 4; i++) {
                REQUIRE (t[i] == v1data[i]);
                
            }
        }
    }
}

#endif
