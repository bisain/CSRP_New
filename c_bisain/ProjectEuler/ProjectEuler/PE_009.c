//
//  PE_009.c
//  ProjectEuler
//
//  Created by Park, Sabin - 0559 - MITLL on 5/22/15.
//  Copyright (c) 2015 Park, Sabin - 0559 - MITLL. All rights reserved.
//

#include "header.h"

// there exists exactly one pythagorean triplet for which a + b + c = 1000
// use a for-loop from 1 to 1000 for A
// inside of that for-loop, create another for-loop for B (1 to 1000)
// calculate C
// Take the sume of A, B, and C and see if it equals 1000
// if it does, return A*B*C


int pythagoreanProduct(int targetSum) {
    int product = 0;
    
    
    for(int a=1; a<targetSum; a++) {
        for(int b=1; b<targetSum; b++) {
            double c = sqrt(a*a + b*b);
            
            if((a + b + c) == targetSum) {
                product = a*b*c;
            }
        }
    }
    
    return product;
}